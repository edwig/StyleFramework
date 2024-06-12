@echo off
@echo Cleaning the source directories

@rmdir /s /q .vs
@rmdir /s /q lib
@rmdir /s /q Bin_Win32Debug
@rmdir /s /q Bin_Win32DebugUnicode
@rmdir /s /q Bin_Win32Release
@rmdir /s /q Bin_Win32ReleaseUnicode
@rmdir /s /q Bin_x64Debug
@rmdir /s /q Bin_x64DebugUnicode
@rmdir /s /q Bin_x64Release
@rmdir /s /q Bin_x64ReleaseUnicode

call :RmSubdirs StyleFramework
call :RmSubdirs TestDialogs
call :RmSubdirs TestFrame
call :RmSubdirs TestProperties
call :RmSubdirs TestWizard

echo .
echo Ready cleaning compilations
goto :end

:RmSubDirs

RmDir  /q /s %1\Debug
RmDir  /q /s %1\DebugUnicode
RmDir  /q /s %1\Release
RmDir  /q /s %1\ReleaseUnicode
RmDir  /q /s %1\x64

goto :end

:end

