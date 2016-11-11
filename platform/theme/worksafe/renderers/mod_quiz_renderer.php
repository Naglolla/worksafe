<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

require_once($CFG->dirroot . "/mod/quiz/renderer.php");
require_once($CFG->libdir.'/dml/moodle_database.php');
require_once($CFG->dirroot . "/local/coursehelper/classes/apiservices.php");

class theme_worksafe_mod_quiz_renderer extends mod_quiz_renderer
{
    public $curldefaults=array(
      CURLOPT_FAILONERROR => true,
      CURLOPT_RETURNTRANSFER => true,
      CURLOPT_TIMEOUT => 4,
      CURLOPT_SSL_VERIFYPEER => false,

    );

    /**
     * Ouputs the form for making an attempt
     *
     * @param quiz_attempt $attemptobj
     * @param int $page Current page number
     * @param array $slots Array of integers relating to questions
     * @param int $id ID of the attempt
     * @param int $nextpage Next page number
     */
    public function attempt_form($attemptobj, $page, $slots, $id, $nextpage) {
        global $DB;
        $output = '';

        // Start the form.
        $output .= html_writer::start_tag('form',
                array('action' => $attemptobj->processattempt_url(), 'method' => 'post',
                'enctype' => 'multipart/form-data', 'accept-charset' => 'utf-8',
                'id' => 'responseform'));
        $output .= html_writer::start_tag('div');

        // Print all the questions.
        foreach ($slots as $slot) {
            $output .= $attemptobj->render_question($slot, false,
                    $attemptobj->attempt_url($slot, $page));
        }

        $courseobj = $attemptobj->get_course();
        $course = $DB->get_record('course', array('id' => $courseobj->id));
        $course_params = apiservices::get_course_params($course->idnumber);
        $is_final_exam = ($course_params->course_type == MOODLE_COURSE_TYPE_FINAL_EXAM) ? TRUE:FALSE;
        
        $output .= html_writer::start_tag('div', array('class' => 'submitbtns'));
        $output .= html_writer::empty_tag('input', array('type' => 'submit', 'name' => 'next',
                'value' => get_string('quiz-confirm-answer','theme_worksafe')));
        $output .= html_writer::tag('div', html_writer::link($attemptobj->summary_url(), $is_final_exam ? get_string('quiz-exit-exam','theme_worksafe'):get_string('quiz-exit-quiz','theme_worksafe')), array('class' => 'link'));
        $output .= html_writer::end_tag('div');

        // Some hidden fields to trach what is going on.
        $output .= html_writer::empty_tag('input', array('type' => 'hidden', 'name' => 'attempt',
                'value' => $attemptobj->get_attemptid()));
        $output .= html_writer::empty_tag('input', array('type' => 'hidden', 'name' => 'thispage',
                'value' => $page, 'id' => 'followingpage'));
        $output .= html_writer::empty_tag('input', array('type' => 'hidden', 'name' => 'nextpage',
                'value' => $nextpage));
        $output .= html_writer::empty_tag('input', array('type' => 'hidden', 'name' => 'timeup',
                'value' => '0', 'id' => 'timeup'));
        $output .= html_writer::empty_tag('input', array('type' => 'hidden', 'name' => 'sesskey',
                'value' => sesskey()));
        $output .= html_writer::empty_tag('input', array('type' => 'hidden', 'name' => 'scrollpos',
                'value' => '', 'id' => 'scrollpos'));

        // Add a hidden field with questionids. Do this at the end of the form, so
        // if you navigate before the form has finished loading, it does not wipe all
        // the student's answers.
        $output .= html_writer::empty_tag('input', array('type' => 'hidden', 'name' => 'slots',
                'value' => implode(',', $slots)));

        // Finish the form.
        $output .= html_writer::end_tag('div');
        $output .= html_writer::end_tag('form');

        $output .= $this->connection_warning();

        return $output;
    }

