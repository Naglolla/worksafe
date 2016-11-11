<?php
/*
function api_custom_default_rules_configuration_alter(&$config){
  $rule = '{ "commerce_payment_paypal_wpp" : {
    "LABEL" : "PayPal WPP - Credit Card",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "TAGS" : [ "Commerce Payment" ],
    "REQUIRES" : [ "commerce_payment" ],
    "ON" : { "commerce_payment_methods" : [] },
    "DO" : [
      { "commerce_payment_enable_paypal_wpp" : {
          "commerce_order" : [ "commerce-order" ],
          "payment_method" : { "value" : {
              "method_id" : "paypal_wpp",
              "settings" : {
                "api_username" : "",
                "api_password" : "",
                "api_signature" : "",
                "server" : "sandbox",
                "card_types" : {
                  "visa" : "visa",
                  "mastercard" : "mastercard",
                  "amex" : 0,
                  "discover" : 0,
                  "maestro" : 0,
                  "solo" : 0
                },
                "code" : 1,
                "currency_code" : "USD",
                "allow_supported_currencies" : 0,
                "txn_type" : "auth_capture",
                "log" : { "request" : "request", "response" : "response" }
              }
            }
          }
        }
      }
    ]
  }
}';
  $config['commerce_payment_paypal_wpp'] = rules_import($rule);
  $rule = '{ "commerce_coupon_fixed_amount_calculate_amount" : {
    "LABEL" : "Redeem a coupon with fixed amount",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "REQUIRES" : [ "rules", "php", "commerce_coupon" ],
    "ON" : { "commerce_coupon_redeem" : [] },
    "IF" : [
      { "data_is" : {
          "data" : [ "coupon:type" ],
          "op" : "=",
          "value" : "commerce_coupon_fixed"
        }
      },
      { "entity_has_field" : { "entity" : [ "coupon" ], "field" : "commerce_coupon_fixed_amount" } },
      { "entity_has_field" : {
          "entity" : [ "commerce_order" ],
          "field" : "commerce_coupon_order_reference"
        }
      },
      { "NOT AND" : [
          { "data_is_empty" : { "data" : [ "coupon:commerce-coupon-fixed-amount" ] } }
        ]
      },
      { "data_is" : {
          "data" : [ "coupon:commerce-coupon-fixed-amount:amount" ],
          "op" : "\u003E",
          "value" : 0
        }
      },
      { "data_is" : { "data" : [ "coupon:is-active" ], "op" : "=", "value" : true } },
      { "NOT php_eval" : { "code" : "return count($commerce_order-\u003Ecommerce_coupon_order_reference[\u0027und\u0027]) \u003E 0;\r\n" } }
    ],
    "DO" : [
      { "list_add" : {
          "list" : [ "commerce-order:commerce-coupon-order-reference" ],
          "item" : [ "coupon" ],
          "unique" : 1
        }
      },
      { "commerce_coupon_action_create_coupon_line_item" : {
          "USING" : {
            "commerce_coupon" : [ "coupon" ],
            "commerce_order" : [ "commerce-order" ],
            "amount" : [ "coupon:commerce-coupon-fixed-amount:amount" ],
            "component_name" : [ "coupon:price-component-name" ],
            "currency_code" : [ "coupon:commerce-coupon-fixed-amount:currency-code" ]
          },
          "PROVIDE" : { "commerce_coupon_line_item" : { "commerce_coupon_line_item" : "commerce coupon line item" } }
        }
      }
    ]
  }
}';
  $config['commerce_coupon_fixed_amount_calculate_amount'] = rules_import($rule);
  $rule = '{ "commerce_coupon_pct_percent_amount" : {
    "LABEL" : "Calculate coupon with percentage amount",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "REQUIRES" : [ "rules", "php", "commerce_coupon" ],
    "ON" : { "commerce_coupon_redeem" : [] },
    "IF" : [
      { "data_is" : {
          "data" : [ "coupon:type" ],
          "op" : "=",
          "value" : "commerce_coupon_pct"
        }
      },
      { "entity_has_field" : { "entity" : [ "coupon" ], "field" : "commerce_coupon_percent_amount" } },
      { "NOT AND" : [
          { "data_is_empty" : { "data" : [ "coupon:commerce-coupon-percent-amount" ] } }
        ]
      },
      { "entity_has_field" : {
          "entity" : [ "commerce_order" ],
          "field" : "commerce_coupon_order_reference"
        }
      },
      { "data_is" : {
          "data" : [ "coupon:commerce-coupon-percent-amount" ],
          "op" : "\u003E",
          "value" : 1
        }
      },
      { "data_is" : { "data" : [ "coupon:is-active" ], "op" : "=", "value" : true } },
      { "NOT php_eval" : { "code" : "return count($commerce_order-\u003Ecommerce_coupon_order_reference[\u0027und\u0027]) \u003E 0;\r\n" } }
    ],
    "DO" : [
      { "list_add" : {
          "list" : [ "commerce-order:commerce-coupon-order-reference" ],
          "item" : [ "coupon" ],
          "unique" : 1
        }
      }
    ]
  }
}';
  $config['commerce_coupon_pct_percent_amount'] = rules_import($rule);
  $rule = '{ "commerce_coupon_pct_apply_pct_coupons_to_line_item" : {
    "LABEL" : "Apply percentage coupons to product line item",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "REQUIRES" : [ "rules", "commerce_product_reference" ],
    "ON" : { "commerce_product_calculate_sell_price" : [] },
    "IF" : [
      { "NOT data_is_empty" : { "data" : [ "commerce-line-item:line-item-id" ] } },
      { "entity_has_field" : {
          "entity" : [ "commerce-line-item:order" ],
          "field" : "commerce_coupon_order_reference"
        }
      }
    ],
    "DO" : [
      { "LOOP" : {
          "USING" : { "list" : [ "commerce-line-item:order:commerce-coupon-order-reference" ] },
          "ITEM" : { "list_coupon" : "Current coupon" },
          "DO" : [
            { "component_rules_commerce_couponprodref_apply_coupon_to_line_item_component" : { "line_item" : [ "commerce-line-item" ], "coupon" : [ "list-coupon" ] } }
          ]
        }
      }
    ]
  }
}';
  $config['commerce_coupon_pct_apply_pct_coupons_to_line_item'] = rules_import($rule);
}

function api_custom_default_rules_configuration(){
    $config = array();

    $rule = '{ "commerce_coupon_coupon_validation_check_company" : {
      "LABEL" : "Coupon Validation: Check company",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_coupon" ],
      "ON" : { "commerce_coupon_validate" : [] },
      "IF" : [
        { "entity_has_field" : {
            "entity" : [ "site:current-user:field-branch" ],
            "field" : "field_company"
          }
        },
        { "entity_has_field" : { "entity" : [ "coupon" ], "field" : "field_company" } },
        { "NOT data_is" : {
            "data" : [ "site:current-user:field-branch:field-company:nid" ],
            "value" : [ "coupon:field-company:nid" ]
          }
        }
      ],
      "DO" : [ { "commerce_coupon_action_is_invalid_coupon" : [] } ]
    }
  }';
    $config['commerce_coupon_coupon_validation_check_company'] = rules_import($rule);

    $rule = '{ "commerce_coupon_fixed_amount_calculate_amount_max" : {
    "LABEL" : "Redeem a coupon with fixed amount (assertion and message)",
    "PLUGIN" : "reaction rule",
    "WEIGHT" : "-1",
    "OWNER" : "rules",
    "REQUIRES" : [ "rules", "php", "commerce_coupon" ],
    "ON" : { "commerce_coupon_redeem" : [] },
    "IF" : [
      { "data_is" : {
          "data" : [ "coupon:type" ],
          "op" : "=",
          "value" : "commerce_coupon_fixed"
        }
      },
      { "entity_has_field" : { "entity" : [ "coupon" ], "field" : "commerce_coupon_fixed_amount" } },
      { "entity_has_field" : {
          "entity" : [ "commerce_order" ],
          "field" : "commerce_coupon_order_reference"
        }
      },
      { "NOT AND" : [
          { "data_is_empty" : { "data" : [ "coupon:commerce-coupon-fixed-amount" ] } }
        ]
      },
      { "data_is" : {
          "data" : [ "coupon:commerce-coupon-fixed-amount:amount" ],
          "op" : "\u003E",
          "value" : 0
        }
      },
      { "data_is" : { "data" : [ "coupon:is-active" ], "op" : "=", "value" : true } },
      { "php_eval" : { "code" : "return count($commerce_order-\u003Ecommerce_coupon_order_reference[\u0027und\u0027]) \u003E 0;\r\n" } }
    ],
    "DO" : [
      { "commerce_coupon_action_is_invalid_coupon" : [] },
      { "drupal_message" : { "message" : "Sorry, you can only apply a coupon once per order.", "type" : "error" } }
    ]
  }
}';
    $config['commerce_coupon_fixed_amount_calculate_amount_max'] = rules_import($rule);

    $rule = '{ "commerce_coupon_pct_percent_amount_max" : {
    "LABEL" : "Calculate coupon with percentage amount (assertion and message))",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "REQUIRES" : [ "rules", "php", "commerce_coupon" ],
    "ON" : { "commerce_coupon_redeem" : [] },
    "IF" : [
      { "data_is" : {
          "data" : [ "coupon:type" ],
          "op" : "=",
          "value" : "commerce_coupon_pct"
        }
      },
      { "entity_has_field" : { "entity" : [ "coupon" ], "field" : "commerce_coupon_percent_amount" } },
      { "NOT AND" : [
          { "data_is_empty" : { "data" : [ "coupon:commerce-coupon-percent-amount" ] } }
        ]
      },
      { "entity_has_field" : {
          "entity" : [ "commerce_order" ],
          "field" : "commerce_coupon_order_reference"
        }
      },
      { "data_is" : {
          "data" : [ "coupon:commerce-coupon-percent-amount" ],
          "op" : "\u003E",
          "value" : 1
        }
      },
      { "data_is" : { "data" : [ "coupon:is-active" ], "op" : "=", "value" : true } },
      { "php_eval" : { "code" : "return count($commerce_order-\u003Ecommerce_coupon_order_reference[\u0027und\u0027]) \u003E 0;\r\n" } }
    ],
    "DO" : [
      { "commerce_coupon_action_is_invalid_coupon" : [] },
      { "drupal_message" : { "message" : "Sorry, you can only apply a coupon once per order.", "type" : "error" } }
    ]
  }
}';
    $config['commerce_coupon_pct_percent_amount_max'] = rules_import($rule);
    return $config;
}
*/