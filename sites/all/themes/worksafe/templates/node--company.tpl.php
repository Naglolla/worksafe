<article<?php print $attributes; ?>>
  <?php print $user_picture; ?>
  <?php print render($title_prefix); ?>
  <?php if (!$page && $title): ?>
  <header>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
  </header>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <div<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
    ?>
    <h2><?php print $node->title; ?></h2>
    <div class="company-details">
      <div class="field"><div class="field-label"><?php print t('Company Address'); ?>:</div><div class="fiels-items"><?php print $address_1; ?></div></div>
      <div class="field"><div class="field-label"><?php print t('Company Address 2'); ?>:</div><div class="fiels-items"><?php print $address_2; ?></div></div>
      <div class="field"><div class="field-label"><?php print t('Company City'); ?>:</div><div class="fiels-items"><?php print $city; ?></div></div>
      <div class="field"><div class="field-label"><?php print t('Company State'); ?>:</div><div class="fiels-items"><?php print $state; ?></div></div>
      <div class="field"><div class="field-label"><?php print t('Company Province/Region'); ?>:</div><div class="fiels-items"><?php print $province_region; ?></div></div>
      <div class="field"><div class="field-label"><?php print t('Company ZIP/Postal Code'); ?>:</div><div class="fiels-items"><?php print $zip; ?></div></div>
      <div class="field"><div class="field-label"><?php print t('Company Country'); ?>:</div><div class="fiels-items"><?php print $country; ?></div></div>
      <div class="field"><div class="field-label"><?php print t('Company Tel'); ?>:</div><div class="fiels-items"><?php print $tel; ?></div></div>
      <?php print render($content); ?>
    </div>
    <?php if(!empty($safety_keys_block)): ?>
      <h2 class="block-title"><?php print t('Safety Keys'); ?></h2>
      <?php print $safety_keys_block; ?>
      <?php print l(t('Export'), 'directory/search/export/' . $node->title); ?>
    <?php endif; ?>
  </div>

  <div class="clearfix">
    <?php if (!empty($content['links'])): ?>
      <nav class="links node-links clearfix"><?php print render($content['links']); ?></nav>
    <?php endif; ?>
  </div>
</article>
