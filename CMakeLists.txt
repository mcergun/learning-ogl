cmake_minimum_required(VERSION 3.11)

project(oktan-app VERSION 0.0.0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_HOME_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

configure_file(oktan/Version.cfg ${PROJECT_SOURCE_DIR}/oktan/Version.h)

add_subdirectory(oktan)

include_directories(
    ".."
    "."
    "./oktan"
    "./oktan/vendor/glad/include"
    "./oktan/vendor/glm"
)

add_executable(oktan-app oktan/platform/opengl/main.cpp)

set(LINK_LIBS "oktan-generic oktan-platform oktan-vendor")

target_link_libraries(oktan-app oktan-engine)
# target_link_libraries(oktan-app oktan-generic oktan-platform oktan-vendor)