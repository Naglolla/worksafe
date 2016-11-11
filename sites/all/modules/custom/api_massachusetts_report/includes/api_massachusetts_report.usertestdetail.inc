<?php

class APIMassachusettsReportUserTestDetail extends APIMassachusettsReport {
  private $sheetTitle;
  private $programID;
  private $overall;
  private $stateID;
  
  public function __construct($program_id){
    $this->sheetTitle = 'UserTestDetail';
    $this->stateID = $this->getStateID(self::state);
    $this->programID = $program_id ? $program_id:$this->getUSTProgramID();
    $this->overall = 80;
  }

  public function getSheetTitle() {
    return $this->sheetTitle;
  }

  public function report(){
    $detail_sheet = array();
    
    $detail_sheet['headers'][$this->sheetTitle] = array(
      'UserTestDetailID',
      'FK_UserID',
      'FK_CourseID',
      'FK_ModuleID',
      'FK_TestID',
      'FK_QuestionID',
      'FK_UserCourseID',
      'FK_UserTestID',
      'Correct',
      'Answered',
    );
    
    $course_ids = $this->getCourseIDs($this->programID,self::state);
    
    if (count($course_ids)){
    
      $details = $this->getTestDetail($course_ids);

      foreach ($details as $detail) {
        $course_params = api_course_get_course_params($detail->FK_UserCourseID);
        $detail_sheet['data'][$this->sheetTitle][] = array(
          $detail->UserTestDetailID,
          $detail->FK_UserID,
          $this->programID,
          $course_params === FALSE ? 0:$course_params->product_id,
          $detail->FK_TestID,
          $detail->FK_QuestionID,
          $detail->FK_UserCourseID,
          $detail->FK_UserTestID,
          $detail->rightanswer == $detail->responsesummary ? 1:0,
          1,//always the same value (Answered)
        );    
      }
       
    }
    
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
  
  /*
   *  Get Test Detail (Exam Attempts), based on Moodle course_ids 
   */
  private function getTestDetail($course_ids = array()){
    $moodle_con = moodle_connector_connect();
    if (!$moodle_con) {
      return FALSE;
    }

    $query = $moodle_con->select('question_attempts','a');
    $query->join('quiz_attempts', 't', 'a.questionusageid = t.uniqueid');
    $query->join('quiz', 'q', 't.quiz = q.id');
    $query->join('user', 'u', 't.userid = u.id');

    $query->condition('q.course', $course_ids, 'IN');
    
    $query->addField('a', 'rightanswer');
    $query->addField('a', 'responsesummary');
    $query->addField('a', 'questionid', 'FK_QuestionID');
    $query->addField('a', 'id', 'FK_AnswerID');
    $query->addField('a', 'id', 'UserTestDetailID');
    $query->addField('a', 'timemodified', 'DateAnswered');
    $query->addField('t', 'id', 'FK_UserTestID');
    $query->addField('t', 'quiz', 'FK_TestID');
    $query->addField('q', 'course', 'FK_UserCourseID');
    $query->addField('u', 'idnumber', 'FK_UserID');
    $result = $query->execute()->fetchAll();

    return $result;
  }

}