    /**
     * Builds the review page
     *
     * @param quiz_attempt $attemptobj an instance of quiz_attempt.
     * @param array $slots an array of intgers relating to questions.
     * @param int $page the current page number
     * @param bool $showall whether to show entire attempt on one page.
     * @param bool $lastpage if true the current page is the last page.
     * @param mod_quiz_display_options $displayoptions instance of mod_quiz_display_options.
     * @param array $summarydata contains all table data
     * @return $output containing html data.
     */
    public function review_page(quiz_attempt $attemptobj, $slots, $page, $showall,
                                $lastpage, mod_quiz_display_options $displayoptions,
                                $summarydata) {

        global $DB,$USER;

        $output = '';
        $output .= $this->header();

        // Quiz Results
        $summarydata = array();
        $attempt = $attemptobj->get_attempt();
        
        debugging(print_r($attempt,true),DEBUG_DEVELOPER);
        
        $quiz = $attemptobj->get_quiz();
        $course = $attemptobj->get_course();
        //$cm = $attemptobj->get_cm();
        //$cm = get_fast_modinfo($course->id);
        $modinfo = get_fast_modinfo($course);
        $cm = $modinfo->get_cm($attemptobj->get_cmid());

        debugging(print_r($cm,true),DEBUG_DEVELOPER);
        
        $grade = quiz_rescale_grade($attempt->sumgrades, $quiz, false);
        
        //Generate 'back to the course' url
        $course = $DB->get_record('course', array('id' => $course->id));
        $course_params = apiservices::get_course_params($course->idnumber);

        $back_course_link = '/course/' . $USER->idnumber . '/' . $course_params->program_id . '/' . $course_params->state . '/' . $course_params->type;
        
        // Quiz or Final Exam
        $is_final_exam = ($course_params->course_type == MOODLE_COURSE_TYPE_FINAL_EXAM) ? TRUE:FALSE;
        
        $output .= html_writer::start_tag('div', array('class' => 'title-header'));
        $output .= html_writer::tag('div', $quiz->name . ': ' . get_string('quiz-completed','theme_worksafe'), array('class' => 'name'));
        $output .= html_writer::tag('div', html_writer::link($back_course_link, get_string('quiz-back-to-course','theme_worksafe'),array('target' => '_top')), array('class' => 'link'));
        $output .= html_writer::end_tag('div');

        $output .= html_writer::tag('div', '', array('class' => 'clear'));
        $output .= html_writer::tag('h3', $is_final_exam ? get_string('quiz-final-exam-results','theme_worksafe'):get_string('quiz-quiz-results','theme_worksafe'), array('class' => 'title'));

        // Show raw marks only if they are different from the grade (like on the view page).
        if ($quiz->grade != $quiz->sumgrades) {
            $marks = new stdClass();
            $marks->grade = quiz_format_grade($quiz, $attempt->sumgrades);
            $marks->maxgrade = quiz_format_grade($quiz, $quiz->sumgrades);

            $summarydata['correct-questions'] = array(
                'title'   => get_string('quiz-correct-questions', 'theme_worksafe'),
                'content' => format_float($marks->grade, 0),
            );
            $summarydata['incorrect-questions'] = array(
                'title'   => get_string('quiz-incorrect-questions', 'theme_worksafe'),
                'content' => format_float($marks->maxgrade - $marks->grade,0),
            );

            $completion_percentage = $course_params ? $this->get_quiz_passing_threshold($course_params->state,$course_params->type,$is_final_exam):100;
            $percentage = format_float($attempt->sumgrades * 100 / $quiz->sumgrades, 0);

            if ($percentage >= $completion_percentage){

                // Set completion for this activity, if the user is not an admin
                if (!is_siteadmin()){
                    $completion = new completion_info($course);
                    $data = $completion->get_data($cm, false, $USER->id);
                    
                    debugging(print_r($data,true),DEBUG_DEVELOPER);
                    
                    $data->completionstate = COMPLETION_COMPLETE;
                    $data->timemodified = time();
                    $completion->internal_set_data($cm, $data);
                    
                    // Update percentage for the current attempt
                    try {
                      $result = $DB->set_field('local_coursehelper', 'completionstate', COMPLETION_COMPLETE, array('cmid' => $attempt->id , 'component' => 'mod_quiz' , 'userid' => $USER->id));
                      debugging(print_r($result,true),DEBUG_DEVELOPER);
                    } catch (Exception $ex) {
                      debugging(print_r($ex,true),DEBUG_DEVELOPER);
                    }
                    
                    debugging(print_r($completion,true),DEBUG_DEVELOPER);
                }

                $user_id = $USER->idnumber ? $USER->idnumber:0;
                $response = apiservices::send_moodle_event($user_id, $course_params->program_id, $course_params->state,$course_params->type);

                // Show response in Debug Mode
                debugging(print_r($response,true),DEBUG_DEVELOPER);

                $final_result_content = html_writer::tag('span', ($is_final_exam ? get_string('quiz-quiz-exam-passed', 'theme_worksafe'):get_string('quiz-quiz-passed', 'theme_worksafe')), array('class' => 'passed'));
            } else {
                $final_result_content = html_writer::tag('span', ($is_final_exam ? get_string('quiz-quiz-exam-failed', 'theme_worksafe'):get_string('quiz-quiz-failed', 'theme_worksafe')), array('class' => 'failed'));
            }

            $summarydata['percentage-total'] = array(
                'title'   => get_string('quiz-quiz-total', 'theme_worksafe'),
                'content' => $percentage . '%',
            );
            $summarydata['percentage-needed'] = array(
                'title'   => get_string('quiz-quiz-needed', 'theme_worksafe'),
                'content' => $completion_percentage . '%',
            );
            $summarydata['final-result'] = array(
                'title'   => get_string('quiz-final-result', 'theme_worksafe'),
                'content' => $final_result_content,
            );
        }

        $output .= $this->review_summary_table($summarydata, $page);
        //$output .= $this->review_next_navigation($attemptobj, $page, $lastpage);
        $output .= $this->footer();
        return $output;
    }

