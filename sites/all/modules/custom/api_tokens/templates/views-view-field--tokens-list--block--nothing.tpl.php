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
   // We programmatically create the links because:
   //    - We wan't to add both of them in a single column.
   //    - Dinamic links: User can only edit own entities (created by user).
   // And create manually because they don't appear in the row fields.
   // This is because we are only receiving the entity.
   $entity_uri = entity_uri('token_entity', $row->_field_data['id']['entity']);
   $entity_uri = reset($entity_uri);
   
   $edit_link = l(t('edit'), 'admin/structure/entity-type/' . $entity_uri . '/edit');
   
   //Hide it for now until proper sprint to work on this.
   //$view_link = l(t('view'), $entity_uri);
?>

<?php if($view->is_company_admin): print $edit_link; endif; ?>

<?php //print $view_link; ?>
<a href="<?php print url('token_entity/token_entity_bundle/'.$row->id); ?>"><?php print t('View') ?></a>

<?php if($view->is_company_admin): ?>
  <a href="<?php print url('token/buyreload-token', array('query' => array('id' => $row->id))); ?>"><?php print t('Add funds') ?></a>
<?php elseif ($view->user_uid == $row->users_eck_token_entity_uid): ?>
  <a href="<?php print url('token/buyreload-token', array('query' => array('id' => $row->id))); ?>"><?php print t('Add funds') ?></a>
<?php endif; ?>

