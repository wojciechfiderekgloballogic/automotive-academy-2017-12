@echo off
set TMP_BUILD_BRANCH=TMP_BUILD_BRANCH
set TARGET_BRANCH=%1


if "%~1"=="" goto NO_TARGET_BRACH


git checkout master
git pull
git checkout %TARGET_BRANCH%
git checkout -b %TMP_BUILD_BRANCH%
git merge master

make all

main

@git checkout master
@git branch -D %TMP_BUILD_BRANCH%


goto EOF

:NO_TARGET_BRACH
echo Target branch not provided !


:EOF
