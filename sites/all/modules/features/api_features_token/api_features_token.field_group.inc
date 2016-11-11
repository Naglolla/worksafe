<?php
/**
 * @file
 * api_features_token.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function api_features_token_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_discount|commerce_line_item|token_line_item|form';
  $field_group->group_name = 'group_discount';
  $field_group->entity_type = 'commerce_line_item';
  $field_group->bundle = 'token_line_item';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Discount',
    'weight' => '14',
    'children' => array(
      0 => 'field_discount_value',
      1 => 'field_fixed_percentage',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Discount',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-discount field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_discount|commerce_line_item|token_line_item|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_entity_token_discount|token_entity|token_entity_bundle|form';
  $field_group->group_name = 'group_entity_token_discount';
  $field_group->entity_type = 'token_entity';
  $field_group->bundle = 'token_entity_bundle';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Apply a Discount',
    'weight' => '1',
    'children' => array(
      0 => 'field_entity_token_fixed_percent',
      1 => 'field_entity_tokendiscount_value',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Apply a Discount',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-entity-token-discount field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_entity_token_discount|token_entity|token_entity_bundle|form'] = $field_group;

  return $export;
}
