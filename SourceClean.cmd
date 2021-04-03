@echo off
@echo Cleaning the source directories

@rmdir /s /q .vs
@rmdir /s /q StyleLibrary\x64
@rmdir /s /q TestDialogs\x64
@rmdir /s /q TestFrame\x64
@rmdir /s /q TestProperties\x64
@rmdir /s /q x64
@rmdir /s /q lib
@rmdir /s /q Debug
@rmdir /s /q Release