<?php

class ApiTokensMigration extends ApiMigration {

  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    $this->arguments = $arguments;

    $this->description = t('Tokens migration');
    $query = Database::getConnection('legacy', 'default')
             ->select('Token', 'token')
             ->fields('token', array(
                 'TokenID', 'FK_UserID', 'FK_CompanyID', 'FK_OrderID', 'Token', 'TotalQuantity', 'CurrentQuantity', 'DateCreated',
                 'TransferTokenID', 'SendAlert', 'PromoCodes', 'ApplyPromoCodeAutomatically', 'ApplyToCourseType', 'TokenNotes'
            ));

    $this->dependencies = ['ApiUsers'];
    
    $this->source = new MigrateSourceSQL($query, array(), null, array('map_joinable' => false));
    
    $this->destination = new MigrateDestinationEntityAPI('token_entity', 'token_entity_bundle');
    
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        //If i need a unique id.
        'TokenID' => array('type' => 'int', 'unsigned' => TRUE, 'not null' => TRUE, 'description' => 'Token ID.')
      ),
      MigrateDestinationEntityAPI::getKeySchema('token_entity', 'token_entity_bundle')
    );
    

    $this->addFieldMapping('title', 'Token');
    $this->addFieldMapping('field_token_entity_id', 'Token');
    $this->addFieldMapping('field_token_entity_money_charged', 'CurrentQuantity');
    $this->addFieldMapping('field_token_total_value', 'TotalQuantity');
    $this->addFieldMapping('field_token_notes', 'TokenNotes');
    $this->addFieldMapping('field_token_entity_date_from_to', 'DateCreated');

    $this->addFieldMapping('field_token_entity_visibility')
         ->defaultValue(1);
    $this->addFieldMapping('field_token_entity_enabled')
         ->defaultValue(1);
    $this->addFieldMapping('uid', 'FK_UserID')->sourceMigration('ApiUsers')->defaultValue(1);
    
    $this->addFieldMapping('created')->defaultValue(REQUEST_TIME);
    $this->addFieldMapping('field_token_entity_companies', 'FK_CompanyID')->sourceMigration('ApiCompanies')->defaultValue(NULL);
    
  }
  
  /**
   * @inheritdoc
   */
  public function prepare($entity, $row) {  
    // Converting date to timestamp
    $entity->created = strtotime($row->DateCreated);
  }
}
