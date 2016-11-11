<?php

/**
 * @file
 * Integrate Api Api Help, FAQ & Contacts forms for Drupal.
 */

/**
 * Form builder for Api Help, FAQ & Contacts form.
 */
function api_faq_contact_configuration_form() {
  $form = array();
  
  $form['help_and_faq'] = array(
    '#type' => 'fieldset',
    '#title' => t('Help & FAQ'),
  );
  $form['help_and_faq']['help_and_faq_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Help & FAQ Page Title'),
    '#default_value' => variable_get('api_help_and_faq_title', ''),
  );
  $form['help_and_faq']['help_and_faq_content'] = array(
    '#type' => 'text_format',
    '#title' => t('Help & FAQ page Content.'),
    '#description' => t('Insert the text to display on the Help & FAQ page.'),
    '#default_value' => variable_get('api_help_and_faq_content', ''),
    '#format' => 'full_html',
    '#size' => 50,
  );
  
  $form['contact_form'] = array(
    '#type' => 'fieldset',
    '#title' => t('Contact Form'),
  );
  $form['contact_form']['faq_contact_form_status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display Contact Form'),
    '#default_value' => variable_get('api_faq_contact_form_status', ''),
  );
  $form['contact_form']['contact_email'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail address'),
    '#description' => t('This e-mail address will receive all Contact Form requests.'),
    '#default_value' => variable_get('api_faq_contact_contact_email', ''),
  );
  $form['contact_form']['contact_customer_support_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Customer Support e-mail address'),
    '#description' => t('This e-mail address will receive all "Request Company Admin" requests from Contact Form.'),
    '#default_value' => variable_get('api_faq_contact_customer_support_email', ''),
  );

  $form['#validate'] = array('api_faq_contact_configuration_form_validate');    
  $form['#submit'] = array('api_faq_contact_configuration_form_submit');      
  return system_settings_form($form);
}

/**
 * Implements api_faq_contact_configuration_form validate function.
 */
function api_faq_contact_configuration_form_validate(&$form, $form_state) {
  $values = $form_state['values'];
  if (!empty($values['contact_email']) && !valid_email_address($values['contact_email'])) {
    form_set_error('contact_email', t('Please enter a valid e-mail address.'));
  }
  if (!empty($values['contact_customer_support_email']) && !valid_email_address($values['contact_customer_support_email'])) {
    form_set_error('contact_customer_support_email', t('Please enter a valid e-mail address.'));
  }
}

/**
 * Implements api_faq_contact_configuration_form submit function.
 */
function api_faq_contact_configuration_form_submit($form, $form_state) {
  $values = $form_state['values'];
  variable_set('api_help_and_faq_title', $values['help_and_faq_title']);
  variable_set('api_help_and_faq_content', $values['help_and_faq_content']['value']);
  variable_set('api_faq_contact_form_status', $values['faq_contact_form_status']);
  variable_set('api_faq_contact_contact_email', $values['contact_email']);
  variable_set('api_faq_contact_customer_support_email', $values['contact_customer_support_email']);
}
