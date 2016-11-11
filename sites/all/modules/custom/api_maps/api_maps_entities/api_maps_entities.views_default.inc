<?php
/**
 * @file
 * api_maps_entities.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function api_maps_entities_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'api_maps_views';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_us_state';
  $view->human_name = 'API Maps Views';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'API States List';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_title' => 'field_title',
    'field_state_id' => 'field_state_id',
    'edit_link' => 'edit_link',
  );
  $handler->display->display_options['style_options']['default'] = 'field_title';
  $handler->display->display_options['style_options']['info'] = array(
    'field_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_state_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<div class="form-actions form-wrapper view-commerce-message-messages" id="edit-actions">
<a target="_blank" id="edit-submit" class="form-submit" href="/admin/structure/entity-type/us_state/us_state/add">Create New</a>
</div>';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No US States Entities Created Yet.';
  $handler->display->display_options['empty']['area']['format'] = 'commerce_order_message';
  /* Field: US State: Title */
  $handler->display->display_options['fields']['field_title']['id'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['table'] = 'field_data_field_title';
  $handler->display->display_options['fields']['field_title']['field'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['label'] = 'State Name';
  $handler->display->display_options['fields']['field_title']['alter']['path'] = '[view_link]';
  $handler->display->display_options['fields']['field_title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_title']['type'] = 'title_linked';
  $handler->display->display_options['fields']['field_title']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: US State: State ID */
  $handler->display->display_options['fields']['field_state_id']['id'] = 'field_state_id';
  $handler->display->display_options['fields']['field_state_id']['table'] = 'field_data_field_state_id';
  $handler->display->display_options['fields']['field_state_id']['field'] = 'field_state_id';
  $handler->display->display_options['fields']['field_state_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_state_id']['element_default_classes'] = FALSE;
  /* Field: US State: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_us_state';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['label'] = '';
  $handler->display->display_options['fields']['edit_link']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['edit_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_link']['text'] = 'Edit';
  /* Filter criterion: US State: us_state type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_us_state';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'us_state' => 'us_state',
  );

  /* Display: API States List */
  $handler = $view->new_display('page', 'API States List', 'api_states_list');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<div class="form-actions form-wrapper view-commerce-message-messages" id="edit-actions">
<a target="_blank" id="edit-submit" class="form-submit" href="/admin/structure/entity-type/us_state/us_state/add">Create New</a>
</div>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: US State: Title */
  $handler->display->display_options['fields']['field_title']['id'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['table'] = 'field_data_field_title';
  $handler->display->display_options['fields']['field_title']['field'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['label'] = 'State Name';
  $handler->display->display_options['fields']['field_title']['alter']['path'] = '[view_link]';
  $handler->display->display_options['fields']['field_title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_title']['type'] = 'title_linked';
  $handler->display->display_options['fields']['field_title']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: US State: State ID */
  $handler->display->display_options['fields']['field_state_id']['id'] = 'field_state_id';
  $handler->display->display_options['fields']['field_state_id']['table'] = 'field_data_field_state_id';
  $handler->display->display_options['fields']['field_state_id']['field'] = 'field_state_id';
  $handler->display->display_options['fields']['field_state_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_state_id']['element_default_classes'] = FALSE;
  /* Field: US State: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_us_state';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['label'] = 'Operation';
  $handler->display->display_options['fields']['edit_link']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['edit_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_link']['text'] = 'Edit';
  $handler->display->display_options['path'] = 'admin/config/api/api-states-list';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'API States List';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: API Graph List */
  $handler = $view->new_display('page', 'API Graph List', 'api_graph_list');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'API Graph List';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<div class="form-actions form-wrapper view-commerce-message-messages" id="edit-actions">
<a target="_blank" id="edit-submit" class="form-submit" href="/admin/structure/entity-type/us_state/us_map_graph/add">Create New</a>
</div>';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No US Map Graph Entities Created Yet.';
  $handler->display->display_options['empty']['area']['format'] = 'commerce_order_message';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: US State: Graph Color */
  $handler->display->display_options['fields']['field_graph_state_color']['id'] = 'field_graph_state_color';
  $handler->display->display_options['fields']['field_graph_state_color']['table'] = 'field_data_field_graph_state_color';
  $handler->display->display_options['fields']['field_graph_state_color']['field'] = 'field_graph_state_color';
  $handler->display->display_options['fields']['field_graph_state_color']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_graph_state_color']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_graph_state_color']['type'] = 'color_field_swatch';
  $handler->display->display_options['fields']['field_graph_state_color']['settings'] = array(
    'width' => '50',
    'height' => '50',
  );
  /* Field: US State: Graph Label */
  $handler->display->display_options['fields']['field_graph_color_label']['id'] = 'field_graph_color_label';
  $handler->display->display_options['fields']['field_graph_color_label']['table'] = 'field_data_field_graph_color_label';
  $handler->display->display_options['fields']['field_graph_color_label']['field'] = 'field_graph_color_label';
  $handler->display->display_options['fields']['field_graph_color_label']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_graph_color_label']['element_default_classes'] = FALSE;
  /* Field: US State: Display on graph */
  $handler->display->display_options['fields']['field_graph_display_on_graph']['id'] = 'field_graph_display_on_graph';
  $handler->display->display_options['fields']['field_graph_display_on_graph']['table'] = 'field_data_field_graph_display_on_graph';
  $handler->display->display_options['fields']['field_graph_display_on_graph']['field'] = 'field_graph_display_on_graph';
  $handler->display->display_options['fields']['field_graph_display_on_graph']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_graph_display_on_graph']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_graph_display_on_graph']['element_default_classes'] = FALSE;
  /* Field: US State: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_us_state';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['label'] = 'Operation';
  $handler->display->display_options['fields']['edit_link']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['edit_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_link']['text'] = 'Edit';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: US State: us_state type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_us_state';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'us_map_graph' => 'us_map_graph',
  );
  $handler->display->display_options['path'] = 'admin/config/api/api-graph-list';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Api Map Graph List';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Api States List Block */
  $handler = $view->new_display('block', 'Api States List Block', 'api_states_list_block');
  $handler->display->display_options['block_description'] = 'API States List Block';

  /* Display: API Graph List Block */
  $handler = $view->new_display('block', 'API Graph List Block', 'api_graph_list_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'API Graph List';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<div class="form-actions form-wrapper view-commerce-message-messages" id="edit-actions">
<a target="_blank" id="edit-submit" class="form-submit" href="/admin/structure/entity-type/us_state/us_map_graph/add">Create New</a>
</div>';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No US Map Graph Entities Created Yet.';
  $handler->display->display_options['empty']['area']['format'] = 'commerce_order_message';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: US State: Graph Color */
  $handler->display->display_options['fields']['field_graph_state_color']['id'] = 'field_graph_state_color';
  $handler->display->display_options['fields']['field_graph_state_color']['table'] = 'field_data_field_graph_state_color';
  $handler->display->display_options['fields']['field_graph_state_color']['field'] = 'field_graph_state_color';
  $handler->display->display_options['fields']['field_graph_state_color']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_graph_state_color']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_graph_state_color']['type'] = 'color_field_swatch';
  $handler->display->display_options['fields']['field_graph_state_color']['settings'] = array(
    'width' => '50',
    'height' => '50',
  );
  /* Field: US State: Graph Label */
  $handler->display->display_options['fields']['field_graph_color_label']['id'] = 'field_graph_color_label';
  $handler->display->display_options['fields']['field_graph_color_label']['table'] = 'field_data_field_graph_color_label';
  $handler->display->display_options['fields']['field_graph_color_label']['field'] = 'field_graph_color_label';
  $handler->display->display_options['fields']['field_graph_color_label']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_graph_color_label']['element_default_classes'] = FALSE;
  /* Field: US State: Display on graph */
  $handler->display->display_options['fields']['field_graph_display_on_graph']['id'] = 'field_graph_display_on_graph';
  $handler->display->display_options['fields']['field_graph_display_on_graph']['table'] = 'field_data_field_graph_display_on_graph';
  $handler->display->display_options['fields']['field_graph_display_on_graph']['field'] = 'field_graph_display_on_graph';
  $handler->display->display_options['fields']['field_graph_display_on_graph']['label'] = 'Display on Graph';
  $handler->display->display_options['fields']['field_graph_display_on_graph']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_graph_display_on_graph']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_graph_display_on_graph']['type'] = 'list_key';
  /* Field: US State: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_us_state';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['label'] = '';
  $handler->display->display_options['fields']['edit_link']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['edit_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_link']['text'] = 'Edit';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: US State: us_state type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_us_state';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'us_map_graph' => 'us_map_graph',
  );
  $handler->display->display_options['block_description'] = 'API Graph List Block';

  /* Display: API Map States Display */
  $handler = $view->new_display('block', 'API Map States Display', 'api_map_states_display');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'API Map States Display';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'api-map-states-list-view';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '1800';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '1800';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'us-state-row';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: US State: State Map ID */
  $handler->display->display_options['fields']['field_map_state_id']['id'] = 'field_map_state_id';
  $handler->display->display_options['fields']['field_map_state_id']['table'] = 'field_data_field_map_state_id';
  $handler->display->display_options['fields']['field_map_state_id']['field'] = 'field_map_state_id';
  $handler->display->display_options['fields']['field_map_state_id']['label'] = '';
  $handler->display->display_options['fields']['field_map_state_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_map_state_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_map_state_id']['element_default_classes'] = FALSE;
  /* Field: US State: Title */
  $handler->display->display_options['fields']['field_title']['id'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['table'] = 'field_data_field_title';
  $handler->display->display_options['fields']['field_title']['field'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['label'] = '';
  $handler->display->display_options['fields']['field_title']['alter']['path'] = '[view_link]';
  $handler->display->display_options['fields']['field_title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_title']['element_type'] = 'h5';
  $handler->display->display_options['fields']['field_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_title']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_title']['settings'] = array(
    'title_style' => '_none',
    'title_link' => '',
    'title_class' => '',
  );
  /* Field: US State: Training Deadline */
  $handler->display->display_options['fields']['field_state_deadline']['id'] = 'field_state_deadline';
  $handler->display->display_options['fields']['field_state_deadline']['table'] = 'field_data_field_state_deadline';
  $handler->display->display_options['fields']['field_state_deadline']['field'] = 'field_state_deadline';
  $handler->display->display_options['fields']['field_state_deadline']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_state_deadline']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_state_deadline']['element_label_class'] = 'field-label';
  $handler->display->display_options['fields']['field_state_deadline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_state_deadline']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_state_deadline']['hide_empty'] = TRUE;
  /* Field: US State: Retraining Info */
  $handler->display->display_options['fields']['field_state_retraining_info']['id'] = 'field_state_retraining_info';
  $handler->display->display_options['fields']['field_state_retraining_info']['table'] = 'field_data_field_state_retraining_info';
  $handler->display->display_options['fields']['field_state_retraining_info']['field'] = 'field_state_retraining_info';
  $handler->display->display_options['fields']['field_state_retraining_info']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_state_retraining_info']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_state_retraining_info']['element_label_class'] = 'field-label';
  $handler->display->display_options['fields']['field_state_retraining_info']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_state_retraining_info']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_state_retraining_info']['hide_empty'] = TRUE;
  /* Field: US State: Regulating Agency */
  $handler->display->display_options['fields']['field_state_regu_agency']['id'] = 'field_state_regu_agency';
  $handler->display->display_options['fields']['field_state_regu_agency']['table'] = 'field_data_field_state_regu_agency';
  $handler->display->display_options['fields']['field_state_regu_agency']['field'] = 'field_state_regu_agency';
  $handler->display->display_options['fields']['field_state_regu_agency']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_state_regu_agency']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_state_regu_agency']['element_label_class'] = 'field-label';
  $handler->display->display_options['fields']['field_state_regu_agency']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_state_regu_agency']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_state_regu_agency']['hide_empty'] = TRUE;
  /* Field: US State: Agency Link */
  $handler->display->display_options['fields']['field_state_agency_link_info']['id'] = 'field_state_agency_link_info';
  $handler->display->display_options['fields']['field_state_agency_link_info']['table'] = 'field_data_field_state_agency_link_info';
  $handler->display->display_options['fields']['field_state_agency_link_info']['field'] = 'field_state_agency_link_info';
  $handler->display->display_options['fields']['field_state_agency_link_info']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_state_agency_link_info']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_state_agency_link_info']['element_label_class'] = 'field-label';
  $handler->display->display_options['fields']['field_state_agency_link_info']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_state_agency_link_info']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_state_agency_link_info']['hide_empty'] = TRUE;
  /* Field: US State: Program Status */
  $handler->display->display_options['fields']['field_state_program_status']['id'] = 'field_state_program_status';
  $handler->display->display_options['fields']['field_state_program_status']['table'] = 'field_data_field_state_program_status';
  $handler->display->display_options['fields']['field_state_program_status']['field'] = 'field_state_program_status';
  $handler->display->display_options['fields']['field_state_program_status']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_state_program_status']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_state_program_status']['element_label_class'] = 'field-label';
  $handler->display->display_options['fields']['field_state_program_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_state_program_status']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_state_program_status']['hide_empty'] = TRUE;
  /* Field: US State: Reciprocity */
  $handler->display->display_options['fields']['field_state_reciprocity_info']['id'] = 'field_state_reciprocity_info';
  $handler->display->display_options['fields']['field_state_reciprocity_info']['table'] = 'field_data_field_state_reciprocity_info';
  $handler->display->display_options['fields']['field_state_reciprocity_info']['field'] = 'field_state_reciprocity_info';
  $handler->display->display_options['fields']['field_state_reciprocity_info']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_state_reciprocity_info']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_state_reciprocity_info']['element_label_class'] = 'field-label';
  $handler->display->display_options['fields']['field_state_reciprocity_info']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_state_reciprocity_info']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_state_reciprocity_info']['hide_empty'] = TRUE;
  /* Field: US State: Contact Information */
  $handler->display->display_options['fields']['field_state_contact_info']['id'] = 'field_state_contact_info';
  $handler->display->display_options['fields']['field_state_contact_info']['table'] = 'field_data_field_state_contact_info';
  $handler->display->display_options['fields']['field_state_contact_info']['field'] = 'field_state_contact_info';
  $handler->display->display_options['fields']['field_state_contact_info']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_state_contact_info']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_state_contact_info']['element_label_class'] = 'field-label';
  $handler->display->display_options['fields']['field_state_contact_info']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_state_contact_info']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_state_contact_info']['hide_empty'] = TRUE;
  /* Field: US State: API/Antea Approval */
  $handler->display->display_options['fields']['field_state_api_antea_approval']['id'] = 'field_state_api_antea_approval';
  $handler->display->display_options['fields']['field_state_api_antea_approval']['table'] = 'field_data_field_state_api_antea_approval';
  $handler->display->display_options['fields']['field_state_api_antea_approval']['field'] = 'field_state_api_antea_approval';
  $handler->display->display_options['fields']['field_state_api_antea_approval']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_state_api_antea_approval']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_state_api_antea_approval']['element_label_class'] = 'field-label';
  $handler->display->display_options['fields']['field_state_api_antea_approval']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_state_api_antea_approval']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_state_api_antea_approval']['hide_empty'] = TRUE;
  /* Field: US State: Classroom Training */
  $handler->display->display_options['fields']['field_state_classroom_training']['id'] = 'field_state_classroom_training';
  $handler->display->display_options['fields']['field_state_classroom_training']['table'] = 'field_data_field_state_classroom_training';
  $handler->display->display_options['fields']['field_state_classroom_training']['field'] = 'field_state_classroom_training';
  $handler->display->display_options['fields']['field_state_classroom_training']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_state_classroom_training']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_state_classroom_training']['element_label_class'] = 'field-label';
  $handler->display->display_options['fields']['field_state_classroom_training']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_state_classroom_training']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_state_classroom_training']['hide_empty'] = TRUE;
  /* Field: US State: State Additional Info */
  $handler->display->display_options['fields']['field_state_additional_info']['id'] = 'field_state_additional_info';
  $handler->display->display_options['fields']['field_state_additional_info']['table'] = 'field_data_field_state_additional_info';
  $handler->display->display_options['fields']['field_state_additional_info']['field'] = 'field_state_additional_info';
  $handler->display->display_options['fields']['field_state_additional_info']['label'] = '';
  $handler->display->display_options['fields']['field_state_additional_info']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_state_additional_info']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_state_additional_info']['element_label_class'] = 'field-label';
  $handler->display->display_options['fields']['field_state_additional_info']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_state_additional_info']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_state_additional_info']['hide_empty'] = TRUE;
  $handler->display->display_options['block_description'] = 'API Map States Display';
  $translatables['api_maps_views'] = array(
    t('Master'),
    t('API States List'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<div class="form-actions form-wrapper view-commerce-message-messages" id="edit-actions">
<a target="_blank" id="edit-submit" class="form-submit" href="/admin/structure/entity-type/us_state/us_state/add">Create New</a>
</div>'),
    t('No US States Entities Created Yet.'),
    t('State Name'),
    t('State ID'),
    t('Edit'),
    t('Operation'),
    t('API Graph List'),
    t('<div class="form-actions form-wrapper view-commerce-message-messages" id="edit-actions">
<a target="_blank" id="edit-submit" class="form-submit" href="/admin/structure/entity-type/us_state/us_map_graph/add">Create New</a>
</div>'),
    t('No US Map Graph Entities Created Yet.'),
    t('Graph Color'),
    t('Graph Label'),
    t('Display on graph'),
    t('Api States List Block'),
    t('API States List Block'),
    t('API Graph List Block'),
    t('Display on Graph'),
    t('API Map States Display'),
    t('Training Deadline'),
    t('Retraining Info'),
    t('Regulating Agency'),
    t('Agency Link'),
    t('Program Status'),
    t('Reciprocity'),
    t('Contact Information'),
    t('API/Antea Approval'),
    t('Classroom Training'),
    t('State Additional Info'),
  );
  $export['api_maps_views'] = $view;

  return $export;
}
