<?php
class api_custom_handler_field_company_safety_keys extends views_handler_field {
  function query() {
     // do nothing -- to override the parent query.
  }

  public function render($values) {
    return count(api_users_get_company_safety_keys($values->nid));
  }
}
