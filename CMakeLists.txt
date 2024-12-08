cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

project(CherryBadges VERSION 1.0.0)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
    src/TrailCutMod.cpp
    # Add any extra C++ source files here
)

# Add TrailCutMod.cpp to the sources list
set(SOURCES
    src/main.cpp
    src/TrailCutMod.cpp
)

# Target the sources
add_library(${PROJECT_NAME} SHARED ${SOURCES})

if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
else()
    message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()

add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

setup_geode_mod(${PROJECT_NAME})
