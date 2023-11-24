:: 注意: 脚本一定要用Notepad++转化为文档格式为Windows(CR LF)

:: 使用@echo off后显示echo的时候只显示结果
@echo off
echo Use CMake Create Visual Studio 2022 Project

:: 定义目录常量
setlocal
set BUILD_DIR=build
set RELEASE_DIR=Release
echo BUILD_DIR: %BUILD_DIR%

:: 获取当前目录
set ROOT_PATH=%cd%
echo ROOT_PATH: %ROOT_PATH%
set INSTALL=%ROOT_PATH%/%RELEASE_DIR%

:: ==============================================================
:: 这是.bat脚本的注释 
:: ==============================================================

echo ">>>>> Generates a make file for use with mingw32-make ..."
rmdir /s /q %BUILD_DIR%
mkdir %BUILD_DIR%
rmdir /s /q %RELEASE_DIR%
mkdir %RELEASE_DIR%
cd %BUILD_DIR%

:: cmake -G "Visual Studio 17 2022" -A Win32 ..
:: cmake -G "Visual Studio 17 2022" -A x64 -DCMAKE_INSTALL_PREFIX:PATH=%INSTALL% ..
:: cmake -G "Visual Studio 17 2022" -A ARM ..
:: cmake -G "Visual Studio 17 2022" -A ARM64 ..
cmake -G "MinGW Makefiles" -DCMAKE_INSTALL_PREFIX:PATH=%INSTALL% ..
echo .

echo ">>>>> Generates a make file for use with mingw32-make ..."
set CUR_PATH=%cd%
echo CUR_PATH: %CUR_PATH%

:: 使用mingw32-make来编译
mingw32-make.exe -j6

:: 如果设置了CMAKE_INSTALL_PREFIX
mingw32-make.exe install

:: 1.可以运行build目录下的
:: gtk_hello.exe

:: 2.也可以运行Release/bin/目录下的
%INSTALL%/bin/gtk_hello.exe

echo "Done ."
pause
