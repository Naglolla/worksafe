<?php

/**
 *
 * Function to fetch Sales Report page statistics.
 *
 * @return Statistics markup.
 */
function api_sales_report_summary_report() {
  $safety_key_stats = api_safety_keys_get_safety_key_satats();
  $user_stats = api_users_get_users_count();
  $company_stats = api_company_get_companies_count();
  return theme('api_sales_report_summary_report', array('safety_key_stats' => $safety_key_stats, 'user_stats' => $user_stats, 'company_stats' => $company_stats));
}

/**
 * Display Sales Report page.
 */
function api_sales_report_page($form, $form_state) {
  $form = array();
  $params = drupal_get_query_parameters();

  $form['#attached']['css'] = array(
		drupal_get_path('module', 'api_sales_report') . '/css/api_sales_report.css' => array(
		'type' => 'file',
		),
	);

  // Statistics Section.
  $sales_report_stats = api_sales_report_summary_report();
  $form['stats_container'] = array(
    '#type' => 'fieldset',
    '#attributes' => array('id' => 'statistics-container'),
  );
  $form['stats_container']['sales_report_stats'] = array(
    '#type' => 'markup',
    '#markup' => $sales_report_stats,
  );

  // Sales Report Section.

  $form['report_filters_container'] = array(
    '#type' => 'fieldset',
    '#attributes' => array('id' => 'report-filters-container'),
  );
  // Date Filter.
  $form['report_filters_container']['orders_date'] = array(
    '#type' => 'date_popup',
    '#title' => t('Date From'),
    '#default_value' => $params['orders_date'],
    '#date_format' => 'm/d/Y',
    '#date_label_position' => 'within',
  );
  $form['report_filters_container']['orders_to'] = array(
    '#type' => 'date_popup',
    '#title' => t('Date To'),
    '#default_value' => $params['orders_to'],
    '#date_format' => 'm/d/Y',
    '#date_label_position' => 'within',
  );

  // Payment Method Options.
  $payment_method_options = array(
    'all' => t('All'),
    'token' => t('Token'),
    'credit_card' => t('Credit Card'),
    'both' => t('Both'),
  );
  $form['report_filters_container']['payment_method'] = array(
    '#type' => 'select',
    '#title' => t('Payment Type'),
    '#default_value' => $params['payment_method'],
    '#options' => $payment_method_options,
  );

  // Payment Status Options.
  $payment_status_options = array(
    'all' => t('All'),
    'pending' => t('Pending'),
    'processing' => t('Processing'),
    'completed' => t('Completed'),
  );
  $form['report_filters_container']['payment_status'] = array(
    '#type' => 'select',
    '#title' => t('Payment Status'),
    '#default_value' => $params['payment_status'],
    '#options' => $payment_status_options,
  );

  // Program Options. Data not so often modified. So detch from cache for better performance.
  $program_options_cache = cache_get('sales_report_programs');
  if (isset($program_options_cache->data)) {
    $program_options = $program_options_cache->data;
  } else {
    $programs = api_programs_get_programs();
    $program_options = array('all' => t('All'));
    foreach ($programs as $program) {
      $program_options[$program->program_id] = $program->title;
    }
    cache_set('sales_report_programs', $program_options);
  }
  $form['report_filters_container']['program'] = array(
    '#type' => 'select',
    '#title' => t('Program'),
    '#default_value' => $params['program'],
    '#options' => $program_options,
  );

  // Submit Button
  $form['filter'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
    '#validate' => array('api_sales_report_validate_filters'),
    '#submit' => array('api_sales_report_submit_filters'),
  );
  // Download Button
  $form['export'] = array(
    '#type' => 'submit',
    '#value' => t('Export to Excel'),
    '#submit' => array('api_sales_report_export_results'),
  );

  // Create table with last 200 records.
  $records_table = api_sales_report_get_orders_list($params);

  // Add table with last 200 records.
  $form['records_table'] = $records_table['table'];

  return $form;
}

/**
 * Form Validate function.
 *
 * @param type $form
 * @param type $form_state
 */
