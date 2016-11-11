@ECHO OFF
CLS

REM Run drush commands
set drush=call drush

REM Enable API Custom
%DRUSH% en api_custom -y

REM Clear Cache of drush commands
%DRUSH% cc drush

REM Disable / Enable modules
%DRUSH% api disable modules_disabled.txt
%DRUSH% api enable modules_enabled.txt

REM Update Database / Run hooks install and update
%DRUSH% updb -y

REM %DRUSH% en api_user_moodle -y
REM %DRUSH% en api_features_token -y
REM %DRUSH% en worksafe -y
REM %DRUSH% en color_field -y
REM %DRUSH% fr api_ferature_dependencies -y

REM Features revert
%DRUSH% fra -y
%DRUSH% fr api_features_blocks -y
%DRUSH% fr api_features_menus -y

REM Set default values
%DRUSH% vset theme_default worksafe
%DRUSH% moodle-vset enablecompletion 1
%DRUSH% moodle-vset forcejavascript 0 --plugin=scorm
%DRUSH% api language

REM Clear Cache
%DRUSH% cc all
php platform\admin\cli\purge_caches.php