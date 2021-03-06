@echo off
set TMP_BUILD_BRANCH=TMP_BUILD_BRANCH

if "%~1"=="" goto NO_TARGET_BRACH

set BASE_BRANCH=master
set TARGET_BRANCH=%1


printf "\n---- Prepare -----\n"


git fetch

git checkout master
git pull

git fetch origin %TARGET_BRANCH%:%TARGET_BRANCH%

git checkout -b %TMP_BUILD_BRANCH%


printf "\n----- MERGE ------\n"
git merge %TARGET_BRANCH%



printf "\n----- BUILD ------\n"
make all


printf "\n------ RUN -------\n"
main


printf "\n----- Pausing -> if any confilicts in section MERGE then you can check file before continue ------\n"
pause


printf "\n----- Clean ------\n"
git checkout -f master
git branch -D %TMP_BUILD_BRANCH%


goto EOF

:NO_BASE_BRACH
echo Base branch not provided !
goto EOF

:NO_TARGET_BRACH
echo Target branch not provided !
goto EOF

:EOF
