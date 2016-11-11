<?php
/**
 * @file
 * api_site_configurations.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function api_site_configurations_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "password_policy" && $api == "default_password_policy") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
