<?php
/**
 * @file
 * api_stringoverrides.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function api_stringoverrides_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'locale_custom_disabled_strings_en';
  $strongarm->value = array();
  $export['locale_custom_disabled_strings_en'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'locale_custom_strings_en';
  $strongarm->value = array(
    '' => array(
      'Back to login' => 'Cancel',
      'Create new account' => 'Register now',
      'Sorry, unrecognized username or password. <a href="@password">Have you forgotten your password?</a>' => 'The Username or Password you entered is incorrect.',
      'The specified passwords do not match.' => 'Password and Password confirmation are not the same, please try again',
      'Update email/password' => 'My Profile',
      'Your current password is missing or incorrect; it\'s required to change the <em class="placeholder">Password</em>.' => 'Invalid current password, please try again.',
    ),
  );
  $export['locale_custom_strings_en'] = $strongarm;

  return $export;
}
