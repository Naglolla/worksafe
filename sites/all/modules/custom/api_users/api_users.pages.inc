<?php

/**
 * @file
 * Provides users list for company admins users.
 */

/**
 * Display list of users for specific company.
 */
function api_users_company_users_list($form, $form_state) {
  $form = array();
  $params = drupal_get_query_parameters();

  $form['username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#default_value' => $params['username'],
    '#size' => 20,
    '#maxlength' => 30,
  );
  $form['first_name'] = array(
    '#type' => 'textfield',
    '#title' => t('First name'),
    '#default_value' => $params['first_name'],
    '#size' => 20,
    '#maxlength' => 30,
  );
  $form['last_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Last name'),
    '#default_value' => $params['last_name'],
    '#size' => 20,
    '#maxlength' => 30,
  );
  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail'),
    '#default_value' => $params['email'],
    '#size' => 20,
    '#maxlength' => 30,
  );
  // Safety Key Options.
  $safe_key_options = array(
    'all' => t('All'),
    'valid_safety' => t('Valid Safety Key'),
    'expired_safety' => t('Expired Safety Key'),
    'no_safety' => t('No Safety Key'),
  );
  $form['safety_key'] = array(
    '#type' => 'select',
    '#title' => t('Safety key'),
    '#default_value' => $params['safety_key'],
    '#options' => $safe_key_options,
  );
  // Program Options.
  $programs = api_programs_get_programs();
  $program_options = array('all' => t('All'));
  foreach ($programs as $program) {
    $program_options[$program->program_id] = $program->title;
  }
  $form['program'] = array(
    '#type' => 'select',
    '#title' => t('Safety Key Program'),
    '#default_value' => $params['program'],
    '#options' => $program_options,
  );
  // Status Options.
  $status_options = array(
    'all' => t('All'),
    'active' => t('Active'),
    'blocked' => t('Blocked'),
  );
  $form['status'] = array(
    '#type' => 'select',
    '#title' => t('Status'),
    '#default_value' => $params['status'],
    '#options' => $status_options,
  );
  // Program status Options.
  $program_status_options = array(
    'all' => t('All'),
  );
  $form['program_status'] = array(
    '#type' => 'select',
    '#title' => t('Program status'),
    '#default_value' => $params['program_status'],
    '#options' => $program_status_options,
  );
  // Submit Button
  $form['filter'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
    '#submit' => array('api_users_submit_filters'),
  );
  // Download Button
  $form['export'] = array(
    '#type' => 'submit',
    '#value' => t('Export to Excel'),
    '#submit' => array('api_users_export_results'),
  );
  // Create user action.
  $form['create_user'] = array(
    '#type' => 'submit',
    '#value' => t('Create User'),
    '#submit' => array('api_users_create_user_redirect'),
  );
  // Pre-registration user.
  $form['pre_registration_user'] = array(
    '#type' => 'submit',
    '#value' => t('Pre-registration'),
    '#submit' => array('api_users_pre_registration_redirect'),
  );

  // Create table with last 50 records.
  $records_table = api_users_company_get_users_list(array_filter($params));

  // Add table with last 50 records.
  $form['records_table'] = $records_table['table'];

  return $form;
}

/**
 * Get users list from DB.
 * @return table of users.
 */
function api_users_company_get_users_list($filters = array()) {
  global $user;

  // Build the sortable table header.
  $header = array(
    'name' => array('data' => t('Username'), 'field' => 'u.name'),
    // We add the full name in this column (field_first_name_value + field_last_name_value)
    // But we target the "first name" field so to make it smart and allow sorting asd/desc the full name.
    'full_name' => array('data' => t('Full name'), 'field' => 'ffn.field_first_name_value'),
    'mail' => array('data' => t('Email'), 'field' => 'u.mail'),
    'status' => array('data' => t('Status'), 'field' => 'u.status'),
    'safety_key' => array('data' => t('Safety key')),
    'view_link' => array('data' => t('View')),
  );
  
  $users_list = api_users_get_company_users($user->uid, $filters, $header);

  $options = array();
  foreach ($users_list as $record) {
    $safety_key = '';
    if (isset($record->safety_key)) {
      $safety_key = l(t($record->safety_key->id), $record->safety_key->path, array('attributes' => array('target'=>'_blank')));
    }
    $options[] = array(
      'name' => $record->name,
      'full_name' => $record->field_first_name_value . ' ' . $record->field_last_name_value,
      'mail' => $record->mail,
      'status' => ($record->status)? t('Active') : t('Blocked'),
      'safety_key' => $safety_key,
      'view_link' => l(t('View'), 'user/' . $record->uid . '/edit', array('attributes' => array('target'=>'_blank'))),
    );
  }
  $form = array('table');
  $form['table']['records'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $options,
    '#empty' => t('No content available.'),
    '#attributes' => array('class' => array('views-table cols-8')),
  );
  $form['table']['pager'] = array('#markup' => theme('pager'));
  return $form;
}

