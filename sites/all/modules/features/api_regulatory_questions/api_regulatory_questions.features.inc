<?php
/**
 * @file
 * api_regulatory_questions.features.inc
 */

/**
 * Implements hook_views_api().
 */
function api_regulatory_questions_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function api_regulatory_questions_eck_bundle_info() {
  $items = array(
    'regulatory_questions_regulatory_questions' => array(
      'machine_name' => 'regulatory_questions_regulatory_questions',
      'entity_type' => 'regulatory_questions',
      'name' => 'regulatory_questions',
      'label' => 'Regulatory questions',
      'config' => array(),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function api_regulatory_questions_eck_entity_type_info() {
  $items = array(
    'regulatory_questions' => array(
      'name' => 'regulatory_questions',
      'label' => 'Regulatory questions',
      'properties' => array(
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
          'schema' => NULL,
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
          'schema' => NULL,
        ),
      ),
    ),
  );
  return $items;
}
