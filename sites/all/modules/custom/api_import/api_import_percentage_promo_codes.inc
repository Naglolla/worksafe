<?php

class ApiPercentagePromoCodesMigration extends ApiMigration {
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    $this->arguments = $arguments;
    
    $this->description = t('Percentage promo codes migration');
    //promocodeTypeid is used in the legacy system to identify promo codes
    //1 means percentage promo codes
    //2 means fixed amount promo codes
    
    $query = Database::getConnection('legacy', 'default')
            ->select('PromoCode', 'promocode')
            ->fields('promocode', array(
              'PromoCodeID', 'PromoCode', 'PromoCodeValue', 'DateCreated', 'isActive',
              'isOneTime',
            ))
            ->condition('promocode.Fk_PromocodeTypeid', 1);
    
    $query->leftJoin('State', 'state', 'promocode.Fk_StateID = state.StateID');
    $query->addField('state', 'StateAbbr');
    
    $this->source = new MigrateSourceSQL($query, array(), NULL, array('map_joinable' => FALSE));
    $this->destination = new MigrateDestinationEntityAPI('commerce_coupon', 'commerce_coupon_pct');
    $this->map = new MigrateSQLMap($this->machineName, 
                                   array(
                                     'PromoCodeID' => array('type' => 'int', 
                                                       'unsigned' => TRUE, 
                                                       'not null' => TRUE, 
                                                       'description' => 'PromoCode ID.')),
                                   MigrateDestinationEntityAPI::getKeySchema('commerce_coupon'));
    
    $this->addFieldMapping('commerce_coupon_code', 'PromoCode');
    $this->addFieldMapping('commerce_coupon_percent_amount', 'PromoCodeValue');
    $this->addFieldMapping('is_active', 'isActive');
    
    //these require postprocessing
    $this->addFieldMapping('created', 'DateCreated'); //needs to be translated to timestamp
    $this->addFieldMapping('commerce_coupon_number_of_uses', 'isOneTime'); //number of uses in zero in our system means unlimited uses?
    $this->addFieldMapping('field_states', 'StateAbbr');
    
  }
  
  public function prepareRow($row) {
    //convert DateCreated to timestamp
    $row->DateCreated = strtotime($row->DateCreated);
    
    //formatting StateAbbr as an array needed by the destination multi-value field
    $state_id = $row->StateAbbr;
    $row->StateAbbr = array();
    $row->StateAbbr[] = $state_id;
    
    
    
    return TRUE;
  }
}