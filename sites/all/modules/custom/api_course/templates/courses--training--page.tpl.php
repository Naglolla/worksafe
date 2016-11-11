<div class="header">
  <div class="modulename"><?php print $module_name; ?></div>
  <div class="module-navigator">
    <div class="modules"><?php print t('Module'); ?>&nbsp;<span><?php print $current_module; ?>&nbsp;<?php print t('of'); ?>&nbsp;<?php print $count_modules; ?></span></div>
    <div class="backcourse"><?php print $back_course_link; ?></div>
  </div>
</div>
<hr>
<iframe src="<?php print $course_url; ?>" width="100%" class="autoresize" scrolling="no"></iframe>
<div class="footer">
  <?php print $quiz_course_link; ?>
  <?php print $next_module_link; ?>
</div>
