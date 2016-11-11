<?php

/**
 * Implements hook_field_views_data_alter().
 */
function api_custom_field_views_data_alter(&$result, $field, $module) {
  if ($module == 'addressfield') {
    foreach ($result as $table_name => $table) {
      $field_name = $field['field_name'];
      if (isset($result[$table_name][$field_name])) {
        $field_title = $result[$table_name][$field_name]['title'];
        $group = $result[$table_name][$field_name]['group'];
        $title = $field_title . ' with API Custom';
        $help = $result[$table_name][$field_name . '_data']['help'] . '. Address field province/region from ' . $field_name . ' field.';
        $result[$table_name]['table']['group'] = t('Province/Region');
        $result[$table_name][$field_name . '_data'] = array(
          'group' => $group,
          'title' => $title,
          'help' => $help,
          'field' => array(
            'handler' => 'api_custom_handler_addressfield',
            'click sortable' => TRUE,
          ),
          'filter' => array(
            'handler' => 'views_handler_filter_string',
          ),
        );
      }
    }
  }
}


/**
 * Implements hook_views_data()
 */
function api_custom_views_data() {
  // Add company's safety keys number.
  $data = array();
  $data['custom']['table']['group'] = t('Company - Safety Keys');
  $data['custom']['table']['join'] = array(
   // #global is a special flag which let's a table appear all the time.
   '#global' => array(),
  );
  $data['custom']['custom_handler'] = array(
    'title' => t('Number of Safety Keys.'),
    'help' => t('Number of Safety Keys issued for a company.'),
    'field' => array(
      'handler' => 'api_custom_handler_field_company_safety_keys',
    ),
  );

 return $data;
}
