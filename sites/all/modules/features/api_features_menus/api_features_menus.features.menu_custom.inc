<?php
/**
 * @file
 * api_features_menus.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function api_features_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-api-main-menu.
  $menus['menu-api-main-menu'] = array(
    'menu_name' => 'menu-api-main-menu',
    'title' => 'API main menu',
    'description' => 'This is the main menu for API site.',
  );
  // Exported menu: menu-api-user-menu.
  $menus['menu-api-user-menu'] = array(
    'menu_name' => 'menu-api-user-menu',
    'title' => 'API user menu',
    'description' => 'User menu for API site.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('API main menu');
  t('API user menu');
  t('This is the main menu for API site.');
  t('User menu for API site.');


  return $menus;
}
