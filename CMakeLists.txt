cmake_minimum_required(VERSION 3.10)
project(mario_project)

set(CMAKE_CXX_STANDART 23)
set(CMAKE_CXX_STANDART_REQUIRED True)

set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")

include_directories(include)

add_executable(mario_project)
