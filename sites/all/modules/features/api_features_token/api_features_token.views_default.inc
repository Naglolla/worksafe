<?php
/**
 * @file
 * api_features_token.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function api_features_token_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'company_admin_tokens_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_token_entity';
  $view->human_name = 'Company Admin Tokens List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Tokens Lists';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '';
  $handler->display->display_options['pager']['options']['tags']['next'] = '';
  $handler->display->display_options['pager']['options']['tags']['last'] = '';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_token_entity_id' => 'field_token_entity_id',
    'field_token_entity_money_charged' => 'field_token_entity_money_charged',
    'field_token_entity_states' => 'field_token_entity_states',
    'field_token_entity_programs' => 'field_token_entity_programs',
    'field_token_entity_date_from_to' => 'field_token_entity_date_from_to',
    'field_token_entity_date_from_to_1' => 'field_token_entity_date_from_to_1',
    'field_token_entity_enabled' => 'field_token_entity_enabled',
    'field_entity_token_fixed_percent' => 'field_entity_token_fixed_percent',
    'field_entity_tokendiscount_value' => 'field_entity_token_fixed_percent',
    'nothing_1' => 'nothing_1',
    'name' => 'name',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_token_entity_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_token_entity_money_charged' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_token_entity_states' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_token_entity_programs' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_token_entity_date_from_to' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_token_entity_date_from_to_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_token_entity_enabled' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_entity_token_fixed_percent' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_entity_tokendiscount_value' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Token entity: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'eck_token_entity';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Token entity: Token ID */
  $handler->display->display_options['fields']['field_token_entity_id']['id'] = 'field_token_entity_id';
  $handler->display->display_options['fields']['field_token_entity_id']['table'] = 'field_data_field_token_entity_id';
  $handler->display->display_options['fields']['field_token_entity_id']['field'] = 'field_token_entity_id';
  $handler->display->display_options['fields']['field_token_entity_id']['element_label_colon'] = FALSE;
  /* Field: Token entity: Token Amount */
  $handler->display->display_options['fields']['field_token_entity_money_charged']['id'] = 'field_token_entity_money_charged';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['table'] = 'field_data_field_token_entity_money_charged';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['field'] = 'field_token_entity_money_charged';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['label'] = 'Balance';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_token_entity_money_charged']['alter']['text'] = '$[field_token_entity_money_charged]';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_money_charged']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_money_charged']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  /* Field: Token entity: U.S. States */
  $handler->display->display_options['fields']['field_token_entity_states']['id'] = 'field_token_entity_states';
  $handler->display->display_options['fields']['field_token_entity_states']['table'] = 'field_data_field_token_entity_states';
  $handler->display->display_options['fields']['field_token_entity_states']['field'] = 'field_token_entity_states';
  $handler->display->display_options['fields']['field_token_entity_states']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_states']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_states']['empty'] = 'N/A';
  $handler->display->display_options['fields']['field_token_entity_states']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_token_entity_states']['multi_type'] = 'ul';
  /* Field: Token entity: Program */
  $handler->display->display_options['fields']['field_token_entity_programs']['id'] = 'field_token_entity_programs';
  $handler->display->display_options['fields']['field_token_entity_programs']['table'] = 'field_data_field_token_entity_programs';
  $handler->display->display_options['fields']['field_token_entity_programs']['field'] = 'field_token_entity_programs';
  $handler->display->display_options['fields']['field_token_entity_programs']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_programs']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_programs']['empty'] = 'N/A';
  $handler->display->display_options['fields']['field_token_entity_programs']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_token_entity_programs']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_token_entity_programs']['multi_type'] = 'ul';
  /* Field: Token entity: Start Date / End Date */
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['id'] = 'field_token_entity_date_from_to';
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['table'] = 'field_data_field_token_entity_date_from_to';
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['field'] = 'field_token_entity_date_from_to';
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['label'] = 'Date From';
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['empty'] = 'N/A';
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['field_api_classes'] = TRUE;
  /* Field: Token entity: Start Date / End Date */
  $handler->display->display_options['fields']['field_token_entity_date_from_to_1']['id'] = 'field_token_entity_date_from_to_1';
  $handler->display->display_options['fields']['field_token_entity_date_from_to_1']['table'] = 'field_data_field_token_entity_date_from_to';
  $handler->display->display_options['fields']['field_token_entity_date_from_to_1']['field'] = 'field_token_entity_date_from_to';
  $handler->display->display_options['fields']['field_token_entity_date_from_to_1']['label'] = 'Date to';
  $handler->display->display_options['fields']['field_token_entity_date_from_to_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_date_from_to_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_date_from_to_1']['empty'] = 'N/A';
  $handler->display->display_options['fields']['field_token_entity_date_from_to_1']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Token entity: Enabled */
  $handler->display->display_options['fields']['field_token_entity_enabled']['id'] = 'field_token_entity_enabled';
  $handler->display->display_options['fields']['field_token_entity_enabled']['table'] = 'field_data_field_token_entity_enabled';
  $handler->display->display_options['fields']['field_token_entity_enabled']['field'] = 'field_token_entity_enabled';
  $handler->display->display_options['fields']['field_token_entity_enabled']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_enabled']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_enabled']['type'] = 'list_key';
  /* Field: Token entity: Discount Type */
  $handler->display->display_options['fields']['field_entity_token_fixed_percent']['id'] = 'field_entity_token_fixed_percent';
  $handler->display->display_options['fields']['field_entity_token_fixed_percent']['table'] = 'field_data_field_entity_token_fixed_percent';
  $handler->display->display_options['fields']['field_entity_token_fixed_percent']['field'] = 'field_entity_token_fixed_percent';
  $handler->display->display_options['fields']['field_entity_token_fixed_percent']['label'] = '';
  $handler->display->display_options['fields']['field_entity_token_fixed_percent']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_entity_token_fixed_percent']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_entity_token_fixed_percent']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_entity_token_fixed_percent']['type'] = 'list_key';
  /* Field: Token entity: Discount Value */
  $handler->display->display_options['fields']['field_entity_tokendiscount_value']['id'] = 'field_entity_tokendiscount_value';
  $handler->display->display_options['fields']['field_entity_tokendiscount_value']['table'] = 'field_data_field_entity_tokendiscount_value';
  $handler->display->display_options['fields']['field_entity_tokendiscount_value']['field'] = 'field_entity_tokendiscount_value';
  $handler->display->display_options['fields']['field_entity_tokendiscount_value']['label'] = '';
  $handler->display->display_options['fields']['field_entity_tokendiscount_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_entity_tokendiscount_value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_entity_tokendiscount_value']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_entity_tokendiscount_value']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Discount';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Created by';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Options';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Token entity: Company */
  $handler->display->display_options['fields']['field_token_entity_companies']['id'] = 'field_token_entity_companies';
  $handler->display->display_options['fields']['field_token_entity_companies']['table'] = 'field_data_field_token_entity_companies';
  $handler->display->display_options['fields']['field_token_entity_companies']['field'] = 'field_token_entity_companies';
  $handler->display->display_options['fields']['field_token_entity_companies']['label'] = '';
  $handler->display->display_options['fields']['field_token_entity_companies']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_token_entity_companies']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_companies']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_companies']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_token_entity_companies']['settings'] = array(
    'view_mode' => 'default',
    'links' => 0,
  );
  $handler->display->display_options['fields']['field_token_entity_companies']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_token_entity_companies']['multi_type'] = 'ul';
  /* Field: Token entity: Visibility */
  $handler->display->display_options['fields']['field_token_entity_visibility']['id'] = 'field_token_entity_visibility';
  $handler->display->display_options['fields']['field_token_entity_visibility']['table'] = 'field_data_field_token_entity_visibility';
  $handler->display->display_options['fields']['field_token_entity_visibility']['field'] = 'field_token_entity_visibility';
  $handler->display->display_options['fields']['field_token_entity_visibility']['label'] = '';
  $handler->display->display_options['fields']['field_token_entity_visibility']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_token_entity_visibility']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_visibility']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_visibility']['type'] = 'list_key';
  /* Sort criterion: Token entity: Token ID (field_token_entity_id) */
  $handler->display->display_options['sorts']['field_token_entity_id_value']['id'] = 'field_token_entity_id_value';
  $handler->display->display_options['sorts']['field_token_entity_id_value']['table'] = 'field_data_field_token_entity_id';
  $handler->display->display_options['sorts']['field_token_entity_id_value']['field'] = 'field_token_entity_id_value';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Token entity: token_entity type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_token_entity';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'token_entity_bundle' => 'token_entity_bundle',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Token entity: Company (field_token_entity_companies) */
  $handler->display->display_options['filters']['field_token_entity_companies_target_id']['id'] = 'field_token_entity_companies_target_id';
  $handler->display->display_options['filters']['field_token_entity_companies_target_id']['table'] = 'field_data_field_token_entity_companies';
  $handler->display->display_options['filters']['field_token_entity_companies_target_id']['field'] = 'field_token_entity_companies_target_id';
  $handler->display->display_options['filters']['field_token_entity_companies_target_id']['group'] = 2;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_tokens_list');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No available information.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Token entity: token_entity type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_token_entity';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'token_entity_bundle' => 'token_entity_bundle',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Token entity: Company (field_token_entity_companies) */
  $handler->display->display_options['filters']['field_token_entity_companies_target_id']['id'] = 'field_token_entity_companies_target_id';
  $handler->display->display_options['filters']['field_token_entity_companies_target_id']['table'] = 'field_data_field_token_entity_companies';
  $handler->display->display_options['filters']['field_token_entity_companies_target_id']['field'] = 'field_token_entity_companies_target_id';
  $handler->display->display_options['filters']['field_token_entity_companies_target_id']['group'] = 2;
  /* Filter criterion: Token entity: Token ID (field_token_entity_id) */
  $handler->display->display_options['filters']['field_token_entity_id_value']['id'] = 'field_token_entity_id_value';
  $handler->display->display_options['filters']['field_token_entity_id_value']['table'] = 'field_data_field_token_entity_id';
  $handler->display->display_options['filters']['field_token_entity_id_value']['field'] = 'field_token_entity_id_value';
  $handler->display->display_options['filters']['field_token_entity_id_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_token_entity_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_token_entity_id_value']['expose']['operator_id'] = 'field_token_entity_id_value_op';
  $handler->display->display_options['filters']['field_token_entity_id_value']['expose']['label'] = 'Token ID';
  $handler->display->display_options['filters']['field_token_entity_id_value']['expose']['operator'] = 'field_token_entity_id_value_op';
  $handler->display->display_options['filters']['field_token_entity_id_value']['expose']['identifier'] = 'field_token_entity_id_value';
  $handler->display->display_options['filters']['field_token_entity_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $translatables['company_admin_tokens_list'] = array(
    t('Master'),
    t('Tokens Lists'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('User'),
    t('Token ID'),
    t('Balance'),
    t('$[field_token_entity_money_charged]'),
    t('U.S. States'),
    t('N/A'),
    t('Program'),
    t('Date From'),
    t('Date to'),
    t('Enabled'),
    t('Discount'),
    t('Created by'),
    t('Options'),
    t('Block'),
    t('Search'),
    t('No available information.'),
  );
  $export['company_admin_tokens_list'] = $view;

  $view = new view();
  $view->name = 'token_management';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_token_entity';
  $view->human_name = 'Token Management';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = ' Modify Token';
  $handler->display->display_options['css_class'] = 'button primary export-csv-button';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view the administration theme';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'field_token_entity_id' => 'field_token_entity_id',
    'field_token_entity_companies' => 'field_token_entity_companies',
    'field_token_total_value' => 'field_token_total_value',
    'field_token_entity_money_charged' => 'field_token_entity_money_charged',
    'created' => 'created',
    'name' => 'name',
    'nothing' => 'nothing',
    'nothing_1' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_token_entity_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_token_entity_companies' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_token_total_value' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_token_entity_money_charged' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => ' - ',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Token entity: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'eck_token_entity';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Token entity: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_token_entity';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Token entity: Token ID */
  $handler->display->display_options['fields']['field_token_entity_id']['id'] = 'field_token_entity_id';
  $handler->display->display_options['fields']['field_token_entity_id']['table'] = 'field_data_field_token_entity_id';
  $handler->display->display_options['fields']['field_token_entity_id']['field'] = 'field_token_entity_id';
  $handler->display->display_options['fields']['field_token_entity_id']['label'] = 'Token';
  $handler->display->display_options['fields']['field_token_entity_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_token_entity_id']['alter']['path'] = 'token/[id]/view';
  $handler->display->display_options['fields']['field_token_entity_id']['element_type'] = '0';
  $handler->display->display_options['fields']['field_token_entity_id']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_token_entity_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_id']['field_api_classes'] = TRUE;
  /* Field: Token entity: Company */
  $handler->display->display_options['fields']['field_token_entity_companies']['id'] = 'field_token_entity_companies';
  $handler->display->display_options['fields']['field_token_entity_companies']['table'] = 'field_data_field_token_entity_companies';
  $handler->display->display_options['fields']['field_token_entity_companies']['field'] = 'field_token_entity_companies';
  $handler->display->display_options['fields']['field_token_entity_companies']['element_type'] = '0';
  $handler->display->display_options['fields']['field_token_entity_companies']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_token_entity_companies']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_companies']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_token_entity_companies']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_token_entity_companies']['field_api_classes'] = TRUE;
  /* Field: Token entity: Total Value */
  $handler->display->display_options['fields']['field_token_total_value']['id'] = 'field_token_total_value';
  $handler->display->display_options['fields']['field_token_total_value']['table'] = 'field_data_field_token_total_value';
  $handler->display->display_options['fields']['field_token_total_value']['field'] = 'field_token_total_value';
  $handler->display->display_options['fields']['field_token_total_value']['empty'] = 'N/A';
  $handler->display->display_options['fields']['field_token_total_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Token entity: Token Amount */
  $handler->display->display_options['fields']['field_token_entity_money_charged']['id'] = 'field_token_entity_money_charged';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['table'] = 'field_data_field_token_entity_money_charged';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['field'] = 'field_token_entity_money_charged';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['label'] = 'Balance';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_money_charged']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_token_entity_money_charged']['field_api_classes'] = TRUE;
  /* Field: Token entity: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_token_entity';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd-M-y H:m';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Customer';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'admin/structure/entity-type/token_entity/token_entity_bundle/[id]/edit';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Remove';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Remove';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'token/[id]/remove';
  /* Filter criterion: Token entity: token_entity type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_token_entity';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'token_entity_bundle' => 'token_entity_bundle',
  );
  /* Filter criterion: Token entity: Token ID (field_token_entity_id) */
  $handler->display->display_options['filters']['field_token_entity_id_value']['id'] = 'field_token_entity_id_value';
  $handler->display->display_options['filters']['field_token_entity_id_value']['table'] = 'field_data_field_token_entity_id';
  $handler->display->display_options['filters']['field_token_entity_id_value']['field'] = 'field_token_entity_id_value';
  $handler->display->display_options['filters']['field_token_entity_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_token_entity_id_value']['expose']['operator_id'] = 'field_token_entity_id_value_op';
  $handler->display->display_options['filters']['field_token_entity_id_value']['expose']['label'] = 'Token ID';
  $handler->display->display_options['filters']['field_token_entity_id_value']['expose']['operator'] = 'field_token_entity_id_value_op';
  $handler->display->display_options['filters']['field_token_entity_id_value']['expose']['identifier'] = 'field_token_entity_id_value';
  $handler->display->display_options['filters']['field_token_entity_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: Token entity: Company (field_token_entity_companies) */
  $handler->display->display_options['filters']['field_token_entity_companies_target_id']['id'] = 'field_token_entity_companies_target_id';
  $handler->display->display_options['filters']['field_token_entity_companies_target_id']['table'] = 'field_data_field_token_entity_companies';
  $handler->display->display_options['filters']['field_token_entity_companies_target_id']['field'] = 'field_token_entity_companies_target_id';
  $handler->display->display_options['filters']['field_token_entity_companies_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_token_entity_companies_target_id']['expose']['operator_id'] = 'field_token_entity_companies_target_id_op';
  $handler->display->display_options['filters']['field_token_entity_companies_target_id']['expose']['label'] = 'Company';
  $handler->display->display_options['filters']['field_token_entity_companies_target_id']['expose']['operator'] = 'field_token_entity_companies_target_id_op';
  $handler->display->display_options['filters']['field_token_entity_companies_target_id']['expose']['identifier'] = 'field_token_entity_companies_target_id';
  $handler->display->display_options['filters']['field_token_entity_companies_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Token entity: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_token_entity';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Token entity: Token ID */
  $handler->display->display_options['fields']['field_token_entity_id']['id'] = 'field_token_entity_id';
  $handler->display->display_options['fields']['field_token_entity_id']['table'] = 'field_data_field_token_entity_id';
  $handler->display->display_options['fields']['field_token_entity_id']['field'] = 'field_token_entity_id';
  $handler->display->display_options['fields']['field_token_entity_id']['label'] = 'Token';
  $handler->display->display_options['fields']['field_token_entity_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_token_entity_id']['alter']['path'] = 'token/[id]/view';
  $handler->display->display_options['fields']['field_token_entity_id']['element_type'] = '0';
  $handler->display->display_options['fields']['field_token_entity_id']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_token_entity_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_id']['field_api_classes'] = TRUE;
  /* Field: Token entity: Company */
  $handler->display->display_options['fields']['field_token_entity_companies']['id'] = 'field_token_entity_companies';
  $handler->display->display_options['fields']['field_token_entity_companies']['table'] = 'field_data_field_token_entity_companies';
  $handler->display->display_options['fields']['field_token_entity_companies']['field'] = 'field_token_entity_companies';
  $handler->display->display_options['fields']['field_token_entity_companies']['element_type'] = '0';
  $handler->display->display_options['fields']['field_token_entity_companies']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_token_entity_companies']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_companies']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_token_entity_companies']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_token_entity_companies']['field_api_classes'] = TRUE;
  /* Field: Token entity: Total Value */
  $handler->display->display_options['fields']['field_token_total_value']['id'] = 'field_token_total_value';
  $handler->display->display_options['fields']['field_token_total_value']['table'] = 'field_data_field_token_total_value';
  $handler->display->display_options['fields']['field_token_total_value']['field'] = 'field_token_total_value';
  $handler->display->display_options['fields']['field_token_total_value']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_token_total_value']['alter']['text'] = '$[field_token_total_value]';
  $handler->display->display_options['fields']['field_token_total_value']['empty'] = 'N/A';
  $handler->display->display_options['fields']['field_token_total_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Token entity: Token Amount */
  $handler->display->display_options['fields']['field_token_entity_money_charged']['id'] = 'field_token_entity_money_charged';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['table'] = 'field_data_field_token_entity_money_charged';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['field'] = 'field_token_entity_money_charged';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['label'] = 'Balance';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_money_charged']['empty'] = '0.00';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_token_entity_money_charged']['field_api_classes'] = TRUE;
  /* Field: Token entity: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_token_entity';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'api_mm_dd_yyyy';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd-M-y H:m';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Customer';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'admin/structure/entity-type/token_entity/token_entity_bundle/[id]/edit';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Remove';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Remove';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'token/[id]/remove';
  $handler->display->display_options['path'] = 'token/modify';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['attach_text'] = 'Export';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'tokens-%timestamp-full.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Token entity: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_token_entity';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Token entity: Token ID */
  $handler->display->display_options['fields']['field_token_entity_id']['id'] = 'field_token_entity_id';
  $handler->display->display_options['fields']['field_token_entity_id']['table'] = 'field_data_field_token_entity_id';
  $handler->display->display_options['fields']['field_token_entity_id']['field'] = 'field_token_entity_id';
  $handler->display->display_options['fields']['field_token_entity_id']['label'] = 'Token';
  $handler->display->display_options['fields']['field_token_entity_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_token_entity_id']['alter']['path'] = 'token/[id]/view';
  $handler->display->display_options['fields']['field_token_entity_id']['element_type'] = '0';
  $handler->display->display_options['fields']['field_token_entity_id']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_token_entity_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_id']['field_api_classes'] = TRUE;
  /* Field: Token entity: Company */
  $handler->display->display_options['fields']['field_token_entity_companies']['id'] = 'field_token_entity_companies';
  $handler->display->display_options['fields']['field_token_entity_companies']['table'] = 'field_data_field_token_entity_companies';
  $handler->display->display_options['fields']['field_token_entity_companies']['field'] = 'field_token_entity_companies';
  $handler->display->display_options['fields']['field_token_entity_companies']['element_type'] = '0';
  $handler->display->display_options['fields']['field_token_entity_companies']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_token_entity_companies']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_companies']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_token_entity_companies']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_token_entity_companies']['field_api_classes'] = TRUE;
  /* Field: Token entity: Total Value */
  $handler->display->display_options['fields']['field_token_total_value']['id'] = 'field_token_total_value';
  $handler->display->display_options['fields']['field_token_total_value']['table'] = 'field_data_field_token_total_value';
  $handler->display->display_options['fields']['field_token_total_value']['field'] = 'field_token_total_value';
  $handler->display->display_options['fields']['field_token_total_value']['empty'] = 'N/A';
  $handler->display->display_options['fields']['field_token_total_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Token entity: Token Amount */
  $handler->display->display_options['fields']['field_token_entity_money_charged']['id'] = 'field_token_entity_money_charged';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['table'] = 'field_data_field_token_entity_money_charged';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['field'] = 'field_token_entity_money_charged';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['label'] = 'Balance';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_money_charged']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_token_entity_money_charged']['field_api_classes'] = TRUE;
  /* Field: Token entity: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_token_entity';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'api_mm_dd_yyyy';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd-M-y H:m';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Customer';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  $handler->display->display_options['path'] = 'token/modify/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $translatables['token_management'] = array(
    t('Master'),
    t(' Modify Token'),
    t('more'),
    t('Search'),
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
    t('User'),
    t('Id'),
    t('.'),
    t(','),
    t('Token'),
    t('Company'),
    t('Total Value'),
    t('N/A'),
    t('Balance'),
    t('Created'),
    t('Customer'),
    t('Operations'),
    t('Edit'),
    t('Remove'),
    t('Token ID'),
    t('Page'),
    t('$[field_token_total_value]'),
    t('0.00'),
    t('Data export'),
  );
  $export['token_management'] = $view;

  $view = new view();
  $view->name = 'tokens_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_token_entity';
  $view->human_name = 'Tokens List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Tokens Lists';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '';
  $handler->display->display_options['pager']['options']['tags']['next'] = '';
  $handler->display->display_options['pager']['options']['tags']['last'] = '';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_token_entity_id' => 'field_token_entity_id',
    'field_token_entity_money_charged' => 'field_token_entity_money_charged',
    'field_token_entity_states' => 'field_token_entity_states',
    'field_token_entity_programs' => 'field_token_entity_programs',
    'field_token_entity_date_from_to' => 'field_token_entity_date_from_to',
    'field_token_entity_date_from_to_1' => 'field_token_entity_date_from_to_1',
    'field_token_entity_enabled' => 'field_token_entity_enabled',
    'field_entity_token_fixed_percent' => 'field_entity_token_fixed_percent',
    'field_entity_tokendiscount_value' => 'field_entity_token_fixed_percent',
    'nothing_1' => 'nothing_1',
    'name' => 'name',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_token_entity_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_token_entity_money_charged' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_token_entity_states' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_token_entity_programs' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_token_entity_date_from_to' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_token_entity_date_from_to_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_token_entity_enabled' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_entity_token_fixed_percent' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_entity_tokendiscount_value' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Token entity: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'eck_token_entity';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Token entity: Token ID */
  $handler->display->display_options['fields']['field_token_entity_id']['id'] = 'field_token_entity_id';
  $handler->display->display_options['fields']['field_token_entity_id']['table'] = 'field_data_field_token_entity_id';
  $handler->display->display_options['fields']['field_token_entity_id']['field'] = 'field_token_entity_id';
  $handler->display->display_options['fields']['field_token_entity_id']['element_label_colon'] = FALSE;
  /* Field: Token entity: Token Amount */
  $handler->display->display_options['fields']['field_token_entity_money_charged']['id'] = 'field_token_entity_money_charged';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['table'] = 'field_data_field_token_entity_money_charged';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['field'] = 'field_token_entity_money_charged';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['label'] = 'Balance';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_token_entity_money_charged']['alter']['text'] = '$[field_token_entity_money_charged]';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_money_charged']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_money_charged']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Token entity: U.S. States */
  $handler->display->display_options['fields']['field_token_entity_states']['id'] = 'field_token_entity_states';
  $handler->display->display_options['fields']['field_token_entity_states']['table'] = 'field_data_field_token_entity_states';
  $handler->display->display_options['fields']['field_token_entity_states']['field'] = 'field_token_entity_states';
  $handler->display->display_options['fields']['field_token_entity_states']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_states']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_states']['empty'] = 'N/A';
  $handler->display->display_options['fields']['field_token_entity_states']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_token_entity_states']['multi_type'] = 'ul';
  /* Field: Token entity: Program */
  $handler->display->display_options['fields']['field_token_entity_programs']['id'] = 'field_token_entity_programs';
  $handler->display->display_options['fields']['field_token_entity_programs']['table'] = 'field_data_field_token_entity_programs';
  $handler->display->display_options['fields']['field_token_entity_programs']['field'] = 'field_token_entity_programs';
  $handler->display->display_options['fields']['field_token_entity_programs']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_programs']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_programs']['empty'] = 'N/A';
  $handler->display->display_options['fields']['field_token_entity_programs']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_token_entity_programs']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_token_entity_programs']['multi_type'] = 'ul';
  /* Field: Token entity: Start Date / End Date */
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['id'] = 'field_token_entity_date_from_to';
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['table'] = 'field_data_field_token_entity_date_from_to';
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['field'] = 'field_token_entity_date_from_to';
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['label'] = 'Date From';
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['empty'] = 'N/A';
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['field_api_classes'] = TRUE;
  /* Field: Token entity: Start Date / End Date */
  $handler->display->display_options['fields']['field_token_entity_date_from_to_1']['id'] = 'field_token_entity_date_from_to_1';
  $handler->display->display_options['fields']['field_token_entity_date_from_to_1']['table'] = 'field_data_field_token_entity_date_from_to';
  $handler->display->display_options['fields']['field_token_entity_date_from_to_1']['field'] = 'field_token_entity_date_from_to';
  $handler->display->display_options['fields']['field_token_entity_date_from_to_1']['label'] = 'Date to';
  $handler->display->display_options['fields']['field_token_entity_date_from_to_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_date_from_to_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_date_from_to_1']['empty'] = 'N/A';
  $handler->display->display_options['fields']['field_token_entity_date_from_to_1']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Token entity: Enabled */
  $handler->display->display_options['fields']['field_token_entity_enabled']['id'] = 'field_token_entity_enabled';
  $handler->display->display_options['fields']['field_token_entity_enabled']['table'] = 'field_data_field_token_entity_enabled';
  $handler->display->display_options['fields']['field_token_entity_enabled']['field'] = 'field_token_entity_enabled';
  $handler->display->display_options['fields']['field_token_entity_enabled']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_enabled']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_enabled']['type'] = 'list_key';
  /* Field: Token entity: Discount Type */
  $handler->display->display_options['fields']['field_entity_token_fixed_percent']['id'] = 'field_entity_token_fixed_percent';
  $handler->display->display_options['fields']['field_entity_token_fixed_percent']['table'] = 'field_data_field_entity_token_fixed_percent';
  $handler->display->display_options['fields']['field_entity_token_fixed_percent']['field'] = 'field_entity_token_fixed_percent';
  $handler->display->display_options['fields']['field_entity_token_fixed_percent']['label'] = '';
  $handler->display->display_options['fields']['field_entity_token_fixed_percent']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_entity_token_fixed_percent']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_entity_token_fixed_percent']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_entity_token_fixed_percent']['type'] = 'list_key';
  /* Field: Token entity: Discount Value */
  $handler->display->display_options['fields']['field_entity_tokendiscount_value']['id'] = 'field_entity_tokendiscount_value';
  $handler->display->display_options['fields']['field_entity_tokendiscount_value']['table'] = 'field_data_field_entity_tokendiscount_value';
  $handler->display->display_options['fields']['field_entity_tokendiscount_value']['field'] = 'field_entity_tokendiscount_value';
  $handler->display->display_options['fields']['field_entity_tokendiscount_value']['label'] = '';
  $handler->display->display_options['fields']['field_entity_tokendiscount_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_entity_tokendiscount_value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_entity_tokendiscount_value']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_entity_tokendiscount_value']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Discount';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Created by';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Options';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Token entity: Company */
  $handler->display->display_options['fields']['field_token_entity_companies']['id'] = 'field_token_entity_companies';
  $handler->display->display_options['fields']['field_token_entity_companies']['table'] = 'field_data_field_token_entity_companies';
  $handler->display->display_options['fields']['field_token_entity_companies']['field'] = 'field_token_entity_companies';
  $handler->display->display_options['fields']['field_token_entity_companies']['label'] = '';
  $handler->display->display_options['fields']['field_token_entity_companies']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_token_entity_companies']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_companies']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_companies']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_token_entity_companies']['settings'] = array(
    'view_mode' => 'default',
    'links' => 0,
  );
  $handler->display->display_options['fields']['field_token_entity_companies']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_token_entity_companies']['multi_type'] = 'ul';
  /* Field: Token entity: Visibility */
  $handler->display->display_options['fields']['field_token_entity_visibility']['id'] = 'field_token_entity_visibility';
  $handler->display->display_options['fields']['field_token_entity_visibility']['table'] = 'field_data_field_token_entity_visibility';
  $handler->display->display_options['fields']['field_token_entity_visibility']['field'] = 'field_token_entity_visibility';
  $handler->display->display_options['fields']['field_token_entity_visibility']['label'] = '';
  $handler->display->display_options['fields']['field_token_entity_visibility']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_token_entity_visibility']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_visibility']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_visibility']['type'] = 'list_key';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Token entity: token_entity type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_token_entity';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'token_entity_bundle' => 'token_entity_bundle',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Token entity: Author */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'eck_token_entity';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['group'] = 2;
  /* Filter criterion: Token entity: Company (field_token_entity_companies) */
  $handler->display->display_options['filters']['field_token_entity_companies_target_id']['id'] = 'field_token_entity_companies_target_id';
  $handler->display->display_options['filters']['field_token_entity_companies_target_id']['table'] = 'field_data_field_token_entity_companies';
  $handler->display->display_options['filters']['field_token_entity_companies_target_id']['field'] = 'field_token_entity_companies_target_id';
  $handler->display->display_options['filters']['field_token_entity_companies_target_id']['group'] = 2;
  /* Filter criterion: Token entity: Company (field_token_entity_companies) */
  $handler->display->display_options['filters']['field_token_entity_companies_target_id_1']['id'] = 'field_token_entity_companies_target_id_1';
  $handler->display->display_options['filters']['field_token_entity_companies_target_id_1']['table'] = 'field_data_field_token_entity_companies';
  $handler->display->display_options['filters']['field_token_entity_companies_target_id_1']['field'] = 'field_token_entity_companies_target_id';
  $handler->display->display_options['filters']['field_token_entity_companies_target_id_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_token_entity_companies_target_id_1']['group'] = 2;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_tokens_list');

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['attach_text'] = 'Export to Excel';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Token entity: Token ID */
  $handler->display->display_options['fields']['field_token_entity_id']['id'] = 'field_token_entity_id';
  $handler->display->display_options['fields']['field_token_entity_id']['table'] = 'field_data_field_token_entity_id';
  $handler->display->display_options['fields']['field_token_entity_id']['field'] = 'field_token_entity_id';
  $handler->display->display_options['fields']['field_token_entity_id']['element_label_colon'] = FALSE;
  /* Field: Token entity: Token Amount */
  $handler->display->display_options['fields']['field_token_entity_money_charged']['id'] = 'field_token_entity_money_charged';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['table'] = 'field_data_field_token_entity_money_charged';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['field'] = 'field_token_entity_money_charged';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['label'] = 'Balance';
  $handler->display->display_options['fields']['field_token_entity_money_charged']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_money_charged']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Token entity: U.S. States */
  $handler->display->display_options['fields']['field_token_entity_states']['id'] = 'field_token_entity_states';
  $handler->display->display_options['fields']['field_token_entity_states']['table'] = 'field_data_field_token_entity_states';
  $handler->display->display_options['fields']['field_token_entity_states']['field'] = 'field_token_entity_states';
  $handler->display->display_options['fields']['field_token_entity_states']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_states']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_states']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_token_entity_states']['multi_type'] = 'ul';
  /* Field: Token entity: Program */
  $handler->display->display_options['fields']['field_token_entity_programs']['id'] = 'field_token_entity_programs';
  $handler->display->display_options['fields']['field_token_entity_programs']['table'] = 'field_data_field_token_entity_programs';
  $handler->display->display_options['fields']['field_token_entity_programs']['field'] = 'field_token_entity_programs';
  $handler->display->display_options['fields']['field_token_entity_programs']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_programs']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_programs']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_token_entity_programs']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_token_entity_programs']['multi_type'] = 'ul';
  /* Field: Token entity: Start Date / End Date */
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['id'] = 'field_token_entity_date_from_to';
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['table'] = 'field_data_field_token_entity_date_from_to';
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['field'] = 'field_token_entity_date_from_to';
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['label'] = 'Date From';
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_token_entity_date_from_to']['field_api_classes'] = TRUE;
  /* Field: Token entity: Start Date / End Date */
  $handler->display->display_options['fields']['field_token_entity_date_from_to_1']['id'] = 'field_token_entity_date_from_to_1';
  $handler->display->display_options['fields']['field_token_entity_date_from_to_1']['table'] = 'field_data_field_token_entity_date_from_to';
  $handler->display->display_options['fields']['field_token_entity_date_from_to_1']['field'] = 'field_token_entity_date_from_to';
  $handler->display->display_options['fields']['field_token_entity_date_from_to_1']['label'] = 'Date to';
  $handler->display->display_options['fields']['field_token_entity_date_from_to_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_date_from_to_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_date_from_to_1']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Token entity: Enabled */
  $handler->display->display_options['fields']['field_token_entity_enabled']['id'] = 'field_token_entity_enabled';
  $handler->display->display_options['fields']['field_token_entity_enabled']['table'] = 'field_data_field_token_entity_enabled';
  $handler->display->display_options['fields']['field_token_entity_enabled']['field'] = 'field_token_entity_enabled';
  $handler->display->display_options['fields']['field_token_entity_enabled']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_enabled']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_enabled']['type'] = 'list_key';
  /* Field: Token entity: Discount Type */
  $handler->display->display_options['fields']['field_entity_token_fixed_percent']['id'] = 'field_entity_token_fixed_percent';
  $handler->display->display_options['fields']['field_entity_token_fixed_percent']['table'] = 'field_data_field_entity_token_fixed_percent';
  $handler->display->display_options['fields']['field_entity_token_fixed_percent']['field'] = 'field_entity_token_fixed_percent';
  $handler->display->display_options['fields']['field_entity_token_fixed_percent']['label'] = '';
  $handler->display->display_options['fields']['field_entity_token_fixed_percent']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_entity_token_fixed_percent']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_entity_token_fixed_percent']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_entity_token_fixed_percent']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_entity_token_fixed_percent']['field_api_classes'] = TRUE;
  /* Field: Token entity: Discount Value */
  $handler->display->display_options['fields']['field_entity_tokendiscount_value']['id'] = 'field_entity_tokendiscount_value';
  $handler->display->display_options['fields']['field_entity_tokendiscount_value']['table'] = 'field_data_field_entity_tokendiscount_value';
  $handler->display->display_options['fields']['field_entity_tokendiscount_value']['field'] = 'field_entity_tokendiscount_value';
  $handler->display->display_options['fields']['field_entity_tokendiscount_value']['label'] = '';
  $handler->display->display_options['fields']['field_entity_tokendiscount_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_entity_tokendiscount_value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_entity_tokendiscount_value']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_entity_tokendiscount_value']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Discount';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Created by';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Token entity: Company */
  $handler->display->display_options['fields']['field_token_entity_companies']['id'] = 'field_token_entity_companies';
  $handler->display->display_options['fields']['field_token_entity_companies']['table'] = 'field_data_field_token_entity_companies';
  $handler->display->display_options['fields']['field_token_entity_companies']['field'] = 'field_token_entity_companies';
  $handler->display->display_options['fields']['field_token_entity_companies']['label'] = '';
  $handler->display->display_options['fields']['field_token_entity_companies']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_token_entity_companies']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_companies']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_companies']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_token_entity_companies']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_token_entity_companies']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_token_entity_companies']['multi_type'] = 'ul';
  /* Field: Token entity: Visibility */
  $handler->display->display_options['fields']['field_token_entity_visibility']['id'] = 'field_token_entity_visibility';
  $handler->display->display_options['fields']['field_token_entity_visibility']['table'] = 'field_data_field_token_entity_visibility';
  $handler->display->display_options['fields']['field_token_entity_visibility']['field'] = 'field_token_entity_visibility';
  $handler->display->display_options['fields']['field_token_entity_visibility']['label'] = '';
  $handler->display->display_options['fields']['field_token_entity_visibility']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_token_entity_visibility']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_visibility']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_token_entity_visibility']['type'] = 'list_key';
  $handler->display->display_options['path'] = 'user/%/export-tokens';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'block_tokens_list' => 0,
  );
  $translatables['tokens_list'] = array(
    t('Master'),
    t('Tokens Lists'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('User'),
    t('Token ID'),
    t('Balance'),
    t('$[field_token_entity_money_charged]'),
    t('U.S. States'),
    t('N/A'),
    t('Program'),
    t('Date From'),
    t('Date to'),
    t('Enabled'),
    t('Discount'),
    t('Created by'),
    t('Options'),
    t('Block'),
    t('Data export'),
  );
  $export['tokens_list'] = $view;

  return $export;
}
