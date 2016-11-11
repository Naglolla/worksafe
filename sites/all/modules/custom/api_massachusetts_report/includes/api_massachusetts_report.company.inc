<?php

class APIMassachusettsReportCompany extends APIMassachusettsReport {
  private $sheetTitle;
    
  public function __construct($program_id){
    $this->sheetTitle = 'Company';
  }

  public function getSheetTitle() {
    return $this->sheetTitle;
  }

  public function report(){
    $company_sheet = array();

    $companies = $this->getCompanies();
    
    foreach ($companies as $company) {
      $company_sheet['data'][$this->sheetTitle][] = array_values($company);
    }
    
    $company_sheet['headers'][$this->sheetTitle] = array(
      'CompanyID',
      'CompanyName',
      'CompanyEmail',
      'CompanyTel',
      'CompanyAddy',
      'FK_StateID',
      'CompanyAddy2',
      'CompanyCity',
      'CompanyZip',
    );
    return $company_sheet;
  }

  private function getCompanies(){
    $companies_list = array();
    
    $user_uids = $this->getUsersByState(self::state);
    
    foreach ($user_uids as $uid) {
      $company_id = _get_user_company($uid);
      if (!empty($company_id) && !isset($companies_list[$company_id])){
        $company_node = node_load($company_id);
        if (!empty($company_node->nid)){
          $companies_list[$company_node->nid] = $this->getCompanyInfo($company_node);
        }
      }
    }
    
    ksort($companies_list);
    return $companies_list;
  }
  
  private function getCompaniesLegacy(){
    $companies_list = array();
    
    $query = db_select('node', 'n');
    $query->fields('n', array('nid','title'));
    $query->condition('n.status', NODE_PUBLISHED)->condition('n.type', COMPANY_CONTENT_TYPE);
    $query->range(0, 5000);
    $companies = $query->execute()->fetchAllKeyed(0,0);
    $companies_nids = array_keys($companies);
    
    foreach ($companies_nids as $nid) {
      $company_node = node_load($nid);
      $companies_list[] = $this->getCompanyInfo($company_node);
    }
    
    return $companies_list;
  }
  
  private function getCompanyInfo($company){
    $state_code = _api_custom_field_item('node', $company, 'field_address', 'administrative_area');
    $company_info = array();
    $company_info['CompanyID'] = $company->nid;
    $company_info['CompanyName'] = $company->title;
    $company_info['CompanyEmail'] = '';
    $company_info['CompanyTel'] = _api_custom_field_item('node', $company, 'field_tel');
    $company_info['CompanyAddy'] = _api_custom_field_item('node', $company, 'field_address', 'thoroughfare');
    $company_info['FK_StateID'] = $this->getStateID($state_code);
    $company_info['CompanyAddy2'] = _api_custom_field_item('node', $company, 'field_address', 'premise');
    $company_info['CompanyCity'] = _api_custom_field_item('node', $company, 'field_address', 'locality');
    $company_info['CompanyZip'] = _api_custom_field_item('node', $company, 'field_address', 'postal_code');
    
    return $company_info;
  }
  
}
