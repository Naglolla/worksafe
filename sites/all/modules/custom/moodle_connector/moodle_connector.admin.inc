<?php

/**
 * @file
 * Administration page callbacks for Moodle Connector.
 */

/**
 * Implements hook_admin_settings().
 */
function moodle_connector_admin_settings() {

  // Moodle Database Settings.
  // Moodle URL.
  $form['moodle_connector_url'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Moodle URL'),
    '#default_value' => variable_get('moodle_connector_url', ''),
    '#description'   => t("The full URL of the Moodle instance. Example: 'http://moodle.example.com'. Don't put the trailing '/'."),
    '#required'      => TRUE,
  );
  $form['moodle_connector_db_prefix'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Database Prefix'),
    '#default_value' => variable_get('moodle_connector_db_prefix', 'mdl_'),
    '#description'   => t("The prefix for the Moodle database tables. Default is 'mdl_'."),
    '#size'          => 20,
    '#required'      => TRUE,
  );
  
  return system_settings_form($form);
}
