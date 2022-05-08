@echo off
pushd %~dp0\..\
call build\premake5.exe vs2019
popd
PAUSE