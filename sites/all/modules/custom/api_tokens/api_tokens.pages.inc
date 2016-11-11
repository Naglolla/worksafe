<?php

function api_tokens_get_token($token_id){
  $token = reset(entity_load('token_entity', array($token_id)));
  return $token;
}

function api_tokens_modify_token_page(){
  $output = views_embed_view('token_management', 'page');

  return $output;
}

function api_tokens_delete_confirm($form, &$form_state, $token_id) {
  $token = api_tokens_get_token($token_id);
  $form['token_id'] = array('#type' => 'value', '#value' => $token->id);
  return confirm_form($form,
    //t('Are you sure you want to remove the token %token_id?', array('%token_id' => $token->field_token_entity_id[LANGUAGE_NONE][0]['value'])),'token/' . $token->id . '/view',
    t('Are you sure you want to remove the token %token_id?', array('%token_id' => $token->field_token_entity_id[LANGUAGE_NONE][0]['value'])),'token/modify',
    t('This action cannot be undone.'),
    t('Remove'),
    t('Cancel')
  );
}

function api_tokens_delete_confirm_submit($form, &$form_state) {
  if($form_state['values']['confirm']) {
    $token_id = $form_state['values']['token_id'];
    $token = api_tokens_get_token($token_id);
    $token_amount = floatval($token->field_token_entity_money_charged[LANGUAGE_NONE][0]['value']);

    if ($token_amount > 0){
      drupal_set_message(t('The token you want to remove has money left. You can not delete.'), 'error');
    } else {
      $history = api_tokens_get_purchase_history($token_id, TRUE);
      if (count($history)){
        drupal_set_message(t('The token you want to remove has already been used. You can not delete.'), 'error');
      } else {
        drupal_set_message(t("The token @token_code has been deleted",
          array(
            "@token_code" => $token->field_token_entity_id[LANGUAGE_NONE][0]['value'],
        )));
        entity_delete('token_entity', $token_id);
      }
    }
  }
  $form_state['redirect'] = 'token/modify';
}

function api_tokens_company_admin_token_list_page(){
  global $user;
  
  //drupal_set_title(t('Tokens'));
  $company_nid = _get_user_company($user->uid);

  // List all tokens that belongs to the company.
  $output = views_embed_view('company_admin_tokens_list', 'block_tokens_list');
  return $output;
}

function api_tokens_view_token_page($token_id){
  $token = api_tokens_get_token($token_id);
  if ($token){
    $token_meta = entity_metadata_wrapper('token_entity', $token);
    $token_code = $token_meta->field_token_entity_id->value();
    drupal_set_title(t('Token @token_code',  array('@token_code' => $token_code)));

    $user = $token_meta->uid->value();

    if ($token_meta->field_entity_tokendiscount_value->value()){
      if ($token_meta->field_entity_token_fixed_percent->value() == TOKEN_FIXED_DISCOUNT){
        $discount = commerce_currency_format($token_meta->field_entity_tokendiscount_value->value(),'USD',NULL,FALSE);
      } else {
        $discount = $token_meta->field_entity_tokendiscount_value->value() . '%';
      }
    } else {
      $discount = NULL;
    }

    $programs = array();
    if ($token_meta->field_token_entity_programs->value()){
      foreach ($token_meta->field_token_entity_programs->value() as $program) {
        array_push($programs,$program->title);
      }
    }

    $states = array();
    $us_states = _api_custom_get_us_states();
    if ($token_meta->field_token_entity_states->value()){
      foreach ($token_meta->field_token_entity_states->value() as $state) {
        array_push($states,$us_states[$state]);
      }
    }

    $details = array(
      'details' => array(
        'created' => format_date($token_meta->created->value(), 'custom', 'm/d/Y'),
        'total_value' => $token_meta->field_token_total_value->value() ? commerce_currency_format($token_meta->field_token_total_value->value(),'USD',NULL,FALSE):t('N/A'),
        'balance' => commerce_currency_format($token_meta->field_token_entity_money_charged->value(),'USD',NULL,FALSE),
        'person' => array(
          'name' => $user->field_first_name[LANGUAGE_NONE][0]['value'] . ' ' . $user->field_last_name[LANGUAGE_NONE][0]['value'],
          'email' => $user->mail,
          'phone' => $user->field_tel[LANGUAGE_NONE][0]['value'],
        ),
        'discount' => $discount,
        'program' => $programs,
        'state' => $states,
        'notes' => $token_meta->field_token_notes->value() ? $token_meta->field_token_notes->value():t('N/A'),
        'history' => api_tokens_purchase_history_page($token_id),
        'export' => count(api_tokens_get_purchase_history($token_id)) ? l(t('Export'), 'token/'.$token_id.'/history/export', array('attributes' => array('class'=> 'button primary export-csv-button'))):NULL,
      )
    );
    return theme('token_details',$details);
  } else {
    return t('No available information.');
  }
}

