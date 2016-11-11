@ECHO OFF
CLS

set /p dbUsername=Enter DB Username:
set /p dbPassword=Enter DB Password:
set /p dbHost=Enter DB Host:
set /p dbName=Enter DB Name (ie: worksafe2):
set /p mainUrl=Enter Main url (ie: http://worksafe2.api.org):
set /p mdlDataroot=Enter Moodle dataroot path (ie: C:\\moodledata):
set /p googleanalyticsAccount=Enter Google Analytics ID (ie: UI-1234-1) :

ECHO ************************************************
ECHO Start Installation:
ECHO ------------------
ECHO Current folder: %CD%
ECHO DB Username: %dbUsername%
ECHO DB Password: %dbPassword%
ECHO DB Host: %dbHost%
ECHO DB Name: %dbName%
ECHO Main URL: %mainUrl%
ECHO Moodle dataroot path: %mdlDataroot%
ECHO ************************************************
Choice /M "Do you want to continue"
If Errorlevel 2 Goto No
set drush=call drush
ECHO.
ECHO Installing Drupal ...
ECHO.
%DRUSH% si commerce_kickstart commerce_kickstart_configure_store_form.install_demo_store=0 commerce_kickstart_configure_store_form.install_localization=1 --site-name=Worksafe --account-name=administrator --account-pass=123456 --db-url="sqlsrv://%dbUsername%:%dbPassword%@%dbHost%/%dbName%" --yes
ECHO.
ECHO Installing Moodle ...
ECHO.
php platform\admin\cli\install.php --wwwroot="%mainUrl%/platform" --dataroot="%mdlDataroot%" --dbtype="sqlsrv" --dbhost="%dbHost%" --dbname=%dbName% --dbuser=%dbUsername% --dbpass=%dbPassword% --fullname="API Worksafe 2.0" --shortname="Worksafe" --adminuser=admin --adminpass=123456 --non-interactive --agree-license
ECHO.
ECHO Running DRUSH commands
ECHO.

REM Enable API Custom
%DRUSH% en api_custom -y

REM Clear Cache of drush commands
%DRUSH% cc drush

REM Disable / Enable modules
%DRUSH% api disable modules_disabled.txt
%DRUSH% api enable modules_enabled.txt

REM Features revert
%DRUSH% fra -y
%DRUSH% fr api_features_blocks -y
%DRUSH% fr api_features_menus -y

REM Update Database / Run hooks install and update
%DRUSH% updb -y

REM Set default values
%DRUSH% vset theme_default worksafe
%DRUSH% vset file_temporary_path sites/default/files/tmp
%DRUSH% vset moodle_connector_url %mainUrl%/eplatform
%DRUSH% vset moodle_iframe_url %mainUrl%/platform
%DRUSH% vset googleanalytics_account %googleanalyticsAccount%
%DRUSH% moodle-vset theme worksafe
%DRUSH% moodle-vset enablecompletion 1
%DRUSH% moodle-vset forcejavascript 0 --plugin=scorm
%DRUSH% api language

REM Clear Cache
%DRUSH% cc all
php platform\admin\cli\purge_caches.php

ECHO.
ECHO ************************************************
ECHO DRUPAL URL: %mainUrl%
ECHO DRUPAL USERNAME: administrator
ECHO DRUPAL PASSWORD: 123456
ECHO MOODLE URL: %mainUrl%/platform
ECHO MOODLE USERNAME: admin
ECHO MOODLE PASSWORD: 123456
ECHO ************************************************
Goto End
:No
ECHO Install aborted
:End
pause