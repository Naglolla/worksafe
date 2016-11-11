<?php
/**
 * @file
 * api_feature_feeds.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function api_feature_feeds_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'users';
  $feeds_importer->config = array(
    'name' => 'Users',
    'description' => 'Users import',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv xml',
        'direct' => 0,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'APIFeedsUserProcessor',
      'config' => array(
        'roles' => array(),
        'status' => 1,
        'defuse_mail' => FALSE,
        'mappings' => array(
          0 => array(
            'source' => 'First Name',
            'target' => 'field_first_name',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Middle Name',
            'target' => 'field_middle_name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Last Name',
            'target' => 'field_last_name',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Email Address',
            'target' => 'mail',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'Password',
            'target' => 'pass',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Job Title',
            'target' => 'field_job_title',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Company Address1',
            'target' => 'field_local_company_address:thoroughfare',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Company Address2',
            'target' => 'field_local_company_address:premise',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Company Telephone No.',
            'target' => 'field_local_company_telfax',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Company Fax',
            'target' => 'field_local_facility_telfax',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Company Region',
            'target' => 'field_local_company_region',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Company City',
            'target' => 'field_local_company_address:dependent_locality',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Company State',
            'target' => 'field_local_company_address:administrative_area',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'Company Country',
            'target' => 'field_local_company_address:country',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'User Address1',
            'target' => 'field_address:thoroughfare',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'User Address2',
            'target' => 'field_address:premise',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'User City',
            'target' => 'field_address:locality',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'User State',
            'target' => 'field_address:administrative_area',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'User Zip',
            'target' => 'field_address:postal_code',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'User Country',
            'target' => 'field_address:country',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'User Telephone No.',
            'target' => 'field_tel',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => 0,
        'update_non_existent' => 'skip',
        'input_format' => NULL,
        'skip_hash_check' => FALSE,
        'bundle' => 'user',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['users'] = $feeds_importer;

  return $export;
}
