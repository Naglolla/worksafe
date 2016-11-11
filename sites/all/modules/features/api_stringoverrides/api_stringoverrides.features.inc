<?php
/**
 * @file
 * api_stringoverrides.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function api_stringoverrides_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
