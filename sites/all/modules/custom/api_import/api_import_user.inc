<?php

class ApiUsersMigration extends ApiMigration {

  public function __construct($arguments = array()) {
    $this->arguments = $arguments;
    parent::__construct();

    $this->description = t('Users migration');
    $query = Database::getConnection('legacy', 'default')
             ->select('Users', 'user')
             ->fields('user', array(
               'UserID', 'Username', 'FirstName', 'MiddleName', 'LastName',
               'Email', 'Job', 'Tel', 'Fax', 'Address1', 'Address2',
               'City', 'Zip', 'Country', 'ShowInDIR',
               'BillingAddr1', 'BillingAddr2', 'BillingCity', 'BillingZip', 'BillingCountry', 'BillingFK_StateID',
               'FK_CompanyID',
               'Approved'
             ));
    $query->leftJoin('State', 'state', 'user.FK_StateID = state.StateID');
    $query->addField('state', 'StateAbbr');
    $query->leftJoin('Language', 'lang', 'user.FK_LangID = lang.LangID');
    $query->addField('lang', 'LangPrefix');
    $query->leftJoin('Company', 'company', 'user.FK_CompanyID = company.CompanyID');
    $query->fields('company', array(
      'CompanyID', 'CompanyAddy', 'CompanyAddy2',
      'CompanyCity', 'CompanyCountry', 'CompanyZip',
      'CompanyRegion', 'CompanyTel', 'CompanyFax'
    ));
    $query->addField('company', 'FK_StateID', 'FK_CompanyStateID');

    $this->source = new MigrateSourceSQL($query, array(), null, array('map_joinable' => false));
    $this->destination = new MigrateDestinationUser();
    $this->map = new MigrateSQLMap($this->machineName,
        array(
          'UserID' => array('type' => 'int', 'unsigned' => TRUE, 'not null' => TRUE, 'description' => 'user ID.')
        ),
        MigrateDestinationUser::getKeySchema()
    );

    $this->addFieldMapping('is_new')
         ->defaultValue(TRUE);

    /**
     * Users are blocked by default
     * 0 = blocked
     * 1 = active
     **/
    $this->addFieldMapping('status', 'Approved')
         ->defaultValue(1);

    /** Register **/
    $this->addFieldMapping('field_first_name', 'FirstName');
    $this->addFieldMapping('field_middle_name', 'MiddleName');
    $this->addFieldMapping('field_last_name', 'LastName');
    $this->addFieldMapping('field_job_title', 'Job');

    /** Company **/
    $this->addFieldMapping('field_branch', 'branch_nid');
    $this->addFieldMapping('field_address', 'Country')
      ->defaultValue(static::getDefaultCountryCode());
    $this->addFieldMapping('field_address:thoroughfare', 'Address1');
    $this->addFieldMapping('field_address:premise', 'Address2');
    $this->addFieldMapping('field_address:locality', 'City');
    $this->addFieldMapping('field_address:administrative_area', 'StateAbbr');
    $this->addFieldMapping('field_address:postal_code', 'Zip');

    /** Contact Details **/
    $this->addFieldMapping('field_local_company_address', 'CompanyCountry')
         ->defaultValue(static::getDefaultCountryCode());
    $this->addFieldMapping('field_local_company_address:thoroughfare', 'CompanyAddy');
    $this->addFieldMapping('field_local_company_address:premise', 'CompanyAddy2');
    $this->addFieldMapping('field_local_company_address:locality', 'CompanyCity');
    $this->addFieldMapping('field_local_company_address:administrative_area', 'FK_CompanyStateID');

    $this->addFieldMapping('field_local_company_address:postal_code', 'CompanyZip');
    $this->addFieldMapping('field_local_company_region', 'CompanyRegion');
    $this->addFieldMapping('field_local_company_telfax', 'CompanyTel');

    $this->addFieldMapping('field_tel', 'Tel');

    /** Account Information **/
    $this->addFieldMapping('name', 'Username')
         ->dedupe('users', 'name');
    //$this->addFieldMapping('pass', 'password');
    $this->addFieldMapping('mail', 'Email');

    /** Preferences **/
    $this->addFieldMapping('field_public_safety_key', 'ShowInDIR');

    /** Others **/
    $this->addFieldMapping('language')
         ->defaultValue('');
    $this->addFieldMapping('theme')
         ->defaultValue('');
    $this->addFieldMapping('signature')
         ->defaultValue('');
    $this->addFieldMapping('signature_format')
         ->defaultValue('filtered_html');
    $this->addFieldMapping('field_accept_terms_and_condition')
         ->defaultValue(true);

    $this->addFieldMapping('picture')
         ->defaultValue(0);

    $this->addFieldMapping('timezone')
         ->defaultValue(NULL);

    $this->addFieldMapping('roles', 'roles');

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
    parent::prepareRow($row);
    static $countries;
    if(!$countries) {
      $countries = country_get_list();
    }
    $code = array_search($row->Country, $countries);
    $row->Country = $code ?: static::getDefaultCountryCode();
    $code = array_search($row->CompanyCountry, $countries);
    $row->CompanyCountry = $code ?: static::getDefaultCountryCode();
    $code = array_search($row->BillingCountry, $countries);
    $row->BillingCountry = $code ?: static::getDefaultCountryCode();

    // Add Facility realtion.
    // Get user company nid.
    $company_nid = $this->getCompanyNID($row->FK_CompanyID);

    if (!empty($company_nid)) {
      $query = Database::getConnection('legacy', 'default')
        ->select('UserContactDetails', 'ucd')
        ->fields('ucd', array('FK_UserID', 'UserContactDetailID', 'Address1', 'Address2', 'City', 'FK_StateID', 'Zip', 'Country', 'Tel', 'SSNo', 'FacilityID'));
      $query = $query->condition('ucd.FK_UserID', $row->UserID);
      $query = $query->range(0, 1);
      $result = $query->execute()->fetchAll();

      if (!empty($result)) {
        // Add a new faciility with this info.
        $info = reset($result);
        $branch_info['branch_state'] = $this->getStateCodeById($info->FK_StateID);
        $branch_info['branch_title'] = t('@city @state', array('@city' => $info->City, '@state' => $branch_state));

        if (!empty($info->FacilityID)) {
          $branch_info['branch_title'] = filter_xss($info->FacilityID);
        }

        $code = array_search($info->Country, $countries);
        $branch_info['country_code'] = $code ?: static::getDefaultCountryCode();
        $branch_info['company_nid'] = $company_nid;
        $branch_info['City'] = $info->City;
        $branch_info['Zip'] = $info->Zip;
        $branch_info['Address1'] = $info->Address1;
        $branch_info['Address2'] = $info->Address2;
        $branch_info['Tel'] = $info->Tel;

        $branch_nid = $this->createBranch($branch_info);
      } else {
        // looking for a company's facility.
        $company_branches = api_custom_company_branches($company_nid);
        if (!empty($company_branches)) {
          $company_branches_nids = reset($company_branches);
          $branch_nid = $company_branches_nids->nid;
        } else {
          // Create branch with company info.
          $branch_info['company_nid'] = $company_nid;
          $company = node_load($company_nid);

          $state = _api_custom_field_item('node', $company, 'field_address', 'administrative_area');
          $states = _api_custom_get_us_states();
          $state_name = !empty($states[$state]) ? $states[$state] : $state;

          // Try to get the Country name
          $country = _api_custom_field_item('node', $company, 'field_address', 'country');
          $countries = _addressfield_country_options_list();
          $country_name = !empty($countries[$country]) ? $countries[$country] : $country;

          $city = _api_custom_field_item('node', $company, 'field_address', 'locality');
          $province_region = _api_custom_field_item('node', $company, 'field_address', 'province_region');

          $branch_info['branch_title'] = t('@city @state', array('@city' => $city, '@state' => $state_name));
          $branch_info['branch_state'] = $state;
          $branch_info['country_code'] = $country;
          $branch_info['City'] = $city;
          $branch_info['Zip'] = _api_custom_field_item('node', $company, 'field_address', 'postal_code');
          $branch_info['Address1'] = _api_custom_field_item('node', $company, 'field_address', 'thoroughfare');
          $branch_info['Address2'] = _api_custom_field_item('node', $company, 'field_address', 'premise');
          $branch_info['Tel'] = _api_custom_field_item('node', $company, 'field_tel');
          $branch_info['Region'] = _api_custom_field_item('node', $company, 'field_address', 'province_region');
          $branch_nid = $this->createBranch($branch_info);
        }
      }
    }

    $row->branch_nid = !empty($branch_nid) ? $branch_nid : NULL;
    return true;
  }

