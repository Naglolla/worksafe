 <?php

/**
 * @file
 * Directory Links template.
 *
 * Variables available:
 * - $arguments: Array.
 *
 */
 ?>
<div class="container-24" id="footer-link">
  <div class="content directory grid-8">
    <a href=<?php print $directory_url; ?>>
      <div class="logo pin"> </div>
      <div class="information">
        <div class="title">
          <?php print t('Directory'); ?>
        </div>
        <div class="sub-title">
          <?php print t('Search for a contractor with a valid API Safety Key near you.'); ?>
        </div>
      </div>
    </a>
  </div>
  <div class="content safety-key grid-8">
    <a href=<?php print $safety_keys['safety_help_url']; ?>>
      <div class="logo key"> </div>
      <div class="information">
        <div class="title">
          <?php print t('Safety Key'); ?>
        </div>
        <div class="sub-title">
          <?php print t($safety_keys['safety_help_text']); ?>
        </div>
      </div>
    </a>
  </div>
  <div class="content token grid-8">
    <a href=<?php (!empty($tokens_url)) ? print $tokens_url : print '#'; ?>>
      <div class="logo token"> </div>
      <div class="information">
        <div class="title">
          <?php print t('Token'); ?>
        </div>
        <div class="sub-title">
          <?php print t('Purchase tokens for your company or personal use, to later pay for your Programs.'); ?>
        </div>
      </div>
    </a>
  </div>
</div>
