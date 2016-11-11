<?php
/**
 * @file
 * commerce_kickstart_lite_product.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function commerce_kickstart_lite_product_field_default_fields() {
  $fields = array();

  // Exported field: 'commerce_product-product-commerce_price'.
  $fields['commerce_product-product-commerce_price'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'commerce_product',
      ),
      'field_name' => 'commerce_price',
      'foreign keys' => array(),
      'indexes' => array(
        'currency_price' => array(
          0 => 'amount',
          1 => 'currency_code',
        ),
      ),
      'locked' => '1',
      'module' => 'commerce_price',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'commerce_price',
    ),
    'field_instance' => array(
      'bundle' => 'product',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'add_to_cart_confirmation_view' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
        ),
        'commerce_line_item_display' => array(
          'label' => 'hidden',
          'module' => 'commerce_price',
          'settings' => array(
            'calculation' => 'calculated_sell_price',
          ),
          'type' => 'commerce_price_formatted_amount',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'commerce_price',
          'settings' => array(
            'calculation' => 'calculated_sell_price',
          ),
          'type' => 'commerce_price_formatted_amount',
          'weight' => '2',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'commerce_price',
          'settings' => array(
            'calculation' => 'calculated_sell_price',
          ),
          'type' => 'commerce_price_formatted_amount',
          'weight' => 0,
        ),
        'line_item' => array(
          'label' => 'hidden',
          'module' => 'commerce_price',
          'settings' => array(
            'calculation' => 'calculated_sell_price',
          ),
          'type' => 'commerce_price_formatted_amount',
          'weight' => 0,
        ),
        'node_product_list' => array(
          'label' => 'hidden',
          'module' => 'commerce_extra_price_formatters',
          'settings' => array(
            'alternative_text_for_zero_price' => '',
            'calculation' => TRUE,
            'prefix' => 'From',
            'suffix' => '',
            'text_format' => 'plain_text',
            'whole_numbers_only' => FALSE,
          ),
          'type' => 'commerce_price_prefix_suffix',
          'weight' => '3',
        ),
        'node_teaser' => array(
          'label' => 'hidden',
          'module' => 'commerce_price',
          'settings' => array(
            'calculation' => 'calculated_sell_price',
          ),
          'type' => 'commerce_price_formatted_amount',
          'weight' => 0,
        ),
        'product_in_cart' => array(
          'label' => 'hidden',
          'module' => 'commerce_price',
          'settings' => array(
            'calculation' => 'calculated_sell_price',
          ),
          'type' => 'commerce_price_formatted_amount',
          'weight' => 0,
        ),
        'token' => array(
          'label' => 'hidden',
          'module' => 'commerce_price',
          'settings' => array(
            'calculation' => 'calculated_sell_price',
          ),
          'type' => 'commerce_price_formatted_amount',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'commerce_product',
      'field_name' => 'commerce_price',
      'label' => 'Price',
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
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'commerce_product-product-field_course_type'.
  $fields['commerce_product-product-field_course_type'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_course_type',
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
          1 => 'Training',
          2 => 'Quiz',
          3 => 'Final Exam',
          4 => 'Full Course + Exam',
          5 => 'All Modules',
          6 => 'Recommended Practice',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_integer',
    ),
    'field_instance' => array(
      'bundle' => 'product',
      'commerce_cart_settings' => array(
        'attribute_field' => 0,
        'attribute_widget' => 'select',
        'attribute_widget_title' => 'Course type',
      ),
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'add_to_cart_confirmation_view' => array(
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
          'weight' => 8,
        ),
        'line_item' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'node_product_list' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'node_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'product_in_cart' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'commerce_product',
      'fences_wrapper' => '',
      'field_name' => 'field_course_type',
      'label' => 'Course type',
      'required' => 1,
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
        'weight' => '-1',
      ),
    ),
  );

  // Exported field: 'commerce_product-product-field_images'.
  $fields['commerce_product-product-field_images'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_images',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'product',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'add_to_cart_confirmation_view' => array(
          'label' => 'hidden',
          'module' => 'image_delta_formatter',
          'settings' => array(
            'deltas' => '0',
            'deltas_reversed' => 0,
            'image_link' => '',
            'image_style' => 'product_thumbnail',
          ),
          'type' => 'image_delta',
          'weight' => '0',
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => 'product_full',
          ),
          'type' => 'image',
          'weight' => '3',
        ),
        'line_item' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'node_product_list' => array(
          'label' => 'hidden',
          'module' => 'image_delta_formatter',
          'settings' => array(
            'deltas' => '0',
            'deltas_reversed' => 0,
            'image_link' => 'content',
            'image_style' => 'product_medium',
          ),
          'type' => 'image_delta',
          'weight' => '1',
        ),
        'node_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'product_in_cart' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'commerce_product',
      'fences_wrapper' => 'figure',
      'field_name' => 'field_images',
      'label' => 'Images',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 0,
        'file_directory' => '',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'image',
        'settings' => array(
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '8',
      ),
    ),
  );

  // Exported field: 'commerce_product-product-field_module_number'.
  $fields['commerce_product-product-field_module_number'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_module_number',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'number',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'number_integer',
    ),
    'field_instance' => array(
      'bundle' => 'product',
      'default_value' => array(
        0 => array(
          'value' => '0',
        ),
      ),
      'deleted' => '0',
      'description' => '0: final exam',
      'display' => array(
        'add_to_cart_confirmation_view' => array(
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
          'weight' => 7,
        ),
        'line_item' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'node_product_list' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'node_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'product_in_cart' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'commerce_product',
      'fences_wrapper' => '',
      'field_name' => 'field_module_number',
      'label' => 'Module number',
      'required' => 1,
      'settings' => array(
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'commerce_product-product-field_operator_types'.
  $fields['commerce_product-product-field_operator_types'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_operator_types',
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
          'A+B' => 'A+B',
          'A' => 'A',
          'B' => 'B',
          'C' => 'C',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'product',
      'commerce_cart_settings' => array(
        'attribute_field' => 0,
        'attribute_widget' => 'select',
        'attribute_widget_title' => 'Operator types',
      ),
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'add_to_cart_confirmation_view' => array(
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
          'weight' => 10,
        ),
        'line_item' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'node_product_list' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'node_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'product_in_cart' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'commerce_product',
      'fences_wrapper' => '',
      'field_name' => 'field_operator_types',
      'label' => 'Operator types',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => '1',
        ),
        'type' => 'options_select',
        'weight' => '-2',
      ),
    ),
  );

  // Exported field: 'commerce_product-product-field_states'.
  $fields['commerce_product-product-field_states'] = array(
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
      'bundle' => 'product',
      'commerce_cart_settings' => array(
        'attribute_field' => 0,
        'attribute_widget' => 'select',
        'attribute_widget_title' => 'States',
      ),
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'add_to_cart_confirmation_view' => array(
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
          'weight' => 9,
        ),
        'line_item' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'node_product_list' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 0,
        ),
        'node_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'product_in_cart' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'commerce_product',
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
          'apply_chosen' => '1',
        ),
        'type' => 'options_select',
        'weight' => '-3',
      ),
    ),
  );

  // Exported field: 'commerce_product-product-title_field'.
  $fields['commerce_product-product-title_field'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'title_field',
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
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => '1',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'product',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'add_to_cart_confirmation_view' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 6,
        ),
        'line_item' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'node_product_list' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '2',
        ),
        'node_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'product_in_cart' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'commerce_product',
      'fences_wrapper' => 'h2',
      'field_name' => 'title_field',
      'label' => 'Title',
      'required' => TRUE,
      'settings' => array(
        'hide_label' => array(
          'entity' => FALSE,
          'page' => FALSE,
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-product_display-body'.
  $fields['node-product_display-body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
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
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'product_display',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '2',
        ),
        'product_list' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'trim_length' => 600,
          ),
          'type' => 'text_summary_or_trimmed',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'fences_wrapper' => '',
      'field_name' => 'body',
      'label' => 'Short description of the program contents',
      'required' => 0,
      'settings' => array(
        'display_summary' => 0,
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '20',
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-product_display-field_product'.
  $fields['node-product_display-field_product'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_product',
      'foreign keys' => array(
        'product_id' => array(
          'columns' => array(
            'product_id' => 'product_id',
          ),
          'table' => 'commerce_product',
        ),
      ),
      'indexes' => array(
        'product_id' => array(
          0 => 'product_id',
        ),
      ),
      'locked' => '0',
      'module' => 'commerce_product_reference',
      'settings' => array(
        'options_list_limit' => '',
      ),
      'translatable' => '0',
      'type' => 'commerce_product_reference',
    ),
    'field_instance' => array(
      'bundle' => 'product_display',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'commerce_cart',
          'settings' => array(
            'combine' => 1,
            'default_quantity' => '1',
            'line_item_type' => 'product',
            'show_quantity' => 1,
            'show_single_product_attributes' => 0,
          ),
          'type' => 'commerce_cart_add_to_cart_form',
          'weight' => '3',
        ),
        'product_list' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '7',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'fences_wrapper' => 'div',
      'field_name' => 'field_product',
      'label' => 'Course',
      'required' => 0,
      'settings' => array(
        'field_injection' => 1,
        'referenceable_types' => array(
          'product' => 'product',
        ),
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'inline_entity_form',
        'settings' => array(
          'fields' => array(),
          'type_settings' => array(
            'allow_existing' => 0,
            'autogenerate_title' => 0,
            'delete_references' => 1,
            'label_plural' => 'products',
            'label_singular' => 'product',
            'match_operator' => 'CONTAINS',
            'override_labels' => 0,
          ),
        ),
        'type' => 'inline_entity_form',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'node-product_display-field_product_category'.
  $fields['node-product_display-field_product_category'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_product_category',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'product_category',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'product_display',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
        ),
        'product_list' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'fences_wrapper' => '',
      'field_name' => 'field_product_category',
      'label' => 'Program category',
      'product_catalog' => 1,
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => '0',
        ),
        'type' => 'options_select',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-product_display-title_field'.
  $fields['node-product_display-title_field'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'title_field',
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
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => '1',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'product_display',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'product_list' => array(
          'label' => 'hidden',
          'module' => 'title',
          'settings' => array(
            'title_class' => '',
            'title_link' => 'content',
            'title_style' => '_none',
          ),
          'type' => 'title_linked',
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'fences_wrapper' => 'h2',
      'field_name' => 'title_field',
      'label' => 'Program Name',
      'required' => 1,
      'settings' => array(
        'hide_label' => array(
          'entity' => 0,
          'page' => 0,
        ),
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '0',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('0: final exam');
  t('Course');
  t('Course type');
  t('Images');
  t('Module number');
  t('Operator types');
  t('Price');
  t('Program Name');
  t('Program category');
  t('Short description of the program contents');
  t('States');
  t('Title');

  return $fields;
}
