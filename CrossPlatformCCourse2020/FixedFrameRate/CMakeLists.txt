cmake_minimum_required(VERSION 3.17)
project(FixedFrameRate C)

set(CMAKE_C_STANDARD 11)

link_libraries(SDL2)

add_executable(FixedFrameRate main.c)