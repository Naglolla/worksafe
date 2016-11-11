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
 $symbol = field_get_items('entity', $row, 'field_field_entity_token_fixed_percent');
 $symbol = $symbol['raw']['value'];
 $discount = field_get_items('entity', $row, 'field_field_entity_tokendiscount_value');
 $discount = $discount['raw']['value']; 
?>

<?php if ($discount): ?>
  <span class="discount">
    <?php if ($symbol == 1): ?>
      <?php print '$' . $discount; ?>
    <?php else: ?>
      <?php print $discount . '%' ; ?>
    <?php endif; ?>
  </span>
<?php else: ?>
  <?php print t('N/A'); ?>
<?php endif; ?>
