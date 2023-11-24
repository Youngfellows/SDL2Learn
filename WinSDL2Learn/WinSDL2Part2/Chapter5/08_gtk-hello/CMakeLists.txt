# 设置cmake最小版本
cmake_minimum_required(VERSION 3.13)

# 设置项目名称与C++语言支持
project(gtk-hello LANGUAGES CXX)

#set(CMAKE_CXX_STANDARD 11)

# 查找gtk库
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)

# gtk库头文件包含目录与库链接目录
INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})

# 定义宏
add_definitions(${GTK3_CFLAGS_OTHER})

# 生成可执行文件
ADD_EXECUTABLE(gtk_hello main.cpp)

# 链接GTK3库
TARGET_LINK_LIBRARIES(gtk_hello ${GTK3_LIBRARIES})

# 安装
install(TARGETS gtk_hello DESTINATION bin)