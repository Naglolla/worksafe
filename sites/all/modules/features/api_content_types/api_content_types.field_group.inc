<?php
/**
 * @file
 * api_content_types.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function api_content_types_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_safety_key|node|product_display|form';
  $field_group->group_name = 'group_safety_key';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_display';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Safety Key Certificate',
    'weight' => '17',
    'children' => array(
      0 => 'field_certificate_text',
      1 => 'field_col_sk_certificates',
      2 => 'field_sk_back_title',
      3 => 'field_sk_default_background',
      4 => 'field_sk_front_text_1',
      5 => 'field_sk_front_text_2',
      6 => 'field_sk_printed_name_text',
      7 => 'field_sk_signature_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-safety-key field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_safety_key|node|product_display|form'] = $field_group;

  return $export;
}
