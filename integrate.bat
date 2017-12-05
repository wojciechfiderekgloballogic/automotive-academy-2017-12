@echo off
set TMP_BUILD_BRANCH=TMP_BUILD_BRANCH

if "%~1"=="" goto NO_BASE_BRACH
if "%~2"=="" goto NO_TARGET_BRACH

set BASE_BRANCH=%1
set TARGET_BRANCH=%2


printf "\n---- Prepare -----\n"

git checkout master

git pull
git fetch origin %BASE_BRANCH%:%BASE_BRANCH%
git fetch origin %TARGET_BRANCH%:%TARGET_BRANCH%

git checkout -b %TMP_BUILD_BRANCH%
git merge %BASE_BRANCH%


printf "\n----- MERGE ------\n"
git merge %TARGET_BRANCH%



printf "\n----- BUILD ------\n"
make all


printf "\n------ RUN -------\n"
main


printf "\n----- Clean ------\n"
git checkout master
git branch -D %TMP_BUILD_BRANCH%


goto EOF

:NO_BASE_BRACH
echo Base branch not provided !
goto EOF

:NO_TARGET_BRACH
echo Target branch not provided !
goto EOF

:EOF
