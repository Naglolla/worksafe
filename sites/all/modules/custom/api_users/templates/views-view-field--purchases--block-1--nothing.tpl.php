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
  if (!empty($row->order_id)) {
    $order = commerce_order_load($row->order_id);
    $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
    $payment_methods = api_tokens_get_order_payment_methods($order_wrapper);
    $output = sprintf('<div>%s<span class="data">%s</span></div>', t('Payment type: '), implode(', ', $payment_methods));
  }
?>
<?php print $output; ?>
