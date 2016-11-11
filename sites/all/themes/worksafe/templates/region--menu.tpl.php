<div<?php print $attributes; ?>>
  <div<?php print $content_attributes; ?>>
    <?php if ($main_menu && $content): ?>
    <nav class="navigation clearfix">
      <div class="primary-menu inline grid-6">
          <a href="/<?php ($lang != 'en')? print $lang : '' ?>">
            <div id="logo"></div>
          </a>
      </div>
      <div class="second-menu inline grid-18">
        <?php print $content; ?>
      </div>
    </nav>
    <?php endif; ?>
  </div>
</div>
<?php if ($main_menu && $content): ?>
  <div id="mobile-menu-content" class="mobile-menu">
    <div id="mobile-menu-icon" class="icon"></div>
    <?php print $content; ?>
  </div>
<?php endif; ?>
