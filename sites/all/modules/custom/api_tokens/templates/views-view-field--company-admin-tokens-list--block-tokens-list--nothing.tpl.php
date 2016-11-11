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
<a href="<?php print url('token_entity/token_entity_bundle/'.$row->id); ?>"><?php print t('View') ?></a>

<?php if($view->is_company_admin): ?>
  <a href="<?php print url('token/buyreload-token', array('query' => array('id' => $row->id))); ?>"><?php print t('Add funds') ?></a>
<?php elseif ($view->user_uid == $row->users_eck_token_entity_uid): ?>
  <a href="<?php print url('token/buyreload-token', array('query' => array('id' => $row->id))); ?>"><?php print t('Add funds') ?></a>
<?php endif; ?>

