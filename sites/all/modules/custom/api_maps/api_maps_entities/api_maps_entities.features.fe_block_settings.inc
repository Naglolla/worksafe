<?php
/**
 * @file
 * api_maps_entities.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function api_maps_entities_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['api_maps-api_maps_us_block'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'api_maps_us_block',
    'module' => 'api_maps',
    'node_types' => array(),
    'pages' => 'api-map',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => '0',
      ),
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  return $export;
}
