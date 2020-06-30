cmake_minimum_required (VERSION 3.1)
set (CMAKE_C_STANDARD 11)
set (CMAKE_CXX_STANDARD 11)
project (myGameEngine)

include_directories("${PROJECT_SOURCE_DIR}/Framework/Common")
include_directories("${PROJECT_SOURCE_DIR}/Framework/Interface")

add_subdirectory(Framework)
add_subdirectory(Empty)
add_subdirectory(util)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
set(ASSERTIONS_ENABLED 1)
endif()
configure_file("${PROJECT_SOURCE_DIR}/config.h.in"
"${PROJECT_SOURCE_DIR}/include/config.h")