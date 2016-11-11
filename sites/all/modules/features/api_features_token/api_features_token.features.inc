<?php
/**
 * @file
 * api_features_token.features.inc
 */

/**
 * Implements hook_commerce_line_item_default_types().
 */
function api_features_token_commerce_line_item_default_types() {
  $items = array(
    'token_line_item' => array(
      'name' => 'Token line item',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Add product',
      'base' => 'commerce_product_line_item',
    ),
    'token_use_line_item' => array(
      'name' => 'Token use line item',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Add product',
      'base' => 'commerce_product_line_item',
    ),
  );
  return $items;
}

/**
 * Implements hook_commerce_product_default_types().
 */
function api_features_token_commerce_product_default_types() {
  $items = array(
    'token' => array(
      'type' => 'token',
      'name' => 'Token',
      'description' => '',
      'help' => '',
      'revision' => '1',
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function api_features_token_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function api_features_token_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function api_features_token_eck_bundle_info() {
  $items = array(
    'token_entity_token_entity_bundle' => array(
      'machine_name' => 'token_entity_token_entity_bundle',
      'entity_type' => 'token_entity',
      'name' => 'token_entity_bundle',
      'label' => 'Token',
      'config' => array(),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function api_features_token_eck_entity_type_info() {
  $items = array(
    'token_entity' => array(
      'name' => 'token_entity',
      'label' => 'Token entity',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
          'schema' => NULL,
        ),
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
          'schema' => NULL,
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
          'schema' => NULL,
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
          'schema' => NULL,
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_node_info().
 */
function api_features_token_node_info() {
  $items = array(
    'token' => array(
      'name' => t('Token'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
