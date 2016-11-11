<?php
/**
 * @file
 * api_features_blocks.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function api_features_blocks_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['api_course-api_course_user_examination'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'api_course_user_examination',
    'module' => 'api_course',
    'node_types' => array(),
    'pages' => 'admin/people/customer-support/*',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '1',
  );

  $export['api_custom-api_custom_full_hero_block'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'api_custom_full_hero_block',
    'module' => 'api_custom',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => '0',
      ),
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => 'header',
        'status' => '1',
        'theme' => 'worksafe',
        'weight' => '-30',
      ),
    ),
    'title' => '',
    'visibility' => '1',
  );

  $export['api_custom-api_custom_hello_user_block'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'api_custom_hello_user_block',
    'module' => 'api_custom',
    'node_types' => array(),
    'pages' => 'courses/*',
    'roles' => array(
      'authenticated user' => '2',
    ),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => 'user_second',
        'status' => '1',
        'theme' => 'worksafe',
        'weight' => '-22',
      ),
    ),
    'title' => '<none>',
    'visibility' => '0',
  );

  $export['api_custom-api_directory_links'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'api_directory_links',
    'module' => 'api_custom',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => '0',
      ),
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'worksafe',
        'weight' => '-28',
      ),
    ),
    'title' => '',
    'visibility' => '1',
  );

  $export['api_custom-api_footer_copyright'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'api_footer_copyright',
    'module' => 'api_custom',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => '0',
      ),
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => 'footer_third',
        'status' => '1',
        'theme' => 'worksafe',
        'weight' => '-29',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['api_custom-api_training_programs'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'api_training_programs',
    'module' => 'api_custom',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => '0',
      ),
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'worksafe',
        'weight' => '-30',
      ),
    ),
    'title' => '',
    'visibility' => '1',
  );

  $export['api_moodle-api_moodle_my_courses_block'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'api_moodle_my_courses_block',
    'module' => 'api_moodle',
    'node_types' => array(),
    'pages' => 'available-programs
programs',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => 'sidebar_second',
        'status' => '1',
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'worksafe',
        'weight' => '-27',
      ),
    ),
    'title' => 'purchases',
    'visibility' => '1',
  );

  $export['api_moodle-api_moodle_program_block'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'api_moodle_program_block',
    'module' => 'api_moodle',
    'node_types' => array(),
    'pages' => 'course/*/*/*/*',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => 'sidebar_second',
        'status' => '1',
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'worksafe',
        'weight' => '-26',
      ),
    ),
    'title' => 'Final Exam',
    'visibility' => '1',
  );

  $export['api_moodle-api_moodle_user_programs_list'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'api_moodle_user_programs_list',
    'module' => 'api_moodle',
    'node_types' => array(),
    'pages' => 'admin/people/customer-support/*',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'commerce_kickstart_admin',
        'weight' => '-26',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '1',
  );

  $export['api_safety_keys-safety_key_program_block'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'safety_key_program_block',
    'module' => 'api_safety_keys',
    'node_types' => array(),
    'pages' => 'course/*/*/*/*',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => 'sidebar_second',
        'status' => '1',
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'worksafe',
        'weight' => '-25',
      ),
    ),
    'title' => '',
    'visibility' => '1',
  );

  $export['block-api_footer_image'] = array(
    'cache' => -1,
    'custom' => '0',
    'machine_name' => 'api_footer_image',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => 'footer_first',
        'status' => '1',
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '<none>',
    'visibility' => '0',
  );

  $export['block-copyright'] = array(
    'cache' => -1,
    'custom' => '0',
    'machine_name' => 'copyright',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => '0',
      ),
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '<none>',
    'visibility' => '0',
  );

  $export['block-directorylinks'] = array(
    'cache' => -1,
    'custom' => '0',
    'machine_name' => 'directorylinks',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '<none>',
    'visibility' => '1',
  );

  $export['block-header'] = array(
    'cache' => -1,
    'custom' => '0',
    'machine_name' => 'header',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '<none>',
    'visibility' => '1',
  );

  $export['block-trainingprogram'] = array(
    'cache' => -1,
    'custom' => '0',
    'machine_name' => 'trainingprogram',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => '0',
      ),
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '-29',
      ),
    ),
    'title' => '<none>',
    'visibility' => '1',
  );

  $export['comment-recent'] = array(
    'cache' => '1',
    'custom' => '0',
    'delta' => 'recent',
    'module' => 'comment',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['commerce_cart-cart'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'cart',
    'module' => 'commerce_cart',
    'node_types' => array(),
    'pages' => 'checkout*',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['commerce_checkout_progress-indication'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'indication',
    'module' => 'commerce_checkout_progress',
    'node_types' => array(),
    'pages' => 'checkout/*
cart',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'commerce_kickstart_admin',
        'weight' => '-28',
      ),
      'commerce_kickstart_theme' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'commerce_kickstart_theme',
        'weight' => '-10',
      ),
      'omega_kickstart' => array(
        'region' => 'breadcrumb',
        'status' => '1',
        'theme' => 'omega_kickstart',
        'weight' => '-10',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '-24',
      ),
    ),
    'title' => '',
    'visibility' => '1',
  );

  $export['commerce_kickstart_block-powered_drupal_commerce'] = array(
    'cache' => 1,
    'custom' => '0',
    'delta' => 'powered_drupal_commerce',
    'module' => 'commerce_kickstart_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '-19',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '-19',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '-19',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '-4',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['commerce_kickstart_block-proudly_built_by_cg'] = array(
    'cache' => 1,
    'custom' => '0',
    'delta' => 'proudly_built_by_cg',
    'module' => 'commerce_kickstart_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '-19',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '-3',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['crumbs-breadcrumb'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'breadcrumb',
    'module' => 'crumbs',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['current_search-kickstart_search'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'kickstart_search',
    'module' => 'current_search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => 'breadcrumb',
        'status' => '1',
        'theme' => 'omega_kickstart',
        'weight' => '-10',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '-23',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['current_search-standard'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'standard',
    'module' => 'current_search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['facetapi-H24ObDRB0Wq0KpRW1qalIgb7TvlKP7aj'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'H24ObDRB0Wq0KpRW1qalIgb7TvlKP7aj',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => 'sidebar_first',
        'status' => '1',
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '-20',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['facetapi-TFVaQKSORCPdrULxfXDnLQZ40xH0Nper'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'TFVaQKSORCPdrULxfXDnLQZ40xH0Nper',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => 'sidebar_first',
        'status' => '1',
        'theme' => 'omega_kickstart',
        'weight' => '-1',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '-22',
      ),
    ),
    'title' => 'Price',
    'visibility' => '0',
  );

  $export['locale-language'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'language',
    'module' => 'locale',
    'node_types' => array(),
    'pages' => 'courses/*',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => 'user_first',
        'status' => '1',
        'theme' => 'commerce_kickstart_theme',
        'weight' => '-19',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => 'user_first',
        'status' => '1',
        'theme' => 'worksafe',
        'weight' => '-22',
      ),
    ),
    'title' => '<none>',
    'visibility' => '0',
  );

  $export['menu-menu-api-main-menu'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'menu-api-main-menu',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => 'courses/*',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => 'menu',
        'status' => '1',
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => 'menu',
        'status' => '1',
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['menu-menu-api-user-menu'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'menu-api-user-menu',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => 'courses/*',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => 'user_second',
        'status' => '1',
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '<none>',
    'visibility' => '0',
  );

  $export['menu-menu-footer-navigation'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'menu-footer-navigation',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => 'footer_first',
        'status' => '1',
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['menu-menu-payment-methods'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'menu-payment-methods',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => 'footer2_second',
        'status' => '1',
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '-16',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['menu-menu-user-menu'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'menu-user-menu',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => 'user_first',
        'status' => '1',
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['menu-secondary-navigation'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'secondary-navigation',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['moodle_courselist-moodle'] = array(
    'cache' => '1',
    'custom' => '0',
    'delta' => 'moodle',
    'module' => 'moodle_courselist',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['node-recent'] = array(
    'cache' => '1',
    'custom' => '0',
    'delta' => 'recent',
    'module' => 'node',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['node-syndicate'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'syndicate',
    'module' => 'node',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['search_api_sorts-search-sorts'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'search-sorts',
    'module' => 'search_api_sorts',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '4',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '4',
      ),
      'omega_kickstart' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'omega_kickstart',
        'weight' => '-22',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '-24',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['social_media_links-social-media-links'] = array(
    'cache' => 1,
    'custom' => '0',
    'delta' => 'social-media-links',
    'module' => 'social_media_links',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => 'footer_second',
        'status' => '1',
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => 'footer_second',
        'status' => '1',
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '<none>',
    'visibility' => '0',
  );

  $export['system-help'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'help',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => 'help',
        'status' => '1',
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => 'preface_first',
        'status' => '1',
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '-15',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['system-main'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'main',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'commerce_kickstart_admin',
        'weight' => '-27',
      ),
      'commerce_kickstart_theme' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'worksafe',
        'weight' => '-30',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['system-main-menu'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'main-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '-21',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['system-management'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'management',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['system-navigation'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'navigation',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['system-powered-by'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'powered-by',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '10',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '10',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '10',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '-5',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['system-user-menu'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'user-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '-21',
      ),
    ),
    'title' => '<none>',
    'visibility' => '0',
  );

  $export['user-login'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'login',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['user-new'] = array(
    'cache' => '1',
    'custom' => '0',
    'delta' => 'new',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['user-online'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'online',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['views--exp-display_products-page'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => '-exp-display_products-page',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => 'branding',
        'status' => '1',
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '-21',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['views-49752f912f8ab9a08d50b004eeffd55d'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => '49752f912f8ab9a08d50b004eeffd55d',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['views-73bf5fb8a97d85b206f0ac7edff0a9aa'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => '73bf5fb8a97d85b206f0ac7edff0a9aa',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['views-bf5ee37bd60ea98abcb761c967f50021'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'bf5ee37bd60ea98abcb761c967f50021',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['views-branches-branches_block'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'branches-branches_block',
    'module' => 'views',
    'node_types' => array(
      0 => 'company',
    ),
    'pages' => 'node/*/edit
    node/*/unpublish',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'commerce_kickstart_theme',
        'weight' => '-16',
      ),
      'omega_kickstart' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'worksafe',
        'weight' => '-24',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['views-c117238b5c55f571b4e7a454037d5f6e'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'c117238b5c55f571b4e7a454037d5f6e',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['views-collection_products-block_1'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'collection_products-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_theme',
        'weight' => '0',
      ),
      'omega_kickstart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'worksafe',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['views-shopping_cart-block'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'shopping_cart-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'courses/*',
    'roles' => array(),
    'themes' => array(
      'commerce_kickstart_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'commerce_kickstart_admin',
        'weight' => '0',
      ),
      'commerce_kickstart_theme' => array(
        'region' => 'user_second',
        'status' => '1',
        'theme' => 'commerce_kickstart_theme',
        'weight' => '-17',
      ),
      'omega_kickstart' => array(
        'region' => 'user_second',
        'status' => '1',
        'theme' => 'omega_kickstart',
        'weight' => '0',
      ),
      'worksafe' => array(
        'region' => 'shopping_cart',
        'status' => '1',
        'theme' => 'worksafe',
        'weight' => '-20',
      ),
    ),
    'title' => '<none>',
    'visibility' => '0',
  );

  return $export;
}
