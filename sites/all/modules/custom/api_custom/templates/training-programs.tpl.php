 <?php

/**
 * @file
 * Training Programs template.
 *
 * Variables available:
 * - $arguments: Array.
 *
 */
 ?>

<div class="container-24" id="training-program">
  <div class="title"><?php print t('Training Programs'); ?></div>
  <div id="program-container">
    <?php foreach($nodes as $node): ?>
      <div class="no-margin grid-12">
          <div class="program" 
            <?php if(isset($node->field_program_image[LANGUAGE_NONE][0]['uri'])):?>
              style="background-image: url(<?php print file_create_url($node->field_program_image[LANGUAGE_NONE][0]['uri']); ?>);"
            <?php endif; ?>
          >
          <div class="header" style="background-color: <?php print $node->field_program_color[LANGUAGE_NONE][0]['rgb']; ?>;">&nbsp;</div>
          <div class="name"><?php print $node->title; ?></div>
          <div class="information"><?php print $node->body[LANGUAGE_NONE][0]['safe_value']; ?></div>
          <div class="purchase">
            <a href="program/<?php print $node->nid; ?>/buy"><?php print t('Purchase Training'); ?></a>
          </div>
        </div>
      </div>    
    <?php endforeach; ?>
  </div>
  
  <!-- Slides Container -->
  <div id="slider-program-container">
    <div class="slider-group" u="slides">
      <?php foreach($nodes as $node): ?>
        <div>
          <?php if(isset($node->field_program_image[LANGUAGE_NONE][0]['uri'])):?>
            <a href="program/<?php print $node->nid; ?>/buy">
              <img src="<?php print file_create_url($node->field_program_image[LANGUAGE_NONE][0]['uri']); ?>" u="image" />
            </a>
          <?php else: ?>
            <a href="program/<?php print $node->nid; ?>/buy">
              <img src="sites/all/themes/worksafe/images/e-p-onshore.png" u="image" />
            </a>
          <?php endif; ?>
          <div class="header" style="background-color: <?php print $node->field_program_color[LANGUAGE_NONE][0]['rgb']; ?>;">&nbsp;</div>
          <div class="title"><?php print $node->title; ?></div>
        </div>
      <?php endforeach; ?>
    </div>
    <div class="bullet" u="navigator">
      <div class="bullet-content " u="prototype">&nbsp;</div>
    </div> 
  </div>
  <!-- End Slider Container -->
  
</div>
