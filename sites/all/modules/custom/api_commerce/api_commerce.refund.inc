<?php

function api_commerce_refund_confirm($form, &$form_state, $order_id) {
  $order = api_commerce_get_order($order_id);
  $form['order_id'] = array('#type' => 'value', '#value' => $order->order_id);
  return confirm_form($form,
    t('Are you sure you want to request a refund for the order #%order_id?', array('%order_id' => $order->order_id)),
    'user/'.$order->uid.'/edit',
    t('This action cannot be undone.'),
    t('Refund'),
    t('Cancel')
  );
}

function api_commerce_refund_confirm_submit($form, &$form_state) {
  $order_id = $form_state['values']['order_id'];
  $order = api_commerce_get_order($order_id);
  if($form_state['values']['confirm']) {
    // Submit the request to PayPal.
    $response = api_commerce_order_refund_request($order_id);
    
    if ($response){
      // Current transaction
      $payment_transaction = api_commerce_get_transaction($order_id);
    
      // Prepare a transaction object to log the API response.
      $transaction = commerce_payment_transaction_new('paypal_wpp', $order->order_id);
      $transaction->instance_id = $payment_transaction->instance_id;
      $transaction->amount = - $payment_transaction->amount;
      $transaction->currency_code = $payment_transaction->currency_code;
      $transaction->payload[REQUEST_TIME] = $response;

      // Build a meaningful response message.
      $message = array();
      $action = 'Refund';

      // Set the remote ID and transaction status based on the acknowledgment code.
      switch ($response['ACK']) {
        case 'SuccessWithWarning':
        case 'Success':
          $transaction->remote_id = $response['REFUNDTRANSACTIONID'];
          $transaction->status = COMMERCE_PAYMENT_STATUS_SUCCESS;

          if ($response['ACK'] == 'SuccessWithWarning') {
            $message[0] = '<b>' . t('@action - Success (with warning)', array('@action' => $action)) . '</b>';
            $message[] = t('@severity @code: @message', array('@severity' => $response['L_SEVERITYCODE0'], '@code' => $response['L_ERRORCODE0'], '@message' => $response['L_LONGMESSAGE0']));
          }
          else {
            $message[] = '<b>' . t('@action - Success', array('@action' => $action)) . '</b>';
          }

          drupal_set_message(t("A refund for the order #@order_id has been requested.",
              array(
                "@order_id" => $order->order_id,
            )));
          
          // Update order status to 'Canceled'
          $order->status = 'canceled';
          commerce_order_save($order);
          
          // Reset products from the order
          api_commerce_reset_products($order);
          break;

        case 'FailureWithWarning':
        case 'Failure':
        default:
          // Create a failed transaction with the error message.
          $transaction->status = COMMERCE_PAYMENT_STATUS_FAILURE;
          $message[] = '<b>' . t('@action - Failure', array('@action' => $action)) . '</b>';
          $message[] = t('@severity @code: @message', array('@severity' => $response['L_SEVERITYCODE0'], '@code' => $response['L_ERRORCODE0'], '@message' => $response['L_LONGMESSAGE0']));

          drupal_set_message(t("A refund for the order #@order_id fail.",
              array(
                "@order_id" => $order->order_id,
            )),'error');
          drupal_set_message(t('@severity @code: @message', array('@severity' => $response['L_SEVERITYCODE0'], '@code' => $response['L_ERRORCODE0'], '@message' => $response['L_LONGMESSAGE0'])),'error');
          break;
      }  
      // Store the type of transaction in the remote status.
      $transaction->remote_status = $action;

      // Set the final message.
      $transaction->message = implode('<br />', $message);

      // Save the transaction information.
      commerce_payment_transaction_save($transaction);
    } else {
      drupal_set_message(t("A refund for the order #@order_id fail.",
            array(
              "@order_id" => $order->order_id,
          )),'error');
    }
  }
  $form_state['redirect'] = 'user/'.$order->uid.'/edit';
}

function api_commerce_get_order($order_id){
  $order = reset(entity_load('commerce_order', array($order_id)));
  return $order;
}

function api_commerce_get_transaction($order_id,$payment_method = 'paypal_wpp'){
  $transaction = reset(commerce_payment_transaction_load_multiple(array(), array('order_id' => $order_id, 'payment_method' => $payment_method)));
  return $transaction;
}

function api_commerce_order_refund_request($order_id){
  $order = api_commerce_get_order($order_id);
  $transaction = api_commerce_get_transaction($order_id);
  
  if ($order && $transaction){
    $payment_method = commerce_payment_method_instance_load($transaction->instance_id);
    $payment_method['settings'] += commerce_paypal_wpp_default_settings();
  
    $nvp = array(
      'METHOD' => 'RefundTransaction',
      'TRANSACTIONID' => $transaction->remote_id,
      'REFUNDTYPE' => 'Full'
    );
  
    $response = commerce_paypal_api_request($payment_method, $nvp, $order);
    return $response;
  }
  return FALSE;
}

function api_commerce_reset_products($order){
  // Reset 'courses'
  commerce_moodle_commerce_checkout_complete($order);
  
  // Reset 'tokens'
  $ow = entity_metadata_wrapper('commerce_order', $order);
  foreach ($ow->commerce_line_items as $line_item) {
    // Is a token item?
    if ($line_item->type->value() != TOKEN_LINE_ITEM_TYPE) {
      // Skip line item.
      continue;
    }

    // Load line item.
    $line_item_token = commerce_line_item_load($line_item->line_item_id->value());

    // Token Code / ID
    $token_code = $line_item->field_token_id->value();
    $token_id = _get_token_by_code($token_code);

    if ($token_id){
      $token = reset(entity_load(TOKEN_ENTITY, array($token_id),array('type' => TOKEN_ENTITY_BUNDLE)));
      $token->field_token_entity_money_charged[LANGUAGE_NONE][0]['value'] = 0;
      entity_save(TOKEN_ENTITY, $token);
    }
  }
  
  return TRUE;
}
