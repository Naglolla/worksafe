<?php

/**
 * Description of api_commerce
 *
 * @author
 */
class api_commerce {
  
  const commerce_line_item_type_product = 'product';
  const commerce_line_item_type_token = 'token_line_item';
  
  private $line_items;
  private $orders;
  private $order_id;
  private $uid;
  
  /**
   * Constructor.
   */
  function __construct($uid) {
    $this->uid = $uid;
  }
  
  public function getCourses($order_id){
    $this->order_id = $order_id;
    $this->orders = $this->getOrders($this->uid,array($this->order_id));
    $purchases = array();
    
    if (count($this->orders) > 0){
      $this->line_items = $this->getLineItemsFromOrders($this->orders,FALSE);

      foreach($this->line_items as $item){
        $purchase = new stdClass();

        if ($item->type == self::commerce_line_item_type_product){
          $program_id = $item->data['program_nid'];
          $operator_type = $item->data['field_order_product_type'] ? $item->data['field_order_product_type']:'NA';
          $state = $item->data['field_order_product_state'] ? $item->data['field_order_product_state']:'NA';

          $purchase_unique_id = $program_id . '__' . $operator_type . '__' . $state;

          if (!isset($purchases[$purchase_unique_id]) && $program_id){
            $us_states = _api_custom_get_us_states();

            $purchase->type = 'course';
            $purchase->created = $item->created;
            $purchase->uid = $this->uid;
            $purchase->id = $program_id;
            $purchase->program_name = api_moodle_get_program_name($program_id);
            $purchase->operator_type = $operator_type;
            $purchase->state = $state;
            $purchase->program_state_description = ($state == 'NA') ? 'N/A':$us_states[$state];
            $purchase->modules = api_moodle_user_get_purchased_items($this->uid, $program_id, $state, $operator_type);
            api_moodle_set_course_status($purchase);
            $purchases[$purchase_unique_id] = $purchase;
          } else {
            continue;
          }
        }
      }
      $purchases = array_values($purchases); //remove array keys
      usort($purchases, "self::sortCompareByCreated");
    }
    return $purchases;
  }
  
  public function getPurchases(){
    
    $purchases = array();
    
    $this->orders = $this->getOrders($this->uid);
    
    if (count($this->orders) > 0){
      $this->line_items = $this->getLineItemsFromOrders($this->orders);

      foreach($this->line_items as $item){
        $purchase = new stdClass();

        if ($item->type == self::commerce_line_item_type_product){
          $program_id = $item->data['program_nid'];
          $operator_type = $item->data['field_order_product_type'] ? $item->data['field_order_product_type']:'NA';
          $state = $item->data['field_order_product_state'] ? $item->data['field_order_product_state']:'NA';

          $purchase_unique_id = $program_id . '__' . $operator_type . '__' . $state;

          if (!isset($purchases[$purchase_unique_id]) && $program_id){
            $us_states = _api_custom_get_us_states();

            $purchase->type = 'course';
            $purchase->created = $item->created;
            $purchase->uid = $this->uid;
            $purchase->id = $program_id;
            $purchase->program_name = api_moodle_get_program_name($program_id);
            $purchase->operator_type = $operator_type;
            $purchase->state = $state;
            $purchase->program_state_description = ($state == 'NA') ? 'N/A':$us_states[$state];
            $purchase->modules = api_moodle_user_get_purchased_items($this->uid, $program_id, $state, $operator_type);
            api_moodle_set_course_status($purchase);
            $purchases[$purchase_unique_id] = $purchase;
          } else {
            continue;
          }
        } else if ($item->type == self::commerce_line_item_type_token){
          $token_code = $item->field_token_id[LANGUAGE_NONE][0]['value'];
          $purchase_unique_id = 'TOKEN__' . $token_code;

          if (!isset($purchases[$purchase_unique_id]) && $token_code){
            $purchase->type = 'token';
            $purchase->uid = $this->uid;
            $purchase->status = 'token';
            $purchase->created = $item->created;
            $purchase->code = $token_code;
            $purchase->token_id = $this->getTokenIdFromCode($token_code);
            $purchase->amount = $this->getTokenAmountByID($purchase->token_id);
            $purchases[$purchase_unique_id] = $purchase;
          } else {
            continue;
          }
        }
      }
      $purchases = array_values($purchases); //remove array keys
      usort($purchases, "self::sortCompareByCreated");
    }
    return $purchases;
  }
  
  public function getCourseName($course){
    $course_name = $course->program_name;
    if ($course->state != 'NA') {
      $course_name .= ': ' . t($course->program_state_description);
    }
    if ($course->operator_type != 'NA') {
      $course_name .= ', ' . t('Class') . ' ' . $course->operator_type;
    }
    return $course_name;
  }
  
  private function getOrders($uid,$order_ids = array()){
    $orders = entity_load('commerce_order', $order_ids, array('uid' =>$uid,'status'=>array('pending','processing','completed')), FALSE);
    return $orders;
  }
  
  private function getLineItemsFromOrders($orders,$include_tokens = TRUE){
    $items_ids = array();
    foreach($orders as $order){
      $line_items = $order->commerce_line_items[LANGUAGE_NONE];
      foreach($line_items as $line_item){
        array_push($items_ids,$line_item['line_item_id']);
      }
    }
    $items_product_entity = entity_load('commerce_line_item', $items_ids,array('type' =>'product'));
    if ($include_tokens){
      $items_token_entity = entity_load('commerce_line_item', $items_ids,array('type' =>'token_line_item'));
    } else {
      $items_token_entity = array();
    }
    $items_orders = array_merge($items_product_entity, $items_token_entity);
    usort($items_orders, "self::sortCompareByCreated");
    return $items_orders;
  }

  private function getTokenIdFromCode($code){
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'token_entity')->fieldCondition('field_token_entity_id', 'value', $code, '=');
    $results = $query->execute();
    if ($results && isset($results['token_entity'])){
      return reset(array_keys(reset($results)));
    }
    return FALSE;
  }
  
  private function getTokenAmountByID($token_id){
    $token = reset(entity_load('token_entity', array($token_id)));
    if ($token && isset($token->field_token_entity_money_charged)){
      return $token->field_token_entity_money_charged[LANGUAGE_NONE][0]['value'];
    }
    return FALSE;
  }
  
  /**
   *  Helper to sort an object by 'created' property
   */
  static private function sortCompareByCreated($a, $b)
  {
    return strcmp($b->created, $a->created);
  }
}
