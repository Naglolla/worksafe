<div class="summary-report">
  <div class="stats">
    <h2><?php print t('Safety Key Stats'); ?></h2>
    <div class="field"><div class="field-label"><?php print t('Total Safety Keys'); ?>:</div><div class="field-items"><?php print $safety_key_stats['total']; ?></div></div>
    <div class="field"><div class="field-label"><?php print t('Total Valid Safety Keys'); ?>:<span class="form-required" title="<?php print t('Exclude Expired Safety Keys'); ?>">*</span></div><div class="field-items"><?php print $safety_key_stats['total_valid']; ?></div></div>
    <div class="field"><div class="field-label"><?php print t('Issued in Last 30 Days'); ?>:</div><div class="field-items"><?php print $safety_key_stats['30_days']; ?></div></div>
    <div class="field"><div class="field-label"><?php print t('Issued in Last 7 Days'); ?>:</div><div class="field-items"><?php print $safety_key_stats['7_days']; ?></div></div>
    <div class="field"><div class="field-label"><?php print t('Issued in Last 24 Hours'); ?>:</div><div class="field-items"><?php print $safety_key_stats['24_hours']; ?></div></div>
  </div>
  <div class="stats">
    <h2><?php print t('User Stats'); ?></h2>
    <div class="field"><div class="field-label"><?php print t('Total Users'); ?>:</div><div class="field-items"><?php print $user_stats; ?></div></div>
    <div class="field"><div class="field-label"><?php print t('Total Users With Safety Keys'); ?>:<span class="form-required" title="<?php print t('Exclude Expired Safety Keys'); ?>">*</span></div><div class="field-items"><?php print $safety_key_stats['sk_users']; ?></div></div>
  </div>
  <div class="stats">
    <h2><?php print t('Company Stats'); ?></h2>
    <div class="field"><div class="field-label"><?php print t('Total Companies'); ?>:</div><div class="field-items"><?php print $company_stats; ?></div></div>
  </div>
  <br/>
  <div class="info">
    <span class="form-required" title="<?php print t('Exclude Expired Safety Keys'); ?>">*</span><?php print t('Exclude Expired Safety Keys'); ?>
  </div>
</div>
