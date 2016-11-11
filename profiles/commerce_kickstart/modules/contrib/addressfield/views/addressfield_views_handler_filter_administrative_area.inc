<?php
class addressfield_views_handler_filter_administrative_area extends views_handler_filter_in_operator {
  function get_value_options() {
    $this->value_title = t('Administrative Area');
    $field = field_info_field($this->definition['field_name']);
    $states = _api_custom_get_us_states();
    unset($states['']);
    unset($states[' ']);
    $this->value_options = $states;
  }
}
