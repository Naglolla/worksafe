<?php

class APIMassachusettsReportUserTestResults extends APIMassachusettsReport {
  private $sheetTitle;
  private $programID;
  private $overall;
  public function __construct($program_id){
    $this->sheetTitle = 'UserTestResults';
    $this->stateID = $this->getStateID(self::state);
    $this->programID = $program_id ? $program_id:$this->getUSTProgramID();
    $this->overall = 80;
  }

  public function getSheetTitle() {
    return $this->sheetTitle;
  }

  public function report(){
    $attempt_sheet = array();
    
    $attempt_sheet['headers'][$this->sheetTitle] = array(
      'UserTestID',
      'FK_UserID',
      'FK_CourseID',
      'FK_ModuleID',
      'FK_TestID',
      'FK_UserCourseID',
      'CorrectAnswers',
      'IncorrectAnswers',
      'StartedDate',
      'CompletedDate',
      'Passed'
    );
    
    $course_ids = $this->getCourseIDs($this->programID,self::state);
    
    if (count($course_ids)){
    
      $attempts = $this->getExamAttempts($course_ids);

      foreach ($attempts as $attempt) {
        if ($attempt->attempt_sumgrades){
          $attempt->CorrectAnswers = (int)$attempt->attempt_sumgrades;
          $attempt->IncorrectAnswers = (int)$attempt->sumgrades - (int)$attempt->attempt_sumgrades;
          $percentage = ($attempt->CorrectAnswers / $attempt->sumgrades) * 100;
          $attempt->Passed = $percentage >= $this->overall ? 1:0;
        }
        $course_params = api_course_get_course_params($attempt->FK_UserCourseID);
        $attempt_sheet['data'][$this->sheetTitle][] = array(
          $attempt->UserTestID,
          $attempt->FK_UserID,
          $this->programID,
          $course_params === FALSE ? 0:$course_params->product_id,
          $attempt->FK_TestID,
          $attempt->FK_UserCourseID,
          $attempt->attempt_sumgrades ? $attempt->CorrectAnswers:0,
          $attempt->attempt_sumgrades ? $attempt->IncorrectAnswers:0,
          format_date($attempt->StartedDate, 'custom', 'm/d/Y'),
          $attempt->CompletedDate ? format_date($attempt->CompletedDate, 'custom', 'm/d/Y'):'',
          $attempt->attempt_sumgrades ? $attempt->Passed:0
        );
      }
    
    }
    
    return $attempt_sheet;
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
   *  Get Exam Attempts, based on Moodle course_ids 
   */
  private function getExamAttempts($course_ids = array()){
    $moodle_con = moodle_connector_connect();
    if (!$moodle_con) {
      return FALSE;
    }

    $query = $moodle_con->select('quiz_attempts','a');
    $query->join('quiz', 'q', 'a.quiz = q.id');
    $query->join('user', 'u', 'a.userid = u.id');

    $query->condition('a.state', array(FINISHED,IN_PROGRESS,RESTORED), 'IN');
    $query->condition('q.course', $course_ids, 'IN');

    $query->addField('a', 'quiz', 'FK_TestID');
    $query->addField('a', 'state');
    $query->addField('a', 'sumgrades', 'attempt_sumgrades');
    $query->addField('q', 'sumgrades');
    $query->addField('a', 'id', 'UserTestID');
    $query->addField('q', 'course', 'FK_UserCourseID');
    $query->addField('a', 'timestart', 'StartedDate');
    $query->addField('a', 'timefinish', 'CompletedDate');
    $query->addField('u', 'idnumber', 'FK_UserID');
    $result = $query->execute()->fetchAll();

    return $result;
  }
}
