<?php

/**
 * @file
 * Definition of api_custom_handler_addressfield.
 */

/**
 * Provides diferent fields display options for addres entity(field).
 * @ingroup views_field_handlers
 */
class api_custom_handler_addressfield extends views_handler_field {
  /**
   * Render the addresfields province_region field.
   */
  public function render($values) {
    $province = unserialize($this->get_value($values));
    return $province['province_region'];
  }

}
