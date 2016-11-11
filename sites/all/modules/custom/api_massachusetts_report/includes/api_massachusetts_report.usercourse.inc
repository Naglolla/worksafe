<?php

class APIMassachusettsReportUserCourse extends APIMassachusettsReport {
  const commerce_line_item_type_product = 'product';
  const commerce_line_item_type_token = 'token_line_item';

  private $sheetTitle;
  private $programID;
  private $stateID;
  
  public function __construct($program_id){
    $this->sheetTitle = 'UserCourse';
    $this->stateID = $this->getStateID(self::state);
    $this->programID = $program_id ? $program_id:$this->getUSTProgramID();
  }

  public function getSheetTitle() {
    return $this->sheetTitle;
  }

  public function report() {
    $user_course_sheet = array();
    
    $user_uids = $this->getUsersByState(self::state);
    $course_ids = $this->getCourseIDs($this->programID, self::state);
    
    if (count($user_uids) && count($course_ids)){
      $users_enrolments = $this->getUsersEnrolments($user_uids,$course_ids);
      
      foreach ($users_enrolments as $user_enrolment) {
        $course_params = api_course_get_course_params($user_enrolment->FK_CourseID);
        $operator_type = $course_params->type;
        $user_course_sheet['data'][$this->sheetTitle][] = array(
          $user_enrolment->UserCourseID,
          $this->programID,
          $user_enrolment->FK_UserID,
          $this->getOperatorID($operator_type)
        );
      }
    }
    
    $user_course_sheet['headers'][$this->sheetTitle] = array(
      'UserCourseID',
      'FK_CourseID',
      'FK_UserID',
      'FK_OperatorID',
    );

    return $user_course_sheet;
  }
  
  /*
   * Get Moodle course IDs
   */
  private function getCourseIDs($program_id,$state = 'MA'){
    $program = api_moodle_get_program($program_id);
    $course_ids = array();
    if ($program){
      $modules = $program->modules[$state];
      foreach($modules as $types){
        foreach($types as $type){
          foreach($type as $module){
            if ($module->course_id){
              $course_ids[] = $module->course_id;
            }
          }
        }
      }
    }
    return $course_ids;
  }
  
  private function getUsersEnrolments($user_uids,$course_ids) {
    $moodle_con = moodle_connector_connect();
    if (!$moodle_con) {
      return FALSE;
    }

    $query = $moodle_con->select('user_enrolments','ue');
    $query->join('enrol', 'e', 'ue.enrolid = e.id');
    $query->join('user', 'u', 'ue.userid = u.id');
    
    $query->condition('u.idnumber', $user_uids, 'IN');
    $query->condition('e.courseid', $course_ids, 'IN');
    
    $query->addField('ue', 'id', 'UserCourseID');
    $query->addField('u', 'idnumber', 'FK_UserID');
    $query->addField('e', 'courseid', 'FK_CourseID');
    
    $query->orderBy('UserCourseID');
    
    $result = $query->execute()->fetchAll();

    return $result;
  }
  
}
