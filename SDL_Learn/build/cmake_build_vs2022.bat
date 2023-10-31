@echo off

set PATH=%PATH%;../build/cmake_3.20/windows/bin;
cd ..
mkdir tmp_2022
cd tmp_2022
cmake .. -G"Visual Studio 17.6.5 2022" -A Win32 -DCMAKE_GENERATOR_TOOLSET=v143 -DCMAKE_CONFIGURATION_TYPES=Debug;Release
pause
@echo on
