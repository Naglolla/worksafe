<?php
// This file is part of Moodle - http://moodle.org/
//
// Moodle is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Moodle is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Moodle.  If not, see <http://www.gnu.org/licenses/>.

/**
 * Event observer.
 *
 * @package    local_course
 * @copyright  2015 API Worksafe
 * @license    http://www.gnu.org/copyleft/gpl.html GNU GPL v3 or later
 */

defined('MOODLE_INTERNAL') || die();

require_once($CFG->dirroot . "/local/coursehelper/classes/apiservices.php");

/**
 * Event observer.
 * Stores all actions about modules create/update/delete in plugin own's table.
 * This allows the block to avoid expensive queries to the log table.
 *
 * @package    local_coursehelper
 * @copyright  2015 API Worksafe
 * @license    http://www.gnu.org/copyleft/gpl.html GNU GPL v3 or later
 */
class local_coursehelper_observer {

    const SCORM_STATUS_PASSED = 2;
    const SCORM_STATUS_COMPLETED = 4;
  
    /**
     * Store all actions about modules create/update/delete in own table.
     *
     * @param \core\event\base $event
     */
    public static function store(\core\event\base $event) {
        global $DB;
        $eventdata = new \stdClass();
        $eventdata->grade = 0;
        switch ($event->eventname) {
            case '\core\event\course_module_created':
                break;
            case '\core\event\course_completed':
                $eventdata->grade = 100;
                break;
            case '\core\event\course_module_updated':
            case '\mod_scorm\event\course_module_viewed':
            case '\mod_scorm\event\sco_launched':
            case '\core\event\course_module_completion_updated': 
                break;
            case '\mod_quiz\event\attempt_submitted':
                $quiz = $event->get_record_snapshot('quiz', $event->other['quizid']);
                $attempt = $event->get_record_snapshot('quiz_attempts', $event->objectid);
                $percentage = format_float($attempt->sumgrades * 100 / $quiz->sumgrades, 0);
                $eventdata->grade = $percentage;
                break;
            case '\core\event\course_module_deleted':
                $eventdata->modname = $event->other['modulename'];
                break;
            default:
                return;
        }
        
        debugging(print_r($event,true),DEBUG_DEVELOPER);
        
        $eventdata->timecreated = $event->timecreated;
        $eventdata->courseid = $event->courseid;
        $eventdata->cmid = $event->objectid;
        $eventdata->userid = $event->userid;
        $eventdata->completionstate = 0;
        $eventdata->component = $event->component;
        $eventdata->action = $event->action;
        $eventdata->target = $event->target;
        $eventdata->objecttable = $event->objecttable;
        $DB->insert_record('local_coursehelper', $eventdata);
        
        
    }
    
    public static function course_created(\core\event\course_created $event){
        debugging('Event: ' . $event->eventname ,DEBUG_DEVELOPER);
        debugging(print_r($event,true),DEBUG_DEVELOPER);
        
        self::course_update($event->courseid);
    }
    
    public static function course_updated(\core\event\course_updated $event){
        debugging('Event: ' . $event->eventname ,DEBUG_DEVELOPER);
        debugging(print_r($event,true),DEBUG_DEVELOPER);
        
        self::course_update($event->courseid);
        
        //  TO-DO: check activity type
        //self::course_scorm_module_update($event->courseid);
    }
    
    public static function course_module_created(\core\event\course_module_created $event){
        debugging('Event: ' . $event->eventname ,DEBUG_DEVELOPER);
        debugging(print_r($event,true),DEBUG_DEVELOPER);

        // Set default options, by activity type
        if ($event->other['modulename'] == 'scorm'){
            self::course_scorm_module_update($event->courseid);
        } else if ($event->other['modulename'] == 'quiz'){
            self::course_quiz_module_update($event->courseid);
        }
        
        self::course_completion_update($event->courseid);
    }
    
