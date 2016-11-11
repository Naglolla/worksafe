<?php  // Moodle configuration file

$dirname = dirname(dirname(__FILE__));
require_once $dirname."\includes\sse.php";
unset($CFG);
global $CFG;
$CFG = new stdClass();

$CFG->dbtype    = 'sqlsrv';
$CFG->dblibrary = 'native';
$CFG->dbhost    = 'api-eq-sql1.api.int';
$CFG->dbname    = 'worksafe2';
$CFG->dbuser    = 'worksafe';
$CFG->dbpass    = '-8sqBCNM+#';
$CFG->prefix    = 'mdl_';
$CFG->dboptions = array (
  'dbpersist' => 0,
  'dbport' => '',
  'dbsocket' => '',
);
$CFG->sslproxy=true;
$CFG->wwwroot   = 'https://worksafe2.api.org/platform';
$CFG->dataroot  = 'C:\\\\inetpub\\\\wwwroot\\\\moodledata';
$CFG->admin     = 'admin';

$CFG->directorypermissions = 02777;

require_once(dirname(__FILE__) . '/lib/setup.php');

// There is no php closing tag in this file,
// it is intentional because it prevents trailing whitespace problems!
