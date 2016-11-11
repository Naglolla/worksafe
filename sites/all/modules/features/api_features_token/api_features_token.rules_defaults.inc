<?php
/**
 * @file
 * api_features_token.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function api_features_token_default_rules_configuration() {
  $items = array();
  $items['rules_token_price_calculation'] = entity_import('rules_config', '{ "rules_token_price_calculation" : {
      "LABEL" : "Token price calculation",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_money_charged" } }
      ],
      "DO" : [
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-money-charged" ],
              "op" : "*",
              "input_2" : "100"
            },
            "PROVIDE" : { "result" : { "line_items_money_charged_cents" : "Line item money charged (in cents)" } }
          }
        },
        { "commerce_line_item_unit_price_amount" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "line-items-money-charged-cents" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  return $items;
}
