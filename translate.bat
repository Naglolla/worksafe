@ECHO OFF
CLS

REM Run drush commands
set drush=call drush
%DRUSH% en l10n_update -y
%DRUSH% l10n-update-refresh
%DRUSH% l10n-update
%DRUSH% cc all