<?php

/* 
 * Defaults settings values.
 */
       
// Auth Drupal Services plugin
$defaults['auth_drupalservices']['host_uri'] = 'http://worksafe2.api.org';
$defaults['auth_drupalservices']['remote_user'] = 'remote';
$defaults['auth_drupalservices']['remote_pw'] = 'remote';
$defaults['auth_drupalservices']['field_map_firstname'] = 'field_first_name';
$defaults['auth_drupalservices']['field_map_lastname'] = 'field_last_name';
$defaults['auth_drupalservices']['field_map_email'] = 'mail';
$defaults['auth_drupalservices']['call_logout_service'] = '1';

$CFG->enablecompletion = '1';