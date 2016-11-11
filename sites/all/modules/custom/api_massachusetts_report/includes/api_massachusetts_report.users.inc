<?php

class APIMassachusettsReportUsers extends APIMassachusettsReport {
  private $sheetTitle;
  public function __construct($program_id){
    $this->sheetTitle = 'Users';
  }

  public function getSheetTitle() {
    return $this->sheetTitle;
  }

  public function report(){
    $users_sheet = array();
    
    $user_uids = $this->getUsersByState(self::state);
    
    foreach ($user_uids as $uid) {
      $user = user_load($uid);
      // Skip anonymous user / internal roles
      if (empty($user) || empty($user->uid)) {
        continue;
      } else if ($user->roles && (in_array(ADMIN_ROLE,$user->roles) || in_array('service-authentication',$user->roles))){
        continue;
      }
      
      $users_sheet['data'][$this->sheetTitle][] = array(
        $user->uid,
        $user->name,
        _api_custom_field_item('user', $user, 'field_first_name', 'value'),
        _api_custom_field_item('user', $user, 'field_middle_name', 'value'),
        _api_custom_field_item('user', $user, 'field_last_name', 'value'),
        $user->mail,
        _api_custom_field_item('user', $user, 'field_tel', 'value'),
        _api_custom_field_item('user', $user, 'field_address', 'thoroughfare'),
        _api_custom_field_item('user', $user, 'field_address', 'premise'),
        _api_custom_field_item('user', $user, 'field_address', 'locality'),
        _api_custom_field_item('user', $user, 'field_address', 'postal_code'),
        $this->getStateID(_api_custom_field_item('user', $user, 'field_address', 'administrative_area')),
        _get_user_company($user->uid),
      );
    }
    
    $users_sheet['headers'][$this->sheetTitle] = array(
      'UserID',
      'Username',
      'FirstName',
      'MiddleName',
      'LastName',
      'Email',
      'Tel',
      'Address1',
      'Address2',
      'City',
      'Zip',
      'FK_StateID',
      'FK_CompanyID',
    );
    
    return $users_sheet;
  }

}