  /**
   * @inheritdoc
   */
  public function prepare($entity, $row) {
    $lang = 0;
    if(strpos($row->LangPrefix, 'es-') !== false) {
      $lang = 1;
    }
    $entity->field_language[LANGUAGE_NONE][0]['value'] = $lang;
    if(isset($row->FK_CompanyStateID)) {
      $entity->field_local_company_address[LANGUAGE_NONE][0]['administrative_area'] = $this->getStateCodeById($row->FK_CompanyStateID);
    }
  }

  /**
   * @inheritdoc
   */
  public function complete($entity, $row) {
    $query = Database::getConnection('legacy', 'default')
      ->select('Roles', 'r')
      ->fields('r', array('RoleName'));
    $query->join('UserRoles', 'user_role',
      'r.RoleID = user_role.RoleID AND user_role.UserID = :userId',
      array(':userId' => $row->UserID));
    $roles = $query->execute();
    foreach ($roles as $role) {
      switch ($role->RoleName) {
        case 'Company Admin':
          $r = user_role_load_by_name('company admin');
          user_multiple_role_edit(array($entity->uid), 'add_role', $r->rid);
          break;
        case 'Admins':
          $r = user_role_load_by_name('antea user');
          user_multiple_role_edit(array($entity->uid), 'add_role', $r->rid);
          break;
      }
    }

    if (isset($row->BillingAddr1)) {
      $customer = commerce_customer_profile_new('billing', $entity->uid);
      $customer->_is_new = TRUE;
      $customer->commerce_customer_address[LANGUAGE_NONE][0] = array(
        'country' => $row->BillingCountry,
        'thoroughfare' => $row->BillingAddr1,
        'premise' => $row->BillingAddr2,
        'locality' => $row->BillingCity,
        'administrative_area' => $this->getStateCodeById($row->BillingFK_StateID),
        'postal_code' => $row->BillingZip
      );
      commerce_customer_profile_save($customer);
    }

  }