    /**
     * Creates any controls a the page should have.
     *
     * @param quiz_attempt $attemptobj
     */
    public function summary_page_controls($attemptobj) {
        $output = '';

        // Return to place button.
        /*if ($attemptobj->get_state() == quiz_attempt::IN_PROGRESS) {
            $button = new single_button(
                    new moodle_url($attemptobj->attempt_url(null, $attemptobj->get_currentpage())),
                    get_string('returnattempt', 'quiz'));
            $output .= $this->container($this->container($this->render($button),
                    'controls'), 'submitbtns mdl-align');
        }*/

        // Finish attempt button.
        $options = array(
            'attempt' => $attemptobj->get_attemptid(),
            'finishattempt' => 1,
            'timeup' => 0,
            'slots' => '',
            'sesskey' => sesskey(),
        );

        $button = new single_button(
                new moodle_url($attemptobj->processattempt_url(), $options),
                get_string('quiz-confirm', 'theme_worksafe'));
        $button->id = 'responseform';
        if ($attemptobj->get_state() == quiz_attempt::IN_PROGRESS) {
            $button->add_action(new confirm_action(get_string('confirmclose', 'quiz'), null,
                    get_string('quiz-confirm', 'theme_worksafe')));
        }

        $duedate = $attemptobj->get_due_date();
        $message = '';
        if ($attemptobj->get_state() == quiz_attempt::OVERDUE) {
            $message = get_string('overduemustbesubmittedby', 'quiz', userdate($duedate));

        } else if ($duedate) {
            $message = get_string('mustbesubmittedby', 'quiz', userdate($duedate));
        }

        $output .= $this->countdown_timer($attemptobj, time());
        $output .= $this->container($message . $this->container(
                $this->render($button), 'controls'), 'submitbtns mdl-align');

        return $output;
    }

    /**
     * Attempt Page
     *
     * @param quiz_attempt $attemptobj Instance of quiz_attempt
     * @param int $page Current page number
     * @param quiz_access_manager $accessmanager Instance of quiz_access_manager
     * @param array $messages An array of messages
     * @param array $slots Contains an array of integers that relate to questions
     * @param int $id The ID of an attempt
     * @param int $nextpage The number of the next page
     */
    public function attempt_page($attemptobj, $page, $accessmanager, $messages, $slots, $id,
            $nextpage) {
        $output = '';
        $output .= $this->header();

        $attempt = $attemptobj->get_attempt();
        $quiz = $attemptobj->get_quiz();

        $output .= html_writer::start_tag('div', array('class' => 'title-header'));
        $output .= html_writer::tag('div', $quiz->name, array('class' => 'name'));
        $output .= html_writer::end_tag('div');

        $output .= html_writer::tag('div', '<p>&nbsp;</p>', array('class' => 'clear'));
        $output .= $this->countdown_timer($attemptobj, time());
        $output .= $this->quiz_notices($messages);
        $output .= $this->attempt_form($attemptobj, $page, $slots, $id, $nextpage);
        $output .= $this->footer();
        return $output;
    }

