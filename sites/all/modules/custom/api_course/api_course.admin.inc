<?php

/**
 * @file
 * Administration page callbacks for Course module.
 */

/**
 * Implements hook_admin_settings().
 */
function api_course_admin_settings() {

  // Status - Restored
  $form['api_course_restored'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Course Status: Restored'),
    '#default_value' => variable_get('api_course_restored','Restored'),
    '#description'   => t("Course Status: Restored"),
    '#required'      => FALSE,
  );

  return system_settings_form($form);
}
