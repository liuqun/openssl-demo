cmake_minimum_required(VERSION 3.1)
project(DEMO LANGUAGES C)
include(${CMAKE_ROOT}/Modules/CheckIncludeFile.cmake)
check_include_file("stdint.h" HAVE_STDINT_H)
configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
)
include_directories(${PROJECT_BINARY_DIR})
add_definitions(-DHAVE_CONFIG_H)
aux_source_directory(./src DEMO_SOURCES)
add_executable(demo ${DEMO_SOURCES})
set_property(TARGET demo PROPERTY C_STANDARD 11)
