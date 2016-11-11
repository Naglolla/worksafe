<?php
define('CONTEXT_COURSE', 50);

class APIMassachusettsReportTestQuestionCustom extends APIMassachusettsReport {
  private $sheetTitle;
  private $state;
  private $programID;
  private $overall;
  
  public function __construct($program_id){
    $this->sheetTitle = 'TestQuestionCustom';
    $this->stateID = $this->getStateID();
    $this->programID = $program_id ? $program_id:$this->getUSTProgramID();
    $this->overall = 80;
  }

  public function getSheetTitle() {
    return $this->sheetTitle;
  }

  public function report(){
    $detail_sheet = array();
    
    $detail_sheet['headers'][$this->sheetTitle] = array(
      'QuestionID',
      'fk_TestID',
      'FK_ModuleID',
      'FK_CourseID',
      'QuestionOrder',
      'MessDepModuleModuleID',
    );
    
    $course_ids = $this->getCourseIDs($this->programID,self::state);
    
    if (count($course_ids)){
      
      $details = $this->getQuestionCustom($course_ids);

      foreach ($details as $detail) {
        $course_params = api_course_get_course_params($detail->course);
        $product_id = $course_params === FALSE ? 0:$course_params->product_id;
        $detail_sheet['data'][$this->sheetTitle][] = array(
          $detail->QuestionID,
          $detail->fk_TestID,
          $product_id,
          $this->programID,
          1, // random order
          $this->getModuleNumberFromProduct($product_id)
        );    
      }
       
    }
    
    return $detail_sheet;
  }

  /*
   * Get Moodle course IDs / Quiz + Final Exam
   */
  private function getCourseIDs($program_id,$state = 'MA'){
    $program = api_moodle_get_program($program_id);
    $course_ids = array();
    if ($program){
      $modules = $program->modules[$state];
      foreach($modules as $types){
        foreach($types as $type){
          if (isset($type[MOODLE_COURSE_TYPE_FINAL_EXAM])){
            $course_ids[] = $type[MOODLE_COURSE_TYPE_FINAL_EXAM]->course_id;
          } else if (isset($type[MOODLE_COURSE_TYPE_QUIZ])){
            $course_ids[] = $type[MOODLE_COURSE_TYPE_QUIZ]->course_id;
          }
        }
      }
    }
    return $course_ids;
  }
  
  private function getQuestionCustom($course_ids = array()){
    $moodle_con = moodle_connector_connect();
    if (!$moodle_con) {
      return FALSE;
    }
    
    $query = $moodle_con->select('question','q');
    $query->join('question_categories', 'c', 'q.category = c.id');
    $query->join('context', 't', 't.id = c.contextid');
    $query->join('quiz', 'z', 'z.course = t.instanceid');
    
    $query->condition('q.questiontextformat', 1, '=');
    $query->condition('t.contextlevel', CONTEXT_COURSE, '=');
    $query->condition('t.instanceid', $course_ids, 'IN');
    
    $query->addField('q', 'id', 'QuestionID');
    $query->addField('c', 'contextid');
    $query->addField('t', 'instanceid', 'course');
    $query->addField('z', 'id', 'fk_TestID');
    
    $query->orderBy('QuestionID');
    
    $result = $query->execute()->fetchAll();
    
    return $result;
  }

  private function getModuleNumberFromProduct($product_id){
    $product_entity = reset(entity_load('commerce_product', array($product_id),array('status'=>1)));
    if ($product_entity){
      $product_entity_meta = entity_metadata_wrapper('commerce_product', $product_entity);
      if ($product_entity_meta && $product_entity_meta->field_module_number->value()){
        return $product_entity_meta->field_module_number->value();
      }
    }
    return 0;
  }
}