  protected function getStateCodeById($id) {
    $query = Database::getConnection('legacy', 'default')
      ->select('State', 's')
      ->fields('s', array('StateAbbr'))
      ->condition('s.StateID', $id, '=');
    $state = $query->execute()->fetchField();
    return $state;
  }

  protected function getCompanyNID($id) {
    $query= db_select('migrate_map_apicompanies', 'mc');
    $query->fields('mc', array('destid1'));
    $query->condition('mc.sourceid1', $id);
    $company_nid = $query->execute()->fetchField();
    return $company_nid;
  }

  public function createBranch($branch_info) {

    $branch = new stdClass();
    $branch->title = $branch_info['branch_title'];
    $branch->type = BRANCH_CONTENT_TYPE;
    node_object_prepare($branch); // Sets some defaults. Invokes hook_prepare() and hook_node_prepare().
    $branch->language = LANGUAGE_NONE; // Or e.g. 'en' if locale is enabled
    $branch->uid = 1;
    $branch->status = 1; //(1 or 0): published or not
    $branch->promote = 0; //(1 or 0): promoted to front page
    $branch->comment = 0; // 0 = comments disabled, 1 = read only, 2 = read/write

    $branch->field_address[LANGUAGE_NONE][] = array(
      'country' => $branch_info['country_code'],
      'administrative_area' => $branch_info['branch_state'],
      'sub_administrative_area' => NULL,
      'locality' => $branch_info['City'],
      'dependent_locality' => NULL,
      'province_region' => !empty($branch_info['Region']) ? $branch_info['Region'] : '',
      'postal_code' => filter_xss($branch_info['Zip']),
      'thoroughfare' => filter_xss($branch_info['Address1']),
      'premise' => filter_xss($branch_info['Address2']),
      'sub_premise' => NULL,
      'organisation_name' => NULL,
      'name_line' => NULL,
      'first_name' => NULL,
      'last_name' => NULL,
      'data' => NULL,
    );
    $branch->field_tel[LANGUAGE_NONE][] = array('value' => filter_xss($branch_info['Tel']));
    // Company reference field
    $branch->field_company[LANGUAGE_NONE][] = array(
      'target_id' => $branch_info['company_nid'],
      'target_type' => 'node',
    );
    $branch = node_submit($branch); // Prepare node for saving
    node_save($branch);
    return $branch->nid;
  }

}
