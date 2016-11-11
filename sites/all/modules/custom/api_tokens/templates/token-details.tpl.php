<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
?>
<h2><?php print t('Token details');?></h2>
<?php if ($details['created']): ?>
<div>
  <label><?php print t('Created');?>:</label> <?php print $details['created'];?>
</div>
<?php endif; ?>
<?php if ($details['total_value']): ?>
<div>
  <label><?php print t('Total Value');?>:</label> <?php print $details['total_value'];?>
</div>
<?php endif; ?>
<?php if ($details['balance']): ?>
<div>
  <label><?php print t('Balance');?>:</label> <?php print $details['balance'];?>
</div>
<?php endif; ?>
<?php if ($details['person']): ?>
<div>
  <label><?php print t('Name');?>:</label> <?php print $details['person']['name'];?>
</div>
<div>
  <label><?php print t('E-Mail');?>:</label> <?php print $details['person']['email'];?>
</div>
<div>
  <label><?php print t('Phone Number');?>:</label> <?php print $details['person']['phone'] ? $details['person']['phone']:'N/A';?>
</div>
<?php endif; ?>
<?php if ($details['discount']): ?>
<div>
  <label><?php print t('Applied Discount');?>:</label> <?php print $details['discount'];?>
</div>
<?php endif; ?>
<?php if ($details['program']): ?>
<div>
  <label><?php print t('Program');?>:</label>
  <?php
    foreach ($details['program'] as $program) {
  ?>
  <div><?php print $program;?></div>
  <?php
    }
  ?>
</div>
<?php endif; ?>
<?php if ($details['state']): ?>
<div>
  <label><?php print t('State');?>:</label>
  <?php
    foreach ($details['state'] as $state) {
  ?>
  <div><?php print $state;?></div>
  <?php
    }
  ?>
</div>
<?php endif; ?>
<?php if ($details['notes']): ?>
<div>
  <label><?php print t('Notes');?>:</label> <?php print $details['notes'];?>
</div>
<?php endif; ?>
<?php if ($details['history']): ?>
<h2><?php print t('Purchase History');?></h2>
<div>
  <?php print $details['history'];?>
</div>
<?php endif; ?>
<?php if ($details['export']): ?>
<div>
  <?php print $details['export'];?>
</div>
<?php endif; ?>
