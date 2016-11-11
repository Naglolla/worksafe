<?php
/**
 * @file
 * api_features_coupons_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function api_features_coupons_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'api_coupons';
  $view->description = 'Display a list of coupons for the store admin.';
  $view->tag = 'commerce coupon';
  $view->base_table = 'commerce_coupon';
  $view->human_name = 'API Coupons';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Coupons';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer commerce_coupon entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'commerce_coupon_code' => 'commerce_coupon_code',
    'commerce_coupon_fixed_amount' => 'commerce_coupon_fixed_amount',
    'commerce_coupon_percent_amount' => 'commerce_coupon_percent_amount',
    'field_expiration_date_1' => 'field_expiration_date_1',
    'is_active' => 'is_active',
    'field_commerce_couponprodref' => 'field_commerce_couponprodref',
    'operations' => 'operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'commerce_coupon_code' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_enumerate' => 'views_aggregator_enumerate',
        'views_aggregator_group_and_compress' => 'views_aggregator_group_and_compress',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'commerce_coupon_fixed_amount' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'commerce_coupon_percent_amount' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_expiration_date_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'is_active' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_commerce_couponprodref' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_enumerate' => 'views_aggregator_enumerate',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'operations' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '1';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  /* Relationship: Commerce Coupon: Type */
  $handler->display->display_options['relationships']['type']['id'] = 'type';
  $handler->display->display_options['relationships']['type']['table'] = 'commerce_coupon';
  $handler->display->display_options['relationships']['type']['field'] = 'type';
  $handler->display->display_options['relationships']['type']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_commerce_couponprodref_target_id']['id'] = 'field_commerce_couponprodref_target_id';
  $handler->display->display_options['relationships']['field_commerce_couponprodref_target_id']['table'] = 'field_data_field_commerce_couponprodref';
  $handler->display->display_options['relationships']['field_commerce_couponprodref_target_id']['field'] = 'field_commerce_couponprodref_target_id';
  /* Field: Commerce Coupon: Coupon Code */
  $handler->display->display_options['fields']['commerce_coupon_code']['id'] = 'commerce_coupon_code';
  $handler->display->display_options['fields']['commerce_coupon_code']['table'] = 'field_data_commerce_coupon_code';
  $handler->display->display_options['fields']['commerce_coupon_code']['field'] = 'commerce_coupon_code';
  /* Field: Commerce Coupon: Fixed Amount */
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['id'] = 'commerce_coupon_fixed_amount';
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['table'] = 'field_data_commerce_coupon_fixed_amount';
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['field'] = 'commerce_coupon_fixed_amount';
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['label'] = 'Amount';
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['element_type'] = '0';
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['settings'] = array(
    'calculation' => FALSE,
  );
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['field_api_classes'] = TRUE;
  /* Field: Commerce Coupon: Percentage Amount */
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['id'] = 'commerce_coupon_percent_amount';
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['table'] = 'field_data_commerce_coupon_percent_amount';
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['field'] = 'commerce_coupon_percent_amount';
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['label'] = 'Percentage';
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['element_type'] = '0';
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['field_api_classes'] = TRUE;
  /* Field: Commerce Coupon: Expiration Date */
  $handler->display->display_options['fields']['field_expiration_date_1']['id'] = 'field_expiration_date_1';
  $handler->display->display_options['fields']['field_expiration_date_1']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date_1']['field'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date_1']['label'] = 'Start Date / End Date';
  $handler->display->display_options['fields']['field_expiration_date_1']['settings'] = array(
    'format_type' => 'api_m_d_y',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Commerce Coupon: Is active */
  $handler->display->display_options['fields']['is_active']['id'] = 'is_active';
  $handler->display->display_options['fields']['is_active']['table'] = 'commerce_coupon';
  $handler->display->display_options['fields']['is_active']['field'] = 'is_active';
  $handler->display->display_options['fields']['is_active']['label'] = 'Enable/Disable';
  $handler->display->display_options['fields']['is_active']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['is_active']['not'] = 0;
  /* Field: Commerce Coupon: Program */
  $handler->display->display_options['fields']['field_commerce_couponprodref']['id'] = 'field_commerce_couponprodref';
  $handler->display->display_options['fields']['field_commerce_couponprodref']['table'] = 'field_data_field_commerce_couponprodref';
  $handler->display->display_options['fields']['field_commerce_couponprodref']['field'] = 'field_commerce_couponprodref';
  $handler->display->display_options['fields']['field_commerce_couponprodref']['label'] = 'Programs';
  $handler->display->display_options['fields']['field_commerce_couponprodref']['element_type'] = '0';
  $handler->display->display_options['fields']['field_commerce_couponprodref']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_commerce_couponprodref']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_commerce_couponprodref']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_commerce_couponprodref']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_commerce_couponprodref']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_commerce_couponprodref']['field_api_classes'] = TRUE;
  /* Field: Commerce Coupon: Operations */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'commerce_coupon';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  $handler->display->display_options['fields']['operations']['add_destination'] = 1;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
  );
  /* Filter criterion: Commerce Coupon: Coupon Code (commerce_coupon_code) */
  $handler->display->display_options['filters']['commerce_coupon_code_value']['id'] = 'commerce_coupon_code_value';
  $handler->display->display_options['filters']['commerce_coupon_code_value']['table'] = 'field_data_commerce_coupon_code';
  $handler->display->display_options['filters']['commerce_coupon_code_value']['field'] = 'commerce_coupon_code_value';
  $handler->display->display_options['filters']['commerce_coupon_code_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['commerce_coupon_code_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['commerce_coupon_code_value']['expose']['operator_id'] = 'commerce_coupon_code_value_op';
  $handler->display->display_options['filters']['commerce_coupon_code_value']['expose']['label'] = 'Coupon Code';
  $handler->display->display_options['filters']['commerce_coupon_code_value']['expose']['operator'] = 'commerce_coupon_code_value_op';
  $handler->display->display_options['filters']['commerce_coupon_code_value']['expose']['identifier'] = 'commerce_coupon_code_value';
  $handler->display->display_options['filters']['commerce_coupon_code_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    5 => 0,
  );
  /* Filter criterion: Field: States (field_states) */
  $handler->display->display_options['filters']['field_states_value']['id'] = 'field_states_value';
  $handler->display->display_options['filters']['field_states_value']['table'] = 'field_data_field_states';
  $handler->display->display_options['filters']['field_states_value']['field'] = 'field_states_value';
  $handler->display->display_options['filters']['field_states_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_states_value']['expose']['operator_id'] = 'field_states_value_op';
  $handler->display->display_options['filters']['field_states_value']['expose']['label'] = 'States';
  $handler->display->display_options['filters']['field_states_value']['expose']['operator'] = 'field_states_value_op';
  $handler->display->display_options['filters']['field_states_value']['expose']['identifier'] = 'field_states_value';
  $handler->display->display_options['filters']['field_states_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_states_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    5 => 0,
  );
  /* Filter criterion: Field: Company (field_company) */
  $handler->display->display_options['filters']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['filters']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_company_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_company_target_id']['expose']['operator_id'] = 'field_company_target_id_op';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['label'] = 'Company';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['operator'] = 'field_company_target_id_op';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['identifier'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    5 => 0,
  );
  /* Filter criterion: Commerce Coupon: Program (field_commerce_couponprodref) */
  $handler->display->display_options['filters']['field_commerce_couponprodref_target_id']['id'] = 'field_commerce_couponprodref_target_id';
  $handler->display->display_options['filters']['field_commerce_couponprodref_target_id']['table'] = 'field_data_field_commerce_couponprodref';
  $handler->display->display_options['filters']['field_commerce_couponprodref_target_id']['field'] = 'field_commerce_couponprodref_target_id';
  $handler->display->display_options['filters']['field_commerce_couponprodref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_commerce_couponprodref_target_id']['expose']['operator_id'] = 'field_commerce_couponprodref_target_id_op';
  $handler->display->display_options['filters']['field_commerce_couponprodref_target_id']['expose']['label'] = 'Program';
  $handler->display->display_options['filters']['field_commerce_couponprodref_target_id']['expose']['operator'] = 'field_commerce_couponprodref_target_id_op';
  $handler->display->display_options['filters']['field_commerce_couponprodref_target_id']['expose']['identifier'] = 'field_commerce_couponprodref_target_id';
  $handler->display->display_options['filters']['field_commerce_couponprodref_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    5 => 0,
  );

  /* Display: Admin page */
  $handler = $view->new_display('page', 'Admin page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Promotional Codes List';
  $handler->display->display_options['display_description'] = 'Manage the coupons.';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Coupon: Coupon Code */
  $handler->display->display_options['fields']['commerce_coupon_code']['id'] = 'commerce_coupon_code';
  $handler->display->display_options['fields']['commerce_coupon_code']['table'] = 'field_data_commerce_coupon_code';
  $handler->display->display_options['fields']['commerce_coupon_code']['field'] = 'commerce_coupon_code';
  /* Field: Commerce Coupon: Fixed Amount */
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['id'] = 'commerce_coupon_fixed_amount';
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['table'] = 'field_data_commerce_coupon_fixed_amount';
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['field'] = 'commerce_coupon_fixed_amount';
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['label'] = 'Amount';
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['element_type'] = '0';
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['settings'] = array(
    'calculation' => FALSE,
  );
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['field_api_classes'] = TRUE;
  /* Field: Commerce Coupon: Percentage Amount */
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['id'] = 'commerce_coupon_percent_amount';
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['table'] = 'field_data_commerce_coupon_percent_amount';
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['field'] = 'commerce_coupon_percent_amount';
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['label'] = 'Percentage';
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['element_type'] = '0';
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['field_api_classes'] = TRUE;
  /* Field: Commerce Coupon: Expiration Date */
  $handler->display->display_options['fields']['field_expiration_date_1']['id'] = 'field_expiration_date_1';
  $handler->display->display_options['fields']['field_expiration_date_1']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date_1']['field'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date_1']['label'] = 'Start Date / End Date';
  $handler->display->display_options['fields']['field_expiration_date_1']['settings'] = array(
    'format_type' => 'api_mm_dd_yyyy',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Commerce Coupon: Is active */
  $handler->display->display_options['fields']['is_active']['id'] = 'is_active';
  $handler->display->display_options['fields']['is_active']['table'] = 'commerce_coupon';
  $handler->display->display_options['fields']['is_active']['field'] = 'is_active';
  $handler->display->display_options['fields']['is_active']['label'] = 'Enable/Disable';
  $handler->display->display_options['fields']['is_active']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['is_active']['not'] = 0;
  /* Field: Commerce Coupon: Program */
  $handler->display->display_options['fields']['field_commerce_couponprodref']['id'] = 'field_commerce_couponprodref';
  $handler->display->display_options['fields']['field_commerce_couponprodref']['table'] = 'field_data_field_commerce_couponprodref';
  $handler->display->display_options['fields']['field_commerce_couponprodref']['field'] = 'field_commerce_couponprodref';
  $handler->display->display_options['fields']['field_commerce_couponprodref']['label'] = 'Programs';
  $handler->display->display_options['fields']['field_commerce_couponprodref']['element_type'] = '0';
  $handler->display->display_options['fields']['field_commerce_couponprodref']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_commerce_couponprodref']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_commerce_couponprodref']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_commerce_couponprodref']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_commerce_couponprodref']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_commerce_couponprodref']['field_api_classes'] = TRUE;
  /* Field: Commerce Coupon: Operations */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'commerce_coupon';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  $handler->display->display_options['fields']['operations']['add_destination'] = 1;
  $handler->display->display_options['path'] = 'admin/commerce/coupons/list';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Promotional Codes List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Coupons';
  $handler->display->display_options['tab_options']['description'] = 'Manage coupons in the store.';
  $handler->display->display_options['tab_options']['weight'] = '';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Promotional Codes';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'xls';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Coupon: Coupon Code */
  $handler->display->display_options['fields']['commerce_coupon_code']['id'] = 'commerce_coupon_code';
  $handler->display->display_options['fields']['commerce_coupon_code']['table'] = 'field_data_commerce_coupon_code';
  $handler->display->display_options['fields']['commerce_coupon_code']['field'] = 'commerce_coupon_code';
  /* Field: Commerce Coupon: Fixed Amount */
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['id'] = 'commerce_coupon_fixed_amount';
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['table'] = 'field_data_commerce_coupon_fixed_amount';
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['field'] = 'commerce_coupon_fixed_amount';
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['label'] = 'Amount';
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['element_type'] = '0';
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['settings'] = array(
    'calculation' => FALSE,
  );
  $handler->display->display_options['fields']['commerce_coupon_fixed_amount']['field_api_classes'] = TRUE;
  /* Field: Commerce Coupon: Percentage Amount */
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['id'] = 'commerce_coupon_percent_amount';
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['table'] = 'field_data_commerce_coupon_percent_amount';
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['field'] = 'commerce_coupon_percent_amount';
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['label'] = 'Percentage';
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['element_type'] = '0';
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['commerce_coupon_percent_amount']['field_api_classes'] = TRUE;
  /* Field: Commerce Coupon: Expiration Date */
  $handler->display->display_options['fields']['field_expiration_date_1']['id'] = 'field_expiration_date_1';
  $handler->display->display_options['fields']['field_expiration_date_1']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date_1']['field'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date_1']['label'] = 'Start Date / End Date';
  $handler->display->display_options['fields']['field_expiration_date_1']['settings'] = array(
    'format_type' => 'api_mm_dd_yyyy',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Commerce Coupon: Is active */
  $handler->display->display_options['fields']['is_active']['id'] = 'is_active';
  $handler->display->display_options['fields']['is_active']['table'] = 'commerce_coupon';
  $handler->display->display_options['fields']['is_active']['field'] = 'is_active';
  $handler->display->display_options['fields']['is_active']['label'] = 'Enable/Disable';
  $handler->display->display_options['fields']['is_active']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['is_active']['not'] = 0;
  /* Field: Commerce Coupon: Program */
  $handler->display->display_options['fields']['field_commerce_couponprodref']['id'] = 'field_commerce_couponprodref';
  $handler->display->display_options['fields']['field_commerce_couponprodref']['table'] = 'field_data_field_commerce_couponprodref';
  $handler->display->display_options['fields']['field_commerce_couponprodref']['field'] = 'field_commerce_couponprodref';
  $handler->display->display_options['fields']['field_commerce_couponprodref']['label'] = 'Programs';
  $handler->display->display_options['fields']['field_commerce_couponprodref']['element_type'] = '0';
  $handler->display->display_options['fields']['field_commerce_couponprodref']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_commerce_couponprodref']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_commerce_couponprodref']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_commerce_couponprodref']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_commerce_couponprodref']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_commerce_couponprodref']['field_api_classes'] = TRUE;
  /* Field: Commerce Coupon: Operations */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'commerce_coupon';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  $handler->display->display_options['fields']['operations']['add_destination'] = 1;
  $handler->display->display_options['path'] = 'export/couponslist';
  $handler->display->display_options['sitename_title'] = 0;
  $translatables['api_coupons'] = array(
    t('Defaults'),
    t('Coupons'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Commerce Coupon Type'),
    t('Content entity referenced from field_commerce_couponprodref'),
    t('Coupon Code'),
    t('Amount'),
    t('Percentage'),
    t('Start Date / End Date'),
    t('Enable/Disable'),
    t('Programs'),
    t('Operations'),
    t('States'),
    t('Company'),
    t('Program'),
    t('Admin page'),
    t('Promotional Codes List'),
    t('Manage the coupons.'),
    t('Feed'),
    t('Promotional Codes'),
  );
  $export['api_coupons'] = $view;

  $view = new view();
  $view->name = 'programs_entity_reference';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Programs Entity Reference';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Programs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product_display' => 'product_display',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'status' => 'status',
    'title' => 0,
    'changed' => 0,
    'edit_node' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['not'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $translatables['programs_entity_reference'] = array(
    t('Master'),
    t('Programs'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Title'),
    t('Published'),
    t('Updated date'),
    t('Nid'),
    t('Entity Reference'),
  );
  $export['programs_entity_reference'] = $view;

  return $export;
}