    public static function course_module_updated(\core\event\course_module_updated $event){
        debugging('Event: ' . $event->eventname ,DEBUG_DEVELOPER);
        debugging(print_r($event,true),DEBUG_DEVELOPER);
      
        $moduleinstance = $event->objectid;
        debugging(print_r($moduleinstance,true),DEBUG_DEVELOPER);
        
        // Set default options, by activity type
        if ($event->other['modulename'] == 'scorm'){
            self::course_scorm_module_update($event->courseid);
        } else if ($event->other['modulename'] == 'quiz'){
            self::course_quiz_module_update($event->courseid);
        }
        
        self::course_completion_update($event->courseid);
    }
    
    public static function course_completed(\core\event\base $event) {
        global $DB;
        
        debugging(print_r($event,true),DEBUG_DEVELOPER);
        
        $eventdata = new \stdClass();
        $eventdata->grade = 100;
        $eventdata->timecreated = $event->timecreated;
        $eventdata->courseid = $event->courseid;
        $eventdata->cmid = $event->objectid;
        $eventdata->userid = $event->userid;
        $eventdata->completionstate = COMPLETION_COMPLETE;
        $eventdata->component = $event->component;
        $eventdata->action = $event->action;
        $eventdata->target = $event->target;
        $eventdata->objecttable = $event->objecttable;
        $DB->insert_record('local_coursehelper', $eventdata);
    }
    
    public static function course(\core\event\base $event) {
        debugging(print_r($event,true),DEBUG_DEVELOPER);
    }
    
    public static function export(\core\event\base $event) {
        if ($event->eventname == '\mod_quiz\event\attempt_submitted'){
            $quiz = $event->get_record_snapshot('quiz', $event->other['quizid']);
            debugging(print_r($quiz,true),DEBUG_DEVELOPER);
            $attempt = $event->get_record_snapshot('quiz_attempts', $event->objectid);
            debugging(print_r($attempt,true),DEBUG_DEVELOPER);

            $percentage = format_float($attempt->sumgrades * 100 / $quiz->sumgrades, 0);
            debugging(print_r($percentage,true),DEBUG_DEVELOPER);
        } else {
            debugging(print_r($event,true),DEBUG_DEVELOPER);
        }
    }
    
    public static function attempt_submitted(\mod_quiz\event\attempt_submitted $event){
        global $DB;
      
        $quiz = $event->get_record_snapshot('quiz', $event->other['quizid']);
        $attempt = $event->get_record_snapshot('quiz_attempts', $event->objectid);
        $percentage = format_float($attempt->sumgrades * 100 / $quiz->sumgrades, 0);
        
        $eventdata = new \stdClass();
        $eventdata->grade = $percentage;
        $eventdata->timecreated = $event->timecreated;
        $eventdata->courseid = $event->courseid;
        $eventdata->cmid = $event->objectid;
        $eventdata->userid = $event->userid;
        $eventdata->completionstate = 0;
        $eventdata->component = $event->component;
        $eventdata->action = $event->action;
        $eventdata->target = $event->target;
        $eventdata->objecttable = $event->objecttable;
        
        debugging(print_r($event,true),DEBUG_DEVELOPER);
        
        $DB->insert_record('local_coursehelper', $eventdata);
        
        self::trigger_event($event->userid, $event->courseid);
    }
    
    public static function attempt_started(\mod_quiz\event\attempt_started $event){
        global $DB;
      
        $eventdata = new \stdClass();
        $eventdata->grade = 0;
        $eventdata->timecreated = $event->timecreated;
        $eventdata->courseid = $event->courseid;
        $eventdata->cmid = $event->objectid;
        $eventdata->userid = $event->userid;
        $eventdata->completionstate = 0;
        $eventdata->component = $event->component;
        $eventdata->action = $event->action;
        $eventdata->target = $event->target;
        $eventdata->objecttable = $event->objecttable;
        
        debugging(print_r($event,true),DEBUG_DEVELOPER);
        
        $DB->insert_record('local_coursehelper', $eventdata);
    }
    
    public static function sco_launched(\mod_quiz\event\attempt_submitted $event){
        global $DB;
      
        $eventdata = new \stdClass();
        $eventdata->grade = 0;
        $eventdata->timecreated = $event->timecreated;
        $eventdata->courseid = $event->courseid;
        $eventdata->cmid = $event->objectid;
        $eventdata->userid = $event->userid;
        $eventdata->completionstate = 0;
        $eventdata->component = $event->component;
        $eventdata->action = $event->action;
        $eventdata->target = $event->target;
        $eventdata->objecttable = $event->objecttable;
        
        debugging(print_r($event,true),DEBUG_DEVELOPER);
        
        $DB->insert_record('local_coursehelper', $eventdata);
        
        self::trigger_event($event->userid, $event->courseid);
    }
    
