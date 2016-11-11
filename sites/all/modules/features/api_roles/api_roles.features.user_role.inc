<?php
/**
 * @file
 * api_roles.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function api_roles_user_default_roles() {
  $roles = array();

  // Exported role: antea user.
  $roles['antea user'] = array(
    'name' => 'antea user',
    'weight' => '7',
  );

  // Exported role: company admin.
  $roles['company admin'] = array(
    'name' => 'company admin',
    'weight' => '6',
  );

  // Exported role: customer support.
  $roles['customer support'] = array(
    'name' => 'customer support',
    'weight' => '4',
  );

  return $roles;
}
