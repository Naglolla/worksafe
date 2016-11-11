<?php

define('MOODLE_COURSE_TYPE_FINAL_EXAM','3');
define('MOODLE_COURSE_TYPE_QUIZ','2');
define('MOODLE_COURSE_TYPE_TRAINING','1');

/**
 * Implement services
 *
 * @author API Worksafe
 */
class apiservices {
  
  public static function get_alternative_connection(){
      global $CFG;
      if (!isset($CFG->dboptions)) {
          $CFG->dboptions = array();
      }

      if (isset($CFG->dbpersist)) {
          $CFG->dboptions['dbpersist'] = $CFG->dbpersist;
      }

      if (!$DBA = moodle_database::get_driver_instance($CFG->dbtype, $CFG->dblibrary,true)) {
          throw new dml_exception('dbdriverproblem', "Unknown driver $CFG->dblibrary/$CFG->dbtype");
      }

      try {
          $DBA->connect($CFG->dbhost, $CFG->dbuser, $CFG->dbpass, $CFG->dbname, '', $CFG->dboptions);
      } catch (moodle_exception $e) {
          // rethrow the exception
          throw $e;
      }
      return $DBA;
  }
  
  public static function get_course_params($course_idnumber){
      $DBA = self::get_alternative_connection();

      $sql = 'SELECT p.entity_id AS program_id, s.field_states_value AS state, t.field_operator_types_value AS type, ct.field_course_type_value AS course_type ';
      $sql .= 'FROM {commerce_product} c ';
      $sql .= 'LEFT JOIN {field_data_field_states} s ON s.entity_id = c.product_id AND s.entity_type = :entity_type ';
      $sql .= 'LEFT JOIN {field_data_field_operator_types} t ON t.entity_id = c.product_id AND t.entity_type = :entity_type2 ';
      $sql .= 'JOIN {field_data_field_product} p ON p.field_product_product_id = c.product_id AND p.bundle = :bundle ';
      $sql .= 'JOIN {field_data_field_course_type} ct ON ct.entity_id = c.product_id AND ct.entity_type = :entity_type3 ';
      $sql .= 'WHERE '.$DBA->sql_like('c.sku', ':skunum').'';
      $params = array('entity_type' => 'commerce_product', 'entity_type2' => 'commerce_product', 'bundle' => 'product_display', 'entity_type3' => 'commerce_product', 'skunum' => '%'.$course_idnumber.'%');
      
      $result = $DBA->get_record_sql($sql, $params);

      if ($result){
          $result->state = $result->state ? $result->state:'NA';
          $result->type = $result->type ? $result->type:'NA';
      }
      
      return $result;
  }
  
  public static function get_program_rules($state,$type){
      $config = get_config('auth_drupalservices');
      $base_url = $config->host_uri;
      $url = $base_url . '/program/rules/state/' . $state . '/type/' . $type;

      $response = self::curl_http_request($url, "");
      if($response->info['http_code'] <> 200){
          return false;
      }
      return $response->response ? $response->response:false;
  }
  
  public static function get_quiz_completion_percentage($course_id) {
      global $DB;
      $gitem = $DB->get_record('grade_items', array('courseid'=>$course_id, 'itemtype'=>'mod', 'itemmodule'=>'quiz'));

      if ($gitem && $gitem->gradepass && $gitem->gradepass > 0){
          return $gitem->gradepass * 10; // convert Grade Pass into percentage
      }
      return 100;
  }
  
  public static function get_quiz_passing_threshold($state,$type,$is_final_exam){
      $rules = self::get_program_rules($state,$type);

      if ($rules && isset($rules->passing_threshold)){
          $passing_threshold = $rules->passing_threshold;
          if($is_final_exam && isset($passing_threshold->final_exam)){
              return $passing_threshold->final_exam;
          } else if (!$is_final_exam && isset($passing_threshold->each_module_quiz)){
              return $passing_threshold->each_module_quiz;
          } else if (isset($passing_threshold->overall)){
              return $passing_threshold->overall;
          } else {
              return 0;
          }
      }
      return 100;
  }
  
  public static function get_safety_key($user_id){
      $config = get_config('auth_drupalservices');
      $base_url = $config->host_uri;
      $url = $base_url . '/user/' . $user_id . '/generate_key';

      $response = self::curl_http_request($url, "");
      if($response->info['http_code'] <> 200){
          return false;
      }
      return $response;
  }
  
  public static function send_moodle_event($user_id,$program_id,$state,$operator_type){
      $config = get_config('auth_drupalservices');
      $base_url = $config->host_uri;
      $url = $base_url . '/courses/event/' . $user_id . '/' . $program_id . '/' . $state . '/' . $operator_type;

      $response = self::curl_http_request($url, "");
      if($response->info['http_code'] <> 200){
          return false;
      }
      return $response->response ? $response->response:false;
  }
  
  public static function curl_http_request($url, $data) {
      $ch = curl_init();    // create curl resource
      curl_setopt_array($ch,
          array(
            CURLOPT_URL => $url,
            CURLOPT_HTTPHEADER => array('Accept: application/json'),
            CURLOPT_POST => true,
            CURLOPT_POSTFIELDS => $data,
            CURLOPT_SSL_VERIFYPEER => false,
            // CURLOPT_VERBOSE => true,
            CURLOPT_FAILONERROR => true,
            CURLOPT_RETURNTRANSFER => true,
            CURLOPT_TIMEOUT => 4,
          )
      );

      // To avoid dns cache issues.
      $ip = gethostbyname(parse_url($url,  PHP_URL_HOST));

      debugging("attempting to reach service url: ".$url, DEBUG_DEVELOPER);

      $ret = new stdClass;
      $ret->response = curl_exec($ch); // execute and get response
      $ret->error    = curl_error($ch);
      $ret->info     = curl_getinfo($ch);
      curl_close($ch);

      if ($ret->info['http_code'] == 200) {
        $ret->response = json_decode($ret->response);
      }

      return $ret;
  }
}