function api_sales_report_validate_filters($form, $form_state) {
  $orders_date = strtotime($form_state['values']['orders_date']);
  $orders_to = strtotime($form_state['values']['orders_to']);
  if ($orders_date && $orders_to) {
    if ($orders_date > $orders_to) {
      form_set_error('orders_to', t('The "Date To" cannot be older than "Date From"'));
    }
    
  }
}

/**
 * Function to re invoke orders list page but with filters.
 *
 * @param type $form
 * @param type $form_state
 */
function api_sales_report_submit_filters($form, $form_state) {
  $orders_date = $form_state['values']['orders_date'];
  $orders_to = $form_state['values']['orders_to'];
  $payment_method = $form_state['values']['payment_method'];
  $payment_status = $form_state['values']['payment_status'];
  $program = $form_state['values']['program'];

  $url = 'admin/config/api/sales-report';
  $query = array();
  $query['query'] = array(
    'orders_date' => $orders_date,
    'orders_to' => $orders_to,
    'payment_method' => $payment_method,
    'payment_status' => $payment_status,
    'program' => $program,
  );
  drupal_goto($url, $query);
}

/**
 * Get users list from DB.
 * @return table of orders.
 */
function api_sales_report_get_orders_list($filters = array()) {
  // Fetch the sortable table header.
  $header = api_sales_report_get_orders_list_header();
  $options = api_sales_report_get_orders($filters, $header);
  $form = array('table');
  $form['table']['records'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $options,
    '#empty' => t('No content available.'),
    '#attributes' => array('class' => array('views-table cols-8')),
  );
  $form['table']['pager'] = array('#markup' => theme('pager'));
  return $form;
}

/**
 *
 * Get orders list filtered.
 * If no filters, return all.
 *
 * @param type $filters array of filters
 * @param type $header table header
 * @return array of orders.
 */
