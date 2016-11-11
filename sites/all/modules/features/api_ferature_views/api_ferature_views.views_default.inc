<?php
/**
 * @file
 * api_ferature_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function api_ferature_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'admin_programs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Admin Programs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Programs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    7 => '7',
  );
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
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/programs';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Programs';
  $handler->display->display_options['menu']['name'] = 'management';
  $translatables['admin_programs'] = array(
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
    t('Edit'),
    t('Page'),
  );
  $export['admin_programs'] = $view;

  $view = new view();
  $view->name = 'api_commerce_backoffice_user_orders';
  $view->description = 'Cloned view from commerce_backoffice_user_orders adapted to API site needs.';
  $view->tag = 'commerce';
  $view->base_table = 'commerce_order';
  $view->human_name = 'API Commerce Backoffice: User orders';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'My Orders';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view own commerce_order entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '';
  $handler->display->display_options['pager']['options']['tags']['next'] = '';
  $handler->display->display_options['pager']['options']['tags']['last'] = '';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'order_number' => 'order_number',
    'created' => 'created',
    'status' => 'status',
    'commerce_line_items' => 'commerce_line_items',
    'commerce_order_total' => 'commerce_order_total',
    'order_id' => 'order_id',
    'order_id_1' => 'order_id',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'order_number' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_line_items' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_order_total' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'order_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'order_id_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'text';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['content'] = 'You have not placed any orders with us yet.';
  $handler->display->display_options['empty']['text']['format'] = 'plain_text';
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = 'Order';
  $handler->display->display_options['fields']['order_number']['link_to_order'] = 'customer';
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'M j, Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  /* Field: Commerce Order: Line items */
  $handler->display->display_options['fields']['commerce_line_items']['id'] = 'commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items']['field'] = 'commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items']['label'] = 'Order Detail';
  $handler->display->display_options['fields']['commerce_line_items']['element_type'] = '0';
  $handler->display->display_options['fields']['commerce_line_items']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_line_items']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['commerce_line_items']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['commerce_line_items']['settings'] = array(
    'view' => 'api_line_items|block_1',
  );
  $handler->display->display_options['fields']['commerce_line_items']['delta_offset'] = '0';
  $handler->display->display_options['fields']['commerce_line_items']['field_api_classes'] = TRUE;
  /* Field: Commerce Order: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['label'] = '';
  $handler->display->display_options['fields']['order_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['order_id']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['order_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['order_id']['link_to_order'] = 'customer';
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id_1']['id'] = 'order_id_1';
  $handler->display->display_options['fields']['order_id_1']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id_1']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id_1']['label'] = '';
  $handler->display->display_options['fields']['order_id_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['order_id_1']['alter']['text'] = 'Print';
  $handler->display->display_options['fields']['order_id_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['order_id_1']['alter']['path'] = 'user/!1/orders/[order_number]?print=1';
  $handler->display->display_options['fields']['order_id_1']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['order_id_1']['element_label_colon'] = FALSE;
  /* Contextual filter: Commerce Order: Uid */
  $handler->display->display_options['arguments']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['arguments']['uid_1']['table'] = 'commerce_order';
  $handler->display->display_options['arguments']['uid_1']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid_1']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid_1']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid_1']['validate']['type'] = 'current_user_or_role';
  $handler->display->display_options['arguments']['uid_1']['validate_options']['restrict_roles'] = TRUE;
  $handler->display->display_options['arguments']['uid_1']['validate_options']['roles'] = array(
    3 => '3',
  );
  /* Filter criterion: Commerce Order: Order state */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['operator'] = 'not in';
  $handler->display->display_options['filters']['state']['value'] = array(
    'cart' => 'cart',
    'checkout' => 'checkout',
  );

  /* Display: User Orders */
  $handler = $view->new_display('page', 'User Orders', 'order_page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = 'Order';
  $handler->display->display_options['fields']['order_number']['link_to_order'] = 'customer';
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'api_mm_dd_yyyy';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'M j, Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  /* Field: Commerce Order: Line items */
  $handler->display->display_options['fields']['commerce_line_items']['id'] = 'commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items']['field'] = 'commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items']['label'] = 'Order Detail';
  $handler->display->display_options['fields']['commerce_line_items']['element_type'] = '0';
  $handler->display->display_options['fields']['commerce_line_items']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_line_items']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['commerce_line_items']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['commerce_line_items']['settings'] = array(
    'view' => 'api_line_items|block_1',
  );
  $handler->display->display_options['fields']['commerce_line_items']['delta_offset'] = '0';
  $handler->display->display_options['fields']['commerce_line_items']['field_api_classes'] = TRUE;
  /* Field: Commerce Order: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['label'] = '';
  $handler->display->display_options['fields']['order_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['order_id']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['order_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['order_id']['link_to_order'] = 'customer';
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id_1']['id'] = 'order_id_1';
  $handler->display->display_options['fields']['order_id_1']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id_1']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id_1']['label'] = '';
  $handler->display->display_options['fields']['order_id_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['order_id_1']['alter']['text'] = 'Print';
  $handler->display->display_options['fields']['order_id_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['order_id_1']['alter']['path'] = 'user/!1/orders/[order_number]?print=1';
  $handler->display->display_options['fields']['order_id_1']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['order_id_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'user/%/orders';
  $handler->display->display_options['menu']['title'] = 'My Orders';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Order history';
  $handler->display->display_options['tab_options']['description'] = 'User orders in the store.';
  $handler->display->display_options['tab_options']['weight'] = '';
  $handler->display->display_options['tab_options']['name'] = 'user-menu';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent orders';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = 'Order';
  $handler->display->display_options['fields']['order_number']['link_to_order'] = 'customer';
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'api_mm_dd_yyyy';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'M j, Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  /* Field: Commerce Order: Line items */
  $handler->display->display_options['fields']['commerce_line_items']['id'] = 'commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items']['field'] = 'commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items']['label'] = 'Order Detail';
  $handler->display->display_options['fields']['commerce_line_items']['element_type'] = '0';
  $handler->display->display_options['fields']['commerce_line_items']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_line_items']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['commerce_line_items']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['commerce_line_items']['settings'] = array(
    'view' => 'api_line_items|block_1',
  );
  $handler->display->display_options['fields']['commerce_line_items']['delta_offset'] = '0';
  $handler->display->display_options['fields']['commerce_line_items']['field_api_classes'] = TRUE;
  /* Field: Commerce Order: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['label'] = '';
  $handler->display->display_options['fields']['order_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['order_id']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['order_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['order_id']['link_to_order'] = 'customer';
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id_1']['id'] = 'order_id_1';
  $handler->display->display_options['fields']['order_id_1']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id_1']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id_1']['label'] = '';
  $handler->display->display_options['fields']['order_id_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['order_id_1']['alter']['text'] = 'Print';
  $handler->display->display_options['fields']['order_id_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['order_id_1']['alter']['path'] = 'user/!1/orders/[order_number]?print=1';
  $handler->display->display_options['fields']['order_id_1']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['order_id_1']['element_label_colon'] = FALSE;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'orders_%timestamp-full.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = 'Order';
  $handler->display->display_options['fields']['order_number']['link_to_order'] = 'customer';
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'api_mm_dd_yyyy';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'M j, Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  /* Field: Commerce Order: Line items */
  $handler->display->display_options['fields']['commerce_line_items']['id'] = 'commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items']['field'] = 'commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items']['label'] = 'Order Detail';
  $handler->display->display_options['fields']['commerce_line_items']['element_type'] = '0';
  $handler->display->display_options['fields']['commerce_line_items']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_line_items']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['commerce_line_items']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['commerce_line_items']['settings'] = array(
    'view' => 'api_line_items|block_1',
  );
  $handler->display->display_options['fields']['commerce_line_items']['delta_offset'] = '0';
  $handler->display->display_options['fields']['commerce_line_items']['field_api_classes'] = TRUE;
  /* Field: Commerce Order: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['label'] = 'View order';
  $handler->display->display_options['fields']['order_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['order_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['order_id']['alter']['text'] = 'View order';
  $handler->display->display_options['fields']['order_id']['link_to_order'] = 'customer';
  $handler->display->display_options['path'] = 'user/%/orders/csv';
  $handler->display->display_options['displays'] = array(
    'order_page' => 'order_page',
    'default' => 0,
    'block_1' => 0,
  );
  $translatables['api_commerce_backoffice_user_orders'] = array(
    t('Defaults'),
    t('My Orders'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('You have not placed any orders with us yet.'),
    t('Order'),
    t('Date'),
    t('Status'),
    t('Order Detail'),
    t('Total'),
    t('View'),
    t('Print'),
    t('All'),
    t('User Orders'),
    t('Block'),
    t('Recent orders'),
    t('Data export'),
    t('Order status'),
    t('View order'),
  );
  $export['api_commerce_backoffice_user_orders'] = $view;

  $view = new view();
  $view->name = 'api_line_items';
  $view->description = 'This is cloned from the original one provided by Drupal Commerce (commerce_line_item_table) and customized for API site.';
  $view->tag = 'commerce';
  $view->base_table = 'commerce_line_item';
  $view->human_name = 'API Line items';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'line_item_id' => 'line_item_id',
    'type' => 'type',
    'line_item_title' => 'line_item_title',
    'line_item_label' => 'line_item_title',
    'commerce_unit_price' => 'commerce_unit_price',
    'quantity' => 'quantity',
    'commerce_total' => 'commerce_total',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'line_item_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'line_item_title' => array(
      'align' => '',
      'separator' => ' ',
    ),
    'line_item_label' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'commerce_unit_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'quantity' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'commerce_total' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty line item text.';
  $handler->display->display_options['empty']['area']['content'] = 'No line items found.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Field: Commerce Line Item: Line item ID */
  $handler->display->display_options['fields']['line_item_id']['id'] = 'line_item_id';
  $handler->display->display_options['fields']['line_item_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['line_item_id']['field'] = 'line_item_id';
  $handler->display->display_options['fields']['line_item_id']['label'] = 'ID';
  $handler->display->display_options['fields']['line_item_id']['exclude'] = TRUE;
  /* Field: Commerce Line Item: Title */
  $handler->display->display_options['fields']['line_item_title']['id'] = 'line_item_title';
  $handler->display->display_options['fields']['line_item_title']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['line_item_title']['field'] = 'line_item_title';
  $handler->display->display_options['fields']['line_item_title']['label'] = 'Product Name';
  /* Field: Commerce Line item: State */
  $handler->display->display_options['fields']['field_order_product_state']['id'] = 'field_order_product_state';
  $handler->display->display_options['fields']['field_order_product_state']['table'] = 'field_data_field_order_product_state';
  $handler->display->display_options['fields']['field_order_product_state']['field'] = 'field_order_product_state';
  $handler->display->display_options['fields']['field_order_product_state']['element_type'] = '0';
  $handler->display->display_options['fields']['field_order_product_state']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_order_product_state']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_order_product_state']['empty'] = 'N/A';
  $handler->display->display_options['fields']['field_order_product_state']['field_api_classes'] = TRUE;
  /* Field: Commerce Line item: Type */
  $handler->display->display_options['fields']['field_order_product_type']['id'] = 'field_order_product_type';
  $handler->display->display_options['fields']['field_order_product_type']['table'] = 'field_data_field_order_product_type';
  $handler->display->display_options['fields']['field_order_product_type']['field'] = 'field_order_product_type';
  $handler->display->display_options['fields']['field_order_product_type']['label'] = 'Class';
  $handler->display->display_options['fields']['field_order_product_type']['element_type'] = '0';
  $handler->display->display_options['fields']['field_order_product_type']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_order_product_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_order_product_type']['empty'] = 'N/A';
  $handler->display->display_options['fields']['field_order_product_type']['field_api_classes'] = TRUE;
  /* Field: Commerce Line Item: Label */
  $handler->display->display_options['fields']['line_item_label']['id'] = 'line_item_label';
  $handler->display->display_options['fields']['line_item_label']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['line_item_label']['field'] = 'line_item_label';
  $handler->display->display_options['fields']['line_item_label']['exclude'] = TRUE;
  $handler->display->display_options['fields']['line_item_label']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['line_item_label']['alter']['text'] = '([line_item_label])';
  /* Field: Commerce Line item: Unit price */
  $handler->display->display_options['fields']['commerce_unit_price']['id'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['table'] = 'field_data_commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['field'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['exclude'] = TRUE;
  $handler->display->display_options['fields']['commerce_unit_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_unit_price']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Line Item: Quantity */
  $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['exclude'] = TRUE;
  $handler->display->display_options['fields']['quantity']['precision'] = '0';
  /* Field: Commerce Line item: Total */
  $handler->display->display_options['fields']['commerce_total']['id'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['table'] = 'field_data_commerce_total';
  $handler->display->display_options['fields']['commerce_total']['field'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['click_sort_column'] = 'amount';
  /* Sort criterion: Commerce Line Item: Line item ID */
  $handler->display->display_options['sorts']['line_item_id']['id'] = 'line_item_id';
  $handler->display->display_options['sorts']['line_item_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['sorts']['line_item_id']['field'] = 'line_item_id';
  /* Contextual filter: Commerce Line Item: Line item ID */
  $handler->display->display_options['arguments']['line_item_id']['id'] = 'line_item_id';
  $handler->display->display_options['arguments']['line_item_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['arguments']['line_item_id']['field'] = 'line_item_id';
  $handler->display->display_options['arguments']['line_item_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['line_item_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['line_item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['line_item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['line_item_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['line_item_id']['break_phrase'] = TRUE;
  /* Filter criterion: Commerce Line Item: Line item is of a product line item type */
  $handler->display->display_options['filters']['product_line_item_type']['id'] = 'product_line_item_type';
  $handler->display->display_options['filters']['product_line_item_type']['table'] = 'commerce_line_item';
  $handler->display->display_options['filters']['product_line_item_type']['field'] = 'product_line_item_type';
  $handler->display->display_options['filters']['product_line_item_type']['value'] = '1';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['type'] = 'ol';
  $handler->display->display_options['style_options']['wrapper_class'] = 'courses-list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Line Item: Line item ID */
  $handler->display->display_options['fields']['line_item_id']['id'] = 'line_item_id';
  $handler->display->display_options['fields']['line_item_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['line_item_id']['field'] = 'line_item_id';
  $handler->display->display_options['fields']['line_item_id']['label'] = 'ID';
  $handler->display->display_options['fields']['line_item_id']['exclude'] = TRUE;
  /* Field: Commerce Line Item: Title */
  $handler->display->display_options['fields']['line_item_title']['id'] = 'line_item_title';
  $handler->display->display_options['fields']['line_item_title']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['line_item_title']['field'] = 'line_item_title';
  $handler->display->display_options['fields']['line_item_title']['label'] = 'Product Name';
  /* Field: Commerce Line item: State */
  $handler->display->display_options['fields']['field_order_product_state']['id'] = 'field_order_product_state';
  $handler->display->display_options['fields']['field_order_product_state']['table'] = 'field_data_field_order_product_state';
  $handler->display->display_options['fields']['field_order_product_state']['field'] = 'field_order_product_state';
  $handler->display->display_options['fields']['field_order_product_state']['element_type'] = '0';
  $handler->display->display_options['fields']['field_order_product_state']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_order_product_state']['empty'] = 'N/A';
  $handler->display->display_options['fields']['field_order_product_state']['field_api_classes'] = TRUE;
  /* Field: Commerce Line item: Type */
  $handler->display->display_options['fields']['field_order_product_type']['id'] = 'field_order_product_type';
  $handler->display->display_options['fields']['field_order_product_type']['table'] = 'field_data_field_order_product_type';
  $handler->display->display_options['fields']['field_order_product_type']['field'] = 'field_order_product_type';
  $handler->display->display_options['fields']['field_order_product_type']['label'] = 'Class';
  $handler->display->display_options['fields']['field_order_product_type']['element_type'] = '0';
  $handler->display->display_options['fields']['field_order_product_type']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_order_product_type']['empty'] = 'N/A';
  $handler->display->display_options['fields']['field_order_product_type']['field_api_classes'] = TRUE;
  /* Field: Commerce Line Item: Label */
  $handler->display->display_options['fields']['line_item_label']['id'] = 'line_item_label';
  $handler->display->display_options['fields']['line_item_label']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['line_item_label']['field'] = 'line_item_label';
  $handler->display->display_options['fields']['line_item_label']['exclude'] = TRUE;
  $handler->display->display_options['fields']['line_item_label']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['line_item_label']['alter']['text'] = '([line_item_label])';
  /* Field: Commerce Line item: Unit price */
  $handler->display->display_options['fields']['commerce_unit_price']['id'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['table'] = 'field_data_commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['field'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['exclude'] = TRUE;
  $handler->display->display_options['fields']['commerce_unit_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_unit_price']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Line Item: Quantity */
  $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['exclude'] = TRUE;
  $handler->display->display_options['fields']['quantity']['precision'] = '0';
  /* Field: Commerce Line item: Total */
  $handler->display->display_options['fields']['commerce_total']['id'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['table'] = 'field_data_commerce_total';
  $handler->display->display_options['fields']['commerce_total']['field'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['exclude'] = TRUE;
  $handler->display->display_options['fields']['commerce_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_total']['settings'] = array(
    'calculation' => FALSE,
  );
  $translatables['api_line_items'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Empty line item text.'),
    t('No line items found.'),
    t('ID'),
    t('.'),
    t(','),
    t('Product Name'),
    t('State'),
    t('N/A'),
    t('Class'),
    t('Label'),
    t('([line_item_label])'),
    t('Unit price'),
    t('Quantity'),
    t('Total'),
    t('All'),
    t('Block'),
  );
  $export['api_line_items'] = $view;

  $view = new view();
  $view->name = 'api_users';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'api_users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'User Administration';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    6 => '6',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'rid' => 'rid',
    'nothing' => 'nothing',
    'nothing_1' => 'nothing_1',
    'edit_node' => 'edit_node',
    'field_first_name' => 'field_first_name',
    'field_middle_name' => 'field_first_name',
    'field_last_name' => 'field_first_name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_middle_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'Full name';
  $handler->display->display_options['fields']['field_first_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_first_name']['field_api_classes'] = TRUE;
  /* Field: User: Middle Name */
  $handler->display->display_options['fields']['field_middle_name']['id'] = 'field_middle_name';
  $handler->display->display_options['fields']['field_middle_name']['table'] = 'field_data_field_middle_name';
  $handler->display->display_options['fields']['field_middle_name']['field'] = 'field_middle_name';
  $handler->display->display_options['fields']['field_middle_name']['label'] = '';
  $handler->display->display_options['fields']['field_middle_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_middle_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_middle_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_middle_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_middle_name']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_middle_name']['field_api_classes'] = TRUE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_last_name']['field_api_classes'] = TRUE;
  /* Field: User: Company Name */
  $handler->display->display_options['fields']['field_company_name']['id'] = 'field_company_name';
  $handler->display->display_options['fields']['field_company_name']['table'] = 'field_data_field_company_name';
  $handler->display->display_options['fields']['field_company_name']['field'] = 'field_company_name';
  $handler->display->display_options['fields']['field_company_name']['label'] = 'Company';
  $handler->display->display_options['fields']['field_company_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_company_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_company_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_company_name']['field_api_classes'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Safety Key';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'N/A';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Status';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'N/A';
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: User revision: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'user_revision';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Username';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: User: First Name (field_first_name) */
  $handler->display->display_options['filters']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['filters']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator_id'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['label'] = 'First name';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['identifier'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: User: Last Name (field_last_name) */
  $handler->display->display_options['filters']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['filters']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator_id'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['identifier'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: User: Company Name (field_company_name) */
  $handler->display->display_options['filters']['field_company_name_value']['id'] = 'field_company_name_value';
  $handler->display->display_options['filters']['field_company_name_value']['table'] = 'field_data_field_company_name';
  $handler->display->display_options['filters']['field_company_name_value']['field'] = 'field_company_name_value';
  $handler->display->display_options['filters']['field_company_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_company_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_company_name_value']['expose']['operator_id'] = 'field_company_name_value_op';
  $handler->display->display_options['filters']['field_company_name_value']['expose']['label'] = 'Company Name';
  $handler->display->display_options['filters']['field_company_name_value']['expose']['operator'] = 'field_company_name_value_op';
  $handler->display->display_options['filters']['field_company_name_value']['expose']['identifier'] = 'field_company_name_value';
  $handler->display->display_options['filters']['field_company_name_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user administration area';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_first_name' => 'field_first_name',
    'field_middle_name' => 'field_first_name',
    'field_last_name' => 'field_first_name',
    'field_company_name' => 'field_company_name',
    'nothing' => 'nothing',
    'nothing_1' => 'nothing_1',
    'rid' => 'rid',
    'edit_node' => 'edit_node',
    'uid' => 'uid',
    'nothing_2' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_middle_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_company_name' => array(
      'sortable' => 0,
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
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'Full Name';
  $handler->display->display_options['fields']['field_first_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_first_name']['field_api_classes'] = TRUE;
  /* Field: User: Middle Name */
  $handler->display->display_options['fields']['field_middle_name']['id'] = 'field_middle_name';
  $handler->display->display_options['fields']['field_middle_name']['table'] = 'field_data_field_middle_name';
  $handler->display->display_options['fields']['field_middle_name']['field'] = 'field_middle_name';
  $handler->display->display_options['fields']['field_middle_name']['label'] = '';
  $handler->display->display_options['fields']['field_middle_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_middle_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_middle_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_middle_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_middle_name']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_middle_name']['field_api_classes'] = TRUE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_last_name']['field_api_classes'] = TRUE;
  /* Field: User: Company Name */
  $handler->display->display_options['fields']['field_company_name']['id'] = 'field_company_name';
  $handler->display->display_options['fields']['field_company_name']['table'] = 'field_data_field_company_name';
  $handler->display->display_options['fields']['field_company_name']['field'] = 'field_company_name';
  $handler->display->display_options['fields']['field_company_name']['label'] = 'Company';
  $handler->display->display_options['fields']['field_company_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_company_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_company_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_company_name']['field_api_classes'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Safety Key';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'N/A';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Status';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'N/A';
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = 'Promote to Company Admin';
  $handler->display->display_options['fields']['nothing_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['path'] = 'api/[uid]/upgrade';
  $handler->display->display_options['fields']['nothing_2']['alter']['target'] = 'as _blank';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_2']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: User revision: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'user_revision';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Username';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: User: First Name (field_first_name) */
  $handler->display->display_options['filters']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['filters']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator_id'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['label'] = 'First Name';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['identifier'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    5 => 0,
  );
  /* Filter criterion: User: Last Name (field_last_name) */
  $handler->display->display_options['filters']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['filters']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator_id'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['label'] = 'Last Name';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['identifier'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    5 => 0,
  );
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-Mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    5 => 0,
  );
  /* Filter criterion: User: Company Name (field_company_name) */
  $handler->display->display_options['filters']['field_company_name_value']['id'] = 'field_company_name_value';
  $handler->display->display_options['filters']['field_company_name_value']['table'] = 'field_data_field_company_name';
  $handler->display->display_options['filters']['field_company_name_value']['field'] = 'field_company_name_value';
  $handler->display->display_options['filters']['field_company_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_company_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_company_name_value']['expose']['operator_id'] = 'field_company_name_value_op';
  $handler->display->display_options['filters']['field_company_name_value']['expose']['label'] = 'Company Name';
  $handler->display->display_options['filters']['field_company_name_value']['expose']['operator'] = 'field_company_name_value_op';
  $handler->display->display_options['filters']['field_company_name_value']['expose']['identifier'] = 'field_company_name_value';
  $handler->display->display_options['filters']['field_company_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['path'] = 'admin/people/api/users';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'User administration';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 1;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit own company';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'Full name';
  $handler->display->display_options['fields']['field_first_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_first_name']['field_api_classes'] = TRUE;
  /* Field: User: Middle Name */
  $handler->display->display_options['fields']['field_middle_name']['id'] = 'field_middle_name';
  $handler->display->display_options['fields']['field_middle_name']['table'] = 'field_data_field_middle_name';
  $handler->display->display_options['fields']['field_middle_name']['field'] = 'field_middle_name';
  $handler->display->display_options['fields']['field_middle_name']['label'] = '';
  $handler->display->display_options['fields']['field_middle_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_middle_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_middle_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_middle_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_middle_name']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_middle_name']['field_api_classes'] = TRUE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_last_name']['field_api_classes'] = TRUE;
  /* Field: User: Company Name */
  $handler->display->display_options['fields']['field_company_name']['id'] = 'field_company_name';
  $handler->display->display_options['fields']['field_company_name']['table'] = 'field_data_field_company_name';
  $handler->display->display_options['fields']['field_company_name']['field'] = 'field_company_name';
  $handler->display->display_options['fields']['field_company_name']['label'] = 'Company';
  $handler->display->display_options['fields']['field_company_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_company_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_company_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_company_name']['field_api_classes'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Safety Key';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'N/A';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Status';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'N/A';
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Company Name (field_company_name) */
  $handler->display->display_options['arguments']['field_company_name_value']['id'] = 'field_company_name_value';
  $handler->display->display_options['arguments']['field_company_name_value']['table'] = 'field_data_field_company_name';
  $handler->display->display_options['arguments']['field_company_name_value']['field'] = 'field_company_name_value';
  $handler->display->display_options['arguments']['field_company_name_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_company_name_value']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_company_name_value']['default_argument_options']['code'] = 'global $user;
$current_user = user_load($user->uid);
if ($current_user->field_company_name && $current_user->field_company_name[LANGUAGE_NONE][0] && $current_user->field_company_name[LANGUAGE_NONE][0][\'value\'] ){
return $current_user->field_company_name[LANGUAGE_NONE][0][\'value\'];
} else {
return \'\';
}';
  $handler->display->display_options['arguments']['field_company_name_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_company_name_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_company_name_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_company_name_value']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: User revision: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'user_revision';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Username';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: User: First Name (field_first_name) */
  $handler->display->display_options['filters']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['filters']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator_id'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['label'] = 'First name';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['identifier'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: User: Last Name (field_last_name) */
  $handler->display->display_options['filters']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['filters']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator_id'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['identifier'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['path'] = 'admin/people/api/company/users';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'User Administration';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: User Historical Information */
  $handler = $view->new_display('page', 'User Historical Information', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'User Historical Information';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'api users customer support';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_first_name' => 'field_first_name',
    'field_middle_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_company_name' => 'field_company_name',
    'nothing' => 'nothing',
    'nothing_1' => 'nothing_1',
    'rid' => 'rid',
    'edit_node' => 'edit_node',
    'view_user' => 'view_user',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_middle_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_company_name' => array(
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
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_user' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No users found matching the search criteria.';
  $handler->display->display_options['empty']['area']['format'] = 'commerce_order_message';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Safety Key */
  $handler->display->display_options['relationships']['eck_safety_key']['id'] = 'eck_safety_key';
  $handler->display->display_options['relationships']['eck_safety_key']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_safety_key']['field'] = 'eck_safety_key';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'admin/people/customer-support/[uid]';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_first_name']['field_api_classes'] = TRUE;
  /* Field: User: Middle Name */
  $handler->display->display_options['fields']['field_middle_name']['id'] = 'field_middle_name';
  $handler->display->display_options['fields']['field_middle_name']['table'] = 'field_data_field_middle_name';
  $handler->display->display_options['fields']['field_middle_name']['field'] = 'field_middle_name';
  $handler->display->display_options['fields']['field_middle_name']['label'] = '';
  $handler->display->display_options['fields']['field_middle_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_middle_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_middle_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_middle_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_middle_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_middle_name']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_middle_name']['field_api_classes'] = TRUE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_last_name']['field_api_classes'] = TRUE;
  /* Field: User: Company Name */
  $handler->display->display_options['fields']['field_company_name']['id'] = 'field_company_name';
  $handler->display->display_options['fields']['field_company_name']['table'] = 'field_data_field_company_name';
  $handler->display->display_options['fields']['field_company_name']['field'] = 'field_company_name';
  $handler->display->display_options['fields']['field_company_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_company_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_company_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_company_name']['field_api_classes'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Safety Key';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'N/A';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Status';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'N/A';
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['exclude'] = TRUE;
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = 'View';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['nothing_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['path'] = 'admin/people/customer-support/[uid]';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: User revision: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'user_revision';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Username';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: User: First Name (field_first_name) */
  $handler->display->display_options['filters']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['filters']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator_id'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['label'] = 'First Name';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['identifier'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: User: Last Name (field_last_name) */
  $handler->display->display_options['filters']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['filters']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator_id'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['label'] = 'Last Name';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['identifier'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-Mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: User: Company Name (field_company_name) */
  $handler->display->display_options['filters']['field_company_name_value']['id'] = 'field_company_name_value';
  $handler->display->display_options['filters']['field_company_name_value']['table'] = 'field_data_field_company_name';
  $handler->display->display_options['filters']['field_company_name_value']['field'] = 'field_company_name_value';
  $handler->display->display_options['filters']['field_company_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_company_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_company_name_value']['expose']['operator_id'] = 'field_company_name_value_op';
  $handler->display->display_options['filters']['field_company_name_value']['expose']['label'] = 'Company Name';
  $handler->display->display_options['filters']['field_company_name_value']['expose']['operator'] = 'field_company_name_value_op';
  $handler->display->display_options['filters']['field_company_name_value']['expose']['identifier'] = 'field_company_name_value';
  $handler->display->display_options['filters']['field_company_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: Safety Key: Number */
  $handler->display->display_options['filters']['number']['id'] = 'number';
  $handler->display->display_options['filters']['number']['table'] = 'eck_safety_key';
  $handler->display->display_options['filters']['number']['field'] = 'number';
  $handler->display->display_options['filters']['number']['relationship'] = 'eck_safety_key';
  $handler->display->display_options['filters']['number']['exposed'] = TRUE;
  $handler->display->display_options['filters']['number']['expose']['operator_id'] = 'number_op';
  $handler->display->display_options['filters']['number']['expose']['label'] = 'Safety Key';
  $handler->display->display_options['filters']['number']['expose']['operator'] = 'number_op';
  $handler->display->display_options['filters']['number']['expose']['identifier'] = 'number';
  $handler->display->display_options['filters']['number']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    5 => 0,
  );
  $handler->display->display_options['path'] = 'admin/people/customer-support';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'User Historical Information';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page 3 */
  $handler = $view->new_display('page', 'Page 3', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'User Historical Information';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'api users customer support';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name' => 'name',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_company_name' => 'field_company_name',
  );
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: View area */
  $handler->display->display_options['footer']['view']['id'] = 'view';
  $handler->display->display_options['footer']['view']['table'] = 'views';
  $handler->display->display_options['footer']['view']['field'] = 'view';
  $handler->display->display_options['footer']['view']['label'] = 'Safety Keys';
  $handler->display->display_options['footer']['view']['view_to_insert'] = 'safety_keys:customer_support_block';
  $handler->display->display_options['footer']['view']['inherit_arguments'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_type'] = 'span';
  $handler->display->display_options['fields']['name']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['name']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['type'] = 'text_plain';
  /* Field: User: Middle Name */
  $handler->display->display_options['fields']['field_middle_name']['id'] = 'field_middle_name';
  $handler->display->display_options['fields']['field_middle_name']['table'] = 'field_data_field_middle_name';
  $handler->display->display_options['fields']['field_middle_name']['field'] = 'field_middle_name';
  $handler->display->display_options['fields']['field_middle_name']['label'] = '';
  $handler->display->display_options['fields']['field_middle_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_middle_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_middle_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_middle_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_middle_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_middle_name']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_middle_name']['field_api_classes'] = TRUE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_last_name']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['type'] = 'text_plain';
  /* Field: User: Company Name */
  $handler->display->display_options['fields']['field_company_name']['id'] = 'field_company_name';
  $handler->display->display_options['fields']['field_company_name']['table'] = 'field_data_field_company_name';
  $handler->display->display_options['fields']['field_company_name']['field'] = 'field_company_name';
  $handler->display->display_options['fields']['field_company_name']['label'] = 'Current Company';
  $handler->display->display_options['fields']['field_company_name']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_company_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_company_name']['type'] = 'text_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Safety Key';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'N/A';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Status';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'N/A';
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['rid']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['rid']['element_default_classes'] = FALSE;
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/people/customer-support/%';

  /* Display: Company admin: user import search */
  $handler = $view->new_display('block', 'Company admin: user import search', 'company_admin_user_import_search');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Search';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit own company';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['text_input_required'] = '';
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'commerce_order_message';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['pager']['options']['tags']['first'] = '';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '';
  $handler->display->display_options['pager']['options']['tags']['next'] = '';
  $handler->display->display_options['pager']['options']['tags']['last'] = '';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_first_name' => 'field_first_name',
    'field_middle_name' => 'field_first_name',
    'field_last_name' => 'field_first_name',
    'mail' => 'mail',
  );
  $handler->display->display_options['style_options']['default'] = 'name';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_middle_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'Full name';
  $handler->display->display_options['fields']['field_first_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_first_name']['field_api_classes'] = TRUE;
  /* Field: User: Middle Name */
  $handler->display->display_options['fields']['field_middle_name']['id'] = 'field_middle_name';
  $handler->display->display_options['fields']['field_middle_name']['table'] = 'field_data_field_middle_name';
  $handler->display->display_options['fields']['field_middle_name']['field'] = 'field_middle_name';
  $handler->display->display_options['fields']['field_middle_name']['label'] = '';
  $handler->display->display_options['fields']['field_middle_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_middle_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_middle_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_middle_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_middle_name']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_middle_name']['field_api_classes'] = TRUE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_last_name']['field_api_classes'] = TRUE;
  /* Field: User: Company Name */
  $handler->display->display_options['fields']['field_company_name']['id'] = 'field_company_name';
  $handler->display->display_options['fields']['field_company_name']['table'] = 'field_data_field_company_name';
  $handler->display->display_options['fields']['field_company_name']['field'] = 'field_company_name';
  $handler->display->display_options['fields']['field_company_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_company_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_company_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_company_name']['field_api_classes'] = TRUE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: User revision: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'user_revision';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'starts';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Username';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    8 => 0,
  );
  $handler->display->display_options['block_description'] = 'Search user';
  $translatables['api_users'] = array(
    t('Master'),
    t('User Administration'),
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
    t('Username'),
    t('Full name'),
    t('Company'),
    t('Safety Key'),
    t('N/A'),
    t('Status'),
    t('Roles'),
    t('Operations'),
    t('First name'),
    t('Last name'),
    t('E-mail'),
    t('Company Name'),
    t('Page'),
    t('Full Name'),
    t('Edit'),
    t('Promote to Company Admin'),
    t('First Name'),
    t('Last Name'),
    t('E-Mail'),
    t('All'),
    t('User Historical Information'),
    t('No users found matching the search criteria.'),
    t('View'),
    t('Page 3'),
    t('Safety Keys'),
    t('Current Company'),
    t('Company admin: user import search'),
    t('Search'),
    t('Search user'),
  );
  $export['api_users'] = $view;

  $view = new view();
  $view->name = 'branches';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Branches';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Facilities';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view the administration theme';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_address_thoroughfare' => 'field_address_thoroughfare',
    'field_address_locality' => 'field_address_locality',
    'field_address_administrative_area' => 'field_address_administrative_area',
    'field_address_country' => 'field_address_country',
    'field_address_postal_code' => 'field_address_postal_code',
    'field_tel' => 'field_tel',
    'edit_node' => 'edit_node',
    'nid' => 'nid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_address_thoroughfare' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_address_locality' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_address_administrative_area' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_address_country' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_address_postal_code' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tel' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'New branch';
  $handler->display->display_options['header']['area']['content'] = '<a href="/node/add/branch/company/!1">Add a new Facility</a>';
  $handler->display->display_options['header']['area']['format'] = 'commerce_order_message';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'New branch';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<a href="/node/add/branch/company/!1">Add a new Facility</a>';
  $handler->display->display_options['empty']['area']['format'] = 'commerce_order_message';
  $handler->display->display_options['empty']['area']['tokenize'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['relationships']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['required'] = TRUE;
  /* Field: Field: Address - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['field_address_thoroughfare']['id'] = 'field_address_thoroughfare';
  $handler->display->display_options['fields']['field_address_thoroughfare']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_thoroughfare']['field'] = 'field_address_thoroughfare';
  $handler->display->display_options['fields']['field_address_thoroughfare']['label'] = 'Address';
  $handler->display->display_options['fields']['field_address_thoroughfare']['element_type'] = '0';
  $handler->display->display_options['fields']['field_address_thoroughfare']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_address_thoroughfare']['element_default_classes'] = FALSE;
  /* Field: Field: Address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_address_locality']['id'] = 'field_address_locality';
  $handler->display->display_options['fields']['field_address_locality']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_locality']['field'] = 'field_address_locality';
  $handler->display->display_options['fields']['field_address_locality']['label'] = 'City';
  $handler->display->display_options['fields']['field_address_locality']['element_type'] = '0';
  $handler->display->display_options['fields']['field_address_locality']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_address_locality']['element_default_classes'] = FALSE;
  /* Field: Field: Address - Administrative area (i.e. State / Province) */
  $handler->display->display_options['fields']['field_address_administrative_area']['id'] = 'field_address_administrative_area';
  $handler->display->display_options['fields']['field_address_administrative_area']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_administrative_area']['field'] = 'field_address_administrative_area';
  $handler->display->display_options['fields']['field_address_administrative_area']['label'] = 'State';
  $handler->display->display_options['fields']['field_address_administrative_area']['element_type'] = '0';
  $handler->display->display_options['fields']['field_address_administrative_area']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_address_administrative_area']['element_default_classes'] = FALSE;
  /* Field: Field: Address - Country */
  $handler->display->display_options['fields']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['label'] = 'Country';
  $handler->display->display_options['fields']['field_address_country']['element_type'] = '0';
  $handler->display->display_options['fields']['field_address_country']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_address_country']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_address_country']['display_name'] = 1;
  /* Field: Field: Address - Postal code */
  $handler->display->display_options['fields']['field_address_postal_code']['id'] = 'field_address_postal_code';
  $handler->display->display_options['fields']['field_address_postal_code']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_postal_code']['field'] = 'field_address_postal_code';
  $handler->display->display_options['fields']['field_address_postal_code']['label'] = 'ZIP / Postal Code';
  $handler->display->display_options['fields']['field_address_postal_code']['element_type'] = '0';
  $handler->display->display_options['fields']['field_address_postal_code']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_address_postal_code']['element_default_classes'] = FALSE;
  /* Field: Field: Primary Telephone */
  $handler->display->display_options['fields']['field_tel']['id'] = 'field_tel';
  $handler->display->display_options['fields']['field_tel']['table'] = 'field_data_field_tel';
  $handler->display->display_options['fields']['field_tel']['field'] = 'field_tel';
  $handler->display->display_options['fields']['field_tel']['label'] = 'Tel';
  $handler->display->display_options['fields']['field_tel']['element_type'] = '0';
  $handler->display->display_options['fields']['field_tel']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_tel']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_tel']['field_api_classes'] = TRUE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Unpublish';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'Unpublish';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node/[nid]/unpublish';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Field: Company (field_company) */
  $handler->display->display_options['arguments']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['arguments']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['arguments']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['arguments']['field_company_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_company_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_company_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_company_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_company_target_id']['summary_options']['items_per_page'] = '25';
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
    'branch' => 'branch',
  );

  /* Display: Company Branches Page */
  $handler = $view->new_display('page', 'Company Branches Page', 'page');
  $handler->display->display_options['path'] = 'company/%/branches';

  /* Display: Company Branches Block */
  $handler = $view->new_display('block', 'Company Branches Block', 'branches_block');
  $translatables['branches'] = array(
    t('Master'),
    t('Facilities'),
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
    t('New branch'),
    t('<a href="/node/add/branch/company/!1">Add a new Facility</a>'),
    t('Content entity referenced from field_company'),
    t('Address'),
    t('City'),
    t('State'),
    t('Country'),
    t('ZIP / Postal Code'),
    t('Tel'),
    t('Edit'),
    t('Unpublish'),
    t('All'),
    t('Company Branches Page'),
    t('Company Branches Block'),
  );
  $export['branches'] = $view;

  $view = new view();
  $view->name = 'companies';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Companies';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Companies';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user administration area';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_address_thoroughfare' => 'field_address_thoroughfare',
    'field_address_locality' => 'field_address_locality',
    'field_address_administrative_area' => 'field_address_administrative_area',
    'edit_node' => 'edit_node',
    'nid' => 'nid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_address_thoroughfare' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_address_locality' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_address_administrative_area' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<a href="/node/add/company?destination=admin/content/companies">Add a new company</a>';
  $handler->display->display_options['header']['area']['format'] = 'commerce_order_message';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Address - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['field_address_thoroughfare']['id'] = 'field_address_thoroughfare';
  $handler->display->display_options['fields']['field_address_thoroughfare']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_thoroughfare']['field'] = 'field_address_thoroughfare';
  $handler->display->display_options['fields']['field_address_thoroughfare']['label'] = 'Address';
  $handler->display->display_options['fields']['field_address_thoroughfare']['element_type'] = '0';
  $handler->display->display_options['fields']['field_address_thoroughfare']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_address_thoroughfare']['element_default_classes'] = FALSE;
  /* Field: Field: Address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_address_locality']['id'] = 'field_address_locality';
  $handler->display->display_options['fields']['field_address_locality']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_locality']['field'] = 'field_address_locality';
  $handler->display->display_options['fields']['field_address_locality']['label'] = 'City';
  $handler->display->display_options['fields']['field_address_locality']['element_type'] = '0';
  $handler->display->display_options['fields']['field_address_locality']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_address_locality']['element_default_classes'] = FALSE;
  /* Field: Field: Address - Administrative area (i.e. State / Province) */
  $handler->display->display_options['fields']['field_address_administrative_area']['id'] = 'field_address_administrative_area';
  $handler->display->display_options['fields']['field_address_administrative_area']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_administrative_area']['field'] = 'field_address_administrative_area';
  $handler->display->display_options['fields']['field_address_administrative_area']['label'] = 'State';
  $handler->display->display_options['fields']['field_address_administrative_area']['element_type'] = '0';
  $handler->display->display_options['fields']['field_address_administrative_area']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_address_administrative_area']['element_default_classes'] = FALSE;
  /* Field: Field: Address - Country */
  $handler->display->display_options['fields']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['label'] = 'Country';
  $handler->display->display_options['fields']['field_address_country']['element_type'] = '0';
  $handler->display->display_options['fields']['field_address_country']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_address_country']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_address_country']['display_name'] = 1;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Safety Keys';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Employees';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '0';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'View Facilities';
  $handler->display->display_options['fields']['view_node']['text'] = 'View Facilities';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Unpublish';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'Unpublish';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node/[nid]/unpublish';
  $handler->display->display_options['fields']['nid']['alter']['alt'] = 'Unpublish';
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
    'company' => 'company',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Field: Address - Locality (i.e. City) */
  $handler->display->display_options['filters']['field_address_locality']['id'] = 'field_address_locality';
  $handler->display->display_options['filters']['field_address_locality']['table'] = 'field_data_field_address';
  $handler->display->display_options['filters']['field_address_locality']['field'] = 'field_address_locality';
  $handler->display->display_options['filters']['field_address_locality']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_address_locality']['group'] = 1;
  $handler->display->display_options['filters']['field_address_locality']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_address_locality']['expose']['operator_id'] = 'field_address_locality_op';
  $handler->display->display_options['filters']['field_address_locality']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['field_address_locality']['expose']['operator'] = 'field_address_locality_op';
  $handler->display->display_options['filters']['field_address_locality']['expose']['identifier'] = 'field_address_locality';
  $handler->display->display_options['filters']['field_address_locality']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Field: Address - Administrative area (i.e. State / Province) */
  $handler->display->display_options['filters']['field_address_administrative_area']['id'] = 'field_address_administrative_area';
  $handler->display->display_options['filters']['field_address_administrative_area']['table'] = 'field_data_field_address';
  $handler->display->display_options['filters']['field_address_administrative_area']['field'] = 'field_address_administrative_area';
  $handler->display->display_options['filters']['field_address_administrative_area']['group'] = 1;
  $handler->display->display_options['filters']['field_address_administrative_area']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_address_administrative_area']['expose']['operator_id'] = 'field_address_administrative_area_op';
  $handler->display->display_options['filters']['field_address_administrative_area']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['field_address_administrative_area']['expose']['operator'] = 'field_address_administrative_area_op';
  $handler->display->display_options['filters']['field_address_administrative_area']['expose']['identifier'] = 'field_address_administrative_area';
  $handler->display->display_options['filters']['field_address_administrative_area']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_address_administrative_area']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_address_administrative_area']['group_info']['label'] = 'HQ Address - Administrative area (i.e. State / Province)';
  $handler->display->display_options['filters']['field_address_administrative_area']['group_info']['identifier'] = 'field_address_administrative_area';
  $handler->display->display_options['filters']['field_address_administrative_area']['group_info']['widget'] = 'radios';
  $handler->display->display_options['filters']['field_address_administrative_area']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_address_administrative_area']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Alabama',
      'operator' => 'contains',
      'value' => 'AL',
    ),
    2 => array(
      'title' => 'Alaska',
      'operator' => 'contains',
      'value' => 'AK',
    ),
    3 => array(
      'title' => 'Colorado',
      'operator' => 'contains',
      'value' => 'CO',
    ),
    4 => array(
      'title' => 'Massachusetts',
      'operator' => 'contains',
      'value' => 'MA',
    ),
  );
  /* Filter criterion: Field: Address - Country */
  $handler->display->display_options['filters']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['filters']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['filters']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['filters']['field_address_country']['group'] = 1;
  $handler->display->display_options['filters']['field_address_country']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_address_country']['expose']['operator_id'] = 'field_address_country_op';
  $handler->display->display_options['filters']['field_address_country']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_address_country']['expose']['operator'] = 'field_address_country_op';
  $handler->display->display_options['filters']['field_address_country']['expose']['identifier'] = 'field_address_country';
  $handler->display->display_options['filters']['field_address_country']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/companies';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Companies';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['companies'] = array(
    t('Master'),
    t('Companies'),
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
    t('<a href="/node/add/company?destination=admin/content/companies">Add a new company</a>'),
    t('Name'),
    t('Address'),
    t('City'),
    t('State'),
    t('Country'),
    t('Safety Keys'),
    t('Employees'),
    t('Edit'),
    t('View Facilities'),
    t('Unpublish'),
    t('HQ Address - Administrative area (i.e. State / Province)'),
    t('Page'),
  );
  $export['companies'] = $view;

  $view = new view();
  $view->name = 'directory';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Directory';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Directory';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
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
    'nid' => 'nid',
    'title' => 'title',
    'field_address_locality' => 'field_address_locality',
    'field_address_administrative_area' => 'field_address_administrative_area',
    'field_address_data' => 'field_address_administrative_area',
    'field_address_country' => 'field_address_administrative_area',
    'custom_handler' => 'custom_handler',
    'view_node' => 'view_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_address_locality' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_address_administrative_area' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '/',
      'empty_column' => 0,
    ),
    'field_address_data' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_address_country' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'custom_handler' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Company';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_address_locality']['id'] = 'field_address_locality';
  $handler->display->display_options['fields']['field_address_locality']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_locality']['field'] = 'field_address_locality';
  $handler->display->display_options['fields']['field_address_locality']['label'] = 'HQ City';
  $handler->display->display_options['fields']['field_address_locality']['element_type'] = '0';
  $handler->display->display_options['fields']['field_address_locality']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_address_locality']['element_default_classes'] = FALSE;
  /* Field: Field: Address - Administrative area (i.e. State / Province) */
  $handler->display->display_options['fields']['field_address_administrative_area']['id'] = 'field_address_administrative_area';
  $handler->display->display_options['fields']['field_address_administrative_area']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_administrative_area']['field'] = 'field_address_administrative_area';
  $handler->display->display_options['fields']['field_address_administrative_area']['label'] = 'HQ State/Country';
  $handler->display->display_options['fields']['field_address_administrative_area']['element_type'] = '0';
  $handler->display->display_options['fields']['field_address_administrative_area']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_address_administrative_area']['element_default_classes'] = FALSE;
  /* Field: Field: Address with API Custom */
  $handler->display->display_options['fields']['field_address_data']['id'] = 'field_address_data';
  $handler->display->display_options['fields']['field_address_data']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_data']['field'] = 'field_address_data';
  $handler->display->display_options['fields']['field_address_data']['label'] = 'Province / Region';
  $handler->display->display_options['fields']['field_address_data']['element_type'] = '0';
  $handler->display->display_options['fields']['field_address_data']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_address_data']['element_default_classes'] = FALSE;
  /* Field: Field: Address - Country */
  $handler->display->display_options['fields']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['label'] = 'Country';
  $handler->display->display_options['fields']['field_address_country']['element_type'] = '0';
  $handler->display->display_options['fields']['field_address_country']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_address_country']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_address_country']['display_name'] = 1;
  /* Field: Company - Safety Keys: Number of Safety Keys. */
  $handler->display->display_options['fields']['custom_handler']['id'] = 'custom_handler';
  $handler->display->display_options['fields']['custom_handler']['table'] = 'custom';
  $handler->display->display_options['fields']['custom_handler']['field'] = 'custom_handler';
  $handler->display->display_options['fields']['custom_handler']['label'] = 'Safety Keys';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'View';
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'company' => 'company',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Address - Country */
  $handler->display->display_options['filters']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['filters']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['filters']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['filters']['field_address_country']['value'] = array(
    'US' => 'US',
  );
  $handler->display->display_options['filters']['field_address_country']['group'] = 1;
  $handler->display->display_options['filters']['field_address_country']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_address_country']['expose']['operator_id'] = 'field_address_country_op';
  $handler->display->display_options['filters']['field_address_country']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_address_country']['expose']['operator'] = 'field_address_country_op';
  $handler->display->display_options['filters']['field_address_country']['expose']['identifier'] = 'field_address_country';
  $handler->display->display_options['filters']['field_address_country']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    5 => 0,
  );
  /* Filter criterion: Field: Address - Administrative area (i.e. State / Province) */
  $handler->display->display_options['filters']['field_address_administrative_area']['id'] = 'field_address_administrative_area';
  $handler->display->display_options['filters']['field_address_administrative_area']['table'] = 'field_data_field_address';
  $handler->display->display_options['filters']['field_address_administrative_area']['field'] = 'field_address_administrative_area';
  $handler->display->display_options['filters']['field_address_administrative_area']['group'] = 1;
  $handler->display->display_options['filters']['field_address_administrative_area']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_address_administrative_area']['expose']['operator_id'] = 'field_address_administrative_area_op';
  $handler->display->display_options['filters']['field_address_administrative_area']['expose']['label'] = 'States';
  $handler->display->display_options['filters']['field_address_administrative_area']['expose']['operator'] = 'field_address_administrative_area_op';
  $handler->display->display_options['filters']['field_address_administrative_area']['expose']['identifier'] = 'field_address_administrative_area';
  $handler->display->display_options['filters']['field_address_administrative_area']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_address_administrative_area']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    5 => 0,
  );
  /* Filter criterion: Field: Address with API Custom */
  $handler->display->display_options['filters']['field_address_data']['id'] = 'field_address_data';
  $handler->display->display_options['filters']['field_address_data']['table'] = 'field_data_field_address';
  $handler->display->display_options['filters']['field_address_data']['field'] = 'field_address_data';
  $handler->display->display_options['filters']['field_address_data']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_address_data']['group'] = 1;
  $handler->display->display_options['filters']['field_address_data']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_address_data']['expose']['operator_id'] = 'field_address_data_op';
  $handler->display->display_options['filters']['field_address_data']['expose']['label'] = 'Province / Region';
  $handler->display->display_options['filters']['field_address_data']['expose']['operator'] = 'field_address_data_op';
  $handler->display->display_options['filters']['field_address_data']['expose']['identifier'] = 'field_address_data';
  $handler->display->display_options['filters']['field_address_data']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Types of Work (field_types_of_work) */
  $handler->display->display_options['filters']['field_types_of_work_value']['id'] = 'field_types_of_work_value';
  $handler->display->display_options['filters']['field_types_of_work_value']['table'] = 'field_data_field_types_of_work';
  $handler->display->display_options['filters']['field_types_of_work_value']['field'] = 'field_types_of_work_value';
  $handler->display->display_options['filters']['field_types_of_work_value']['group'] = 1;
  $handler->display->display_options['filters']['field_types_of_work_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_types_of_work_value']['expose']['operator_id'] = 'field_types_of_work_value_op';
  $handler->display->display_options['filters']['field_types_of_work_value']['expose']['label'] = 'Work Types';
  $handler->display->display_options['filters']['field_types_of_work_value']['expose']['operator'] = 'field_types_of_work_value_op';
  $handler->display->display_options['filters']['field_types_of_work_value']['expose']['identifier'] = 'field_types_of_work_value';
  $handler->display->display_options['filters']['field_types_of_work_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_types_of_work_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Company';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    5 => 0,
  );

  /* Display: Directory Search */
  $handler = $view->new_display('page', 'Directory Search', 'directory_search');
  $handler->display->display_options['display_description'] = 'Search based on country, US state, or work type';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'field_address_locality' => 'field_address_locality',
    'field_address_administrative_area' => 'field_address_administrative_area',
    'field_address_data' => 'field_address_administrative_area',
    'field_address_country' => 'field_address_administrative_area',
    'custom_handler' => 'custom_handler',
    'view_node' => 'view_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_address_locality' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_address_administrative_area' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '/',
      'empty_column' => 0,
    ),
    'field_address_data' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_address_country' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'custom_handler' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No companies were found. Please try again.';
  $handler->display->display_options['empty']['area']['format'] = 'commerce_order_message';
  $handler->display->display_options['path'] = 'directory/search';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2000';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['attach_text'] = 'Export';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'directory.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Company';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_address_locality']['id'] = 'field_address_locality';
  $handler->display->display_options['fields']['field_address_locality']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_locality']['field'] = 'field_address_locality';
  $handler->display->display_options['fields']['field_address_locality']['label'] = 'HQ City';
  $handler->display->display_options['fields']['field_address_locality']['element_type'] = '0';
  $handler->display->display_options['fields']['field_address_locality']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_address_locality']['element_default_classes'] = FALSE;
  /* Field: Field: Address with API Custom */
  $handler->display->display_options['fields']['field_address_data']['id'] = 'field_address_data';
  $handler->display->display_options['fields']['field_address_data']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_data']['field'] = 'field_address_data';
  $handler->display->display_options['fields']['field_address_data']['label'] = 'Province / Region';
  $handler->display->display_options['fields']['field_address_data']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_address_data']['element_type'] = '0';
  $handler->display->display_options['fields']['field_address_data']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_address_data']['element_default_classes'] = FALSE;
  /* Field: Field: Address - Country */
  $handler->display->display_options['fields']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['label'] = 'Country';
  $handler->display->display_options['fields']['field_address_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_address_country']['element_type'] = '0';
  $handler->display->display_options['fields']['field_address_country']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_address_country']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_address_country']['display_name'] = 1;
  /* Field: Field: Address - Administrative area (i.e. State / Province) */
  $handler->display->display_options['fields']['field_address_administrative_area']['id'] = 'field_address_administrative_area';
  $handler->display->display_options['fields']['field_address_administrative_area']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_administrative_area']['field'] = 'field_address_administrative_area';
  $handler->display->display_options['fields']['field_address_administrative_area']['label'] = 'HQ State/Country';
  $handler->display->display_options['fields']['field_address_administrative_area']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_address_administrative_area']['alter']['text'] = '[field_address_administrative_area]/[field_address_country]';
  $handler->display->display_options['fields']['field_address_administrative_area']['element_type'] = '0';
  $handler->display->display_options['fields']['field_address_administrative_area']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_address_administrative_area']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_address_administrative_area']['empty'] = '[field_address_data]/[field_address_country]';
  /* Field: Company - Safety Keys: Number of Safety Keys. */
  $handler->display->display_options['fields']['custom_handler']['id'] = 'custom_handler';
  $handler->display->display_options['fields']['custom_handler']['table'] = 'custom';
  $handler->display->display_options['fields']['custom_handler']['field'] = 'custom_handler';
  $handler->display->display_options['fields']['custom_handler']['label'] = 'Safety Keys';
  $handler->display->display_options['path'] = 'directory/export';
  $handler->display->display_options['displays'] = array(
    'directory_search' => 'directory_search',
    'default' => 0,
  );
  $translatables['directory'] = array(
    t('Master'),
    t('Directory'),
    t('more'),
    t('Search'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Company'),
    t('HQ City'),
    t('HQ State/Country'),
    t('Province / Region'),
    t('Country'),
    t('Safety Keys'),
    t('View'),
    t('States'),
    t('Work Types'),
    t('Directory Search'),
    t('Search based on country, US state, or work type'),
    t('No companies were found. Please try again.'),
    t('Data export'),
    t('[field_address_administrative_area]/[field_address_country]'),
    t('[field_address_data]/[field_address_country]'),
  );
  $export['directory'] = $view;

  $view = new view();
  $view->name = 'programs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Programs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Programs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'program-[nid]';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Programs description';
  $handler->display->display_options['header']['area']['format'] = 'commerce_order_message';
  /* Relationship: Content: Handbook (field_handbook:fid) */
  $handler->display->display_options['relationships']['field_handbook_fid']['id'] = 'field_handbook_fid';
  $handler->display->display_options['relationships']['field_handbook_fid']['table'] = 'field_data_field_handbook';
  $handler->display->display_options['relationships']['field_handbook_fid']['field'] = 'field_handbook_fid';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_program_image']['id'] = 'field_program_image';
  $handler->display->display_options['fields']['field_program_image']['table'] = 'field_data_field_program_image';
  $handler->display->display_options['fields']['field_program_image']['field'] = 'field_program_image';
  $handler->display->display_options['fields']['field_program_image']['label'] = '';
  $handler->display->display_options['fields']['field_program_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_program_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_program_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_program_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_program_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_program_image']['field_api_classes'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Short description of the program contents */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  $handler->display->display_options['fields']['body']['field_api_classes'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'More details';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'program/[nid]/buy';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Number of modules */
  $handler->display->display_options['fields']['field_number_of_modules']['id'] = 'field_number_of_modules';
  $handler->display->display_options['fields']['field_number_of_modules']['table'] = 'field_data_field_number_of_modules';
  $handler->display->display_options['fields']['field_number_of_modules']['field'] = 'field_number_of_modules';
  $handler->display->display_options['fields']['field_number_of_modules']['label'] = 'Number of Modules';
  $handler->display->display_options['fields']['field_number_of_modules']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_number_of_modules']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_number_of_modules']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_number_of_modules']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_number_of_modules']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_number_of_modules']['type'] = 'text_plain';
  /* Field: Content: Completion time */
  $handler->display->display_options['fields']['field_completation_time']['id'] = 'field_completation_time';
  $handler->display->display_options['fields']['field_completation_time']['table'] = 'field_data_field_completation_time';
  $handler->display->display_options['fields']['field_completation_time']['field'] = 'field_completation_time';
  $handler->display->display_options['fields']['field_completation_time']['label'] = 'Completion Time';
  $handler->display->display_options['fields']['field_completation_time']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_completation_time']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_completation_time']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_completation_time']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_completation_time']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_completation_time']['type'] = 'text_plain';
  /* Field: Content: Price range */
  $handler->display->display_options['fields']['field_price_range']['id'] = 'field_price_range';
  $handler->display->display_options['fields']['field_price_range']['table'] = 'field_data_field_price_range';
  $handler->display->display_options['fields']['field_price_range']['field'] = 'field_price_range';
  $handler->display->display_options['fields']['field_price_range']['label'] = 'Price Range';
  $handler->display->display_options['fields']['field_price_range']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_price_range']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_price_range']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_price_range']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_price_range']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_price_range']['type'] = 'text_plain';
  /* Field: Content: Handbook */
  $handler->display->display_options['fields']['field_handbook']['id'] = 'field_handbook';
  $handler->display->display_options['fields']['field_handbook']['table'] = 'field_data_field_handbook';
  $handler->display->display_options['fields']['field_handbook']['field'] = 'field_handbook';
  $handler->display->display_options['fields']['field_handbook']['label'] = '';
  $handler->display->display_options['fields']['field_handbook']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_handbook']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_handbook']['alter']['text'] = 'Program Handbook';
  $handler->display->display_options['fields']['field_handbook']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_handbook']['alter']['path'] = '[field_handbook]';
  $handler->display->display_options['fields']['field_handbook']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_handbook']['alter']['alt'] = 'Program Handbook';
  $handler->display->display_options['fields']['field_handbook']['alter']['link_class'] = 'handbook';
  $handler->display->display_options['fields']['field_handbook']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_handbook']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_handbook']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_handbook']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_handbook']['type'] = 'file_url_plain';
  /* Field: File: Size */
  $handler->display->display_options['fields']['filesize']['id'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filesize']['field'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['relationship'] = 'field_handbook_fid';
  $handler->display->display_options['fields']['filesize']['label'] = '';
  $handler->display->display_options['fields']['filesize']['exclude'] = TRUE;
  $handler->display->display_options['fields']['filesize']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['filesize']['alter']['text'] = '([filesize])';
  $handler->display->display_options['fields']['filesize']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_program_image']['id'] = 'field_program_image';
  $handler->display->display_options['fields']['field_program_image']['table'] = 'field_data_field_program_image';
  $handler->display->display_options['fields']['field_program_image']['field'] = 'field_program_image';
  $handler->display->display_options['fields']['field_program_image']['label'] = '';
  $handler->display->display_options['fields']['field_program_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_program_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_program_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_program_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_program_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_program_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_program_image']['field_api_classes'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Short description of the program contents */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Long description */
  $handler->display->display_options['fields']['field_long_description']['id'] = 'field_long_description';
  $handler->display->display_options['fields']['field_long_description']['table'] = 'field_data_field_long_description';
  $handler->display->display_options['fields']['field_long_description']['field'] = 'field_long_description';
  $handler->display->display_options['fields']['field_long_description']['label'] = '';
  $handler->display->display_options['fields']['field_long_description']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_long_description']['element_class'] = 'program-[nid]-long-description program-long-description';
  $handler->display->display_options['fields']['field_long_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_long_description']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_long_description']['type'] = 'text_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Purchase';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'program/[nid]/buy';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Number of modules */
  $handler->display->display_options['fields']['field_number_of_modules']['id'] = 'field_number_of_modules';
  $handler->display->display_options['fields']['field_number_of_modules']['table'] = 'field_data_field_number_of_modules';
  $handler->display->display_options['fields']['field_number_of_modules']['field'] = 'field_number_of_modules';
  $handler->display->display_options['fields']['field_number_of_modules']['label'] = 'Number of Modules';
  $handler->display->display_options['fields']['field_number_of_modules']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_number_of_modules']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_number_of_modules']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_number_of_modules']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_number_of_modules']['type'] = 'text_plain';
  /* Field: Content: Completion time */
  $handler->display->display_options['fields']['field_completation_time']['id'] = 'field_completation_time';
  $handler->display->display_options['fields']['field_completation_time']['table'] = 'field_data_field_completation_time';
  $handler->display->display_options['fields']['field_completation_time']['field'] = 'field_completation_time';
  $handler->display->display_options['fields']['field_completation_time']['label'] = 'Completion Time';
  $handler->display->display_options['fields']['field_completation_time']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_completation_time']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_completation_time']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_completation_time']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_completation_time']['type'] = 'text_plain';
  /* Field: Content: Price range */
  $handler->display->display_options['fields']['field_price_range']['id'] = 'field_price_range';
  $handler->display->display_options['fields']['field_price_range']['table'] = 'field_data_field_price_range';
  $handler->display->display_options['fields']['field_price_range']['field'] = 'field_price_range';
  $handler->display->display_options['fields']['field_price_range']['label'] = 'Price Range';
  $handler->display->display_options['fields']['field_price_range']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_price_range']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_price_range']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_price_range']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_price_range']['type'] = 'text_plain';
  /* Field: Content: Handbook */
  $handler->display->display_options['fields']['field_handbook']['id'] = 'field_handbook';
  $handler->display->display_options['fields']['field_handbook']['table'] = 'field_data_field_handbook';
  $handler->display->display_options['fields']['field_handbook']['field'] = 'field_handbook';
  $handler->display->display_options['fields']['field_handbook']['label'] = '';
  $handler->display->display_options['fields']['field_handbook']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_handbook']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_handbook']['alter']['text'] = 'Program Handbook';
  $handler->display->display_options['fields']['field_handbook']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_handbook']['alter']['path'] = '[field_handbook]';
  $handler->display->display_options['fields']['field_handbook']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_handbook']['alter']['alt'] = 'Program Handbook';
  $handler->display->display_options['fields']['field_handbook']['alter']['link_class'] = 'handbook';
  $handler->display->display_options['fields']['field_handbook']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_handbook']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_handbook']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_handbook']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_handbook']['type'] = 'file_url_plain';
  /* Field: File: Size */
  $handler->display->display_options['fields']['filesize']['id'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filesize']['field'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['relationship'] = 'field_handbook_fid';
  $handler->display->display_options['fields']['filesize']['label'] = '';
  $handler->display->display_options['fields']['filesize']['exclude'] = TRUE;
  $handler->display->display_options['fields']['filesize']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['filesize']['alter']['text'] = '([filesize])';
  $handler->display->display_options['fields']['filesize']['element_label_colon'] = FALSE;
  /* Field: Content: Operator training program type */
  $handler->display->display_options['fields']['field_apply_rules']['id'] = 'field_apply_rules';
  $handler->display->display_options['fields']['field_apply_rules']['table'] = 'field_data_field_apply_rules';
  $handler->display->display_options['fields']['field_apply_rules']['field'] = 'field_apply_rules';
  $handler->display->display_options['fields']['field_apply_rules']['label'] = '';
  $handler->display->display_options['fields']['field_apply_rules']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_apply_rules']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_apply_rules']['element_default_classes'] = FALSE;
  $handler->display->display_options['path'] = 'programs';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Programs';
  $handler->display->display_options['menu']['weight'] = '-100';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['programs'] = array(
    t('Master'),
    t('Programs'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Programs description'),
    t('file from field_handbook'),
    t('More details'),
    t('Number of Modules'),
    t('Completion Time'),
    t('Price Range'),
    t('Program Handbook'),
    t('([filesize])'),
    t('Page'),
    t('Purchase'),
  );
  $export['programs'] = $view;

  $view = new view();
  $view->name = 'purchases';
  $view->description = 'Cloned view from commerce_backoffice_user_orders adapted to API site needs.';
  $view->tag = 'default';
  $view->base_table = 'commerce_order';
  $view->human_name = 'Purchases';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'My Orders';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view own commerce_order entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '';
  $handler->display->display_options['pager']['options']['tags']['next'] = '';
  $handler->display->display_options['pager']['options']['tags']['last'] = '';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'order_number' => 'order_number',
    'status' => 'status',
    'created' => 'created',
    'commerce_order_total' => 'created',
    'nothing' => 'created',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'order_number' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_order_total' => array(
      'sortable' => 0,
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
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'text';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['empty'] = TRUE;
  $handler->display->display_options['empty']['text']['content'] = 'No available information.';
  $handler->display->display_options['empty']['text']['format'] = 'plain_text';
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = 'Order #';
  $handler->display->display_options['fields']['order_number']['link_to_order'] = 'customer';
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Approved';
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Order Details';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = 'Date Purchased: [created]';
  $handler->display->display_options['fields']['created']['date_format'] = 'api_mm_dd_yyyy';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'M j, Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Commerce Order: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total';
  $handler->display->display_options['fields']['commerce_order_total']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['text'] = 'Order Total: [commerce_order_total]';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Payment Type';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Payment Type: Credit Card';
  /* Contextual filter: Commerce Order: Uid */
  $handler->display->display_options['arguments']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['arguments']['uid_1']['table'] = 'commerce_order';
  $handler->display->display_options['arguments']['uid_1']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid_1']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid_1']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Commerce Order: Order state */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['operator'] = 'not in';
  $handler->display->display_options['filters']['state']['value'] = array(
    'cart' => 'cart',
    'checkout' => 'checkout',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Purchases';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'order_number' => 'order_number',
    'status' => 'status',
    'created' => 'created',
    'commerce_order_total' => 'created',
    'nothing' => 'created',
    'nothing_1' => 'nothing_1',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'order_number' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_order_total' => array(
      'sortable' => 0,
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
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = 'Order #';
  $handler->display->display_options['fields']['order_number']['link_to_order'] = 'customer';
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Approved';
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Order Details';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = 'Date Purchased: [created]';
  $handler->display->display_options['fields']['created']['date_format'] = 'api_mm_dd_yyyy';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'M j, Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Commerce Order: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total';
  $handler->display->display_options['fields']['commerce_order_total']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['text'] = '<br />Order Total: [commerce_order_total]';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Payment Type';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<br />Payment Type: Credit Card';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Operations';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'purchases_%timestamp-full.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'user/%/purchases/csv';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'block_1' => 0,
  );
  $translatables['purchases'] = array(
    t('Defaults'),
    t('My Orders'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('No available information.'),
    t('Order #'),
    t('Approved'),
    t('Order Details'),
    t('Date Purchased: [created]'),
    t('Total'),
    t('Order Total: [commerce_order_total]'),
    t('Payment Type'),
    t('Payment Type: Credit Card'),
    t('All'),
    t('Block'),
    t('Purchases'),
    t('<br />Order Total: [commerce_order_total]'),
    t('<br />Payment Type: Credit Card'),
    t('Operations'),
    t('Data export'),
  );
  $export['purchases'] = $view;

  $view = new view();
  $view->name = 'safety_keys';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_safety_key';
  $view->human_name = 'Safety Keys';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Safety Keys';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view own safety keys';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Safety Key: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'eck_safety_key';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Safety Key: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Safety Key: Number */
  $handler->display->display_options['fields']['number']['id'] = 'number';
  $handler->display->display_options['fields']['number']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['number']['field'] = 'number';
  $handler->display->display_options['fields']['number']['separator'] = '';
  /* Field: Field: Program */
  $handler->display->display_options['fields']['field_program']['id'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['table'] = 'field_data_field_program';
  $handler->display->display_options['fields']['field_program']['field'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['label'] = 'Associated Course';
  $handler->display->display_options['fields']['field_program']['element_type'] = '0';
  $handler->display->display_options['fields']['field_program']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_program']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_program']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program']['field_api_classes'] = TRUE;
  /* Field: Safety Key: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Issued Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Safety Key: Expiration date */
  $handler->display->display_options['fields']['field_key_expiration_date']['id'] = 'field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['table'] = 'field_data_field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['field'] = 'field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['label'] = 'Expiration Date';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_key_expiration_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_key_expiration_date']['field_api_classes'] = TRUE;
  /* Sort criterion: Safety Key: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'eck_safety_key';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Safety Key: Author */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'eck_safety_key';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';

  /* Display: User Safety Keys */
  $handler = $view->new_display('page', 'User Safety Keys', 'user_safety_keys_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Safety Keys';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view own safety keys';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'number' => 'number',
    'field_program' => 'field_program',
    'created' => 'created',
    'field_key_expiration_date' => 'field_key_expiration_date',
    'nothing' => 'nothing_1',
    'nothing_1' => 'nothing_1',
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
    'number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_program' => array(
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
    'field_key_expiration_date' => array(
      'sortable' => 0,
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
    'nothing_1' => array(
      'align' => '',
      'separator' => ' - ',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Safety Key: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Safety Key: Number */
  $handler->display->display_options['fields']['number']['id'] = 'number';
  $handler->display->display_options['fields']['number']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['number']['field'] = 'number';
  $handler->display->display_options['fields']['number']['separator'] = '';
  /* Field: Field: Program */
  $handler->display->display_options['fields']['field_program']['id'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['table'] = 'field_data_field_program';
  $handler->display->display_options['fields']['field_program']['field'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['label'] = 'Associated Course';
  $handler->display->display_options['fields']['field_program']['element_type'] = '0';
  $handler->display->display_options['fields']['field_program']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_program']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_program']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program']['field_api_classes'] = TRUE;
  /* Field: Safety Key: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Issued Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'api_mm_dd_yyyy';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Safety Key: Expiration date */
  $handler->display->display_options['fields']['field_key_expiration_date']['id'] = 'field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['table'] = 'field_data_field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['field'] = 'field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['label'] = 'Expiration Date';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_key_expiration_date']['settings'] = array(
    'format_type' => 'api_mm_dd_yyyy',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_key_expiration_date']['field_api_classes'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'View';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'user/!1/safety_keys/[number]/view';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Print';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Print Certificate';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'user/!1/safety_keys/[number]/print';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Safety Key: Author */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'eck_safety_key';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['uid']['validate_options']['code'] = 'global $user;
if($user->uid == $argument || user_access(\'admin safety keys\')) {
return TRUE;
}
return FALSE;';
  $handler->display->display_options['arguments']['uid']['validate']['fail'] = 'access denied';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Safety Key: Expiration date (field_key_expiration_date) */
  $handler->display->display_options['filters']['field_key_expiration_date_value']['id'] = 'field_key_expiration_date_value';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['table'] = 'field_data_field_key_expiration_date';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['field'] = 'field_key_expiration_date_value';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['default_date'] = 'now';
  $handler->display->display_options['path'] = 'user/%/safety_keys';
  $handler->display->display_options['menu']['title'] = 'My Safety Keys';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: eMaintenance Report */
  $handler = $view->new_display('page', 'eMaintenance Report', 'admin_safety_keys_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'eMaintenance Report';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'admin safety keys';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'number' => 'number',
    'number_1' => 'number_1',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_first_name',
    'field_safety_company' => 'field_safety_company',
    'field_program' => 'field_program',
    'created' => 'created',
    'field_key_expiration_date' => 'field_key_expiration_date',
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
    'number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'number_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_safety_company' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_program' => array(
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
    'field_key_expiration_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Safety Key: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'SafetyPassportUserID';
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Safety Key: Number */
  $handler->display->display_options['fields']['number']['id'] = 'number';
  $handler->display->display_options['fields']['number']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['number']['field'] = 'number';
  $handler->display->display_options['fields']['number']['label'] = 'SafetyPassportNumber';
  $handler->display->display_options['fields']['number']['separator'] = '';
  /* Field: Safety Key: Number */
  $handler->display->display_options['fields']['number_1']['id'] = 'number_1';
  $handler->display->display_options['fields']['number_1']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['number_1']['field'] = 'number';
  $handler->display->display_options['fields']['number_1']['label'] = 'SafetyPassportAltNumber';
  $handler->display->display_options['fields']['number_1']['separator'] = '';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'SafetyPassportUsername';
  $handler->display->display_options['fields']['field_first_name']['type'] = 'text_plain';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['type'] = 'text_plain';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  $handler->display->display_options['fields']['mail']['label'] = 'SafetyPassportUseremail';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: Safety Key: Company */
  $handler->display->display_options['fields']['field_safety_company']['id'] = 'field_safety_company';
  $handler->display->display_options['fields']['field_safety_company']['table'] = 'field_data_field_safety_company';
  $handler->display->display_options['fields']['field_safety_company']['field'] = 'field_safety_company';
  $handler->display->display_options['fields']['field_safety_company']['label'] = 'SafetyPassportCompany';
  $handler->display->display_options['fields']['field_safety_company']['element_type'] = '0';
  $handler->display->display_options['fields']['field_safety_company']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_safety_company']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_safety_company']['field_api_classes'] = TRUE;
  /* Field: Safety Key: Expiration date */
  $handler->display->display_options['fields']['field_key_expiration_date']['id'] = 'field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['table'] = 'field_data_field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['field'] = 'field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['label'] = 'SafetyPassportExpiryDate';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_key_expiration_date']['settings'] = array(
    'format_type' => 'api_short_d_M_y',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_key_expiration_date']['field_api_classes'] = TRUE;
  /* Field: Field: Program */
  $handler->display->display_options['fields']['field_program']['id'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['table'] = 'field_data_field_program';
  $handler->display->display_options['fields']['field_program']['field'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['label'] = 'Associated Course';
  $handler->display->display_options['fields']['field_program']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_program']['element_type'] = '0';
  $handler->display->display_options['fields']['field_program']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_program']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_program']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program']['field_api_classes'] = TRUE;
  /* Field: Safety Key: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Issued Date';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['date_format'] = 'api_mm_dd_yyyy';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Field: Program (field_program) */
  $handler->display->display_options['filters']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['filters']['field_program_target_id']['field'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator_id'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['label'] = 'Program';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['identifier'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    5 => 0,
  );
  /* Filter criterion: Safety Key: Expiration date (field_key_expiration_date) */
  $handler->display->display_options['filters']['field_key_expiration_date_value']['id'] = 'field_key_expiration_date_value';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['table'] = 'field_data_field_key_expiration_date';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['field'] = 'field_key_expiration_date_value';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['default_date'] = 'now';
  $handler->display->display_options['path'] = 'admin/config/api/emaintenance-report';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'eMaintenance Report';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Safety Key Page */
  $handler = $view->new_display('page', 'Safety Key Page', 'safety_key_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Safety Key';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Safety Key: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Safety Key: Number */
  $handler->display->display_options['fields']['number']['id'] = 'number';
  $handler->display->display_options['fields']['number']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['number']['field'] = 'number';
  $handler->display->display_options['fields']['number']['label'] = 'Safety Key';
  $handler->display->display_options['fields']['number']['element_type'] = '0';
  $handler->display->display_options['fields']['number']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['number']['separator'] = '';
  /* Field: Field: Program */
  $handler->display->display_options['fields']['field_program']['id'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['table'] = 'field_data_field_program';
  $handler->display->display_options['fields']['field_program']['field'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['label'] = 'Associated Course';
  $handler->display->display_options['fields']['field_program']['element_type'] = '0';
  $handler->display->display_options['fields']['field_program']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_program']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_program']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_program']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: Type */
  $handler->display->display_options['fields']['field_operator_type']['id'] = 'field_operator_type';
  $handler->display->display_options['fields']['field_operator_type']['table'] = 'field_data_field_operator_type';
  $handler->display->display_options['fields']['field_operator_type']['field'] = 'field_operator_type';
  $handler->display->display_options['fields']['field_operator_type']['label'] = '';
  $handler->display->display_options['fields']['field_operator_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_operator_type']['alter']['text'] = '[field_operator_type], ';
  $handler->display->display_options['fields']['field_operator_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_operator_type']['element_default_classes'] = FALSE;
  /* Field: Field: State */
  $handler->display->display_options['fields']['field_state']['id'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['table'] = 'field_data_field_state';
  $handler->display->display_options['fields']['field_state']['field'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['label'] = '';
  $handler->display->display_options['fields']['field_state']['element_type'] = '0';
  $handler->display->display_options['fields']['field_state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_state']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_state']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_state']['field_api_classes'] = TRUE;
  /* Field: Safety Key: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Issued Date';
  $handler->display->display_options['fields']['created']['element_type'] = '0';
  $handler->display->display_options['fields']['created']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['created']['date_format'] = 'api_mm_dd_yyyy';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Safety Key: Expiration date */
  $handler->display->display_options['fields']['field_key_expiration_date']['id'] = 'field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['table'] = 'field_data_field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['field'] = 'field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['label'] = 'Expiration Date';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_key_expiration_date']['settings'] = array(
    'format_type' => 'api_mm_dd_yyyy',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Safety Key: Author */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['separator'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Safety Key: Author */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'eck_safety_key';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['uid']['validate_options']['code'] = 'global $user;
if($user->uid == $argument || in_array(\'company admin\', $user->roles)) {
return TRUE;
}
return FALSE;';
  $handler->display->display_options['arguments']['uid']['validate']['fail'] = 'access denied';
  /* Contextual filter: Safety Key: Number */
  $handler->display->display_options['arguments']['number']['id'] = 'number';
  $handler->display->display_options['arguments']['number']['table'] = 'eck_safety_key';
  $handler->display->display_options['arguments']['number']['field'] = 'number';
  $handler->display->display_options['arguments']['number']['default_action'] = 'default';
  $handler->display->display_options['arguments']['number']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['number']['default_argument_options']['index'] = '3';
  $handler->display->display_options['arguments']['number']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['number']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['number']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Safety Key: Expiration date (field_key_expiration_date) */
  $handler->display->display_options['filters']['field_key_expiration_date_value']['id'] = 'field_key_expiration_date_value';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['table'] = 'field_data_field_key_expiration_date';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['field'] = 'field_key_expiration_date_value';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['default_date'] = 'now';
  $handler->display->display_options['path'] = 'user/%/safety_keys/%/view';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'My Safety Keys';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Customer Support Block */
  $handler = $view->new_display('block', 'Customer Support Block', 'customer_support_block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'number' => 'number',
    'field_program' => 'field_program',
    'field_state' => 'field_program',
    'field_operator_type' => 'field_program',
    'created' => 'created',
    'field_key_expiration_date' => 'field_key_expiration_date',
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
    'number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_program' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_operator_type' => array(
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
    'field_key_expiration_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Title';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h2>Safety Keys</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No available information.';
  $handler->display->display_options['empty']['area']['format'] = 'commerce_order_message';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Safety Key: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Safety Key: Number */
  $handler->display->display_options['fields']['number']['id'] = 'number';
  $handler->display->display_options['fields']['number']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['number']['field'] = 'number';
  $handler->display->display_options['fields']['number']['label'] = 'Safety Key Number';
  $handler->display->display_options['fields']['number']['separator'] = '';
  /* Field: Safety Key: Company */
  $handler->display->display_options['fields']['field_safety_company']['id'] = 'field_safety_company';
  $handler->display->display_options['fields']['field_safety_company']['table'] = 'field_data_field_safety_company';
  $handler->display->display_options['fields']['field_safety_company']['field'] = 'field_safety_company';
  $handler->display->display_options['fields']['field_safety_company']['element_type'] = '0';
  $handler->display->display_options['fields']['field_safety_company']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_safety_company']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_safety_company']['field_api_classes'] = TRUE;
  /* Field: Field: Program */
  $handler->display->display_options['fields']['field_program']['id'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['table'] = 'field_data_field_program';
  $handler->display->display_options['fields']['field_program']['field'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['element_type'] = '0';
  $handler->display->display_options['fields']['field_program']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_program']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_program']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program']['field_api_classes'] = TRUE;
  /* Field: Field: State */
  $handler->display->display_options['fields']['field_state']['id'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['table'] = 'field_data_field_state';
  $handler->display->display_options['fields']['field_state']['field'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['label'] = '';
  $handler->display->display_options['fields']['field_state']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_state']['element_default_classes'] = FALSE;
  /* Field: Field: Type */
  $handler->display->display_options['fields']['field_operator_type']['id'] = 'field_operator_type';
  $handler->display->display_options['fields']['field_operator_type']['table'] = 'field_data_field_operator_type';
  $handler->display->display_options['fields']['field_operator_type']['field'] = 'field_operator_type';
  $handler->display->display_options['fields']['field_operator_type']['label'] = '';
  $handler->display->display_options['fields']['field_operator_type']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_operator_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_operator_type']['field_api_classes'] = TRUE;
  /* Field: Safety Key: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Safety key Issued date';
  $handler->display->display_options['fields']['created']['date_format'] = 'api_mm_dd_yyyy';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Safety Key: Expiration date */
  $handler->display->display_options['fields']['field_key_expiration_date']['id'] = 'field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['table'] = 'field_data_field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['field'] = 'field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['label'] = 'Safety key Expiration date';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_key_expiration_date']['settings'] = array(
    'format_type' => 'api_mm_dd_yyyy',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_key_expiration_date']['field_api_classes'] = TRUE;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'safety-keys-%timestamp-yyyy-%timestamp-mm-%timestamp-dd.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Safety Key: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: User revision: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'user_revision';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
  $handler->display->display_options['fields']['name']['link_to_user_revision'] = 0;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['field_api_classes'] = TRUE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['field_api_classes'] = TRUE;
  /* Field: User: Company Name */
  $handler->display->display_options['fields']['field_company_name']['id'] = 'field_company_name';
  $handler->display->display_options['fields']['field_company_name']['table'] = 'field_data_field_company_name';
  $handler->display->display_options['fields']['field_company_name']['field'] = 'field_company_name';
  $handler->display->display_options['fields']['field_company_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_company_name']['label'] = 'Current Company';
  $handler->display->display_options['fields']['field_company_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_company_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_company_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_company_name']['field_api_classes'] = TRUE;
  /* Field: Safety Key: Number */
  $handler->display->display_options['fields']['number']['id'] = 'number';
  $handler->display->display_options['fields']['number']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['number']['field'] = 'number';
  $handler->display->display_options['fields']['number']['label'] = 'Safety Key Number';
  $handler->display->display_options['fields']['number']['separator'] = '';
  /* Field: Safety Key: Company */
  $handler->display->display_options['fields']['field_safety_company']['id'] = 'field_safety_company';
  $handler->display->display_options['fields']['field_safety_company']['table'] = 'field_data_field_safety_company';
  $handler->display->display_options['fields']['field_safety_company']['field'] = 'field_safety_company';
  $handler->display->display_options['fields']['field_safety_company']['element_type'] = '0';
  $handler->display->display_options['fields']['field_safety_company']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_safety_company']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_safety_company']['field_api_classes'] = TRUE;
  /* Field: Field: State */
  $handler->display->display_options['fields']['field_state']['id'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['table'] = 'field_data_field_state';
  $handler->display->display_options['fields']['field_state']['field'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['label'] = '';
  $handler->display->display_options['fields']['field_state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_state']['element_default_classes'] = FALSE;
  /* Field: Field: Type */
  $handler->display->display_options['fields']['field_operator_type']['id'] = 'field_operator_type';
  $handler->display->display_options['fields']['field_operator_type']['table'] = 'field_data_field_operator_type';
  $handler->display->display_options['fields']['field_operator_type']['field'] = 'field_operator_type';
  $handler->display->display_options['fields']['field_operator_type']['label'] = '';
  $handler->display->display_options['fields']['field_operator_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_operator_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_operator_type']['element_default_classes'] = FALSE;
  /* Field: Field: Program */
  $handler->display->display_options['fields']['field_program']['id'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['table'] = 'field_data_field_program';
  $handler->display->display_options['fields']['field_program']['field'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_program']['alter']['text'] = '[field_program]
[field_state]
[field_operator_type]';
  $handler->display->display_options['fields']['field_program']['element_type'] = '0';
  $handler->display->display_options['fields']['field_program']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_program']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_program']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program']['field_api_classes'] = TRUE;
  /* Field: Safety Key: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Safety key Issued date';
  $handler->display->display_options['fields']['created']['date_format'] = 'api_mm_dd_yyyy';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Safety Key: Expiration date */
  $handler->display->display_options['fields']['field_key_expiration_date']['id'] = 'field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['table'] = 'field_data_field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['field'] = 'field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['label'] = 'Safety key Expiration date';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_key_expiration_date']['settings'] = array(
    'format_type' => 'api_mm_dd_yyyy',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_key_expiration_date']['field_api_classes'] = TRUE;
  $handler->display->display_options['path'] = 'admin/people/customer-support/%/safety-keys/xls';

  /* Display: Profile Block */
  $handler = $view->new_display('block', 'Profile Block', 'block_safety_keys');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'number' => 'number',
    'field_program' => 'field_program',
    'created' => 'created',
    'field_key_expiration_date' => 'field_key_expiration_date',
    'nothing' => 'nothing_1',
    'nothing_1' => 'nothing_1',
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
    'number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_program' => array(
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
    'field_key_expiration_date' => array(
      'sortable' => 0,
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
    'nothing_1' => array(
      'align' => '',
      'separator' => ' - ',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No available information.';
  $handler->display->display_options['empty']['area']['format'] = 'commerce_order_message';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Safety Key: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Safety Key: Number */
  $handler->display->display_options['fields']['number']['id'] = 'number';
  $handler->display->display_options['fields']['number']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['number']['field'] = 'number';
  $handler->display->display_options['fields']['number']['separator'] = '';
  /* Field: Field: Program */
  $handler->display->display_options['fields']['field_program']['id'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['table'] = 'field_data_field_program';
  $handler->display->display_options['fields']['field_program']['field'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['label'] = 'Associated Course';
  $handler->display->display_options['fields']['field_program']['element_type'] = '0';
  $handler->display->display_options['fields']['field_program']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_program']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_program']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program']['field_api_classes'] = TRUE;
  /* Field: Safety Key: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Issued Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'api_mm_dd_yyyy';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Safety Key: Expiration date */
  $handler->display->display_options['fields']['field_key_expiration_date']['id'] = 'field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['table'] = 'field_data_field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['field'] = 'field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['label'] = 'Expiration Date';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_key_expiration_date']['settings'] = array(
    'format_type' => 'api_mm_dd_yyyy',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_key_expiration_date']['field_api_classes'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'View';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'user/!1/safety_keys/[number]/view';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Print';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Print Certificate';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'user/!1/safety_keys/[number]/print';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Safety Key: Expiration date (field_key_expiration_date) */
  $handler->display->display_options['filters']['field_key_expiration_date_value']['id'] = 'field_key_expiration_date_value';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['table'] = 'field_data_field_key_expiration_date';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['field'] = 'field_key_expiration_date_value';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['default_date'] = 'now';

  /* Display: Safety Key Page for Company Admin */
  $handler = $view->new_display('page', 'Safety Key Page for Company Admin', 'company_admin_safety_key_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Safety Key';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Safety Key: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Safety Key: Number */
  $handler->display->display_options['fields']['number']['id'] = 'number';
  $handler->display->display_options['fields']['number']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['number']['field'] = 'number';
  $handler->display->display_options['fields']['number']['label'] = 'Safety Key';
  $handler->display->display_options['fields']['number']['element_type'] = '0';
  $handler->display->display_options['fields']['number']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['number']['separator'] = '';
  /* Field: Field: Program */
  $handler->display->display_options['fields']['field_program']['id'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['table'] = 'field_data_field_program';
  $handler->display->display_options['fields']['field_program']['field'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['label'] = 'Associated Course';
  $handler->display->display_options['fields']['field_program']['element_type'] = '0';
  $handler->display->display_options['fields']['field_program']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_program']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_program']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_program']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: Type */
  $handler->display->display_options['fields']['field_operator_type']['id'] = 'field_operator_type';
  $handler->display->display_options['fields']['field_operator_type']['table'] = 'field_data_field_operator_type';
  $handler->display->display_options['fields']['field_operator_type']['field'] = 'field_operator_type';
  $handler->display->display_options['fields']['field_operator_type']['label'] = '';
  $handler->display->display_options['fields']['field_operator_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_operator_type']['alter']['text'] = '[field_operator_type], ';
  $handler->display->display_options['fields']['field_operator_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_operator_type']['element_default_classes'] = FALSE;
  /* Field: Field: State */
  $handler->display->display_options['fields']['field_state']['id'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['table'] = 'field_data_field_state';
  $handler->display->display_options['fields']['field_state']['field'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['label'] = '';
  $handler->display->display_options['fields']['field_state']['element_type'] = '0';
  $handler->display->display_options['fields']['field_state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_state']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_state']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_state']['field_api_classes'] = TRUE;
  /* Field: Safety Key: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Issued Date';
  $handler->display->display_options['fields']['created']['element_type'] = '0';
  $handler->display->display_options['fields']['created']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['created']['date_format'] = 'api_mm_dd_yyyy';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Safety Key: Expiration date */
  $handler->display->display_options['fields']['field_key_expiration_date']['id'] = 'field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['table'] = 'field_data_field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['field'] = 'field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['label'] = 'Expiration Date';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_key_expiration_date']['settings'] = array(
    'format_type' => 'api_mm_dd_yyyy',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Safety Key: Author */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['separator'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Safety Key: Number */
  $handler->display->display_options['arguments']['number']['id'] = 'number';
  $handler->display->display_options['arguments']['number']['table'] = 'eck_safety_key';
  $handler->display->display_options['arguments']['number']['field'] = 'number';
  $handler->display->display_options['arguments']['number']['default_action'] = 'default';
  $handler->display->display_options['arguments']['number']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['number']['default_argument_options']['index'] = '3';
  $handler->display->display_options['arguments']['number']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['number']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['number']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['path'] = 'safety-key-company/%';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'My Safety Keys';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Directory company block */
  $handler = $view->new_display('block', 'Directory company block', 'directory_search_block');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'number' => 'number',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_safety_company' => 'field_safety_company',
    'field_program' => 'field_program',
    'created' => 'created',
    'field_key_expiration_date' => 'field_key_expiration_date',
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
    'number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_safety_company' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_program' => array(
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
    'field_key_expiration_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Safety Key: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Safety Key: Number */
  $handler->display->display_options['fields']['number']['id'] = 'number';
  $handler->display->display_options['fields']['number']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['number']['field'] = 'number';
  $handler->display->display_options['fields']['number']['separator'] = '';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_last_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['field_api_classes'] = TRUE;
  /* Field: Safety Key: Company */
  $handler->display->display_options['fields']['field_safety_company']['id'] = 'field_safety_company';
  $handler->display->display_options['fields']['field_safety_company']['table'] = 'field_data_field_safety_company';
  $handler->display->display_options['fields']['field_safety_company']['field'] = 'field_safety_company';
  $handler->display->display_options['fields']['field_safety_company']['label'] = 'Company Name';
  $handler->display->display_options['fields']['field_safety_company']['element_type'] = '0';
  $handler->display->display_options['fields']['field_safety_company']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_safety_company']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_safety_company']['field_api_classes'] = TRUE;
  /* Field: Field: Program */
  $handler->display->display_options['fields']['field_program']['id'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['table'] = 'field_data_field_program';
  $handler->display->display_options['fields']['field_program']['field'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['label'] = 'Associated Course';
  $handler->display->display_options['fields']['field_program']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_program']['element_type'] = '0';
  $handler->display->display_options['fields']['field_program']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_program']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_program']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program']['field_api_classes'] = TRUE;
  /* Field: Safety Key: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Issued Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'api_mm_dd_yyyy';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Safety Key: Expiration date */
  $handler->display->display_options['fields']['field_key_expiration_date']['id'] = 'field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['table'] = 'field_data_field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['field'] = 'field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['label'] = 'Expiration Date';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_key_expiration_date']['settings'] = array(
    'format_type' => 'api_mm_dd_yyyy',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_key_expiration_date']['field_api_classes'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Safety Key: Company (field_safety_company) */
  $handler->display->display_options['arguments']['field_safety_company_value']['id'] = 'field_safety_company_value';
  $handler->display->display_options['arguments']['field_safety_company_value']['table'] = 'field_data_field_safety_company';
  $handler->display->display_options['arguments']['field_safety_company_value']['field'] = 'field_safety_company_value';
  $handler->display->display_options['arguments']['field_safety_company_value']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_safety_company_value']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_safety_company_value']['default_argument_options']['index'] = '0';
  $handler->display->display_options['arguments']['field_safety_company_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_safety_company_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_safety_company_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_safety_company_value']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Safety Key: Expiration date (field_key_expiration_date) */
  $handler->display->display_options['filters']['field_key_expiration_date_value']['id'] = 'field_key_expiration_date_value';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['table'] = 'field_data_field_key_expiration_date';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['field'] = 'field_key_expiration_date_value';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['default_date'] = 'now';

  /* Display: Directory export */
  $handler = $view->new_display('views_data_export', 'Directory export', 'directory_export');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%1-value - safety keys.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Safety Key: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Safety Key: Number */
  $handler->display->display_options['fields']['number']['id'] = 'number';
  $handler->display->display_options['fields']['number']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['number']['field'] = 'number';
  $handler->display->display_options['fields']['number']['separator'] = '';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_last_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['field_api_classes'] = TRUE;
  /* Field: Safety Key: Company */
  $handler->display->display_options['fields']['field_safety_company']['id'] = 'field_safety_company';
  $handler->display->display_options['fields']['field_safety_company']['table'] = 'field_data_field_safety_company';
  $handler->display->display_options['fields']['field_safety_company']['field'] = 'field_safety_company';
  $handler->display->display_options['fields']['field_safety_company']['label'] = 'Company Name';
  $handler->display->display_options['fields']['field_safety_company']['element_type'] = '0';
  $handler->display->display_options['fields']['field_safety_company']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_safety_company']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_safety_company']['field_api_classes'] = TRUE;
  /* Field: Field: Program */
  $handler->display->display_options['fields']['field_program']['id'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['table'] = 'field_data_field_program';
  $handler->display->display_options['fields']['field_program']['field'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['label'] = 'Associated Course';
  $handler->display->display_options['fields']['field_program']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_program']['element_type'] = '0';
  $handler->display->display_options['fields']['field_program']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_program']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_program']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program']['field_api_classes'] = TRUE;
  /* Field: Safety Key: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Issued Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'api_mm_dd_yyyy';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Safety Key: Expiration date */
  $handler->display->display_options['fields']['field_key_expiration_date']['id'] = 'field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['table'] = 'field_data_field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['field'] = 'field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['label'] = 'Expiration Date';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_key_expiration_date']['settings'] = array(
    'format_type' => 'api_mm_dd_yyyy',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_key_expiration_date']['field_api_classes'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Safety Key: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'eck_safety_key';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Safety Key: Company (field_safety_company) */
  $handler->display->display_options['arguments']['field_safety_company_value']['id'] = 'field_safety_company_value';
  $handler->display->display_options['arguments']['field_safety_company_value']['table'] = 'field_data_field_safety_company';
  $handler->display->display_options['arguments']['field_safety_company_value']['field'] = 'field_safety_company_value';
  $handler->display->display_options['arguments']['field_safety_company_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_safety_company_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_safety_company_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_safety_company_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_safety_company_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_safety_company_value']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Safety Key: Expiration date (field_key_expiration_date) */
  $handler->display->display_options['filters']['field_key_expiration_date_value']['id'] = 'field_key_expiration_date_value';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['table'] = 'field_data_field_key_expiration_date';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['field'] = 'field_key_expiration_date_value';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['default_date'] = 'now';
  $handler->display->display_options['path'] = 'directory/search/export/%';

  /* Display: Safety Key */
  $handler = $view->new_display('page', 'Safety Key', 'safety_key_verification');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Safety Key';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Verify';
  $handler->display->display_options['exposed_form']['options']['text_input_required'] = '';
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'commerce_order_message';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No valid Safety Key found.';
  $handler->display->display_options['empty']['area']['format'] = 'commerce_order_message';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Safety Key: Number */
  $handler->display->display_options['fields']['number']['id'] = 'number';
  $handler->display->display_options['fields']['number']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['number']['field'] = 'number';
  $handler->display->display_options['fields']['number']['label'] = 'ID';
  $handler->display->display_options['fields']['number']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['number']['separator'] = '';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_first_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['field_api_classes'] = TRUE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  /* Field: Safety Key: Company */
  $handler->display->display_options['fields']['field_safety_company']['id'] = 'field_safety_company';
  $handler->display->display_options['fields']['field_safety_company']['table'] = 'field_data_field_safety_company';
  $handler->display->display_options['fields']['field_safety_company']['field'] = 'field_safety_company';
  $handler->display->display_options['fields']['field_safety_company']['label'] = 'Company Name';
  $handler->display->display_options['fields']['field_safety_company']['element_default_classes'] = FALSE;
  /* Field: Safety Key: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Issued Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'api_mm_dd_yyyy';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Safety Key: Expiration date */
  $handler->display->display_options['fields']['field_key_expiration_date']['id'] = 'field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['table'] = 'field_data_field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['field'] = 'field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['label'] = 'Expiration Date';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_key_expiration_date']['settings'] = array(
    'format_type' => 'api_mm_dd_yyyy',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_key_expiration_date']['field_api_classes'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Safety Key: Expiration date (field_key_expiration_date) */
  $handler->display->display_options['filters']['field_key_expiration_date_value']['id'] = 'field_key_expiration_date_value';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['table'] = 'field_data_field_key_expiration_date';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['field'] = 'field_key_expiration_date_value';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['default_date'] = 'now';
  /* Filter criterion: Safety Key: Number */
  $handler->display->display_options['filters']['number']['id'] = 'number';
  $handler->display->display_options['filters']['number']['table'] = 'eck_safety_key';
  $handler->display->display_options['filters']['number']['field'] = 'number';
  $handler->display->display_options['filters']['number']['exposed'] = TRUE;
  $handler->display->display_options['filters']['number']['expose']['operator_id'] = 'number_op';
  $handler->display->display_options['filters']['number']['expose']['label'] = 'Safety Key';
  $handler->display->display_options['filters']['number']['expose']['operator'] = 'number_op';
  $handler->display->display_options['filters']['number']['expose']['identifier'] = 'number';
  $handler->display->display_options['filters']['number']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    7 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
  );
  $handler->display->display_options['path'] = 'search/safety_key';
  $handler->display->display_options['menu']['title'] = 'My Safety Keys';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: eMaintenance export */
  $handler = $view->new_display('views_data_export', 'eMaintenance export', 'emaintenance_export');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'eMaintenance Report';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'admin safety keys';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5000';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'safety_keys.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Safety Key: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'SafetyPassportUserID';
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Safety Key: Number */
  $handler->display->display_options['fields']['number']['id'] = 'number';
  $handler->display->display_options['fields']['number']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['number']['field'] = 'number';
  $handler->display->display_options['fields']['number']['label'] = 'SafetyPassportNumber';
  $handler->display->display_options['fields']['number']['separator'] = '';
  /* Field: Safety Key: Number */
  $handler->display->display_options['fields']['number_1']['id'] = 'number_1';
  $handler->display->display_options['fields']['number_1']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['number_1']['field'] = 'number';
  $handler->display->display_options['fields']['number_1']['label'] = 'SafetyPassportAltNumber';
  $handler->display->display_options['fields']['number_1']['separator'] = '';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_last_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['field_api_classes'] = TRUE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'SafetyPassportUsername';
  $handler->display->display_options['fields']['field_first_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['alter']['text'] = '[field_first_name] [field_last_name]';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  $handler->display->display_options['fields']['mail']['label'] = 'SafetyPassportUseremail';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: Safety Key: Company */
  $handler->display->display_options['fields']['field_safety_company']['id'] = 'field_safety_company';
  $handler->display->display_options['fields']['field_safety_company']['table'] = 'field_data_field_safety_company';
  $handler->display->display_options['fields']['field_safety_company']['field'] = 'field_safety_company';
  $handler->display->display_options['fields']['field_safety_company']['label'] = 'SafetyPassportCompany';
  $handler->display->display_options['fields']['field_safety_company']['element_type'] = '0';
  $handler->display->display_options['fields']['field_safety_company']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_safety_company']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_safety_company']['field_api_classes'] = TRUE;
  /* Field: Field: Program */
  $handler->display->display_options['fields']['field_program']['id'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['table'] = 'field_data_field_program';
  $handler->display->display_options['fields']['field_program']['field'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['label'] = 'Associated Course';
  $handler->display->display_options['fields']['field_program']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_program']['element_type'] = '0';
  $handler->display->display_options['fields']['field_program']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_program']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_program']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program']['field_api_classes'] = TRUE;
  /* Field: Safety Key: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_safety_key';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Issued Date';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['date_format'] = 'api_mm_dd_yyyy';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Safety Key: Expiration date */
  $handler->display->display_options['fields']['field_key_expiration_date']['id'] = 'field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['table'] = 'field_data_field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['field'] = 'field_key_expiration_date';
  $handler->display->display_options['fields']['field_key_expiration_date']['label'] = 'SafetyPassportExpiryDate';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_key_expiration_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_key_expiration_date']['settings'] = array(
    'format_type' => 'api_short_d_M_y',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_key_expiration_date']['field_api_classes'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Field: Program (field_program) */
  $handler->display->display_options['filters']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['filters']['field_program_target_id']['field'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator_id'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['label'] = 'Program';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['identifier'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    5 => 0,
  );
  /* Filter criterion: Safety Key: Expiration date (field_key_expiration_date) */
  $handler->display->display_options['filters']['field_key_expiration_date_value']['id'] = 'field_key_expiration_date_value';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['table'] = 'field_data_field_key_expiration_date';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['field'] = 'field_key_expiration_date_value';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_key_expiration_date_value']['default_date'] = 'now';
  $handler->display->display_options['path'] = 'admin/config/api/emaintenance-report/export';
  $handler->display->display_options['displays'] = array(
    'admin_safety_keys_page' => 'admin_safety_keys_page',
    'default' => 0,
    'user_safety_keys_page' => 0,
    'safety_key_page' => 0,
    'customer_support_block' => 0,
    'block_safety_keys' => 0,
    'company_admin_safety_key_page' => 0,
    'directory_search_block' => 0,
    'safety_key_verification' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $translatables['safety_keys'] = array(
    t('Master'),
    t('Safety Keys'),
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
    t('User'),
    t('Id'),
    t('.'),
    t(','),
    t('Number'),
    t('Associated Course'),
    t('Issued Date'),
    t('Expiration Date'),
    t('All'),
    t('User Safety Keys'),
    t('My Safety Keys'),
    t('View'),
    t('Print'),
    t('Print Certificate'),
    t('eMaintenance Report'),
    t('SafetyPassportUserID'),
    t('SafetyPassportNumber'),
    t('SafetyPassportAltNumber'),
    t('SafetyPassportUsername'),
    t('Last Name'),
    t('SafetyPassportUseremail'),
    t('SafetyPassportCompany'),
    t('SafetyPassportExpiryDate'),
    t('Program'),
    t('Safety Key Page'),
    t('Safety Key'),
    t('[field_operator_type], '),
    t('Customer Support Block'),
    t('Title'),
    t('<h2>Safety Keys</h2>'),
    t('No available information.'),
    t('Safety Key Number'),
    t('Company'),
    t('Safety key Issued date'),
    t('Safety key Expiration date'),
    t('Data export'),
    t('Username'),
    t('First Name'),
    t('Current Company'),
    t('[field_program]
[field_state]
[field_operator_type]'),
    t('Profile Block'),
    t('Safety Key Page for Company Admin'),
    t('Directory company block'),
    t('Company Name'),
    t('Directory export'),
    t('Verify'),
    t('No valid Safety Key found.'),
    t('ID'),
    t('eMaintenance export'),
    t('[field_first_name] [field_last_name]'),
  );
  $export['safety_keys'] = $view;

  return $export;
}
