@echo off

set PROJECTFOLDER=_project
set CMAKEBIN=

set EXTERNAL=%~dp0src\external

REM try to find cmake.exe

REM ---------------------------------------
REM Search in src/external/cmake/bin/cmake.exe first
if not exist %EXTERNAL%\cmake\bin\cmake.exe goto Continue1
pushd %EXTERNAL%
set EXTERNAL=%CD%
set CMAKEBIN=%EXTERNAL%\cmake\bin\cmake.exe
popd
goto RunCmake

REM ---------------------------------------
REM search in magic path just for me
:Continue1
set EXTERNAL2=..\..\..\External
if not exist %EXTERNAL2%\cmake\bin\cmake.exe goto Continue2
pushd %EXTERNAL2%
set EXTERNAL2=%CD%
set CMAKEBIN=%EXTERNAL2%\cmake\bin\cmake.exe
popd
goto RunCmake


REM ---------------------------------------
REM search in PATH
:Continue2
for %%X in (cmake.exe) do (set CMAKEBIN=%%~$PATH:X)
if not defined CMAKEBIN goto NotFound
goto RunCmake


REM ---------------------------------------
:RunCmake
	REM run cmake
	set OUTPUTPATH=%~dp0%PROJECTFOLDER%
	if exist %OUTPUTPATH% rmdir %OUTPUTPATH% /s /q
	mkdir %OUTPUTPATH%
	pushd %OUTPUTPATH%
	%CMAKEBIN% -G"Visual Studio 14 2015 Win64" ..
	popd
	goto End

REM ---------------------------------------
:NotFound
REM print error message
	echo Couldn't locate cmake.
	echo Please make sure that cmake.exe is in the PATH or copy cmake into:
	echo %EXTERNAL%\cmake\
	echo In that case cmake.exe is expected to be located at:
	echo %EXTERNAL%\cmake\bin\cmake.exe
	goto End

:End
pause