<?php

/**
 * @file
 * Drush commands
 */

/**
 * Implements hook_drush_command().
 */
function api_custom_drush_command() {
  $items['api-install'] = array(
    'description' => 'API Custom drush helper.',
    'aliases' => array('api'),
    'arguments' => array(
      'operation' => 'Operation name.',
      'argument' => 'Argument for that operation (optional).',
    ),
    'examples' => array(
      'drush api language' => 'Enable language bar.',
    ),
  );
  
  return $items;
}

function drush_api_custom_api_install($operation,$argument = NULL){
  $operations = array(
    'help' => array(
      'callback' => 'api_custom_drush_command_help',
      'argument' => TRUE,
      'help' => 'Show this help. Usage: drush api help'
    ),
    'language' => array(
      'callback' => 'api_custom_drush_command_language',
      'argument' => FALSE,
      'help' => 'Enable the language bar. Usage: drush api language'
    ),
    'captcha' => array(
      'callback' => 'api_custom_drush_command_captcha',
      'argument' => FALSE,
      'help' => 'Enable the captcha in the user register form. Usage: drush api captcha'
    ),
    'enable' => array(
      'callback' => 'api_custom_drush_command_enable',
      'argument' => TRUE,
      'help' => 'Enable modules from a list. Usage: drush api enable <filename>'
    ),
    'disable' => array(
      'callback' => 'api_custom_drush_command_disable',
      'argument' => TRUE,
      'help' => 'Disable modules from a list. Usage: drush api disable <filename>'
    ),
    'install' => array(
      'callback' => 'api_custom_drush_command_install',
      'argument' => FALSE,
    ),
    'update' => array(
      'callback' => 'api_custom_drush_command_update',
      'argument' => TRUE,
      'help' => 'Run drush commands to update the application. Usage: drush api update [filename(see:drush api enable <filename>)]'
    ),
     'paypal' => array(
      'callback' => 'api_custom_drush_command_paypal',
      'argument' => FALSE,
      'help' => 'Set up Paypal account. Usage: drush api paypal'
    ),
    'encrypt' => array(
      'callback' => 'api_custom_drush_command_encrypt',
      'argument' => TRUE,
      'help' => 'Encrypt the password. Usage: drush api encrypt <password>'
    ),
  );
  
  if (!array_key_exists($operation, $operations)){
    drush_log('That command is not allwed / invalid operation.','error');
    return FALSE;
  }
    
  if (isset($operations[$operation]['callback'])){
    $arguments = $operations[$operation]['argument'] === TRUE ? $operations[$operation]['argument']:FALSE;
    if ($arguments === TRUE){
      // Special case for "help" command
      if ($operation == 'help'){
        $argument = $operations;
      }
      $return = call_user_func($operations[$operation]['callback'], $argument);
    } else {
      $return = call_user_func($operations[$operation]['callback']);
    }
  } else {
    drush_log('Drush command terminated abnormally due to an unrecoverable error.','error');
    return FALSE;
  }
  if (!$return){
    drush_log('An error ocurred trying to execute "' . $operation . ' command".','error');
  }
  return TRUE;
}

function api_custom_drush_command_language(){
  require_once DRUPAL_ROOT . '/modules/locale/locale.admin.inc';
  $vars = array('values' => array());
  $vars['values']['site_default'] = "en";
  $vars['values']['enabled'] = array('es' => 'es', 'en' => 0);
  $vars['values']['weight'] = array('es' => 0, 'en' => 0);
  locale_languages_overview_form_submit(array(), $vars);
  return TRUE;
}

function api_custom_drush_command_captcha(){
  if (module_exists('captcha')) {
    db_merge('captcha_points')
      ->key(array('form_id' => 'user_register_form'))
      ->fields(array(
        'form_id' => 'user_register_form',
        'module' => NULL,
        'captcha_type' => 'default',

      ))
      ->execute();
    
    return TRUE;
  }
  drush_log('The module captcha is not enabled.','error');
  return FALSE;
}

function api_custom_drush_command_enable($path){
  $content = file_get_contents($path);
  if ($content){
    $modules = explode("\n", $content);
    foreach ($modules as $module) {
      module_enable(array(trim($module)));
    }
    return TRUE;
  }
  return FALSE;
}

function api_custom_drush_command_disable($path){
  $content = file_get_contents($path);
  if ($content){
    $modules = explode("\n", $content);
    foreach ($modules as $module) {
      module_disable(array(trim($module)));
    }
    return TRUE;
  }
  return FALSE;
}

function api_custom_drush_command_install(){
  return FALSE;
}

function api_custom_drush_command_update($path){
  //Enable modules
  if (is_null($path)){
    $path = 'modules_enabled.txt';
  }
  api_custom_drush_command_enable($path);
  
  //Revert features
  drush_invoke_process("@self", "fra");
  
  //Update
  drush_invoke_process("@self", "updb");
  
  //Enable language bar (local function)
  api_custom_drush_command_language();
  
  return TRUE;
}

function api_custom_drush_command_paypal(){
  drush_print(dt('Payment settings'));
  $paypal_api_username = drush_prompt(dt('API username'),variable_get('paypal_api_username', ''),TRUE);
  $paypal_api_password = drush_prompt(dt('API password'),variable_get('paypal_api_password', ''),TRUE);
  $paypal_api_signature = drush_prompt(dt('Signature'),variable_get('paypal_api_signature', ''),TRUE);
  $options = array(
    'sandbox' => 'Sandbox - use for testing, requires a PayPal Sandbox account',
    'live' => 'Live - use for processing real transactions'
  );
  $paypal_server = drush_choice($options, dt('PayPal server'));
  
  // Save the variables
  variable_set('paypal_api_username', $paypal_api_username);
  variable_set('paypal_api_password', $paypal_api_password);
  variable_set('paypal_api_signature', $paypal_api_signature);
  if ($paypal_server){
    variable_set('paypal_server', $paypal_server);
  }
  return TRUE;
}

function api_custom_drush_command_encrypt($password){
  $algorithm = MCRYPT_BLOWFISH;
  $key = '849354ñlsdflkjsadlkñasdk';
  $mode = MCRYPT_MODE_CBC;
  $encrypted_data = @mcrypt_encrypt($algorithm, $key, $password, $mode);
  drush_print(base64_encode($encrypted_data));
  return TRUE;
}

function api_custom_drush_command_help($operations){
  $rows = array(
    0 => array('Commands','Help'),
    1 => array('--------','----')
  );
  foreach ($operations as $command => $operation) {
    if (isset($operation['help'])){
     $rows[] = array($command,$operation['help']);
    }
  }
  drush_print_table($rows,TRUE);
  return TRUE;
}