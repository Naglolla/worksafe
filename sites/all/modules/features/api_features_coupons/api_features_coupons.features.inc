<?php
/**
 * @file
 * api_features_coupons.features.inc
 */

/**
 * Implements hook_commerce_coupon_default_types().
 */
function api_features_coupons_commerce_coupon_default_types() {
  $items = array(
    'commerce_coupon_fixed' => array(
      'type' => 'commerce_coupon_fixed',
      'label' => 'Fixed coupon',
      'weight' => '0',
      'data' => NULL,
      'status' => '1',
      'module' => NULL,
    ),
    'commerce_coupon_pct' => array(
      'type' => 'commerce_coupon_pct',
      'label' => 'Percentage coupon',
      'weight' => '0',
      'data' => NULL,
      'status' => '1',
      'module' => NULL,
    ),
  );
  return $items;
}
