<?php
/**
 * @file
 * api_regulatory_questions.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function api_regulatory_questions_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'regulatory_questions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_regulatory_questions';
  $view->human_name = 'Regulatory questions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Regulatory questions';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
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
  );
  /* Field: Regulatory questions: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_regulatory_questions';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Regulatory questions: Order */
  $handler->display->display_options['fields']['field_order']['id'] = 'field_order';
  $handler->display->display_options['fields']['field_order']['table'] = 'field_data_field_order';
  $handler->display->display_options['fields']['field_order']['field'] = 'field_order';
  $handler->display->display_options['fields']['field_order']['element_type'] = '0';
  $handler->display->display_options['fields']['field_order']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_order']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_order']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_order']['field_api_classes'] = TRUE;
  /* Field: Field: State */
  $handler->display->display_options['fields']['field_state']['id'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['table'] = 'field_data_field_state';
  $handler->display->display_options['fields']['field_state']['field'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['element_type'] = '0';
  $handler->display->display_options['fields']['field_state']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_state']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_state']['field_api_classes'] = TRUE;
  /* Field: Field: Type */
  $handler->display->display_options['fields']['field_operator_type']['id'] = 'field_operator_type';
  $handler->display->display_options['fields']['field_operator_type']['table'] = 'field_data_field_operator_type';
  $handler->display->display_options['fields']['field_operator_type']['field'] = 'field_operator_type';
  $handler->display->display_options['fields']['field_operator_type']['label'] = 'Operator type';
  $handler->display->display_options['fields']['field_operator_type']['element_type'] = '0';
  $handler->display->display_options['fields']['field_operator_type']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_operator_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_operator_type']['field_api_classes'] = TRUE;
  /* Field: Regulatory questions: Are you a single-site owner or operator? */
  $handler->display->display_options['fields']['field_question_1']['id'] = 'field_question_1';
  $handler->display->display_options['fields']['field_question_1']['table'] = 'field_data_field_question_1';
  $handler->display->display_options['fields']['field_question_1']['field'] = 'field_question_1';
  $handler->display->display_options['fields']['field_question_1']['element_type'] = '0';
  $handler->display->display_options['fields']['field_question_1']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_question_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_question_1']['field_api_classes'] = TRUE;
  /* Field: Regulatory questions: Do you have hazardous substance storage tanks? */
  $handler->display->display_options['fields']['field_question_6']['id'] = 'field_question_6';
  $handler->display->display_options['fields']['field_question_6']['table'] = 'field_data_field_question_6';
  $handler->display->display_options['fields']['field_question_6']['field'] = 'field_question_6';
  $handler->display->display_options['fields']['field_question_6']['element_type'] = '0';
  $handler->display->display_options['fields']['field_question_6']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_question_6']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_question_6']['field_api_classes'] = TRUE;
  /* Field: Regulatory questions: Do you have secondary containment on your sumps and beneath your dispensers? */
  $handler->display->display_options['fields']['field_question_5']['id'] = 'field_question_5';
  $handler->display->display_options['fields']['field_question_5']['table'] = 'field_data_field_question_5';
  $handler->display->display_options['fields']['field_question_5']['field'] = 'field_question_5';
  $handler->display->display_options['fields']['field_question_5']['element_type'] = '0';
  $handler->display->display_options['fields']['field_question_5']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_question_5']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_question_5']['field_api_classes'] = TRUE;
  /* Field: Regulatory questions: Do you use inventory reconciliation or SIR as a method of release detection? */
  $handler->display->display_options['fields']['field_question_2']['id'] = 'field_question_2';
  $handler->display->display_options['fields']['field_question_2']['table'] = 'field_data_field_question_2';
  $handler->display->display_options['fields']['field_question_2']['field'] = 'field_question_2';
  $handler->display->display_options['fields']['field_question_2']['element_type'] = '0';
  $handler->display->display_options['fields']['field_question_2']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_question_2']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_question_2']['field_api_classes'] = TRUE;
  /* Field: Regulatory questions: Does your facilty have steel components, including tanks or piping? */
  $handler->display->display_options['fields']['field_question_7']['id'] = 'field_question_7';
  $handler->display->display_options['fields']['field_question_7']['table'] = 'field_data_field_question_7';
  $handler->display->display_options['fields']['field_question_7']['field'] = 'field_question_7';
  $handler->display->display_options['fields']['field_question_7']['element_type'] = '0';
  $handler->display->display_options['fields']['field_question_7']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_question_7']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_question_7']['field_api_classes'] = TRUE;
  /* Field: Regulatory questions: Does your leak detection system have sensors? */
  $handler->display->display_options['fields']['field_question_4']['id'] = 'field_question_4';
  $handler->display->display_options['fields']['field_question_4']['table'] = 'field_data_field_question_4';
  $handler->display->display_options['fields']['field_question_4']['field'] = 'field_question_4';
  $handler->display->display_options['fields']['field_question_4']['element_type'] = '0';
  $handler->display->display_options['fields']['field_question_4']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_question_4']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_question_4']['field_api_classes'] = TRUE;
  /* Field: Regulatory questions: Is your facility equipped with an automatic tank gauge? */
  $handler->display->display_options['fields']['field_question_3']['id'] = 'field_question_3';
  $handler->display->display_options['fields']['field_question_3']['table'] = 'field_data_field_question_3';
  $handler->display->display_options['fields']['field_question_3']['field'] = 'field_question_3';
  $handler->display->display_options['fields']['field_question_3']['element_type'] = '0';
  $handler->display->display_options['fields']['field_question_3']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_question_3']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_question_3']['field_api_classes'] = TRUE;
  /* Sort criterion: Regulatory questions: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'eck_regulatory_questions';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/regulatory-questions';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Regulatory questions';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['regulatory_questions'] = array(
    t('Master'),
    t('Regulatory questions'),
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
    t('Id'),
    t('.'),
    t(','),
    t('Order'),
    t('State'),
    t('Operator type'),
    t('Are you a single-site owner or operator?'),
    t('Do you have hazardous substance storage tanks?'),
    t('Do you have secondary containment on your sumps and beneath your dispensers?'),
    t('Do you use inventory reconciliation or SIR as a method of release detection?'),
    t('Does your facilty have steel components, including tanks or piping?'),
    t('Does your leak detection system have sensors?'),
    t('Is your facility equipped with an automatic tank gauge?'),
    t('Page'),
  );
  $export['regulatory_questions'] = $view;

  return $export;
}
