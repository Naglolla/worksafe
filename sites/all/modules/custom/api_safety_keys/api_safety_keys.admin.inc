<?php

/**
 * @file
 * Integrate Api Safety Keys forms for Drupal.
 */

/**
 * Form builder for Api Safety Keys form.
 */
function api_safety_keys_configuration_form() {
  $form = array();
  $form['api_safety_key_directory_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Safety Key Help Text'),
    '#description' => t('Safety Key: Description about a Safety Key displayed on homepage (directoty links).'),
    '#default_value' => variable_get('api_safety_key_directory_text', ''),
    '#size' => 5,
  );
  $form['#submit'] = array('api_safety_keys_configuration_form_submit');      
  return system_settings_form($form);
}

/**
 * Implements Submit Function for Api Safety Keys form.
 */
function api_safety_keys_configuration_form_submit($form, $form_state) {
  $values = $form_state['values'];
  variable_set('api_safety_key_directory_text', $values['api_safety_key_directory_text']);
}
