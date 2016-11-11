<?php
/**
 * @file
 * api_features_menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function api_features_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-api-main-menu_directory:<nolink>
  $menu_links['menu-api-main-menu_directory:<nolink>'] = array(
    'menu_name' => 'menu-api-main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Directory',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => 'header-directory-link',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-api-main-menu_directory:<nolink>',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '1',
  );
  // Exported menu link: menu-api-main-menu_help:<nolink>
  $menu_links['menu-api-main-menu_help:<nolink>'] = array(
    'menu_name' => 'menu-api-main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Help',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'menu-api-main-menu_help:<nolink>',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => 'header-help-link',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '5',
  );
  // Exported menu link: menu-api-main-menu_login:user/login
  $menu_links['menu-api-main-menu_login:user/login'] = array(
    'menu_name' => 'menu-api-main-menu',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => 'Login',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'show-only-mobile',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-api-main-menu_login:user/login',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '6',
  );
  // Exported menu link: menu-api-main-menu_logout:user/logout
  $menu_links['menu-api-main-menu_logout:user/logout'] = array(
    'menu_name' => 'menu-api-main-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Logout',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'show-only-mobile',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-api-main-menu_logout:user/logout',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '8',
  );
  // Exported menu link: menu-api-main-menu_account:my-account
  $menu_links['menu-api-main-menu_account:my-account'] = array(
    'menu_name' => 'menu-api-main-menu',
    'link_path' => 'my-account',
    'router_path' => 'my-account',
    'link_title' => 'My Profile',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'menu-api-main-menu_account:my-account',
      'attributes' => array(
        'class' => array(
          0 => 'show-only-mobile',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '7',
  );
  // Exported menu link: menu-api-main-menu_programs:programs
  $menu_links['menu-api-main-menu_programs:programs'] = array(
    'menu_name' => 'menu-api-main-menu',
    'link_path' => 'programs',
    'router_path' => 'programs',
    'link_title' => 'Programs',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-api-main-menu_programs:programs',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-api-main-menu_register:user/register
  $menu_links['menu-api-main-menu_register:user/register'] = array(
    'menu_name' => 'menu-api-main-menu',
    'link_path' => 'user/register',
    'router_path' => 'user/register',
    'link_title' => 'Register',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'show-only-mobile',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-api-main-menu_register:user/register',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '5',
  );
  // Exported menu link: menu-api-main-menu_safety-key:search/safety_key
  $menu_links['menu-api-main-menu_safety-key:search/safety_key'] = array(
    'menu_name' => 'menu-api-main-menu',
    'link_path' => 'search/safety_key',
    'router_path' => 'search/safety_key',
    'link_title' => 'Safety key',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'menu-api-main-menu_safety-key:search/safety_key',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '2',
  );
  // Exported menu link: menu-api-main-menu_state:api-map
  $menu_links['menu-api-main-menu_state:api-map'] = array(
    'menu_name' => 'menu-api-main-menu',
    'link_path' => 'api-map',
    'router_path' => 'api-map',
    'link_title' => 'State',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'menu-api-main-menu_state:api-map',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '4',
  );
  // Exported menu link: menu-api-main-menu_token:<nolink>
  $menu_links['menu-api-main-menu_token:<nolink>'] = array(
    'menu_name' => 'menu-api-main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Token',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'menu-api-main-menu_token:<nolink>',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => 'header-token-link',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '3',
  );
  // Exported menu link: menu-api-user-menu_login:user/login
  $menu_links['menu-api-user-menu_login:user/login'] = array(
    'menu_name' => 'menu-api-user-menu',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => 'Login',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-api-user-menu_login:user/login',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '4',
  );
  // Exported menu link: menu-api-user-menu_logout:user/logout
  $menu_links['menu-api-user-menu_logout:user/logout'] = array(
    'menu_name' => 'menu-api-user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Logout',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-api-user-menu_logout:user/logout',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '3',
  );
  // Exported menu link: menu-api-user-menu_account:my-account
  $menu_links['menu-api-user-menu_account:my-account'] = array(
    'menu_name' => 'menu-api-user-menu',
    'link_path' => 'my-account',
    'router_path' => 'my-account',
    'link_title' => 'My Profile',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'menu-api-user-menu_account:my-account',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '2',
  );
  // Exported menu link: menu-api-user-menu_register:user/register
  $menu_links['menu-api-user-menu_register:user/register'] = array(
    'menu_name' => 'menu-api-user-menu',
    'link_path' => 'user/register',
    'router_path' => 'user/register',
    'link_title' => 'Register',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-api-user-menu_register:user/register',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Directory');
  t('Help');
  t('Login');
  t('Logout');
  t('My Profile');
  t('Programs');
  t('Register');
  t('Safety key');
  t('Token');


  return $menu_links;
}