    public static function trigger_event($userid, $courseid){
        global $DB;
        
        $course = $DB->get_record('course', array('id' => $courseid));
        $course_params = apiservices::get_course_params($course->idnumber);
        $user = $DB->get_record('user', array('id' => $userid));
        
        $response = apiservices::send_moodle_event($user->idnumber, $course_params->program_id, $course_params->state,$course_params->type);
        debugging(print_r($response,true),DEBUG_DEVELOPER);
    }
    
    private static function course_update($courseid){
        global $DB;
        
        $course = $DB->get_record('course', array('id' => $courseid));
        
        if ($course){
            $course->enablecompletion = 1;
            $result = $DB->update_record('course',$course);
          
            debugging(print_r($result,true),DEBUG_DEVELOPER);
        }
    }
    
    private static function course_completion_update($courseid){
        global $DB;
      
        $course = $DB->get_record('course', array('id' => $courseid));
        $completion = new completion_info($course);
        
        if ($completion->is_course_locked()){
            debugging(print_r($completion->is_course_locked(),true),DEBUG_DEVELOPER);
        } else {
            // Update the course information (in case that the course_update event wasn't triggered)
            self::course_update($courseid);
          
            $modinfo = get_fast_modinfo($courseid);
            debugging(print_r($modinfo,true),DEBUG_DEVELOPER);
        
            $mods = $modinfo->get_cms();
            debugging(print_r($mods,true),DEBUG_DEVELOPER);
        
            debugging(print_r(array_keys($mods),true),DEBUG_DEVELOPER);
            
            $mods_keys = array_keys($mods);
            debugging(print_r(reset($mods_keys),true),DEBUG_DEVELOPER);
            
            debugging(print_r($modinfo->get_cm(reset($mods_keys)),true),DEBUG_DEVELOPER);
            
            debugging(print_r($modinfo->get_instances(),true),DEBUG_DEVELOPER);
            
            $instances = $modinfo->get_instances();
            $instances_keys = array_keys($instances);
            debugging(print_r(reset($instances_keys),true),DEBUG_DEVELOPER);
            
            // Delete old criteria.
            $completion->clear_criteria();
            
            // Handle overall aggregation.
            $aggdata = array(
                'course'        => $courseid,
                'criteriatype'  => null
            );
            $aggregation = new completion_aggregation($aggdata);
            $aggregation->setMethod(COMPLETION_AGGREGATION_ALL); //Course is complete when ALL conditions are met
            $aggregation->save();

            // Handle activity aggregation.
            $aggdata['criteriatype'] = COMPLETION_CRITERIA_TYPE_ACTIVITY;
            $aggregation = new completion_aggregation($aggdata);
            $aggregation->setMethod(0);
            $aggregation->save();

            // Handle course aggregation.
            $aggdata['criteriatype'] = COMPLETION_CRITERIA_TYPE_COURSE;
            $aggregation = new completion_aggregation($aggdata);
            $aggregation->setMethod(0);
            $aggregation->save();

            // Handle role aggregation.
            $aggdata['criteriatype'] = COMPLETION_CRITERIA_TYPE_ROLE;
            $aggregation = new completion_aggregation($aggdata);
            $aggregation->setMethod(0);
            $aggregation->save();
            
            // Add course completion criteria (activity)
            $criteria = new stdClass();
            $criteria->course = $courseid;
            $criteria->criteriatype = COMPLETION_CRITERIA_TYPE_ACTIVITY;
            $criteria->module = reset($instances_keys);
            $criteria->moduleinstance = reset($mods_keys);
            $criteria->courseinstance = NULL;
            $criteria->enrolperiod = NULL;
            $criteria->timeend = NULL;
            $criteria->gradepass = NULL;
            $criteria->role = NULL;
            $DB->insert_record('course_completion_criteria', $criteria);
        }
    }
    
