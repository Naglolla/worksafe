<?php

/**
 * @file
 * The default format for adresses.
 */

$plugin = array(
  'title' => t('Province / Region'),
  'format callback' => 'addressfield_format_region_generate',
  'type' => 'address',
  'weight' => -99,
);

/**
 * Format callback.
 *
 * @see CALLBACK_addressfield_format_callback()
 */
function addressfield_format_region_generate(&$format, $address, $context = array()) {
  if ($context['mode'] == 'form') {
    $format['locality_block']['province_region'] = array(
      '#title' => t('Province / Region'),
      '#size' => 30,
      '#attributes' => array('class' => array('province-region')),
      '#type' => 'textfield',
      '#tag' => 'span',
      '#default_value' => isset($address['province_region']) ? $address['province_region'] : '',
      '#weight' => 2,
    );
    $format['locality_block']['postal_code']['#weight'] = 3;
    $format['locality_block']['postal_code']['#title'] = t('ZIP / Postal Code');
  }
  else {
    // Add our own render callback for the format view
    $format['#pre_render'][] = '_api_custom_render_address';
  }
}
