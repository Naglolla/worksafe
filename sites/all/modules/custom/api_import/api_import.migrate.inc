<?php

/**
 * @file
 * Include all migration code for employees database
 */
/**
 * Implements hook_migrate_api().
 */
function api_import_migrate_api() {
  return array(
    'api' => 2,
      'migrations' => array(
        'ApiUsers'     => array('class_name' => 'ApiUsersMigration'),
        'ApiCompanies' => array('class_name' => 'ApiCompaniesMigration'),
        //'ApiWorkType'  => array('class_name' => 'ApiWorkTypeMigration'),
        'ApiPercentagePromoCodes'  => array('class_name' => 'ApiPercentagePromoCodesMigration'),
        'ApiFixedPromoCodes'  => array('class_name' => 'ApiFixedPromoCodesMigration'),
        'ApiPrograms'  => array('class_name' => 'ApiProgramsMigration'),
        'ApiSafetyKeys'  => array('class_name' => 'ApiSafetyKeysMigration'),
        'ApiTokens'  => array('class_name' => 'ApiTokensMigration')
      ),
  );
}