    private static function course_scorm_module_update($courseid){
        global $DB;
        
        $scorm = $DB->get_record('scorm', array('course' => $courseid));
        
        debugging(print_r($scorm,true),DEBUG_DEVELOPER);
        
        $course = $DB->get_record('course', array('id' => $courseid));
        $completion = new completion_info($course);
        
        debugging(print_r($completion,true),DEBUG_DEVELOPER);
        
        debugging(print_r($completion->has_activities(),true),DEBUG_DEVELOPER);
        
        if ($scorm){

            $scorm->auto = 0;
            $scorm->autocommit = 1;
            $scorm->completionscorerequired = NULL;
            $scorm->completionstatusrequired = $scorm->completionstatusrequired ? $scorm->completionstatusrequired:self::SCORM_STATUS_PASSED;
            $scorm->displayactivityname = 0;
            $scorm->displayattemptstatus = 0;
            $scorm->displaycoursestructure = 0;
            $scorm->forcecompleted = 0; //Force completed
            $scorm->forcenewattempt = 1;
            $scorm->grademethod = 1;
            $scorm->hidebrowse = 1;
            $scorm->hidetoc = 1;
            $scorm->lastattemptlock = 0;
            $scorm->maxattempt = 0;
            $scorm->maxgrade = 100;
            $scorm->nav = 0;
            $scorm->popup = 0;
            $scorm->skipview = 0;
            $scorm->timeclose = 0;
            $scorm->timeopen = 0;
            $scorm->updatefreq = 0;
            $scorm->whatgrade = 0;
            $result = $DB->update_record('scorm',$scorm);

            debugging(print_r($result,true),DEBUG_DEVELOPER);
        }
        
        $DB->set_field('course_modules', 'completion', COMPLETION_TRACKING_AUTOMATIC, array('course' => $course->id));
    }
    
    private static function course_quiz_module_update($courseid){
        global $DB;
        
        $quiz = $DB->get_record('quiz', array('course' => $courseid));
        
        debugging(print_r($quiz,true),DEBUG_DEVELOPER);
        
        $course = $DB->get_record('course', array('id' => $courseid));
        $completion = new completion_info($course);
        
        debugging(print_r($completion,true),DEBUG_DEVELOPER);
        
        debugging(print_r($completion->has_activities(),true),DEBUG_DEVELOPER);
        
        if ($quiz){

            /*
            ,[reviewattempt]
            ,[reviewcorrectness]
            ,[reviewmarks]
            ,[reviewspecificfeedback]
            ,[reviewgeneralfeedback]
            ,[reviewrightanswer]
            ,[reviewoverallfeedback]
            ,[sumgrades]
            */
            $quiz->timeopen = 0;
            $quiz->timeclose = 0;
            //$quiz->timelimit = 0; // 0 = Exam, other value = Final Exam (depends of the rule)
            $quiz->overduehandling = 'autoabandon';
            $quiz->graceperiod = 0;
            $quiz->preferredbehaviour = 'deferredfeedback';
            //$quiz->attempts = $quiz->timelimit > 0 ? 1:0; // 0 = Exam, 1 = Final Exam  (depends of the rule)
            $quiz->attemptonlast = 0;
            $quiz->grademethod = QUIZ_ATTEMPTLAST;
            $quiz->decimalpoints = 2;
            $quiz->questiondecimalpoints = -1;
            $quiz->questionsperpage = 1;
            $quiz->navmethod = QUIZ_NAVMETHOD_SEQ;
            $quiz->shufflequestions = 1;
            $quiz->shuffleanswers = 1;
            $quiz->grade = 10.00000;
            $quiz->password = '';
            $quiz->subnet = '';
            $quiz->browsersecurity = '';
            $quiz->delay1 = 0;
            $quiz->delay2 = 0;
            $quiz->showuserpicture = 0;
            $quiz->showblocks = 0;
            $quiz->completionattemptsexhausted = 0;
            $quiz->completionpass = 1; // TO-DO: check this value
            $result = $DB->update_record('quiz',$quiz);

            debugging(print_r($result,true),DEBUG_DEVELOPER);
        }
        
        $DB->set_field('course_modules', 'completion', COMPLETION_TRACKING_AUTOMATIC, array('course' => $course->id));
    }
}
