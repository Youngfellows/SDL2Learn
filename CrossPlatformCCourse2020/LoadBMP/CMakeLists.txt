cmake_minimum_required(VERSION 3.17)
project(LoadBMP C)

set(CMAKE_C_STANDARD 11)

link_libraries(SDL2)

add_executable(LoadBMP main.c)