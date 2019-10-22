@echo off
copy %1raylib.dll %2 /y
mkdir %2assets /y
xcopy %1resource\assets %2assets /s /y
pause