/**
 *
 * Get users list filtered.
 * If no filters, return all.
 *
 * @param type $uid User ID
 * @return array of users.
 */
function api_users_get_company_users($uid, $filters, $header = array()) {
  $user_company_nid = _get_user_company($uid);
  $users_list = _get_company_users($user_company_nid, $filters, $header);
  return $users_list;
}

/**
 * Function to re invoke users list page but with filters.
 *
 * @param type $form
 * @param type $form_state
 */
function api_users_submit_filters($form, $form_state) {
  $username = $form_state['values']['username'];
  $first_name = $form_state['values']['first_name'];
  $last_name = $form_state['values']['last_name'];
  $email = $form_state['values']['email'];
  $safety_key = $form_state['values']['safety_key'];
  $program = $form_state['values']['program'];
  $status = $form_state['values']['status'];
  $program_status = $form_state['values']['program_status'];

  $url = 'admin/people/api/company/api-users';
  $query = array();
  $query['query'] = array(
    'username' => $username,
    'first_name' => $first_name,
    'last_name' => $last_name,
    'email' => $email,
    'safety_key' => $safety_key,
    'program' => $program,
    'status' => $status,
    'program_status' => $program_status
  );
  drupal_goto($url, $query);
}

/**
 * Function to redirect user to create user form.
 * We add a submit function case we need more preloaded fields (in the futre)
 *  for register form.
 * @param type $form
 * @param type $form_state
 */
function api_users_create_user_redirect($form, $form_state) {
  drupal_goto('admin/people/create');
}

/**
 * Function to redirect user to pre registration user form.
 */
function api_users_pre_registration_redirect($form, $form_state) {
  drupal_goto('import/users');
}

/**
 * Function to export results to excel file.
 */
function api_users_export_results() {
  global $user;
  $params = drupal_get_query_parameters();

  $company_nid = _get_user_company($user->uid);
  $company = node_load($company_nid);
  // The 10000000000000000 is terrible. Unfortunatelly Infinite/No limit value does not exist for MySQL.
  // @see http://bugs.mysql.com/bug.php?id=2037
  $db_records = api_users_get_company_users($user->uid, array_filter($params), array(), 10000000000000000);

  if ($db_records) {
    drupal_add_http_header('Content-Type', 'text/csv; utf-8');
    drupal_add_http_header('Content-Disposition', 'attachment;filename=users-list.csv');
    $output = '';
    $header = array(
        t('Username'), t('Full Name'), t('Email'), t('Company'), t('Safety Key'),
        t('Expires'), t('Course Name'), t('Started'), t('Correct Answers'), t('Incorrect Answers')
    );
    $output .= implode(",", $header) . "\n";
    foreach ($db_records as $row) {
      $courses  = api_course_get_user_courses_grade($row->uid);

      $safety_key = $expires = $course_name = $started = $correct = $incorrect = '';
      if (isset($row->safety_key)) {
        $safety_key = $row->id;
        $expires = $row->safety_key->field_key_expiration_date[LANGUAGE_NONE][0]['value'];
        $program_id = $row->safety_key->field_program[LANGUAGE_NONE][0]['target_id'];
        foreach ($courses as $id => $course) {
          if ($course->program_id == $program_id) {
            $course_name = $course->program_name;
            $started = format_date($course->started, 'custom', t('Y-m-d G:i:s', array(), array('context' => 'php date format')));
            $correct = $course->correct;
            $incorrect = $course->incorrect;
            unset($courses[$id]);
            break;
          }
        }
      }
      $output .=
        $row->name . ',' .
        $row->field_first_name_value . ' ' . $row->field_last_name_value . ',' .
        $row->mail . ',' .
        $company->title . ',' .
        $safety_key . ',' .
        $expires . ',' .
        $course_name . ',' .
        $started . ',' .
        $correct . ',' .
        $incorrect . ',' .
        "\n";
    }
    ob_clean();
    print $output;
    exit;
  }
}
