cmake_minimum_required(VERSION 3.10)
project(Stack)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 自动扫描当前目录下的所有 .c 文件
file(GLOB SOURCES "*.c")

# 生成可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})