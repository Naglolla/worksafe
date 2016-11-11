<?php

/**
 * @file
 * Integrate Api Api Help, FAQ & Contacts forms for Drupal.
 */

/**
 * Form builder for Api Help, FAQ & Contacts form.
 */
function api_company_admin_configuration_form() {
  $form = array();

  $form['directory'] = array(
    '#type' => 'fieldset',
    '#title' => t('Directory'),
  );

  $form['directory']['api_directory_content'] = array(
    '#type' => 'textarea',
    '#title' => t('Directory page Content.'),
    '#description' => t('Insert the text to display on the Directory page.'),
    '#default_value' => variable_get('api_directory_content', 'Search for a contractor with a valid API Safety Key near you.'),
    '#size' => 50,
  );

  return system_settings_form($form);
}