function api_sales_report_get_orders($filters, $header = array(), $limit = 500) {
  // Build the Query.
  $query = db_select('commerce_order', 'orders')->extend('PagerDefault')->extend('TableSort');
  $query
    ->fields('orders',array('order_id', 'uid', 'mail', 'status', 'created', 'data'))
    ->fields('u',array('name'))
    ->fields('cpt',array('payment_method', 'amount'))
    ->fields('cli',array('order_id', 'line_item_id', 'data', 'type'))
    ->fields('fdfa',array('field_address_administrative_area'))
    ->fields('fdct',array('commerce_total_currency_code', 'commerce_total_amount'))
    ->fields('fdcot',array('commerce_order_total_data'))
    ->fields('cp',array('title'))
    ->condition('cli.line_item_label', '', 'NOT LIKE')
    ->condition('cli.type', 'commerce_coupon', '!=')
    ->orderByHeader($header)
    ->limit($limit);

  $query->leftjoin('users', 'u', 'u.uid = orders.uid');
  $query->leftjoin('commerce_payment_transaction', 'cpt', 'cpt.order_id = orders.order_id');
  $query->leftjoin('field_data_commerce_line_items', 'fdcli', 'fdcli.entity_id = orders.order_id');
  $query->condition('fdcli.entity_type', 'commerce_order', '=');
  $query->condition('fdcli.deleted', 0, '=');
  $query->leftjoin('commerce_line_item', 'cli', 'cli.line_item_id = fdcli.commerce_line_items_line_item_id');
  $query->leftjoin('field_data_field_address', 'fdfa', 'fdfa.entity_id = u.uid');
  $query->condition('fdfa.entity_type', 'user', '=');
  $query->condition('fdfa.deleted', 0, '=');
  $query->leftjoin('field_data_commerce_total', 'fdct', 'fdct.entity_id = fdcli.commerce_line_items_line_item_id');
  $query->leftjoin('field_data_commerce_order_total', 'fdcot', 'fdcot.entity_id = orders.order_id');
  $query->leftjoin('field_data_commerce_product', 'fdcp', 'fdcp.entity_id = fdcli.commerce_line_items_line_item_id');
  $query->leftjoin('commerce_product', 'cp', 'cp.product_id = fdcp.commerce_product_product_id');

  // Date Filter.
  if (isset($filters['orders_date']) && $filters['orders_date'] != '') {
    if (isset($filters['orders_to']) && $filters['orders_to'] != '') {
      $date_to = $filters['orders_to'];
    } else {
      $date_to = $filters['orders_date'];
    }
    $s = DateTime::createFromFormat('Y-m-d G:i:s', $filters['orders_date']  . ' 00:00:00');
    $e = DateTime::createFromFormat('Y-m-d G:i:s', $date_to  . ' 23:59:59');
    if ($s) {
      $query->condition('orders.created', array($s->getTimestamp(), $e->getTimestamp()), 'BETWEEN');
    }
  }
  // Payment Status Filter.
  if (isset($filters['payment_status']) && $filters['payment_status'] != 'all') {
    $query->condition('orders.status', array($filters['payment_status']), '=');
  } else {
    $query->condition('orders.status', array('pending', 'processing', 'checkout_complete'), 'IN');
  }

  // Payment Method Filter.
  if (isset($filters['payment_method']) && $filters['payment_method'] != 'all') {
    // Unable to join info from DB. Instead, only filter by Token and rest programatically from $result.
    if ($filters['payment_method'] == 'token') {
      $query->condition('cpt.payment_method', 'token_payment');
    } elseif ($filters['payment_method'] == 'credit_card' || $filters['payment_method'] == 'both') {
      $query->condition('cpt.payment_method', 'token_payment', '<>');
    }
  }

  // Execute Query.
  $result = $query->execute();

  // Build Table Rows.
  $options = array();
  foreach ($result as $record) {
    $date = format_date($record->created, 'custom', t('m/d/Y', array(), array('context' => 'php date format')));
    $line_item_data = unserialize($record->cli_data);
    // FILTER BY PROGRAM (Unfortunately it's done here because $query is not able to apply filter to serialized data).
    if (isset($filters['program']) && $filters['program'] != 'all') {
      if (!isset($line_item_data['program_nid']) || $line_item_data['program_nid'] != $filters['program']) {
        continue;
      }
    }
    // Fetch row program (if any).
    $program_title = $program_nid ='';
    $safety_keys_total = 0;
    if (isset($line_item_data['program_nid'])) {
      $program_nid = $line_item_data['program_nid'];
      // Program Title. Data not so often modified. So detch from cache for better performance.
      $program_options_cache = cache_get('sales_report_programs');
      if ($program_options_cache->data && isset($program_options_cache->data[$program_nid])) {
        $program_title = $program_options_cache->data[$program_nid];
      } else {
        // Small query in order to avoid lading the entire node.
        $program_title = db_query("SELECT title FROM {node} WHERE nid = :nid", array(':nid' => $program_nid))->fetchField();
      }
      $safety_keys_total = api_safety_keys_total_valid_by_program($program_nid);
    }

    // Amount field.
    $amount = number_format($record->commerce_total_amount / 100, 2, '.', '');
    $commerce_total = unserialize($record->commerce_order_total_data);
    $price_amount = array();
    foreach ($commerce_total['components'] as $type) {
      // Amount field.
      $price = number_format($type['price']['amount'] / 100, 2, '.', '');
      $price_amount[$type['name']] = str_replace('-', '', $price);
    }

    // Prepar Payment Method
    $payment_method = '';
    $credit_amount = 0;
    if ($record->payment_method == 'token_payment') {
      $payment_method = t('Token');
      $credit_card_only = FALSE;
    } elseif(!empty($record->payment_method)) {
      $payment_method = t('Credit Card');
      $credit_card_only = TRUE;
      $credit_amount = number_format($record->amount / 100, 2, '.', '');
      if (isset($price_amount['token'])) {
        $payment_method .= '<br> '. t('Token');
        $credit_card_only = FALSE;
      }
    }

    // Payment Method. Rest of payment Filter (for "Credit Card" and "Both" options)
    if (isset($filters['payment_method']) && $filters['payment_method'] != 'all') {
      if ($filters['payment_method'] == 'credit_card' && !$credit_card_only) {
        continue;
      } elseif ($filters['payment_method'] == 'both' && $credit_card_only) {
        continue;
      }
    }
    $payment_status = $record->status;
    if ($record->status == 'checkout_complete') {
      $payment_status = 'Complete';
    }

    $payment_status = ucfirst($payment_status);
    if ($record->type == TOKEN_LINE_ITEM_TYPE || $record->type == TOKEN_USE_LINE_ITEM_TYPE) {
      $record->title = t('Token');
    }
    // Row.
    $options[] = array(
      'order_id' => $record->order_id,
      'date' => $date,
      'state' => $record->field_address_administrative_area,
      'username' => $record->name,
      'email' => $record->mail,
      'program' => $program_title,
      'course_product' => $record->title,
      'amount' => '$' . $amount,
      'order_amount' => (isset($price_amount['base_price'])) ? '$' . $price_amount['base_price'] : '',
      'payment_method' => $payment_method,
      'credit_amount' => '$' . $credit_amount,
      'token_amount' => (isset($price_amount['token'])) ? '-$' . $price_amount['token'] : '',
      'payment_status' => t($payment_status),
      'safety_keys' => ($safety_keys_total != 0) ? $safety_keys_total : '',
    );
  }

  return $options;
}

