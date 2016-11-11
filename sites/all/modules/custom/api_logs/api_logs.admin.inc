<?php

/**
 * Display API Logs list.
 */
function api_logs_records_list($form, $form_state) {
  $form = array();
  $params = drupal_get_query_parameters();
  
  $form['#attached']['css'] = array(
		drupal_get_path('module', 'api_logs') . '/css/api_logs.css' => array(
		'type' => 'file',
		),
	);
  
  $form['api_logs_filters_container'] = array(
    '#type' => 'fieldset',
    '#attributes' => array('id' => 'api-logs-filters-container'),
  );
  
  // Date Range (Start Date / End Date).
  $form['api_logs_filters_container']['log_date_from'] = array(
    '#type' => 'date_popup',
    '#title' => t('Date From'),
    '#default_value' => $params['log_date_from'],
    '#date_format' => 'm/d/Y',
    '#date_label_position' => 'within',
  );
  $form['api_logs_filters_container']['log_date_to'] = array(
    '#type' => 'date_popup',
    '#title' => t('Date To'),
    '#default_value' => $params['log_date_to'],
    '#date_format' => 'm/d/Y',
    '#date_label_position' => 'within',
  );
  
  // Operations Types Options.
  $operations_types_options = api_logs_get_operations_types();
  $form['api_logs_filters_container']['operation_type'] = array(
    '#type' => 'select',
    '#title' => t('Operation Type'),
    '#default_value' => $params['operation_type'],
    '#options' => $operations_types_options,
  );
  
  // Author Filter.
  $form['api_logs_filters_container']['author'] = array(
    '#type' => 'textfield',
    '#title' => t('Author'),
    '#default_value' => $params['author'],
  );
  
  // Main ID Filter.
  $form['api_logs_filters_container']['main_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Main ID'),
    '#default_value' => $params['main_id'],
  );

  // Submit Button
  $form['api_logs_filters_container']['filter'] = array(
    '#type' => 'submit',
    '#value' => t('Filter'),
    '#validate' => array('api_logs_validate_filters'),
    '#submit' => array('api_logs_submit_filters'),
    '#attributes' => array('class' => array('ief-entity-submit'))
  );
  
  // Reset Button
  $form['api_logs_filters_container']['reset'] = array(
    '#markup' => '<div><a id="api-logs-reset" class="button" href="api-logs"/>' . t('Reset') . '</a></div>',
  );
  
  $api_logs_table = api_logs_get_records_list($params);

  $form['api_logs_table'] = $api_logs_table['table'];

  return $form;
}

/**
 * Form Validate function.
 *
 * @param type $form
 * @param type $form_state
 */
function api_logs_validate_filters($form, $form_state) {
  $log_date_from = strtotime($form_state['values']['log_date_from']);
  $log_date_to = strtotime($form_state['values']['log_date_to']);
  if ($log_date_from && $log_date_to) {
    if ($log_date_from > $log_date_to) {
      form_set_error('$log_date_to', t('The "Date To" cannot be older than "Date From"'));
    }
  }
}

/**
 * Function to re invoke API Logs list page with filters.
 *
 * @param type $form
 * @param type $form_state
 */
function api_logs_submit_filters($form, $form_state) {
  $log_date_from = $form_state['values']['log_date_from'];
  $log_date_to = $form_state['values']['log_date_to'];
  $operation_type = $form_state['values']['operation_type'];
  $author = $form_state['values']['author'];
  $main_id = $form_state['values']['main_id'];

  $url = 'admin/config/api/api-logs';
  $query = array();
  $query['query'] = array(
    'log_date_from' => $log_date_from,
    'log_date_to' => $log_date_to,
    'operation_type' => $operation_type,
    'author' => $author,
    'main_id' => $main_id,
  );
  drupal_goto($url, $query);
}

/**
 * Get API Logs from DB.
 * @return table of API logs.
 */
