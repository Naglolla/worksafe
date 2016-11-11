<?php

class APIMassachusettsReportState extends APIMassachusettsReport {
  private $sheetTitle;
  public function __construct($program_id){
    $this->sheetTitle = 'State';
  }

  public function getSheetTitle() {
    return $this->sheetTitle;
  }

  public function report(){
    $state_sheet = array();
        
    $states = $this->getStates();
    foreach ($states as $state_abbr => $state) {
      $state_sheet['data'][$this->sheetTitle][] = array(
        $state['id'],
        $state['name'],
        $state_abbr,
      );
    }
    
    $state_sheet['headers'][$this->sheetTitle] = array(
      'StateID',
      'StateName',
      'StateAbbr',
    );

    return $state_sheet;
  }

}