/**
 * Function to fetch orders list header.
 */
function api_sales_report_get_orders_list_header() {
  // Build the sortable table header.
  $header = array(
    'order_id' => array('data' => t('Order ID'), 'field' => 'orders.order_id'),
    'date' => array('data' => t('Date'), 'field' => 'orders.created'),
    'state' => array('data' => t('State')),
    'username' => array('data' => t('Username'), 'field' => 'u.name'),
    'email' => array('data' => t('E-mail')),
    'program' => array('data' => t('Program')),
    'course_product' => array('data' => t('Course/Product')),
    'amount' => array('data' => t('Unit Price'), 'field' => 'fdct.commerce_total_amount'),
    'order_amount' => array('data' => t('Total')),
    'payment_method' => array('data' => t('Payment Type')),
    'credit_amount' => array('data' => t('CC Payment')),
    'token_amount' => array('data' => t('Token Payment')),
    'payment_status' => array('data' => t('Payment Status'), 'field' => 'orders.status'),
    'safety_keys' => array('data' => t('Safety Keys')),
  );
  return $header;
}

/**
 * Function to export results to excel file.
 */
function api_sales_report_export_results() {
  $params = drupal_get_query_parameters();
  // Fetch the sortable table header.
  $header = api_sales_report_get_orders_list_header();

  // The 90000000000000 is terrible. Unfortunatelly Infinite/No limit value does not exist for MySQL.
  // @see http://bugs.mysql.com/bug.php?id=2037
  $db_records = api_sales_report_get_orders(array_filter($params), $header, 90000000000000);
  if ($db_records) {
    drupal_add_http_header('Content-Type', 'text/csv; utf-8');
    drupal_add_http_header('Content-Disposition', 'attachment;filename=orders-list.csv');
    $output = '';
    $header = array(
      t('Order ID'), t('Date'), t('State'), t('Username'), t('E-mail'), t('Program'), t('Course/Product'), t('Unit Price'),
      t('Total'), t('CC Payment'), t('Token Payment'), t('Payment Type'), t('Payment Status'), t('Safety Keys')
    );
    $output .= implode(",", $header) . "\n";
    foreach ($db_records as $row) {
      $output .=
        $row['order_id'] . ',' .
        $row['date'] . ',' .
        $row['state'] . ',' .
        $row['username'] . ',' .
        $row['email'] . ',' .
        $row['program'] . ',' .
        $row['course_product'] . ',' .
        $row['amount'] . ',' .
        $row['order_amount'] . ',' .
        $row['payment_method'] . ',' .
        $row['credit_amount'] . ',' .
        $row['token_amount'] . ',' .
        $row['payment_status'] . ',' .
        $row['safety_keys'] . ',' .
        "\n";
    }
    ob_clean();
    print $output;
    exit;
  }
}
