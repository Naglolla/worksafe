<?php
/**
 * @file
 * api_features_coupons.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function api_features_coupons_field_default_fields() {
  $fields = array();

  // Exported field: 'commerce_coupon-commerce_coupon_fixed-commerce_coupon_code'.
  $fields['commerce_coupon-commerce_coupon_fixed-commerce_coupon_code'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'commerce_coupon',
      ),
      'field_name' => 'commerce_coupon_code',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '1',
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'commerce_coupon_fixed',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'api_company_admin' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'commerce_coupon',
      'field_name' => 'commerce_coupon_code',
      'label' => 'Coupon Code',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'commerce_coupon-commerce_coupon_fixed-commerce_coupon_fixed_amount'.
  $fields['commerce_coupon-commerce_coupon_fixed-commerce_coupon_fixed_amount'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'commerce_coupon',
      ),
      'field_name' => 'commerce_coupon_fixed_amount',
      'foreign keys' => array(),
      'indexes' => array(
        'currency_price' => array(
          0 => 'amount',
          1 => 'currency_code',
        ),
      ),
      'label' => 'Fixed Amount',
      'locked' => '0',
      'module' => 'commerce_price',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'commerce_price',
    ),
    'field_instance' => array(
      'bundle' => 'commerce_coupon_fixed',
      'default_value' => array(
        0 => array(
          'amount' => 0,
          'currency_code' => 'USD',
          'data' => array(
            'components' => array(),
          ),
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'api_company_admin' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'commerce_price',
          'settings' => array(
            'calculation' => FALSE,
          ),
          'type' => 'commerce_price_formatted_amount',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'commerce_coupon',
      'field_name' => 'commerce_coupon_fixed_amount',
      'label' => 'Fixed Amount',
      'required' => TRUE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'commerce_price',
        'settings' => array(
          'currency_code' => 'default',
        ),
        'type' => 'commerce_price_full',
        'weight' => '0',
      ),
    ),
  );

  // Exported field: 'commerce_coupon-commerce_coupon_fixed-commerce_coupon_number_of_uses'.
  $fields['commerce_coupon-commerce_coupon_fixed-commerce_coupon_number_of_uses'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'commerce_coupon',
      ),
      'field_name' => 'commerce_coupon_number_of_uses',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'number',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'number_integer',
    ),
    'field_instance' => array(
      'bundle' => 'commerce_coupon_fixed',
      'default_value' => array(
        0 => array(
          'value' => 1,
        ),
      ),
      'deleted' => '0',
      'description' => 'Number of times that coupon code can be used by any customer on the site, before it is set to inactive',
      'display' => array(
        'api_company_admin' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
        ),
      ),
      'entity_type' => 'commerce_coupon',
      'field_name' => 'commerce_coupon_number_of_uses',
      'label' => 'Maximum number of Uses',
      'required' => FALSE,
      'settings' => array(
        'max' => '',
        'min' => '0',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'commerce_coupon-commerce_coupon_fixed-field_commerce_couponprodref'.
  $fields['commerce_coupon-commerce_coupon_fixed-field_commerce_couponprodref'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_commerce_couponprodref',
      'foreign keys' => array(
        'node' => array(
          'columns' => array(
            'target_id' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'views',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'view' => array(
            'args' => array(),
            'display_name' => 'entityreference_1',
            'view_name' => 'programs_entity_reference',
          ),
        ),
        'target_type' => 'node',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'commerce_coupon_fixed',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'api_company_admin' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 7,
        ),
      ),
      'entity_type' => 'commerce_coupon',
      'fences_wrapper' => '',
      'field_name' => 'field_commerce_couponprodref',
      'label' => 'Program',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => '',
        ),
        'type' => 'options_select',
        'weight' => '11',
      ),
    ),
  );

  // Exported field: 'commerce_coupon-commerce_coupon_fixed-field_company'.
  $fields['commerce_coupon-commerce_coupon_fixed-field_company'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_company',
      'foreign keys' => array(
        'node' => array(
          'columns' => array(
            'target_id' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'type' => 'none',
          ),
          'target_bundles' => array(
            'company' => 'company',
          ),
        ),
        'target_type' => 'node',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'commerce_coupon_fixed',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'api_company_admin' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => '4',
        ),
      ),
      'entity_type' => 'commerce_coupon',
      'fences_wrapper' => '',
      'field_name' => 'field_company',
      'label' => 'Company',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'api_company_admin',
        'settings' => array(
          'apply_chosen' => '',
          'custom_display_fields' => array(),
        ),
        'type' => 'company_reference',
        'weight' => '8',
      ),
    ),
  );

  // Exported field: 'commerce_coupon-commerce_coupon_fixed-field_expiration_date'.
  $fields['commerce_coupon-commerce_coupon_fixed-field_expiration_date'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_expiration_date',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'date',
      'settings' => array(
        'cache_count' => '4',
        'cache_enabled' => 0,
        'granularity' => array(
          'day' => 'day',
          'hour' => 'hour',
          'minute' => 'minute',
          'month' => 'month',
          'second' => 0,
          'year' => 'year',
        ),
        'timezone_db' => 'UTC',
        'todate' => 'optional',
        'tz_handling' => 'site',
      ),
      'translatable' => '0',
      'type' => 'datetime',
    ),
    'field_instance' => array(
      'bundle' => 'commerce_coupon_fixed',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'api_company_admin' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
          ),
          'type' => 'date_default',
          'weight' => '3',
        ),
      ),
      'entity_type' => 'commerce_coupon',
      'field_name' => 'field_expiration_date',
      'label' => 'Expiration Date',
      'required' => FALSE,
      'settings' => array(
        'default_value' => 'now',
        'default_value2' => 'same',
        'default_value_code' => '',
        'default_value_code2' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'date',
        'settings' => array(
          'increment' => 15,
          'input_format' => 'm/d/Y - H:i:s',
          'input_format_custom' => '',
          'label_position' => 'above',
          'text_parts' => array(),
          'year_range' => '-3:+3',
        ),
        'type' => 'date_popup',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'commerce_coupon-commerce_coupon_fixed-field_states'.
  $fields['commerce_coupon-commerce_coupon_fixed-field_states'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_states',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'AL' => 'Alabama',
          'AK' => 'Alaska',
          'AZ' => 'Arizona',
          'AR' => 'Arkansas',
          'CA' => 'California',
          'CO' => 'Colorado',
          'CT' => 'Connecticut',
          'DE' => 'Delaware',
          'DC' => 'District Of Columbia',
          'FL' => 'Florida',
          'GA' => 'Georgia',
          'HI' => 'Hawaii',
          'ID' => 'Idaho',
          'IL' => 'Illinois',
          'IN' => 'Indiana',
          'IA' => 'Iowa',
          'KS' => 'Kansas',
          'KY' => 'Kentucky',
          'LA' => 'Louisiana',
          'ME' => 'Maine',
          'MD' => 'Maryland',
          'MA' => 'Massachusetts',
          'MI' => 'Michigan',
          'MN' => 'Minnesota',
          'MS' => 'Mississippi',
          'MO' => 'Missouri',
          'MT' => 'Montana',
          'NE' => 'Nebraska',
          'NV' => 'Nevada',
          'NH' => 'New Hampshire',
          'NJ' => 'New Jersey',
          'NM' => 'New Mexico',
          'NY' => 'New York',
          'NC' => 'North Carolina',
          'ND' => 'North Dakota',
          'OH' => 'Ohio',
          'OK' => 'Oklahoma',
          'OR' => 'Oregon',
          'PA' => 'Pennsylvania',
          'RI' => 'Rhode Island',
          'SC' => 'South Carolina',
          'SD' => 'South Dakota',
          'TN' => 'Tennessee',
          'TX' => 'Texas',
          'UT' => 'Utah',
          'VT' => 'Vermont',
          'VA' => 'Virginia',
          'WA' => 'Washington',
          'WV' => 'West Virginia',
          'WI' => 'Wisconsin',
          'WY' => 'Wyoming',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'commerce_coupon_fixed',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'api_company_admin' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '5',
        ),
      ),
      'entity_type' => 'commerce_coupon',
      'fences_wrapper' => '',
      'field_name' => 'field_states',
      'label' => 'States',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => '',
        ),
        'type' => 'options_select',
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'commerce_coupon-commerce_coupon_pct-commerce_coupon_code'.
  $fields['commerce_coupon-commerce_coupon_pct-commerce_coupon_code'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'commerce_coupon',
      ),
      'field_name' => 'commerce_coupon_code',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '1',
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'commerce_coupon_pct',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'api_company_admin' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 3,
        ),
      ),
      'entity_type' => 'commerce_coupon',
      'field_name' => 'commerce_coupon_code',
      'label' => 'Coupon Code',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '0',
      ),
    ),
  );

  // Exported field: 'commerce_coupon-commerce_coupon_pct-commerce_coupon_number_of_uses'.
  $fields['commerce_coupon-commerce_coupon_pct-commerce_coupon_number_of_uses'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'commerce_coupon',
      ),
      'field_name' => 'commerce_coupon_number_of_uses',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'number',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'number_integer',
    ),
    'field_instance' => array(
      'bundle' => 'commerce_coupon_pct',
      'default_value' => array(
        0 => array(
          'value' => 1,
        ),
      ),
      'deleted' => '0',
      'description' => 'Number of times that coupon code can be used by any customer on the site, before it is set to inactive',
      'display' => array(
        'api_company_admin' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => ' ',
          ),
          'type' => 'number_integer',
          'weight' => 4,
        ),
      ),
      'entity_type' => 'commerce_coupon',
      'field_name' => 'commerce_coupon_number_of_uses',
      'label' => 'Maximum number of Uses',
      'required' => FALSE,
      'settings' => array(
        'max' => '',
        'min' => '0',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'commerce_coupon-commerce_coupon_pct-commerce_coupon_percent_amount'.
  $fields['commerce_coupon-commerce_coupon_pct-commerce_coupon_percent_amount'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'commerce_coupon',
      ),
      'field_name' => 'commerce_coupon_percent_amount',
      'foreign keys' => array(),
      'indexes' => array(),
      'label' => 'Percentage Amount',
      'locked' => '0',
      'module' => 'number',
      'settings' => array(
        'decimal_separator' => '.',
        'precision' => '10',
        'scale' => '2',
      ),
      'translatable' => '0',
      'type' => 'number_decimal',
    ),
    'field_instance' => array(
      'bundle' => 'commerce_coupon_pct',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'api_company_admin' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 2,
            'thousand_separator' => ' ',
          ),
          'type' => 'number_decimal',
          'weight' => 5,
        ),
      ),
      'entity_type' => 'commerce_coupon',
      'field_name' => 'commerce_coupon_percent_amount',
      'label' => 'Percentage Amount',
      'required' => TRUE,
      'settings' => array(
        'max' => '100',
        'min' => '0',
        'prefix' => '',
        'suffix' => '%',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'commerce_coupon-commerce_coupon_pct-field_company'.
  $fields['commerce_coupon-commerce_coupon_pct-field_company'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_company',
      'foreign keys' => array(
        'node' => array(
          'columns' => array(
            'target_id' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'type' => 'none',
          ),
          'target_bundles' => array(
            'company' => 'company',
          ),
        ),
        'target_type' => 'node',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'commerce_coupon_pct',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'api_company_admin' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 14,
        ),
      ),
      'entity_type' => 'commerce_coupon',
      'fences_wrapper' => '',
      'field_name' => 'field_company',
      'label' => 'Company',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'api_company_admin',
        'settings' => array(
          'apply_chosen' => '',
          'custom_display_fields' => array(),
        ),
        'type' => 'company_reference',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'commerce_coupon-commerce_coupon_pct-field_expiration_date'.
  $fields['commerce_coupon-commerce_coupon_pct-field_expiration_date'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_expiration_date',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'date',
      'settings' => array(
        'cache_count' => '4',
        'cache_enabled' => 0,
        'granularity' => array(
          'day' => 'day',
          'hour' => 'hour',
          'minute' => 'minute',
          'month' => 'month',
          'second' => 0,
          'year' => 'year',
        ),
        'timezone_db' => 'UTC',
        'todate' => 'optional',
        'tz_handling' => 'site',
      ),
      'translatable' => '0',
      'type' => 'datetime',
    ),
    'field_instance' => array(
      'bundle' => 'commerce_coupon_pct',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'api_company_admin' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
          ),
          'type' => 'date_default',
          'weight' => 13,
        ),
      ),
      'entity_type' => 'commerce_coupon',
      'fences_wrapper' => '',
      'field_name' => 'field_expiration_date',
      'label' => 'Expiration Date',
      'required' => 0,
      'settings' => array(
        'default_value' => 'now',
        'default_value2' => 'same',
        'default_value_code' => '',
        'default_value_code2' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'date',
        'settings' => array(
          'increment' => '15',
          'input_format' => 'm/d/Y - H:i:s',
          'input_format_custom' => '',
          'label_position' => 'above',
          'text_parts' => array(),
          'year_range' => '-3:+3',
        ),
        'type' => 'date_popup',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'commerce_coupon-commerce_coupon_pct-field_states'.
  $fields['commerce_coupon-commerce_coupon_pct-field_states'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_states',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'AL' => 'Alabama',
          'AK' => 'Alaska',
          'AZ' => 'Arizona',
          'AR' => 'Arkansas',
          'CA' => 'California',
          'CO' => 'Colorado',
          'CT' => 'Connecticut',
          'DE' => 'Delaware',
          'DC' => 'District Of Columbia',
          'FL' => 'Florida',
          'GA' => 'Georgia',
          'HI' => 'Hawaii',
          'ID' => 'Idaho',
          'IL' => 'Illinois',
          'IN' => 'Indiana',
          'IA' => 'Iowa',
          'KS' => 'Kansas',
          'KY' => 'Kentucky',
          'LA' => 'Louisiana',
          'ME' => 'Maine',
          'MD' => 'Maryland',
          'MA' => 'Massachusetts',
          'MI' => 'Michigan',
          'MN' => 'Minnesota',
          'MS' => 'Mississippi',
          'MO' => 'Missouri',
          'MT' => 'Montana',
          'NE' => 'Nebraska',
          'NV' => 'Nevada',
          'NH' => 'New Hampshire',
          'NJ' => 'New Jersey',
          'NM' => 'New Mexico',
          'NY' => 'New York',
          'NC' => 'North Carolina',
          'ND' => 'North Dakota',
          'OH' => 'Ohio',
          'OK' => 'Oklahoma',
          'OR' => 'Oregon',
          'PA' => 'Pennsylvania',
          'RI' => 'Rhode Island',
          'SC' => 'South Carolina',
          'SD' => 'South Dakota',
          'TN' => 'Tennessee',
          'TX' => 'Texas',
          'UT' => 'Utah',
          'VT' => 'Vermont',
          'VA' => 'Virginia',
          'WA' => 'Washington',
          'WV' => 'West Virginia',
          'WI' => 'Wisconsin',
          'WY' => 'Wyoming',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'commerce_coupon_pct',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'api_company_admin' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 15,
        ),
      ),
      'entity_type' => 'commerce_coupon',
      'fences_wrapper' => '',
      'field_name' => 'field_states',
      'label' => 'States',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => '',
        ),
        'type' => 'options_select',
        'weight' => '6',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Company');
  t('Coupon Code');
  t('Expiration Date');
  t('Fixed Amount');
  t('Maximum number of Uses');
  t('Number of times that coupon code can be used by any customer on the site, before it is set to inactive');
  t('Percentage Amount');
  t('Program');
  t('States');

  return $fields;
}
