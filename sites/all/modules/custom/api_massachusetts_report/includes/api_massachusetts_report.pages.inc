<?php
/**
 * Form builder function to generate MASS DEP report.
 */
function api_massachusetts_report_form() {
  $form['description'] = array(
    '#type' => 'markup',
    '#markup' => t('Here you can generate the MASS DEP report.<br/>'),
  );

  $programs = api_programs_get_programs();
  $program_options = array();
  foreach ($programs as $program) {
    $program_options[$program->program_id] = $program->title;
  }

  $form['program'] = array(
    '#type' => 'select',
    '#title' => t('Program'),
    '#options' => $program_options,
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Generate Report',
  );

  return $form;
}

/**
 * Form submit callback.
 */
function api_massachusetts_report_form_submit($form, &$form_state) {
  if (isset($form_state) && isset($form_state['values']) && isset($form_state['values']['program'])){
    $program_id = $form_state['values']['program'];
  } else {
    $program_id = 0;
  }
  
  /* 
   * Operations to be performed by the batch process:
   * - UserCourse
   * - UserTestResults
   * - UserTestDetail
   * - UserReciprocityDetails
   * - TestQuestionCustom
   * - State
   * - Operator
   * - Users
   * - Company
   */
  
  $operations = array(
    array('api_massachusetts_report_generate_tab', array('APIMassachusettsReportUserCourse', 'api_massachusetts_report.usercourse.inc', $program_id)),
    array('api_massachusetts_report_generate_tab', array('APIMassachusettsReportUserTestResults', 'api_massachusetts_report.usertestresults.inc', $program_id)),
    array('api_massachusetts_report_generate_tab', array('APIMassachusettsReportUserTestDetail', 'api_massachusetts_report.usertestdetail.inc', $program_id)),
    array('api_massachusetts_report_generate_tab', array('APIMassachusettsUserReciprocityDetails', 'api_massachusetts_report.userreciprocitydetails.inc', $program_id)),
    array('api_massachusetts_report_generate_tab', array('APIMassachusettsReportTestQuestionCustom', 'api_massachusetts_report.testquestioncustom.inc', $program_id)),
    array('api_massachusetts_report_generate_tab', array('APIMassachusettsReportState', 'api_massachusetts_report.state.inc', $program_id)),
    array('api_massachusetts_report_generate_tab', array('APIMassachusettsReportOperator', 'api_massachusetts_report.operator.inc', $program_id)),
    array('api_massachusetts_report_generate_tab', array('APIMassachusettsReportUsers', 'api_massachusetts_report.users.inc', $program_id)),
    array('api_massachusetts_report_generate_tab', array('APIMassachusettsReportCompany', 'api_massachusetts_report.company.inc', $program_id)),
  );

  $batch = array(
    'operations' => $operations,
    'finished' => 'api_massachusetts_report_batch_finished',
    'file' => drupal_get_path('module', 'api_massachusetts_report') . '/includes/api_massachusetts_report.pages.inc',
  );

  batch_set($batch);

}

function api_massachusetts_report_generate_tab($class, $include, $program_id, &$context) {
  // Require 'APIMassachusettsReport' class
  require_once 'api_massachusetts_report.inc';
  // Include report class.
  include_once $include;

  $object = new $class($program_id);
  // Get report data.
  $report = $object->report();
  $sheet_title = $object->getSheetTitle();
  $context['results']['headers'][$sheet_title] = $report['headers'][$sheet_title];
  $context['results']['data'][$sheet_title] = $report['data'][$sheet_title] ? $report['data'][$sheet_title]:array(0 => array());
  $context['message'] = t('Generating Excel sheet "@title"', array('@title' => $sheet_title));

}

/**
 * Batch 'finished' callback used by both api_massachusetts_report_batch.
 */
function api_massachusetts_report_batch_finished($success, $results, $operations) {
  if ($success) {
    // Include PHPExcel library.
    module_load_include('inc', 'phpexcel');
    $data = $results['data'];
    $headers = $results['headers'];
    // Store the file in sites/default/files
    $dir = file_stream_wrapper_get_instance_by_uri('public://')->realpath();
    $filename = 'MassDEP_DataDump_' . date('Ymd_Hi', time());
    $filename_xls = $filename . '.xls';
    $path = "$dir/$filename_xls";

    // Use the .xls format
    $options = array('format' => 'xls');

    $result = phpexcel_export($headers, $data, $path, $options);
    if ($result == PHPEXCEL_SUCCESS) {
      // Successful xls generation.

      $zip_filename = "$dir/$filename.zip";
      $zip = new ZipArchive;
      //if ($zip->open($zip_filename, ZIPARCHIVE::CREATE) === TRUE) {
      if ($zip->open($zip_filename, ZIPARCHIVE::OVERWRITE) === TRUE) {
        $zip->addFile('sites/default/files/' . $filename_xls, $filename_xls);
        $zip->close();
        drupal_set_message(l(t('Download Report'), 'sites/default/files/' . $filename . '.zip', array('language' => 'en')));
      } else {
        drupal_set_message(t('Failed to process zip file. Please try again later.'), 'error');
      }
    }
    else {
      drupal_set_message(t('Error on Excel file generation. Please try again later.'), 'error');
    }
  } else {
    drupal_set_message(t('An error occurred while processing the report. Please try again later.'), 'error');
  }
}
