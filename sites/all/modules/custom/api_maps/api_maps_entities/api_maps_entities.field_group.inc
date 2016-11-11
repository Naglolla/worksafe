<?php
/**
 * @file
 * api_maps_entities.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function api_maps_entities_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_agency_link|us_state|us_state|form';
  $field_group->group_name = 'group_agency_link';
  $field_group->entity_type = 'us_state';
  $field_group->bundle = 'us_state';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Agency Link',
    'weight' => '6',
    'children' => array(
      0 => 'field_state_agency_link_info',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-agency-link field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_agency_link|us_state|us_state|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_antea_approval|us_state|us_state|form';
  $field_group->group_name = 'group_antea_approval';
  $field_group->entity_type = 'us_state';
  $field_group->bundle = 'us_state';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'API/Antea Approval',
    'weight' => '11',
    'children' => array(
      0 => 'field_state_api_antea_approval',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-antea-approval field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_antea_approval|us_state|us_state|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_classroom_training|us_state|us_state|form';
  $field_group->group_name = 'group_classroom_training';
  $field_group->entity_type = 'us_state';
  $field_group->bundle = 'us_state';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Classroom Training',
    'weight' => '12',
    'children' => array(
      0 => 'field_state_classroom_training',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-classroom-training field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_classroom_training|us_state|us_state|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_information|us_state|us_state|form';
  $field_group->group_name = 'group_contact_information';
  $field_group->entity_type = 'us_state';
  $field_group->bundle = 'us_state';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '10',
    'children' => array(
      0 => 'field_state_contact_info',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-contact-information field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_contact_information|us_state|us_state|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_map_information|us_state|us_state|form';
  $field_group->group_name = 'group_map_information';
  $field_group->entity_type = 'us_state';
  $field_group->bundle = 'us_state';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'US MAP INFORMATION',
    'weight' => '2',
    'children' => array(
      0 => 'field_map_state_alt_url',
      1 => 'field_map_state_color',
      2 => 'field_map_state_id',
      3 => 'field_map_tip_information',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-map-information field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_map_information|us_state|us_state|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_program_status|us_state|us_state|form';
  $field_group->group_name = 'group_program_status';
  $field_group->entity_type = 'us_state';
  $field_group->bundle = 'us_state';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Program Status',
    'weight' => '8',
    'children' => array(
      0 => 'field_state_program_status',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-program-status field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_program_status|us_state|us_state|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_reciprocity|us_state|us_state|form';
  $field_group->group_name = 'group_reciprocity';
  $field_group->entity_type = 'us_state';
  $field_group->bundle = 'us_state';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Reciprocity',
    'weight' => '9',
    'children' => array(
      0 => 'field_state_reciprocity_info',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-reciprocity field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_reciprocity|us_state|us_state|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_regulating_agency|us_state|us_state|form';
  $field_group->group_name = 'group_regulating_agency';
  $field_group->entity_type = 'us_state';
  $field_group->bundle = 'us_state';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Regulating Agency',
    'weight' => '5',
    'children' => array(
      0 => 'field_state_regu_agency',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-regulating-agency field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_regulating_agency|us_state|us_state|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_retraining_info|us_state|us_state|form';
  $field_group->group_name = 'group_retraining_info';
  $field_group->entity_type = 'us_state';
  $field_group->bundle = 'us_state';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Retraining Info',
    'weight' => '4',
    'children' => array(
      0 => 'field_state_retraining_info',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-retraining-info field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_retraining_info|us_state|us_state|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_state_additional_info|us_state|us_state|form';
  $field_group->group_name = 'group_state_additional_info';
  $field_group->entity_type = 'us_state';
  $field_group->bundle = 'us_state';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'State Additional Info',
    'weight' => '13',
    'children' => array(
      0 => 'field_state_additional_info',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-state-additional-info field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_state_additional_info|us_state|us_state|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_training_deadline|us_state|us_state|form';
  $field_group->group_name = 'group_training_deadline';
  $field_group->entity_type = 'us_state';
  $field_group->bundle = 'us_state';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Training Deadline',
    'weight' => '3',
    'children' => array(
      0 => 'field_state_deadline',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-training-deadline field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_training_deadline|us_state|us_state|form'] = $field_group;

  return $export;
}
