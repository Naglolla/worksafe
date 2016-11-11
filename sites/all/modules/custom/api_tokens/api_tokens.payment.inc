<?php

/**
 * @file
 * Token payment method functions for Drupal commerce.
 */

/**
 * Returns form elements that payment method modules can
 *   incorporate into their submission form callbacks.
 *
 * @param $fields
 *   An array specifying the CC fields that should be included on the form; the
 *     card number and expiration date fields are always present.
 * @param $default
 *   An array of default values for the available CC fields.
 */
function api_tokens_payment_form() {

  $form['token'] = array(
    '#tree' => TRUE,
    '#attached' => array(
      'css' => array(drupal_get_path('module', 'commerce_payment') . '/theme/commerce_payment.theme.css'),
    ),
  );

  // Always add a field for the token code.
  $form['token']['code'] = array(
    '#type' => 'textfield',
    '#title' => t('Token ID'),
    '#attributes' => array('autocomplete' => 'off'),
    '#maxlength' => 8,
    '#size' => 20,
  );

  return $form;
}

/**
 * Validates token code.
 *
 * @param $details
 *   An array of token.
 * @param $settings
 *   Settings used for calling validation functions and setting form errors:
 *   - form_parents: an array of parent elements identifying where the token
 *     form was situated in the form array
 *
 * @return
 *   TRUE or FALSE indicating the validity of all the data.
 *
 * @see api_tokens_payment_form()
 */
function api_tokens_payment_validate($details, $settings, $order) {
  $prefix = implode('][', $settings['form_parents']) . '][';
  $valid = TRUE;

  $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
  $order_amount = $order_wrapper->commerce_order_total->amount->value();

  // if order total = 0 proceed to checkout
  if (empty($order_amount)) {
    return TRUE;
  }

  if (empty($details['code'])) {
    form_set_error($prefix . 'code', t('Token ID field is required.'));
     return FALSE;
  }
  // Validate token code.
  $token_id = _get_token_by_code($details['code']);
  if (empty($token_id)) {
    form_set_error($prefix . 'code', t('The Token you entered was not found.'));
    $valid = FALSE;
  } else {
    global $user;
    $profile = user_load($order->uid);
    // Load token entity.
    $tokens = entity_load(TOKEN_ENTITY, array($token_id));
    $token = reset($tokens);
    $token_wrapper = entity_metadata_wrapper(TOKEN_ENTITY, $token);
    $invalid_product_line = TRUE;
    // Validate if user is using the same Token Code
    foreach ($order_wrapper->commerce_line_items as $delta => $line_item_wrapper) {
      if ($line_item_wrapper->type->value() == TOKEN_USE_LINE_ITEM_TYPE) {
        $line_item_token = $line_item_wrapper->field_token->value();
        if ($token_id == $line_item_token->id) {
          form_set_error($prefix . 'code', t('You have already used this Token ID: @token_code.', array('@token_code' => $line_item_wrapper->field_token->field_token_entity_id->value())));
          $valid = FALSE;
        }
      }
      if ($line_item_wrapper->type->value() == 'product') {
        if(!api_tokens_validate_state_programs_token_line_item($token_wrapper, $line_item_wrapper)) {
          $invalid_product_line = FALSE;
        }
      }

    }

    // Check if Token ID is expired.
    $token_amount = api_tokens_get_order_token_amount($token_wrapper, $order_wrapper);
    if (!$token_amount['enabled']) {
      form_set_error($prefix . 'code', t('The Token ID is expired.'));
      $valid = FALSE;
    }

    if (!api_tokens_validate_company_token_code($token_wrapper, $order_wrapper)) {
      form_set_error($prefix . 'code', t('The Token ID does not belongs to your company.'));
      $valid = FALSE;
    }
    if (!api_tokens_validate_customer_support_token_code($token_wrapper, $order_wrapper)) {
      form_set_error($prefix . 'code', t('The Token ID does not belongs to your company.'));
      $valid = FALSE;
    }

    if ($token_amount['enabled'] && $valid && (!empty($token_amount['discount']) || !empty($token_amount['amount']))) {
      api_tokens_add_line_item($order_wrapper, $token_wrapper, $token_amount);
    }
    // We do this validation after line item creation in order to add multiple tokens to the order.
    if (!empty($token_amount['remaining']) && $token_amount['remaining'] > 0) {
      form_set_error($prefix . 'code', t('The provided Token ID doesn\'t have enough funds. Please, use another Token ID or payment method in order to complete the remaining total.'));
      $valid = FALSE;
    }

    // Validate if user is buying a token
    foreach ($order_wrapper->commerce_line_items as $delta => $line_item_wrapper) {
      if ($line_item_wrapper->type->value() == TOKEN_LINE_ITEM_TYPE) {
        form_set_error($prefix . 'code', t('You can not pay a token using a Token ID.'));
        $valid = FALSE;
      }
    }

    if (!$invalid_product_line) {
      form_set_error($prefix . 'code', t('There are products that you can not buy using this Token ID. Please, use another Token ID or payment method in order to complete the remaining total.'));
      $valid = FALSE;
    }


  }

  return $valid;
}

/**
 * Creates a token use line item on the provided order.
 *
 * @param EntityDrupalWrapper $order_wrapper
 *   The wrapped order entity.
 * @param EntityDrupalWrapper $token_wrapper
 *   The wrapper token entity.
 * @param array $price
 *   The discount amount price array (amount, currency_code).
 */
function api_tokens_add_line_item(EntityDrupalWrapper $order_wrapper, EntityDrupalWrapper $token_wrapper, $token_amount) {
  $token_price = $token_amount['discount'] + $token_amount['amount'];
  $price = array(
    'amount' => -$token_price,
    'currency_code' => commerce_default_currency()
  );
  // Create a new line item.
  $line_item = entity_create('commerce_line_item', array(
    'type' => TOKEN_USE_LINE_ITEM_TYPE,
    'order_id' => $order_wrapper->order_id->value(),
    'quantity' => 1,
  ));
  $line_item_wrapper = entity_metadata_wrapper('commerce_line_item', $line_item);

  // Set a reference to the token.
  $line_item_wrapper->field_token = $token_wrapper->value();

  // Set the token line item price.
  api_tokens_line_item_set_price($price, $line_item_wrapper, $token_wrapper);

  // Set the amount of money used from the token balance.
  $line_item_wrapper->field_token_amount->amount = $token_amount['amount'];
  $line_item_wrapper->field_token_amount->currency_code = commerce_default_currency();
  // Set the discount applied.
  $line_item_wrapper->field_token_discount->amount = $token_amount['discount'];
  $line_item_wrapper->field_token_discount->currency_code = commerce_default_currency();

  // Save the line item to get its ID.
  commerce_line_item_save($line_item_wrapper->value());

  // Add the line item to the order.
  $order_wrapper->commerce_line_items[] = $line_item_wrapper->value();

  // Save the order again to update its line item reference field.
  commerce_order_save($order_wrapper->value());

  // The wrapper "set" pattern breaks down because of the way Discount module
  // rebases line items during order refresh, so we manipulate the entity
  // directly. See commerce_gc_commerce_cart_order_refresh() for a similar
  // pattern.
  //$order = $order_wrapper->value();
  //$lang = field_language('commerce_order', $order, 'commerce_line_items');
  //$order->commerce_line_items[$lang][] = array('line_item_id' => $line_item->line_item_id);
}
