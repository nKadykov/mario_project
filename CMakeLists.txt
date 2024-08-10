cmake_minimum_required(VERSION 3.10)
project(mario_project)

set(CMAKE_CXX_STANDART 23)
set(CMAKE_CXX_STANDART_REQUIRED ON)

set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")

include_directories(include)

set(ASSETS_FOLDER ${CMAKE_SOURCE_DIR}/assets)
if(WIN32)
    set(ASSETS_OUTPUT_DIR Release/assets)
else()
    set(ASSETS_OUTPUT_DIR assets)
endif()

add_executable(${PROJECT_NAME} src/main.cpp)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

add_custom_command(
    TARGET mario_project POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${ASSETS_FOLDER} ${ASSETS_OUTPUT_DIR}
)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})