function api_tokens_purchase_history_export($token_id){
  $output = api_tokens_purchase_history_page($token_id);
  $fulldate = date('Ymd-His');
  drupal_add_http_header('Content-Type', 'application/vnd.ms-excel; utf-8');
  drupal_add_http_header('Content-Disposition', 'attachment;filename=token-purchase-history-'.$fulldate.'.xls');
  ob_clean();
  print $output;
  exit;
}

function api_tokens_get_purchase_history($token_id,$include_token_product = FALSE){
  $token = api_tokens_get_token($token_id);
  $history = array();

  if ($token){
    $items_ids = array();
    $tokens_use = entity_load('commerce_line_item', $items_ids,array('type' =>TOKEN_USE_LINE_ITEM_TYPE));
    if ($include_token_product){
      $items_token_entity = entity_load('commerce_line_item', $items_ids,array('type' =>TOKEN_LINE_ITEM_TYPE));
    } else {
      $items_token_entity = array();
    }
    $tokens = array_merge($tokens_use, $items_token_entity);
    foreach ($tokens as $token) {
      if ($token->type == TOKEN_USE_LINE_ITEM_TYPE && $token->field_token[LANGUAGE_NONE][0]['target_id'] == $token_id){
        $token_use = new stdClass();
        $token_use->order_id = $token->order_id;
        $token_use->created = $token->created;
        $token_use->amount = abs($token->commerce_total[LANGUAGE_NONE][0]['amount']);
        $token_use->amount_token = $token->field_token_amount[LANGUAGE_NONE][0]['amount'];
        $token_use->currency_code = $token->field_token_amount[LANGUAGE_NONE][0]['currency_code'];
        $history[$token->order_id] = $token_use;
      } else if ($token->type == TOKEN_LINE_ITEM_TYPE) {
        $order_token_id = _get_token_by_code($token->field_token_id[LANGUAGE_NONE][0]['value']);
        if ($order_token_id == $token_id){
          $token_use = new stdClass();
          $token_use->order_id = $token->order_id;
          $token_use->created = $token->created;
          $token_use->amount = $token->commerce_total[LANGUAGE_NONE][0]['amount'];
          $token_use->currency_code = $token->commerce_total[LANGUAGE_NONE][0]['currency_code'];
          $history[$token->order_id] = $token_use;
        }
      }
    }
  }
  return $history;
}

function api_tokens_purchase_history_page($token_id){
  $output = t('No available information.');
  $history = api_tokens_get_purchase_history($token_id);

  if (count($history)){
    $output = '';
    $order_ids = array_keys($history);
    $orders = entity_load('commerce_order', $order_ids, array('status'=>array('pending','processing','completed')), FALSE);
    usort($orders, "api_tokens_sort_created");

    $header = array(t('Order ID'),t('Order Details'),t('Amount'),t('User'),t('Date'),t('Status'));
    $rows = array();
    $table_attributes = array('id' => 'purchase-table', 'align' => 'center', 'width' => '100%');

    foreach ($orders as $order) {
      $user = user_load($order->uid);

      $purchased = new api_commerce($user->uid);
      $courses = $purchased->getCourses($order->order_id);

      foreach ($courses as $course) {
        $title = $purchased->getCourseName($course);

        if ($course->status == COURSE_STATUS_SAFETY_KEY_RECEIVED){
          $status = t('Passed');
        } else if ($course->status == COURSE_STATUS_NOT_STARTED){
          $status = t('Not Started');
        } else if ($course->status == COURSE_STATUS_RESTORED || $course->status == COURSE_STATUS_STARTED){
          $status = t('In Progress');
        } else {
          //$course->status == COURSE_STATUS_ALL_MODULES_COMPLETED
          // TO-DO: check if the final exam was failed
          $status = t('Failed');
        }
        $rows[] = array($order->order_id,$title,commerce_currency_format($history[$order->order_number]->amount,$history[$order->order_number]->currency_code,NULL,TRUE),$user->name,format_date($order->created, 'custom', 'm/d/Y'),$status);
      }
    }

    $per_page = 20;
    // Initialize the pager
    $current_page = pager_default_initialize(count($rows), $per_page);
    // Split your list into page sized chunks
    $chunks = array_chunk($rows, $per_page, TRUE);
    // Show the appropriate items from the list
    $output .= theme_table(array('header' => $header, 'rows' => $chunks[$current_page], 'attributes' => $table_attributes));
    // Show the pager
    $output .= theme('pager',array('quantity' => count($rows),'tags' => array('<<','<',NULL,'>','>>')));
  }
  return $output;
}

function api_tokens_sort_created($a, $b)
{
  return strcmp($b->created, $a->created);
}
