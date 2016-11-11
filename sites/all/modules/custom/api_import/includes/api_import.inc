<?php

/**
 * Api migration base class
 *
 * Class ApiMigration
 */
abstract class ApiMigration extends Migration {
  /**
   * Returns system default country code
   * @return string
   */
  protected static function getDefaultCountryCode() {
    return variable_get('site_default_country', 'US');
  }
}
