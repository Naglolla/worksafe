<?php

class ApiSafetyKeysMigration extends ApiMigration {

  public function __construct($arguments) {
    $this->arguments = $arguments;
    parent::__construct();

    $this->description = t('SafetyKeys migration');
    $query = Database::getConnection('legacy', 'default')
             ->select('UserPassport', 'user_passport')
             ->fields('user_passport', array(
                 'UserPassportID', 'FK_UserID', 'FK_TestID', 'FK_CourseID', 
                 'FK_UserCourseID', 'PassportNumber', 'DateIssued', 'DateExpires'
            ));
    
    // Get Course/Program Info.
    $query->leftJoin('Course', 'course', 'user_passport.FK_CourseID = course.CourseID');
    $query->addField('course', 'CourseName');
    // Get State and Operator Raw Info.
    $query->leftJoin('UserCourse', 'user_course', 'user_passport.FK_UserCourseID = user_course.UserCourseID');
    $query->addField('user_course', 'FK_StateID');
    $query->addField('user_course', 'FK_OperatorID');
    // Get State Info.
    $query->leftJoin('State', 'state', 'user_course.FK_StateID = state.StateID');
    $query->addField('state', 'StateAbbr');
    // Get Operator Info.
    $query->leftJoin('Operator', 'operator', 'user_course.FK_OperatorID = operator.OperatorID');
    $query->addField('operator', 'OperatorName');
    
    $query->leftJoin('Users', 'users', 'user_passport.FK_UserID = users.UserID');
    $query->addField('users', 'FK_CompanyID');
    
    $query->leftJoin('Company', 'company', 'users.FK_CompanyID = company.CompanyID');
    $query->addField('company', 'CompanyName');
    
    $this->dependencies = ['ApiPrograms'];
    $this->dependencies = ['ApiCompanies'];
    $this->dependencies = ['ApiUsers'];
    
    $this->source = new MigrateSourceSQL($query, array(), null, array('map_joinable' => false));
    
    $this->destination = new MigrateDestinationEntityAPI('safety_key', 'safety_key');
    
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        //If i need a unique id.
        'UserPassportID' => array('type' => 'int', 'unsigned' => TRUE, 'not null' => TRUE, 'description' => 'UserPassport ID.')
      ),
      MigrateDestinationEntityAPI::getKeySchema('safety_key', 'safety_key')
    );
    
    $this->addFieldMapping('number', 'PassportNumber');
    $this->addFieldMapping('uid', 'FK_UserID')->sourceMigration('ApiUsers')->defaultValue(1);
    //$this->addFieldMapping('uid', 'FK_UserID');
    $this->addFieldMapping('field_state', 'StateAbbr');
    $this->addFieldMapping('field_operator_type', 'OperatorName');
    $this->addFieldMapping('field_program', 'FK_CourseID')->sourceMigration('ApiPrograms')->defaultValue(NULL);
    $this->addFieldMapping('field_safety_company', 'CompanyName');
    $this->addFieldMapping('field_key_expiration_date', 'DateExpires');
    $this->addFieldMapping('created')->defaultValue(REQUEST_TIME);

  }
  
  /**
   * @inheritdoc
   */
  public function prepare($entity, $row) {  
    // Converting date to timestamp
    $entity->created = strtotime($row->DateIssued);
  }
}
