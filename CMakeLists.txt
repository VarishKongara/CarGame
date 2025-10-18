
cmake_minimum_required(VERSION 3.16)
project(CarGame CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# Try to find Raylib 5.5 first
find_package(raylib QUIET)

# If Raylib isn't installed, fetch and build automatically
if (NOT raylib_FOUND)
    message(STATUS "Raylib 5.5 not found — fetching from GitHub...")
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.5
    )
    FetchContent_MakeAvailable(raylib)
endif()

# Collect source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link Raylib
target_link_libraries(${PROJECT_NAME} raylib)

# Linux-specific dependencies
if(UNIX)
    target_link_libraries(${PROJECT_NAME} m pthread dl rt)
endif()

# Warnings for g++
if(CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()
