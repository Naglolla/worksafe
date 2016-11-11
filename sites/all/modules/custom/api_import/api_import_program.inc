<?php

class ApiProgramsMigration extends ApiMigration {

  public function __construct($arguments) {
    $this->arguments = $arguments;
    parent::__construct();

    $this->description = t('Programs migration');

    $query = Database::getConnection('legacy', 'default')
             ->select('Course', 'course')
             ->fields('course', array(
                 'CourseID', 'CourseName', 'CourseDescription', 'Cost', 'KeyTypeID', 'LanguageID', 'FK_CourseTypeID', 'IsActive', 'CreatedDate'
            ));
    
    $this->source = new MigrateSourceSQL($query, array(), null, array('map_joinable' => false));
    
    $this->destination = new MigrateDestinationNode('product_display');
    
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        //If i need a unique id.
        'CourseID' => array('type' => 'int', 'unsigned' => TRUE, 'not null' => TRUE, 'description' => 'Course ID.')
      ),
      MigrateDestinationNode::getKeySchema()
    );
    
    $this->addFieldMapping('title', 'CourseName');
    $this->addFieldMapping('title_field', 'CourseName');
    $this->addFieldMapping('body', 'CourseDescription');
    $this->addFieldMapping('status', 'IsActive');
    $this->addFieldMapping('field_program_legacy_id', 'CourseID');
    $this->addFieldMapping('created')->defaultValue(REQUEST_TIME);
    
  }
  /**
   * @inheritdoc
   */
  public function prepare($entity, $row) {  
    // Converting date to timestamp
    $entity->created = strtotime($row->CreatedDate);
  }
}


