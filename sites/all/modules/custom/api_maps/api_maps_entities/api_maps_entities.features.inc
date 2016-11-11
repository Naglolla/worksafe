<?php
/**
 * @file
 * api_maps_entities.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function api_maps_entities_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function api_maps_entities_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function api_maps_entities_eck_bundle_info() {
  $items = array(
    'us_state_us_map_graph' => array(
      'machine_name' => 'us_state_us_map_graph',
      'entity_type' => 'us_state',
      'name' => 'us_map_graph',
      'label' => 'US Map Graph',
      'config' => array(),
    ),
    'us_state_us_state' => array(
      'machine_name' => 'us_state_us_state',
      'entity_type' => 'us_state',
      'name' => 'us_state',
      'label' => 'US State',
      'config' => array(),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function api_maps_entities_eck_entity_type_info() {
  $items = array(
    'us_state' => array(
      'name' => 'us_state',
      'label' => 'US State',
      'properties' => array(),
    ),
  );
  return $items;
}
