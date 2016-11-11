<?php

/**
 * @file
 * Administration page callbacks for Moodle Iframe.
 */

/**
 * Implements hook_admin_settings().
 */
function moodle_iframe_admin_settings() {

  // Moodle URL.
  $form['moodle_iframe_url'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Moodle URL'),
    '#default_value' => variable_get('moodle_iframe_url',''),
    '#description'   => t("The full URL of the Moodle instance. Example: 'http://moodle.example.com'. Don't put the trailing '/'."),
    '#required'      => FALSE,
  );

  return system_settings_form($form);
}
