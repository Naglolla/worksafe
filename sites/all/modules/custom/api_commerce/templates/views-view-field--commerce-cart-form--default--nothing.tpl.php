<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>
<?php
	if (!empty($row->field_commerce_product[0]['raw']['entity'])) {
    
    print '<label class="table-label">' . $field->options['label'] . ':</label>';
    $product_type = $row->field_commerce_product[0]['raw']['entity']->type;
    $product_entity = $row->field_commerce_product[0]['raw']['entity'];
    
    if ($product_type == 'token'){
      $commerce_line_item_entity = $row->_field_data['commerce_line_item_field_data_commerce_line_items_line_item_']['entity'];
      $token_code = $commerce_line_item_entity->field_token_id[LANGUAGE_NONE][0]['value'];

      if(_get_token_by_code($token_code)){
        print t('Add funds to token ') . $token_code;
      } else {
        print t('Token');
      }
    } else {
      $us_states = _api_custom_get_us_states();
      $states = _api_custom_field_item('commerce_product', $product_entity, 'field_states', 'value');
      $operator_types = _api_custom_field_item('commerce_product', $product_entity, 'field_operator_types', 'value');
      $line_item_entity = end(entity_load('commerce_line_item', array(),array('type' =>'product','line_item_label' => $product_entity->sku)));
      $program_name = api_moodle_get_program_name($line_item_entity->data['program_nid']);
      print $program_name;
      if (!empty($us_states[$states]) && !empty($operator_types)) {
        print t(', @state, Class @type', array('@state' => $us_states[$states], '@type'=>$operator_types));
      }
      print t(', Module: @module',array('@module' =>  $product_entity->title));
    }
	}
?>
