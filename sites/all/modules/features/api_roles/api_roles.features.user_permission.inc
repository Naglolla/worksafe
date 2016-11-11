<?php
/**
 * @file
 * api_roles.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function api_roles_user_default_permissions() {
  $permissions = array();

  // Exported permission: access administration menu.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
      2 => 'customer support',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: access administration pages.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
      2 => 'customer support',
    ),
    'module' => 'system',
  );

  // Exported permission: access checkout.
  $permissions['access checkout'] = array(
    'name' => 'access checkout',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'commerce_checkout',
  );

  // Exported permission: access content.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: access content overview.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      0 => 'administrator',
      1 => 'customer support',
    ),
    'module' => 'node',
  );

  // Exported permission: access the commerceguys marketplace.
  $permissions['access the commerceguys marketplace'] = array(
    'name' => 'access the commerceguys marketplace',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerceguys_marketplace',
  );

  // Exported permission: access user administration area.
  $permissions['access user administration area'] = array(
    'name' => 'access user administration area',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
      2 => 'customer support',
    ),
    'module' => 'api_company_admin',
  );

  // Exported permission: access user profiles.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      0 => 'administrator',
      1 => 'company admin',
      2 => 'customer support',
      3 => 'service-authentication',
    ),
    'module' => 'user',
  );

  // Exported permission: admin safety keys.
  $permissions['admin safety keys'] = array(
    'name' => 'admin safety keys',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
      2 => 'customer support',
    ),
    'module' => 'api_safety_keys',
  );

  // Exported permission: administer checkout.
  $permissions['administer checkout'] = array(
    'name' => 'administer checkout',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_checkout',
  );

  // Exported permission: administer commerce discounts.
  $permissions['administer commerce discounts'] = array(
    'name' => 'administer commerce discounts',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_discount',
  );

  // Exported permission: administer commerce_coupon entities.
  $permissions['administer commerce_coupon entities'] = array(
    'name' => 'administer commerce_coupon entities',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: administer commerce_customer_profile entities.
  $permissions['administer commerce_customer_profile entities'] = array(
    'name' => 'administer commerce_customer_profile entities',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: administer commerce_order entities.
  $permissions['administer commerce_order entities'] = array(
    'name' => 'administer commerce_order entities',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: administer commerce_product entities.
  $permissions['administer commerce_product entities'] = array(
    'name' => 'administer commerce_product entities',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: administer coupon settings.
  $permissions['administer coupon settings'] = array(
    'name' => 'administer coupon settings',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: administer coupon types.
  $permissions['administer coupon types'] = array(
    'name' => 'administer coupon types',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: administer customer profile types.
  $permissions['administer customer profile types'] = array(
    'name' => 'administer customer profile types',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: administer moodle connector.
  $permissions['administer moodle connector'] = array(
    'name' => 'administer moodle connector',
    'roles' => array(),
    'module' => 'moodle_connector',
  );

  // Exported permission: administer password policy.
  $permissions['administer password policy'] = array(
    'name' => 'administer password policy',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'password_policy',
  );

  // Exported permission: administer payment methods.
  $permissions['administer payment methods'] = array(
    'name' => 'administer payment methods',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_payment',
  );

  // Exported permission: administer payments.
  $permissions['administer payments'] = array(
    'name' => 'administer payments',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_payment',
  );

  // Exported permission: administer permissions.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: administer product display types.
  $permissions['administer product display types'] = array(
    'name' => 'administer product display types',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_backoffice_product',
  );

  // Exported permission: administer product pricing.
  $permissions['administer product pricing'] = array(
    'name' => 'administer product pricing',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_product_pricing_ui',
  );

  // Exported permission: administer product types.
  $permissions['administer product types'] = array(
    'name' => 'administer product types',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: administer shipping.
  $permissions['administer shipping'] = array(
    'name' => 'administer shipping',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_shipping',
  );

  // Exported permission: administer users.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      0 => 'administrator',
      1 => 'company admin',
      2 => 'customer support',
    ),
    'module' => 'user',
  );

  // Exported permission: api users admin.
  $permissions['api users admin'] = array(
    'name' => 'api users admin',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
    ),
    'module' => 'api_users',
  );

  // Exported permission: api users customer support.
  $permissions['api users customer support'] = array(
    'name' => 'api users customer support',
    'roles' => array(
      0 => 'antea user',
      1 => 'customer support',
    ),
    'module' => 'api_users',
  );

  // Exported permission: cancel account.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: change own username.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
      2 => 'company admin',
      3 => 'customer support',
    ),
    'module' => 'user',
  );

  // Exported permission: choose user revisions.
  $permissions['choose user revisions'] = array(
    'name' => 'choose user revisions',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user_revision',
  );

  // Exported permission: configure order settings.
  $permissions['configure order settings'] = array(
    'name' => 'configure order settings',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: configure store.
  $permissions['configure store'] = array(
    'name' => 'configure store',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce',
  );

  // Exported permission: create branch content.
  $permissions['create branch content'] = array(
    'name' => 'create branch content',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: create commerce_coupon entities.
  $permissions['create commerce_coupon entities'] = array(
    'name' => 'create commerce_coupon entities',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: create commerce_coupon entities of bundle commerce_coupon_fixed.
  $permissions['create commerce_coupon entities of bundle commerce_coupon_fixed'] = array(
    'name' => 'create commerce_coupon entities of bundle commerce_coupon_fixed',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: create commerce_coupon entities of bundle commerce_coupon_pct.
  $permissions['create commerce_coupon entities of bundle commerce_coupon_pct'] = array(
    'name' => 'create commerce_coupon entities of bundle commerce_coupon_pct',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: create commerce_order entities.
  $permissions['create commerce_order entities'] = array(
    'name' => 'create commerce_order entities',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: create commerce_order entities of bundle commerce_order.
  $permissions['create commerce_order entities of bundle commerce_order'] = array(
    'name' => 'create commerce_order entities of bundle commerce_order',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: create commerce_product entities.
  $permissions['create commerce_product entities'] = array(
    'name' => 'create commerce_product entities',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: create commerce_product entities of bundle product.
  $permissions['create commerce_product entities of bundle product'] = array(
    'name' => 'create commerce_product entities of bundle product',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: create commerce_product entities of bundle token.
  $permissions['create commerce_product entities of bundle token'] = array(
    'name' => 'create commerce_product entities of bundle token',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: create company content.
  $permissions['create company content'] = array(
    'name' => 'create company content',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: create page content.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
    ),
    'module' => 'node',
  );

  // Exported permission: create payments.
  $permissions['create payments'] = array(
    'name' => 'create payments',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_payment',
  );

  // Exported permission: create product_display content.
  $permissions['create product_display content'] = array(
    'name' => 'create product_display content',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
    ),
    'module' => 'node',
  );

  // Exported permission: create token content.
  $permissions['create token content'] = array(
    'name' => 'create token content',
    'roles' => array(
      0 => 'antea user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any branch content.
  $permissions['delete any branch content'] = array(
    'name' => 'delete any branch content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any company content.
  $permissions['delete any company content'] = array(
    'name' => 'delete any company content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any page content.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any product_display content.
  $permissions['delete any product_display content'] = array(
    'name' => 'delete any product_display content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any token content.
  $permissions['delete any token content'] = array(
    'name' => 'delete any token content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own branch content.
  $permissions['delete own branch content'] = array(
    'name' => 'delete own branch content',
    'roles' => array(
      0 => 'antea user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own company content.
  $permissions['delete own company content'] = array(
    'name' => 'delete own company content',
    'roles' => array(
      0 => 'antea user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own page content.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own product_display content.
  $permissions['delete own product_display content'] = array(
    'name' => 'delete own product_display content',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own token content.
  $permissions['delete own token content'] = array(
    'name' => 'delete own token content',
    'roles' => array(
      0 => 'antea user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own user revisions.
  $permissions['delete own user revisions'] = array(
    'name' => 'delete own user revisions',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user_revision',
  );

  // Exported permission: delete payments.
  $permissions['delete payments'] = array(
    'name' => 'delete payments',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_payment',
  );

  // Exported permission: delete revisions.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete user revisions.
  $permissions['delete user revisions'] = array(
    'name' => 'delete user revisions',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user_revision',
  );

  // Exported permission: eck create entity.
  $permissions['eck create entity'] = array(
    'name' => 'eck create entity',
    'roles' => array(
      0 => 'administrator',
      1 => 'customer support',
    ),
    'module' => 'eck',
  );

  // Exported permission: eck delete entity.
  $permissions['eck delete entity'] = array(
    'name' => 'eck delete entity',
    'roles' => array(
      0 => 'administrator',
      1 => 'customer support',
    ),
    'module' => 'eck',
  );

  // Exported permission: eck update entity.
  $permissions['eck update entity'] = array(
    'name' => 'eck update entity',
    'roles' => array(
      0 => 'administrator',
      1 => 'customer support',
    ),
    'module' => 'eck',
  );

  // Exported permission: eck view entity.
  $permissions['eck view entity'] = array(
    'name' => 'eck view entity',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
      2 => 'customer support',
    ),
    'module' => 'eck',
  );

  // Exported permission: edit any branch content.
  $permissions['edit any branch content'] = array(
    'name' => 'edit any branch content',
    'roles' => array(
      0 => 'antea user',
      1 => 'customer support',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any commerce_coupon entity.
  $permissions['edit any commerce_coupon entity'] = array(
    'name' => 'edit any commerce_coupon entity',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: edit any commerce_coupon entity of bundle commerce_coupon_fixed.
  $permissions['edit any commerce_coupon entity of bundle commerce_coupon_fixed'] = array(
    'name' => 'edit any commerce_coupon entity of bundle commerce_coupon_fixed',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: edit any commerce_coupon entity of bundle commerce_coupon_pct.
  $permissions['edit any commerce_coupon entity of bundle commerce_coupon_pct'] = array(
    'name' => 'edit any commerce_coupon entity of bundle commerce_coupon_pct',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: edit any commerce_customer_profile entity.
  $permissions['edit any commerce_customer_profile entity'] = array(
    'name' => 'edit any commerce_customer_profile entity',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: edit any commerce_customer_profile entity of bundle billing.
  $permissions['edit any commerce_customer_profile entity of bundle billing'] = array(
    'name' => 'edit any commerce_customer_profile entity of bundle billing',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: edit any commerce_customer_profile entity of bundle shipping.
  $permissions['edit any commerce_customer_profile entity of bundle shipping'] = array(
    'name' => 'edit any commerce_customer_profile entity of bundle shipping',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: edit any commerce_order entity.
  $permissions['edit any commerce_order entity'] = array(
    'name' => 'edit any commerce_order entity',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: edit any commerce_order entity of bundle commerce_order.
  $permissions['edit any commerce_order entity of bundle commerce_order'] = array(
    'name' => 'edit any commerce_order entity of bundle commerce_order',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: edit any commerce_product entity.
  $permissions['edit any commerce_product entity'] = array(
    'name' => 'edit any commerce_product entity',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit any commerce_product entity of bundle product.
  $permissions['edit any commerce_product entity of bundle product'] = array(
    'name' => 'edit any commerce_product entity of bundle product',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit any commerce_product entity of bundle token.
  $permissions['edit any commerce_product entity of bundle token'] = array(
    'name' => 'edit any commerce_product entity of bundle token',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: edit any company content.
  $permissions['edit any company content'] = array(
    'name' => 'edit any company content',
    'roles' => array(
      0 => 'antea user',
      1 => 'customer support',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any page content.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any product_display content.
  $permissions['edit any product_display content'] = array(
    'name' => 'edit any product_display content',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any token content.
  $permissions['edit any token content'] = array(
    'name' => 'edit any token content',
    'roles' => array(
      0 => 'antea user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own branch content.
  $permissions['edit own branch content'] = array(
    'name' => 'edit own branch content',
    'roles' => array(
      0 => 'antea user',
      1 => 'company admin',
      2 => 'customer support',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own commerce_coupon entities.
  $permissions['edit own commerce_coupon entities'] = array(
    'name' => 'edit own commerce_coupon entities',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: edit own commerce_coupon entities of bundle commerce_coupon_fixed.
  $permissions['edit own commerce_coupon entities of bundle commerce_coupon_fixed'] = array(
    'name' => 'edit own commerce_coupon entities of bundle commerce_coupon_fixed',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: edit own commerce_coupon entities of bundle commerce_coupon_pct.
  $permissions['edit own commerce_coupon entities of bundle commerce_coupon_pct'] = array(
    'name' => 'edit own commerce_coupon entities of bundle commerce_coupon_pct',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: edit own commerce_order entities.
  $permissions['edit own commerce_order entities'] = array(
    'name' => 'edit own commerce_order entities',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: edit own commerce_order entities of bundle commerce_order.
  $permissions['edit own commerce_order entities of bundle commerce_order'] = array(
    'name' => 'edit own commerce_order entities of bundle commerce_order',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: edit own commerce_product entities.
  $permissions['edit own commerce_product entities'] = array(
    'name' => 'edit own commerce_product entities',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit own commerce_product entities of bundle product.
  $permissions['edit own commerce_product entities of bundle product'] = array(
    'name' => 'edit own commerce_product entities of bundle product',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit own commerce_product entities of bundle token.
  $permissions['edit own commerce_product entities of bundle token'] = array(
    'name' => 'edit own commerce_product entities of bundle token',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: edit own company.
  $permissions['edit own company'] = array(
    'name' => 'edit own company',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
      2 => 'company admin',
      3 => 'customer support',
    ),
    'module' => 'api_company_admin',
  );

  // Exported permission: edit own company content.
  $permissions['edit own company content'] = array(
    'name' => 'edit own company content',
    'roles' => array(
      0 => 'antea user',
      1 => 'company admin',
      2 => 'customer support',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own page content.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own product_display content.
  $permissions['edit own product_display content'] = array(
    'name' => 'edit own product_display content',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own token content.
  $permissions['edit own token content'] = array(
    'name' => 'edit own token content',
    'roles' => array(
      0 => 'antea user',
    ),
    'module' => 'node',
  );

  // Exported permission: flush caches.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: import users feeds.
  $permissions['import users feeds'] = array(
    'name' => 'import users feeds',
    'roles' => array(
      0 => 'company admin',
    ),
    'module' => 'feeds',
  );

  // Exported permission: revert own user revisions.
  $permissions['revert own user revisions'] = array(
    'name' => 'revert own user revisions',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user_revision',
  );

  // Exported permission: revert revisions.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      0 => 'administrator',
      1 => 'customer support',
    ),
    'module' => 'node',
  );

  // Exported permission: revert user revisions.
  $permissions['revert user revisions'] = array(
    'name' => 'revert user revisions',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user_revision',
  );

  // Exported permission: select account cancellation method.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: update payments.
  $permissions['update payments'] = array(
    'name' => 'update payments',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_payment',
  );

  // Exported permission: view any commerce_coupon entity.
  $permissions['view any commerce_coupon entity'] = array(
    'name' => 'view any commerce_coupon entity',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: view any commerce_coupon entity of bundle commerce_coupon_fixed.
  $permissions['view any commerce_coupon entity of bundle commerce_coupon_fixed'] = array(
    'name' => 'view any commerce_coupon entity of bundle commerce_coupon_fixed',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: view any commerce_coupon entity of bundle commerce_coupon_pct.
  $permissions['view any commerce_coupon entity of bundle commerce_coupon_pct'] = array(
    'name' => 'view any commerce_coupon entity of bundle commerce_coupon_pct',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: view any commerce_customer_profile entity.
  $permissions['view any commerce_customer_profile entity'] = array(
    'name' => 'view any commerce_customer_profile entity',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: view any commerce_customer_profile entity of bundle billing.
  $permissions['view any commerce_customer_profile entity of bundle billing'] = array(
    'name' => 'view any commerce_customer_profile entity of bundle billing',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: view any commerce_customer_profile entity of bundle shipping.
  $permissions['view any commerce_customer_profile entity of bundle shipping'] = array(
    'name' => 'view any commerce_customer_profile entity of bundle shipping',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: view any commerce_order entity.
  $permissions['view any commerce_order entity'] = array(
    'name' => 'view any commerce_order entity',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
      2 => 'company admin',
      3 => 'customer support',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: view any commerce_order entity of bundle commerce_order.
  $permissions['view any commerce_order entity of bundle commerce_order'] = array(
    'name' => 'view any commerce_order entity of bundle commerce_order',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: view any commerce_product entity.
  $permissions['view any commerce_product entity'] = array(
    'name' => 'view any commerce_product entity',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view any commerce_product entity of bundle product.
  $permissions['view any commerce_product entity of bundle product'] = array(
    'name' => 'view any commerce_product entity of bundle product',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view any commerce_product entity of bundle token.
  $permissions['view any commerce_product entity of bundle token'] = array(
    'name' => 'view any commerce_product entity of bundle token',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: view moodle courselist.
  $permissions['view moodle courselist'] = array(
    'name' => 'view moodle courselist',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'moodle_courselist',
  );

  // Exported permission: view own commerce_coupon entities.
  $permissions['view own commerce_coupon entities'] = array(
    'name' => 'view own commerce_coupon entities',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: view own commerce_coupon entities of bundle commerce_coupon_fixed.
  $permissions['view own commerce_coupon entities of bundle commerce_coupon_fixed'] = array(
    'name' => 'view own commerce_coupon entities of bundle commerce_coupon_fixed',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: view own commerce_coupon entities of bundle commerce_coupon_pct.
  $permissions['view own commerce_coupon entities of bundle commerce_coupon_pct'] = array(
    'name' => 'view own commerce_coupon entities of bundle commerce_coupon_pct',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: view own commerce_order entities.
  $permissions['view own commerce_order entities'] = array(
    'name' => 'view own commerce_order entities',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: view own commerce_order entities of bundle commerce_order.
  $permissions['view own commerce_order entities of bundle commerce_order'] = array(
    'name' => 'view own commerce_order entities of bundle commerce_order',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: view own commerce_product entities.
  $permissions['view own commerce_product entities'] = array(
    'name' => 'view own commerce_product entities',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view own commerce_product entities of bundle product.
  $permissions['view own commerce_product entities of bundle product'] = array(
    'name' => 'view own commerce_product entities of bundle product',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view own commerce_product entities of bundle token.
  $permissions['view own commerce_product entities of bundle token'] = array(
    'name' => 'view own commerce_product entities of bundle token',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: view own safety keys.
  $permissions['view own safety keys'] = array(
    'name' => 'view own safety keys',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'api_safety_keys',
  );

  // Exported permission: view own unpublished content.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
      2 => 'customer support',
    ),
    'module' => 'node',
  );

  // Exported permission: view own user revisions.
  $permissions['view own user revisions'] = array(
    'name' => 'view own user revisions',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user_revision',
  );

  // Exported permission: view payments.
  $permissions['view payments'] = array(
    'name' => 'view payments',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_payment',
  );

  // Exported permission: view program pages.
  $permissions['view program pages'] = array(
    'name' => 'view program pages',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
    ),
    'module' => 'api_moodle',
  );

  // Exported permission: view revisions.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      0 => 'administrator',
      1 => 'customer support',
    ),
    'module' => 'node',
  );

  // Exported permission: view the administration theme.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      0 => 'administrator',
      1 => 'antea user',
      2 => 'customer support',
    ),
    'module' => 'system',
  );

  // Exported permission: view user revisions.
  $permissions['view user revisions'] = array(
    'name' => 'view user revisions',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user_revision',
  );

  return $permissions;
}