    /*
     * View Page
     */
    /**
     * Generates the view page
     *
     * @param int $course The id of the course
     * @param array $quiz Array conting quiz data
     * @param int $cm Course Module ID
     * @param int $context The page context ID
     * @param array $infomessages information about this quiz
     * @param mod_quiz_view_object $viewobj
     * @param string $buttontext text for the start/continue attempt button, if
     *      it should be shown.
     * @param array $infomessages further information about why the student cannot
     *      attempt this quiz now, if appicable this quiz
     */
    public function view_page($course, $quiz, $cm, $context, $viewobj) {
        global $USER, $DB;
        
        if (is_siteadmin()) {
            return parent::view_page($course, $quiz, $cm, $context, $viewobj);
        } else {
            // Save the referer value
            $referer = empty($_SERVER['HTTP_REFERER']) ? '':$_SERVER['HTTP_REFERER'];
            $_SESSION['HTTP_REFERER'] = $referer;

            $quizobj = quiz::create($cm->instance, $USER->id);
            
            $params = array(
              'quizid' => $quizobj->get_quizid(),
              'userid' => $USER->id,
              'status' => 'restored'
            );
            $attempts = $DB->get_records_select('quiz_attempts',
            'quiz = :quizid AND userid = :userid AND state = :status',
            $params, 'attempt ASC');
            $lastattempt = end($attempts);
            
            if ($lastattempt){
              
              $DB->set_field('quiz_attempts', 'state', quiz_attempt::IN_PROGRESS, array('quiz' => $quizobj->get_quizid(), 'userid' => $USER->id, 'state' => 'restored'));
              
              // Skip attempts page, just redirect to the quiz activity
              redirect($quizobj->attempt_url($lastattempt->id, $lastattempt->currentpage),'Loading ...',1);
            } else {
              $attempts = quiz_get_user_attempts($quizobj->get_quizid(), $USER->id, 'all', true);
              $lastattempt = end($attempts);

              // To force the creation of a new preview, we mark the current attempt (if any) as finished
              $DB->set_field('quiz_attempts', 'state', quiz_attempt::FINISHED, array('quiz' => $quizobj->get_quizid(), 'userid' => $USER->id));
        
              // Skip attempts page, just redirect to the quiz activity
              redirect($viewobj->startattempturl,'Loading ...',1);
            }
        }
    }
    
    public function get_quiz_passing_threshold($state,$type,$is_final_exam){
        $rules = $this->get_program_rules($state,$type);

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

    public function get_quiz_completion_percentage($course_id) {
        global $DB;
        $gitem = $DB->get_record('grade_items', array('courseid'=>$course_id, 'itemtype'=>'mod', 'itemmodule'=>'quiz'));

        if ($gitem && $gitem->gradepass && $gitem->gradepass > 0){
            return $gitem->gradepass * 10; // convert Grade Pass into percentage
        }
        return 100;
    }

    public function get_safety_key($user_id){
        $config = get_config('auth_drupalservices');
        $base_url = $config->host_uri;
        $url = $base_url . '/user/' . $user_id . '/generate_key';

        $response = $this->CurlHttpRequest('RemoteAPI->Token', $url, 'POST', "");
        if($response->info['http_code'] <> 200){
            return false;
        }
        return $response;
    }

    public function get_program_rules($state,$type){
        $config = get_config('auth_drupalservices');
        $base_url = $config->host_uri;
        $url = $base_url . '/program/rules/state/' . $state . '/type/' . $type;

        $response = $this->CurlHttpRequest('RemoteAPI->Token', $url, 'POST', "");
        if($response->info['http_code'] <> 200){
            return false;
        }
        return $response->response ? $response->response:false;
    }

    public function CurlHttpRequest( $caller, $url, $method, $data, $includeAuthCookie = false, $includeCSRFToken = false ) {

      $ch = curl_init();    // create curl resource
      switch ($method) {
        case 'POST':   curl_setopt_array($ch, $this->GetCurlPostOptions($url,$data, $includeAuthCookie, $includeCSRFToken)); break;
        case 'GET':    curl_setopt_array($ch, $this->GetCurlGetOptions($url, $includeAuthCookie));        break;
        case 'PUT':    curl_setopt_array($ch, $this->GetCurlPutOptions($url, $data, $includeAuthCookie)); break;
        case 'DELETE': curl_setopt_array($ch, $this->GetCurlDeleteOptions($url, $includeAuthCookie));     break;
        default:
          return NULL;
      }

      // I had to do this as my hosting provider had dns cache issues.
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

   private function GetCurlPostOptions( $url, $data, $includeAuthCookie = false, $includeCSRFToken = false ) {
    $ret = array( CURLOPT_URL => $url,
      CURLOPT_HTTPHEADER => array('Accept: application/json'),
      CURLOPT_POST => true,
      CURLOPT_POSTFIELDS => $data,
      CURLOPT_SSL_VERIFYPEER => false,
      // CURLOPT_VERBOSE => true,
    ) + $this->curldefaults;
    if ($includeAuthCookie) {
      $ret[CURLOPT_COOKIE] = $this->GetCookieHeader();
    }
    if ($includeCSRFToken) {
      $ret[CURLOPT_HTTPHEADER][] = $this->GetCSRFTokenHeader();
    }

    return $ret;
  }

}