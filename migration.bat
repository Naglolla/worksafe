@ECHO OFF
CLS

set drush=call drush
%DRUSH% dis api_import -y
%DRUSH% en api_import -y

REM Choice /M "Do you want to run ApiWorkType migration"
REM If Errorlevel 2 Goto ApiCompanies
REM %DRUSH% mi ApiWorkType

:ApiCompanies
Choice /M "Do you want to run ApiCompanies migration"
If Errorlevel 2 Goto ApiUsers
%DRUSH% mi ApiCompanies

:ApiUsers
Choice /M "Do you want to run ApiUsers migration"
If Errorlevel 2 Goto ApiPercentagePromoCodes
%DRUSH% mi ApiUsers

:ApiPercentagePromoCodes
Choice /M "Do you want to run ApiPercentagePromoCodes migration"
If Errorlevel 2 Goto ApiFixedPromoCodes
%DRUSH% mi ApiPercentagePromoCodes

:ApiFixedPromoCodes
Choice /M "Do you want to run ApiFixedPromoCodes migration"
If Errorlevel 2 Goto ApiPrograms
%DRUSH% mi ApiFixedPromoCodes

:ApiPrograms
Choice /M "Do you want to run ApiPrograms migration"
If Errorlevel 2 Goto ApiSafetyKeys
%DRUSH% mi ApiPrograms

:ApiSafetyKeys
Choice /M "Do you want to run ApiSafetyKeys migration"
If Errorlevel 2 Goto ApiTokens
%DRUSH% mi ApiSafetyKeys

:ApiTokens
Choice /M "Do you want to run ApiTokens migration"
If Errorlevel 2 Goto End
%DRUSH% mi ApiTokens

:End
%DRUSH% cc all
