<?php
/**
 * @file
 * Admin settings.
 */

/**
 * Menu callback; node unpublish form.
 */
function api_custom_unpublish_node_page($node) {
  $type_name = node_type_get_name($node);
  drupal_set_title(t('<em>Unpublish @type</em> @title', array('@type' => $type_name, '@title' => $node->title)), PASS_THROUGH);
  return drupal_get_form('api_custom_unpublish_node_form', $node);
}

function api_custom_unpublish_node_form($form, &$form_state, $node) {
  $form['unpublish_message'] = array(
    '#type' => 'markup',
    '#markup' => t('Are you sure you want to unpublish this content?'),
  );
  $form['unpublish_submit'] = array(
    '#type' => 'submit',
    '#value' => 'Unpublish',
  );
  $form['nid'] = array(
  	'#type' => 'hidden',
  	'#value' => $node->nid,
  );
  return $form;
}

function api_custom_unpublish_node_form_submit($form, &$form_state) {
  $nid = $form_state['values']['nid'];
  $unpublish = api_custom_unpublish_node($nid);
  if (!$unpublish) {
    drupal_set_message(t('Content not found'),'error');
  }
  drupal_goto('admin/content/companies');
}
