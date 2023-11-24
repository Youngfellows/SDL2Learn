::使用sys2的环境mingw64编译在window平台可运行的可执行文件
@echo off
echo Start Build ...

:: 获取当前目录
set ROOT_PATH=%cd%
set BUILD=%ROOT_PATH%/build
echo BUILD: %BUILD%
cd BUILD

set CUR_PATH=%cd%
echo CUR_PATH: %CUR_PATH%

mingw32-make.exe -j6
::如果设置了CMAKE_INSTALL_PREFIX
mingw32-make.exe install
./gtk_hello.exe

echo Done .
pause