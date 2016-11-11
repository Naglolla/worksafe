<?php

/**
 * Defines a field handler that can display the State name instead of the two
 * character State code for an address field.
 */
class addressfield_views_handler_field_administrative_area extends views_handler_field {

  function get_value($values, $field = NULL) {
    $value = parent::get_value($values, $field);

    // If we have a value for the field, look for the State name in the
    // Address Field options list array if specified.
    if (!empty($value)) {
      $states = _api_custom_get_us_states();

      if (!empty($states[$value])) {
        $value = $states[$value];
      }
    }

    return $value;
  }
}
