<?php

class ApiWorkTypeMigration extends ApiMigration {

  public function __construct($arguments) {

    $this->arguments = $arguments;
    parent::__construct();

    $this->description = t('WorkType migration');
    $query = Database::getConnection('legacy', 'default')
             ->select('WorkType', 'work_type')
             ->fields('work_type', array('WorkTypeID', 'WorkTypeName'));

    $this->source = new MigrateSourceSQL($query, array(), null, array('map_joinable' => false));
    $this->destination = new MigrateDestinationTerm('worktype');
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'WorkTypeID' => array('type' => 'int', 'unsigned' => TRUE, 'not null' => TRUE, 'description' => 'Company ID.')
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $this->addFieldMapping('is_new')->defaultValue(TRUE);

    $this->addFieldMapping('name', 'WorkTypeName');

  }
}
