<?php
/**
 * @file
 * api_features_blocks.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function api_features_blocks_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'API footer image';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'api_footer_image';
  $fe_block_boxes->body = '<a href="http://www.americanpetroleuminstitute.com/" target="_blank"><span id="footer-api-image"></span></a>';

  $export['api_footer_image'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Footer text copyright';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'copyright';
  $fe_block_boxes->body = '<span id="footer-copyright">Copyright 2015 – American Petroleum Institute, all rights reserved.
<a href="http://www.americanpetroleuminstitute.com/globalitems/globalfooterpages/privacy" target="_blank">Privacy Policy</a> | <a href="http://www.americanpetroleuminstitute.com/globalitems/globalfooterpages/terms-and-conditions" target="_blank">Terms and Conditions</a> | <a href="/help">Contact Customer Service</a></span>';

  $export['copyright'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Footer Directory  and Safty key Links';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'directorylinks';
  $fe_block_boxes->body = '<div id="footer-link" class="container-24"><div class="content directory grid-8"><a href="directory"><div class="logo pin"></div><div class="information"><div class="title">Directory</div><div class="sub-title">Search for a contractor with a valid API Safety Key near you.</div></div></a></div><div class="content safety-key grid-8"><a href="safety-keys"><div class="logo key"></div><div class="information"><div class="title">Safety Key</div><div class="sub-title">Verify an API Safety Key using the unique identification code.</div></div></a></div><div class="content token grid-8"><a href="token"><div class="logo token"></div><div class="information"><div class="title">Token</div><div class="sub-title">Purchase tokens for your company or personal use, to later pay for your Programs.</div></div></a></div></div>';

  $export['directorylinks'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Full Hero Header';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'header';
  $fe_block_boxes->body = '<div id="header-full-hero"><div id="full-hero"><div class="content"><div class="title"></div><div class="info">With web-based safety training for E&P onshore operators, crude-by-rail operators, Class A, B and C operators, and service station contractors, API WorkSafe proves that when we all work together to improve safety, everybody works safe.</div></div></div><div class="info mobile">With web-based safety training for E&P onshore operators, crude-by-rail operators, Class A, B and C operators, and service station contractors, API WorkSafe proves that when we all work together to improve safety, everybody works safe.</div></div>';

  $export['header'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Training program';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'trainingprogram';
  $fe_block_boxes->body = '<div id="training-program" class="container-24">
   <div class="title">Training Programs</div>
   <div  id="program-container">
     <div class="no-margin grid-12">
       <div class="program onshore">
         <div class="header"></div>
         <div class="name">E&amp;P Onshore</div>
         <div class="information">Class A, B and C operator training that meets federal and state regulatory requirements</div>
         <div class="purchase">
           <a href="programs">Purchase Training</a>
         </div>
       </div>
     </div>
   <div class="no-margin grid-12">
     <div class="program crude-rail">
       <div class="header"></div>
       <div class="name">Crude Oil by Rail</div>
       <div class="information">Class A, B and C operator training that meets federal and state regulatory requirements</div>
       <div class="purchase">
         <a href="programs">Purchase Training</a>
       </div>
     </div>
   </div>
   <div class="no-margin grid-12">
     <div class="program operator ">
       <div class="header"></div>
       <div class="name">Operator</div>
       <div class="information">Class A, B and C operator training that meets federal and state regulatory requirements</div>
       <div class="purchase">
         <a href="programs">Purchase Training</a>
       </div>
     </div>
   </div>
   <div class="no-margin grid-12">
     <div class="program service-station">
       <div class="header"></div>
       <div class="name">Service Station</div>
       <div class="information">Class A, B and C operator training that meets federal and state regulatory requirements</div>
       <div class="purchase">
         <a href="programs">Purchase Training</a>
       </div>
     </div>
</div>
   </div>

 <!-- Slides Container -->
<div id="slider-program-container"><div u="slides" class="slider-group"><div><img u="image" src="sites/all/themes/worksafe/images/e-p-onshore.png" /><div class="onshore header"></div><div class="title">E&amp;P Onshore</div></div><div><img u="image" src="sites/all/themes/worksafe/images/crude-by-rail.png" /><div class="crude-rail header"></div><div class="title">Crude Oil by Rail</div></div><div><img u="image" src="sites/all/themes/worksafe/images/operator.png" /><div class="operator header"></div><div class="title">Operator</div></div><div><img u="image" src="sites/all/themes/worksafe/images/service-station.png" /><div class="service-station header"></div><div class="title">Service Station</div></div></div><div u="navigator" class="bullet"><div u="prototype" class="bullet-content "></div></div></div>
<!-- End Slider Container -->
  </div>';

  $export['trainingprogram'] = $fe_block_boxes;

  return $export;
}
