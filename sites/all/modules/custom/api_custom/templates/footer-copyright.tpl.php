 <?php

/**
 * @file
 * Footer Copyrght template.
 *
 * Variables available:
 * - $arguments: Array.
 *
 */
 ?>

<span id='footer-copyright'>
  <?php // Some links are hardcoded until we begin corresponding stories ?>
  <div><?php print t('Copyright 2015 - American Petroleum Institute, all rights reserved.'); ?></div>
  <a href='http://www.americanpetroleuminstitute.com/globalitems/globalfooterpages/privacy' target="_blank"><?php print t('Privacy Policy'); ?></a> |
  <a href='http://www.americanpetroleuminstitute.com/globalitems/globalfooterpages/terms-and-conditions' target="_blank"><?php print t('Terms and Conditions'); ?></a> |
  <?php print l(t('Contact Customer Service'), $help_faq_url); ?>
</span>
