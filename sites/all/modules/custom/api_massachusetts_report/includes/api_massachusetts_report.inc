<?php

class APIMassachusettsReport {
  const state = 'MA';
  
  private $states = array(
    'AL' => array(
      'id' => 1,
      'name' => 'Alabama'
    ),
    'AK' => array(
      'id' => 2,
      'name' => 'Alaska'
    ),
    'AZ' => array(
      'id' => 3,
      'name' => 'Arizona'
    ),
    'AR' => array(
      'id' => 4,
      'name' => 'Arkansas'
    ),
    'CA' => array(
      'id' => 5,
      'name' => 'California'
    ),
    'CO' => array(
      'id' => 6,
      'name' => 'Colorado'
    ),
    'CT' => array(
      'id' => 7,
      'name' => 'Connecticut'
    ),
    'DC' => array(
      'id' => 8,
      'name' => 'District of Columbia'
    ),
    'FL' => array(
      'id' => 9,
      'name' => 'Florida'
    ),
    'GA' => array(
      'id' => 10,
      'name' => 'Georgia'
    ),
    'HI' => array(
      'id' => 11,
      'name' => 'Hawaii'
    ),
    'ID' => array(
      'id' => 12,
      'name' => 'Idaho'
    ),
    'IL' => array(
      'id' => 13,
      'name' => 'Illinois'
    ),
    'IN' => array(
      'id' => 14,
      'name' => 'Indiana'
    ),
    'IA' => array(
      'id' => 15,
      'name' => 'Iowa'
    ),
    'KS' => array(
      'id' => 16,
      'name' => 'Kansas'
    ),
    'KY' => array(
      'id' => 17,
      'name' => 'Kentucky'
    ),
    'LA' => array(
      'id' => 18,
      'name' => 'Louisiana'
    ),
    'ME' => array(
      'id' => 19,
      'name' => 'Maine'
    ),
    'MD' => array(
      'id' => 20,
      'name' => 'Maryland'
    ),
    'MA' => array(
      'id' => 21,
      'name' => 'Massachusetts'
    ),
    'MI' => array(
      'id' => 22,
      'name' => 'Michigan'
    ),
    'MN' => array(
      'id' => 23,
      'name' => 'Minnesota'
    ),
    'MS' => array(
      'id' => 24,
      'name' => 'Mississippi'
    ),
    'MO' => array(
      'id' => 25,
      'name' => 'Missouri'
    ),
    'NE' => array(
      'id' => 26,
      'name' => 'Nebraska'
    ),
    'NV' => array(
      'id' => 27,
      'name' => 'Nevada'
    ),
    'NJ' => array(
      'id' => 28,
      'name' => 'New Jersey'
    ),
    'NM' => array(
      'id' => 29,
      'name' => 'New Mexico'
    ),
    'NY' => array(
      'id' => 30,
      'name' => 'New York'
    ),
    'NC' => array(
      'id' => 31,
      'name' => 'North Carolina'
    ),
    'ND' => array(
      'id' => 32,
      'name' => 'North Dakota'
    ),
    'OH' => array(
      'id' => 33,
      'name' => 'Ohio'
    ),
    'OK' => array(
      'id' => 34,
      'name' => 'Oklahoma'
    ),
    'PA' => array(
      'id' => 35,
      'name' => 'Pennsylvania'
    ),
    'RI' => array(
      'id' => 36,
      'name' => 'Rhode Island'
    ),
    'SC' => array(
      'id' => 37,
      'name' => 'South Carolina'
    ),
    'SD' => array(
      'id' => 38,
      'name' => 'South Dakota'
    ),
    'TN' => array(
      'id' => 39,
      'name' => 'Tennessee'
    ),
    'TX' => array(
      'id' => 40,
      'name' => 'Texas'
    ),
    'UT' => array(
      'id' => 41,
      'name' => 'Utah'
    ),
    'VT' => array(
      'id' => 42,
      'name' => 'Vermont'
    ),
    'VA' => array(
      'id' => 43,
      'name' => 'Virginia'
    ),
    'WA' => array(
      'id' => 44,
      'name' => 'Washington'
    ),
    'WV' => array(
      'id' => 45,
      'name' => 'West Virginia'
    ),
    'WI' => array(
      'id' => 46,
      'name' => 'Wisconsin'
    ),
    'WY' => array(
      'id' => 47,
      'name' => 'Wyoming'
    ),
    'OR' => array(
      'id' => 48,
      'name' => 'Oregon'
    ),
    'MT' => array(
      'id' => 49,
      'name' => 'Montana'
    ),
    'NH' => array(
      'id' => 50,
      'name' => 'New Hampshire'
    ),
    'DE' => array(
      'id' => 51,
      'name' => 'Delaware'
    ),
    'FD' => array(
      'id' => 52,
      'name' => 'Federal'
    ),
  );
  
  private $operators = array(
    'A' => 1,
    'B' => 2,
    'A+B' => 3,
    'C' => 4,
    'Reciprocity' =>5,
  );
  
  protected $orders;
  
  protected function getStateID($state = 'MA'){
    $states = $this->states;
    if (isset($states[$state]) && isset($states[$state]['id'])){
      return $states[$state]['id'];
    }
    return -1;
  }

  protected function getStates(){
    return $this->states;
  }
  
  protected function getUSTProgramID(){
    $programQuery = new EntityFieldQuery();
    $programQuery->entityCondition('entity_type', 'node')
     ->propertyCondition('type', PRODUCT_DISPLAY_CONTENT_TYPE)
     ->propertyCondition('status', NODE_PUBLISHED)
     ->fieldCondition('field_apply_rules', 'value', 1)
     ->range(0, 1);
    $result = $programQuery->execute();
    if (!empty($result['node'])) {
     $program = reset($result['node']);
     return $program->nid;
    }
    return FALSE;
  }

  protected function getOperatorID($operator_type) {
    $operators = $this->operators;
    if (isset($operators[$operator_type])){
      return $operators[$operator_type];
    }
    return 0;
  }
  
  protected function getOperators() {
    return $this->operators;
  }
  
  protected function getOrders(){
    $orders = entity_load('commerce_order', array(), array('status'=>array('pending','processing','completed')), FALSE);
    return $orders;
  }

  protected function getLineItemsFromOrders($orders){
    $items_ids = array();
    foreach($orders as $order){
      $line_items = $order->commerce_line_items[LANGUAGE_NONE];
      foreach($line_items as $line_item){
        array_push($items_ids,$line_item['line_item_id']);
      }
    }
    $items_orders = entity_load('commerce_line_item', $items_ids,array('type' =>'product'));
    return $items_orders;
  }
  
  protected function getUsersByState($state = 'MA'){
    $user_uids = array();
    
    $this->orders = $this->getOrders();

    if (count($this->orders) > 0){
      $line_items = $this->getLineItemsFromOrders($this->orders);
      foreach($line_items as $item){
        if (!empty($item->data['field_order_product_state']) && $item->data['field_order_product_state'] == $state){
          $uid = $this->orders[$item->order_id]->uid;
          array_push($user_uids, $uid);
        }
      }
    }
    
    return array_values(array_unique($user_uids));
  }
}
