<?php

class APIMassachusettsUserReciprocityDetails extends APIMassachusettsReport {
  private $sheetTitle;
  private $programID;
  private $overall;
  public function __construct($program_id){
    $this->sheetTitle = 'UserReciprocityDetails';
    $this->stateID = $this->getStateID(self::state);
    $this->programID = $program_id ? $program_id:$this->getUSTProgramID();
    $this->overall = 80;
  }

  public function getSheetTitle() {
    return $this->sheetTitle;
  }

  public function report(){
    $detail_sheet = array();
    
    $user_uids = $this->getUsersByState(self::state);
    $course_ids = $this->getCourseIDs($this->programID,self::state);
    
    if (count($user_uids) && count($course_ids)){
      $users_enrolments = $this->getUsersEnrolments($user_uids,$course_ids);
      
      foreach ($users_enrolments as $UserReciprocityDetails => $user_enrolment) {
        $course_params = api_course_get_course_params($user_enrolment->FK_CourseID);
        $operator_type = $course_params->type;
        $state = $course_params->state;
        $detail_sheet['data'][$this->sheetTitle][] = array(
          $UserReciprocityDetails + 1,
          $user_enrolment->FK_UserCourseID,
          $this->getStateID($state),
          $this->getOperatorID($operator_type),
          $user_enrolment->UserTestID,
        );
      }
    }
    
    $detail_sheet['headers'][$this->sheetTitle] = array(
      'UserReciprocityDetails',
      'FK_UserCourseID',
      'ReciprocityStateID',
      'ReciprocityOperatorID',
      'UserTestID'
    );
    
    return $detail_sheet;
  }

  /*
   * Get Moodle course IDs / Final Exam
   */
  private function getCourseIDs($program_id,$state = 'MA'){
    $program = api_moodle_get_program($program_id);
    $course_ids = array();
    if ($program){
      $modules = $program->modules[$state];
      foreach($modules as $module){
        if (isset($module[0][MOODLE_COURSE_TYPE_FINAL_EXAM])){
          $course_ids[] = $module[0][MOODLE_COURSE_TYPE_FINAL_EXAM]->course_id;
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
    $query->join('quiz', 'q', 'e.courseid = q.course');
    $query->join('user', 'u', 'ue.userid = u.id');
    $query->join('quiz_attempts', 'a', 'u.id = a.userid');
    
    
    $query->condition('u.idnumber', $user_uids, 'IN');
    $query->condition('e.courseid', $course_ids, 'IN');
    
    $query->addField('ue', 'id', 'FK_UserCourseID');
    $query->addField('u', 'idnumber', 'FK_UserID');
    $query->addField('e', 'courseid', 'FK_CourseID');
    $query->addField('a', 'id', 'UserTestID');
    
    $query->orderBy('FK_UserCourseID');
    
    $result = $query->execute()->fetchAllAssoc('FK_UserCourseID');

    return array_values($result);
  }

}
