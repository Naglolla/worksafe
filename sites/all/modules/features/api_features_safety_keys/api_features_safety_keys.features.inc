<?php
/**
 * @file
 * api_features_safety_keys.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function api_features_safety_keys_eck_bundle_info() {
  $items = array(
    'safety_key_safety_key' => array(
      'machine_name' => 'safety_key_safety_key',
      'entity_type' => 'safety_key',
      'name' => 'safety_key',
      'label' => 'Safety Key',
      'config' => array(
        'extra_fields' => array(
          'uid' => array(
            'form' => array(
              'label' => 'User',
              'description' => '',
              'widget' => array(
                'type' => 'text',
                'settings' => NULL,
              ),
              'default_value' => 0,
            ),
          ),
          'number' => array(
            'form' => array(
              'label' => 'Number',
              'description' => '',
              'widget' => array(
                'type' => 'text',
                'settings' => array(
                  'size' => '10',
                  'max_length' => '8',
                ),
              ),
              'default_value' => '0',
              'required' => TRUE,
            ),
          ),
          'created' => array(),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function api_features_safety_keys_eck_entity_type_info() {
  $items = array(
    'safety_key' => array(
      'name' => 'safety_key',
      'label' => 'Safety Key',
      'properties' => array(
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
          'schema' => NULL,
        ),
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
          'schema' => NULL,
        ),
        'number' => array(
          'label' => 'Number',
          'type' => 'positive_integer',
          'behavior' => NULL,
          'schema' => array(
            'description' => 'Positive Integer',
            'type' => 'int',
            'size' => 'normal',
            'unsigned' => TRUE,
            'not null' => 1,
          ),
        ),
      ),
    ),
  );
  return $items;
}
