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
		$product_entity = $row->field_commerce_product[0]['raw']['entity'];
		$course_type = _api_custom_field_item('commerce_product', $product_entity, 'field_course_type', 'value');
		$course_types = _api_moodle_get_course_types();
		if (!empty($course_type) && !empty($course_types[$course_type])) {
			print $course_types[$course_type];
		} else {
      print t('N/A');
    }
	}
?>
