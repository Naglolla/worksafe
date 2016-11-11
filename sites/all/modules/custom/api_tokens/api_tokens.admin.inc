<?php

/**
 * @file
 * Integrate Api Tokens forms for Drupal.
 */

/**
 * Form builder for Api Tokens form.
 */
function api_tokens_configuration_form() {
  $form = array();
  $form['tokens_help_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Tokens Help Text'),
    '#description' => t('Tokens: Description about what a Token is.'),
    '#default_value' => variable_get('api_tokens_help_text', ''),
    '#size' => 5,
  );
  $form['#submit'] = array('api_tokens_configuration_form_submit');      
  return system_settings_form($form);
}

/**
 * Implements Submit Function for Api Tokens form.
 */
function api_tokens_configuration_form_submit($form, $form_state) {
  $values = $form_state['values'];
  variable_set('api_tokens_help_text', $values['tokens_help_text']);
}
