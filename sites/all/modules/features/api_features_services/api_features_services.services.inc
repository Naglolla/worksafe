<?php
/**
 * @file
 * api_features_services.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function api_features_services_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'api';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'api';
  $endpoint->authentication = array();
  $endpoint->server_settings = array(
    'formatters' => array(
      'bencode' => TRUE,
      'json' => TRUE,
      'php' => TRUE,
      'xml' => TRUE,
      'jsonp' => FALSE,
    ),
    'parsers' => array(
      'application/json' => TRUE,
      'application/vnd.php.serialized' => TRUE,
      'application/x-www-form-urlencoded' => TRUE,
      'application/xml' => TRUE,
      'multipart/form-data' => TRUE,
      'text/xml' => TRUE,
    ),
  );
  $endpoint->resources = array(
    'api' => array(
      'actions' => array(
        'getMapInfo' => array(
          'enabled' => '1',
        ),
        'generateTokenCode' => array(
          'enabled' => '1',
        ),
        'getCompanyBranches' => array(
          'enabled' => '1',
        ),
        'getCuponCodeVerification' => array(
          'enabled' => '1',
        ),
        'getCuponGeneration' => array(
          'enabled' => '1',
        ),
        'getCompanies' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'api_programs' => array(
      'actions' => array(
        'getStateOperators' => array(
          'enabled' => '1',
        ),
        'getProgramCourses' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'node' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
  );
  $endpoint->debug = 0;
  $export['api'] = $endpoint;

  return $export;
}
