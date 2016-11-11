<?php
/**
 * @file
 * api_features_users.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function api_features_users_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_account_info|user|user|form';
  $field_group->group_name = 'group_account_info';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Account Information',
    'weight' => '4',
    'children' => array(
      0 => 'field_date_of_registration',
      1 => 'mimemail',
      2 => 'timezone',
      3 => 'locale',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Account Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-account-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_account_info|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_details|user|user|form';
  $field_group->group_name = 'group_contact_details';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Personal Details',
    'weight' => '3',
    'children' => array(
      0 => 'field_address',
      1 => 'field_tel',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Personal Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-contact-details field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_contact_details|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_local_company|user|user|form';
  $field_group->group_name = 'group_local_company';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Company',
    'weight' => '1',
    'children' => array(
      0 => 'field_local_company_address',
      1 => 'field_local_company_region',
      2 => 'field_local_company_telfax',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Company',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-local-company field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_local_company|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_local_facility|user|user|form';
  $field_group->group_name = 'group_local_facility';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Facility',
    'weight' => '2',
    'children' => array(
      0 => 'field_branch',
      1 => 'field_local_facility_address',
      2 => 'field_local_facility_id',
      3 => 'field_local_facility_region',
      4 => 'field_local_facility_telfax',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Facility',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-local-facility field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_local_facility|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mailing_preferences|user|user|form';
  $field_group->group_name = 'group_mailing_preferences';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Mailing Preferences',
    'weight' => '9',
    'children' => array(
      0 => 'field_receive_marketing_email',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Mailing Preferences',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-mailing-preferences field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_mailing_preferences|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_register|user|user|form';
  $field_group->group_name = 'group_register';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Account Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_first_name',
      1 => 'field_job_title',
      2 => 'field_language',
      3 => 'field_last_name',
      4 => 'field_middle_name',
      5 => 'field_public_safety_key',
      6 => 'account',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Account Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-register field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_register|user|user|form'] = $field_group;

  return $export;
}
