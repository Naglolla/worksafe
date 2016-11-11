<?php
/**
 * @file
 * api_site_configurations.features.language.inc
 */

/**
 * Implements hook_locale_default_languages().
 */
function api_site_configurations_locale_default_languages() {
  $languages = array();

  // Exported language: en.
  $languages['en'] = array(
    'language' => 'en',
    'name' => 'English',
    'native' => 'EN',
    'direction' => '0',
    'enabled' => '1',
    'plurals' => '0',
    'formula' => '',
    'domain' => '',
    'prefix' => 'en',
    'weight' => '0',
  );
  // Exported language: es.
  $languages['es'] = array(
    'language' => 'es',
    'name' => 'Spanish',
    'native' => 'ES',
    'direction' => '0',
    'enabled' => '1',
    'plurals' => '0',
    'formula' => '',
    'domain' => '',
    'prefix' => 'es',
    'weight' => '0',
  );
  return $languages;
}