function api_logs_get_records_list($filters = array()) {
  // Fetch the sortable table header.
  $header = api_logs_get_api_list_header();
  $options = api_logs_get_logs_from_db($filters, $header);
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
 * Get API Logs list filtered.
 * If no filters, return all.
 *
 * @param type $filters array of filters
 * @param type $header table header
 * @return array of API Logs.
 */
function api_logs_get_logs_from_db($filters, $header = array(), $limit = 25) {
  // Build the Query.
  $query = db_select('api_logs', 'al')->extend('PagerDefault')->extend('TableSort');
  $query
    ->fields('al',array('lid', 'date', 'type', 'author', 'main_id', 'message'))
    ->orderByHeader($header)
    ->limit($limit);

  // Date Range (Start Date / End Date).
  if (isset($filters['log_date_from']) && $filters['log_date_from'] != '') {
    if (isset($filters['log_date_to']) && $filters['log_date_to'] != '') {
      $date_to = $filters['log_date_to'];
    } else {
      $date_to = $filters['log_date_from'];
    }
    $s = DateTime::createFromFormat('Y-m-d G:i:s', $filters['log_date_from']  . ' 00:00:00');
    $e = DateTime::createFromFormat('Y-m-d G:i:s', $date_to  . ' 23:59:59');
    if ($s) {
      $query->condition('al.date', array($s->getTimestamp(), $e->getTimestamp()), 'BETWEEN');
    }
  }

  // Operation Type Filter.
  if (isset($filters['operation_type']) && $filters['operation_type'] != 'all') {
    $query->condition('al.type', array($filters['operation_type']), '=');
  }
  
  // Author Filter.
  if (isset($filters['author']) && !empty($filters['author'])) {
    $query->condition('al.author', '%' . db_like($filters['author']) . '%', 'LIKE');
  }
  
  // Main ID Filter.
  if (isset($filters['main_id']) && !empty($filters['main_id'])) {
    $query->condition('al.main_id', '%' . db_like($filters['main_id']) . '%', 'LIKE');
  }

  // Execute Query.
  $result = $query->execute();

  // Build Table Rows.
  $options = array();
  foreach ($result as $record) {
    $output = truncate_utf8($record->message, 64, TRUE, TRUE);
    $link = l($output, 'admin/config/api/api-logs/record/' . $record->lid);
    
    $row_main_id = unserialize($record->main_id);
    if ($record->type == 'new account') {
      $main_id = l($row_main_id['title'], 'user/' . $row_main_id['id'], array('alias' => TRUE));
    } elseif($record->type == 'program purchase') {
      $main_id = l($row_main_id['title'], 'admin/commerce/orders/' . $row_main_id['id'], array('alias' => TRUE));
    } elseif($record->type == 'token management') {
      $token_id =  _get_token_by_code($row_main_id['id']);
      if ($token_id) {
        $main_id = l($row_main_id['title'], 'token_entity/token_entity_bundle/' . $token_id);
      } else {
        $main_id = $row_main_id['title'];
      }
    } else {
      $main_id = $row_main_id['title'];
    }
    $author = unserialize($record->author);
    
    // Row.
    $options[] = array(
      'date' => format_date($record->date, 'custom', 'Y-m-d h:iA'),
      'operation_type' => str_replace('_', ' ', $record->type),
      'author' => l($author['name'], 'user/' . $author['uid'], array('alias' => TRUE)),
      'main_id' => $main_id,
      'message' => $link,
    );
  }

  return $options;
}

/**
 * Function to fetch API Logs list header.
 */
function api_logs_get_api_list_header() {
  // Build the sortable table header.
  $header = array(
    'date' => array('data' => t('Date'), 'field' => 'al.date'),
    'operation_type' => array('data' => t('Operation Type'), 'field' => 'al.type'),
    'author' => array('data' => t('Author'), 'field' => 'al.author'),
    'main_id' => array('data' => t('Main ID')),
    'message' => array('data' => t('Message')),
  );
  return $header;
}

/**
 * Function to fetch API Logs Operations Types.
 */
function api_logs_get_operations_types() {
  // Operations Types Options. Data not so often modified. So fetch from cache for better performance.
  $operations_options_cache = cache_get('api_logs_operations_types');
  $operations_options_cache = array();

  if (isset($operations_options_cache->data)) {
    $operations_types_options = $operations_options_cache->data;
  } else {
    // Build the Query.
    $query = db_select('api_logs', 'al');
    $query->fields('al',array('type'));
    // Execute Query.
    $result = $query->execute();

    $operations_types_options = array('all' => t('All'));
    foreach ($result as $operation) {
      $operations_types_options[$operation->type] = str_replace('_', ' ', $operation->type);
    }
    cache_set('api_logs_operations_types', $operations_types_options);
  }
  
  return $operations_types_options;
}


/**
 * Page callback: Displays details about a specific API Log Event.
 *
 * @param int $id
 *   Unique ID of the API Log Event.
 *
 * @return array|string
 *   If the ID is located in the API Logs table, a build array in the
 *   format expected by drupal_render(); otherwise, an empty string.
 *
 */
function api_logs_event_details($id) {
  $result = db_query('SELECT * FROM {api_logs} WHERE api_logs.lid = :id', array(':id' => $id))->fetchAssoc();
  if ($api_log = $result) {
    
    // Author info - Pretty Display
    $author = unserialize($api_log['author']);
    $author_info = '';
    foreach ($author as $i => $value) {
      $i = str_replace('_', ' ', $i);
      $author_info .= '<b>' . ucfirst($i) . ':</b> ' . $value . '<br>';
    }
    
    // Variables info - Pretty Display
    $variables = unserialize($api_log['variables']);
    $variables_info = '';
    foreach ($variables as $i => $value) {
      $i = str_replace('_', ' ', $i);
      if (is_array($value)) {
        $variables_info .= '<b>' . ucfirst($i) . ':</b><br>';
        foreach ($value as $val) {
          $variables_info .= '&nbsp;&nbsp;&nbsp;&nbsp;' . $val . '<br>';
        }
      } else {
        $variables_info .= '<b>' . ucfirst($i) . ':</b> ' . $value . '<br>';
      }
    }

    $rows = array(
      array(
        array('data' => t('Type'), 'header' => TRUE),
        t($api_log['type']),
      ),
      array(
        array('data' => t('Date'), 'header' => TRUE),
        format_date($api_log['date'], 'long'),
      ),
      array(
        array('data' => t('User'), 'header' => TRUE),
        //'<pre>' . print_r(unserialize($api_log['author']), true) . '</pre>',
        $author_info,
      ),
      array(
        array('data' => t('Message'), 'header' => TRUE),
        $api_log['message'],
      ),
      array(
        array('data' => t('Variables'), 'header' => TRUE),
        //'<pre>' . print_r(unserialize($api_log['variables']), true) . '</pre>',
        $variables_info,  
      ),
    );
    $build['api_logs_table'] = array(
      '#theme' => 'table',
      '#rows' => $rows,
    );
    return $build;
  }
  else {
    return '';
  }
}

/**
 * Display API Logs Settings Form.
 */
function api_logs_settings($form, $form_state) {
  $form = array();
  $form['api_logs_settings_container'] = array(
    '#type' => 'fieldset',
    '#attributes' => array('id' => 'api-logs-settings-container'),
  );
  $db_max = variable_get('api_logs_max_records', 50000);
  // Author Filter.
  $form['api_logs_settings_container']['max_records'] = array(
    '#type' => 'textfield',
    '#title' => t('Max records to store'),
    '#description' => t('Max amount of records to store in database.'),
    '#default_value' => $db_max,
    '#required' => TRUE,
  );
  $db_remove = variable_get('api_logs_amount_to_remove', 10000);
  // Author Filter.
  $form['api_logs_settings_container']['amount_remove'] = array(
    '#type' => 'textfield',
    '#title' => t('Amount to remove'),
    '#description' => t('Amount of records to remove when cron runs.'),
    '#default_value' => $db_remove,
    '#required' => TRUE,
  );
  // Submit Button
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#validate' => array('api_logs_settings_validate'),
    '#submit' => array('api_logs_settings_submit'),
  );
  return $form;
}

/**
 * API Logs Settings form validation.
 */
function api_logs_settings_validate($form, $form_state) {
  $values = $form_state['values'];
  if (!is_numeric($values['max_records']) || !is_numeric($values['amount_remove'])) {
    form_set_error('', t('Only numeric values can be set. Please verify.'));
  }
  if ($values['amount_remove'] > $values['max_records']) {
    form_set_error('amount_remove', t('Amount to remove can not be higher than Max Records. Please verify.'));
  }
}

/**
 * API Logs Settings form submit.
 */
function api_logs_settings_submit($form, $form_state) {
  $values = $form_state['values'];
  variable_set('api_logs_max_records', $values['max_records']);
  variable_set('api_logs_amount_to_remove', $values['amount_remove']);
  drupal_set_message(t('Configuration saved.'));
}
