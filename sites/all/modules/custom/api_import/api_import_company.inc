<?php

class ApiCompaniesMigration extends ApiMigration {

  const VOCABULARY = 'worktype';

  public function __construct($arguments = array()) {

    $this->arguments = $arguments;
    parent::__construct($arguments);

    $this->description = t('Company migration');
    $query = Database::getConnection('legacy', 'default')
             ->select('Company', 'company')
             ->fields('company', array(
                'CompanyID', 'CompanyName', 'CompanyEmail',
                'CompanyTel', 'CompanyFax', 'CompanyAddy', 'CompanyAddy2',
                'CompanyCity', 'CompanyZip', 'CompanyCountry', 'CompanyRegion',
                'IncludeInDIR', 'ExcludeInDIR'
               )
             );
    $query->leftJoin('State', 'state', 'company.FK_StateID = state.StateID');
    $query->addField('state', 'StateAbbr');

    $this->source = new MigrateSourceSQL($query, [], null, ['map_joinable' => false]);
    $this->destination = new MigrateDestinationNode(COMPANY_CONTENT_TYPE);
    $this->map = new MigrateSQLMap($this->machineName,
      [
        'CompanyID' => ['type' => 'int', 'unsigned' => TRUE, 'not null' => TRUE, 'description' => 'Company ID.']
      ],
      MigrateDestinationNode::getKeySchema()
    );

    $this->addFieldMapping('is_new')->defaultValue(TRUE);

    $this->addFieldMapping('title', 'CompanyName')->defaultValue('NO NAME');
    $this->addFieldMapping('field_tel', 'CompanyTel')->defaultValue('');

    // The country should be passed in as the primary value.
    $this->addFieldMapping('field_address', 'CompanyCountry')
         ->defaultValue(static::getDefaultCountryCode());
    $this->addFieldMapping('field_address:thoroughfare', 'CompanyAddy')->defaultValue('');
    $this->addFieldMapping('field_address:premise', 'CompanyAddy2')->defaultValue('');
    $this->addFieldMapping('field_address:locality', 'CompanyCity')->defaultValue('');
    $this->addFieldMapping('field_address:administrative_area', 'StateAbbr');
    $this->addFieldMapping('field_address:postal_code', 'CompanyZip')->defaultValue('');
    $this->addFieldMapping('field_address:province_region', 'CompanyRegion')->defaultValue('');
    $this->addFieldMapping('field_types_of_work', 'field_typework');
    $this->addFieldMapping('field_us_states', 'field_us_states')->defaultValue('');

  }

  /**
   * @inheritdoc
   */
  /**
   * Mapping Country string to the corresponding drupal country code
   * if there is no match we just set the site defaults and if there is no site default set
   * we fallback to US
   */
  public function prepareRow($row) {
    static $countries;
    if(!$countries) {
      $countries = country_get_list();
    }
    $code = array_search($row->CompanyCountry, $countries);
    $row->CompanyCountry = $code ?: static::getDefaultCountryCode();

    // Get Worktypes
    $query = Database::getConnection('legacy', 'default')
      ->select('WorkType', 'worktype')
      ->fields('worktype', array('WorkTypeID'));
    $query->condition('worktype.Other', 0);
    $query->join('CompanyWorkType', 'company_worktype', 'worktype.WorkTypeID = company_worktype.FK_WorkTypeID');
    $query->join('Company', 'company', 'company_worktype.FK_CompanyID = company.CompanyID AND company.CompanyID = :companyId', array(':companyId' => $row->CompanyID));
    $results = $query->execute();
    $row->field_typework = array();
    foreach($results as $result) {
      $row->field_typework[] = $result->WorkTypeID;
    }

    // Get States Where operate
    $query_states = Database::getConnection('legacy', 'default')
      ->select('State', 'state')
      ->fields('state', array('StateAbbr'));
    $query_states->join('CompanyState', 'cs', 'state.StateID = cs.FK_StateID');
    $query_states->condition('cs.FK_CompanyID',  $row->CompanyID);
    $results = $query_states->execute();
    $row->field_us_states = array();
    foreach($results as $result) {
      $row->field_us_states[$result->StateAbbr] = $result->StateAbbr;
    }

  }
}
