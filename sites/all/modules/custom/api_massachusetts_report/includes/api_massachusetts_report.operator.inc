<?php

class APIMassachusettsReportOperator extends APIMassachusettsReport {
  private $sheetTitle;
  public function __construct($program_id){
    $this->sheetTitle = 'Operator';
  }

  public function getSheetTitle() {
    return $this->sheetTitle;
  }

  public function report(){
    $operator_sheet = array();

    $operators = $this->getOperators();

    foreach ($operators as $type => $id) {
      $operator_sheet['data'][$this->sheetTitle][] = array($id,$type);
    }

    $operator_sheet['headers'][$this->sheetTitle] = array(
      'OperatorID',
      'OperatorName',
    );

    return $operator_sheet;
  }

}
