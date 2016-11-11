<?php

/**
 * @file
 * Drush support for the Moodle integration
 */

/**
 * Implements hook_drush_command().
 */
function api_moodle_drush_command() {
  $items['moodle'] = array(
    'description' => 'Moodle Drush helper.',
    'aliases' => array('mdl'),
  );
  $items['moodle-vset'] = array(
    'description' => 'Moodle Drush helper (Variable Set).',
    'aliases' => array('mdl-vset'),
    'arguments' => array(
      'name' => 'Variable name.',
      'value' => 'Variable value.',
    ),
    'options' => array(
      'plugin' => 'Core, or Plugin Name.',
    ),
  );
  $items['moodle-vget'] = array(
    'description' => 'Moodle Drush helper (Variable Get).',
    'aliases' => array('mdl-vget'),
    'arguments' => array(
      'name' => 'Variable name.',
    ),
    'options' => array(
      'plugin' => 'Core, or Plugin Name.',
    ),
  );
  
  return $items;
}

function drush_api_moodle_moodle(){
  drush_print('Implementing "Moodle" drush command');
}

function drush_api_moodle_moodle_vset($name,$value){
  $plugin = drush_get_option('plugin', 'core');
  
  // Connect to the Moodle database.
  $moodle_con = moodle_connector_connect();
  if (!$moodle_con) {
    watchdog('API Moodle', "Error connecting to the Moodle database.");
    drush_log('Error connecting to the Moodle database.','error');
    return FALSE;
  }
  
  if ($plugin == 'core'){
    $res = $moodle_con->merge('config')
      ->key(array('name' => $name))
      ->fields(array(
          'value' => $value,
      ))
      ->execute();
  } else {
    $res = $moodle_con->merge('config_plugins')
      ->key(array('name' => $name, 'plugin' => $plugin))
      ->fields(array(
          'value' => $value,
      ))
      ->execute();
  }
  
  if (!$res) {
    drush_log('An error occurred trying to update a value','error');
    return FALSE;
  }
  
  drush_log($name . ($plugin == 'core' ? '':' ['.$plugin.']') . ' was set to "' . $value . '"','success');
  return TRUE;
}

function drush_api_moodle_moodle_vget($name){
  $plugin = drush_get_option('plugin', 'core');
  
  // Connect to the Moodle database.
  $moodle_con = moodle_connector_connect();
  if (!$moodle_con) {
    watchdog('API Moodle', "Error connecting to the Moodle database.");
    drush_log('Error connecting to the Moodle database.','error');
    return FALSE;
  }
  
  if ($plugin == 'core'){
    $query = $moodle_con->select('config','c');
    $query->condition('c.name', $name, '=');
    $query->fields('c', array('value'));
    $result = $query->execute()->fetchField();
  } else {
    $query = $moodle_con->select('config_plugins','c');
    $query->condition('c.name', $name, '=');
    $query->condition('c.plugin', $plugin, '=');
    $query->fields('c', array('value'));
    $result = $query->execute()->fetchField();
  }
  
  if ($result == NULL) {
    drush_log('No matching variable found.','error');
    return FALSE;
  }
  
  drush_log($name . ($plugin == 'core' ? '':' ['.$plugin.']') . ": '" . $result . "'",'success');
  return TRUE;
}