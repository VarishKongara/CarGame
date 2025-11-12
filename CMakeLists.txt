cmake_minimum_required(VERSION 3.16)
project(CarGame CXX)

# Use modern C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Export compile commands so clangd (Neovim LSP) can use them
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

# Try to find system Raylib first
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

# Collect all .cpp files in src/
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link Raylib (regardless of source or system)
target_link_libraries(${PROJECT_NAME} raylib)

# Add Raylib include directory for LSP + compiler
# Works even if raylib is fetched automatically
if (DEFINED raylib_SOURCE_DIR)
    target_include_directories(${PROJECT_NAME} PRIVATE ${raylib_SOURCE_DIR}/src)
endif()

# Linux-specific dependencies
if(UNIX)
    target_link_libraries(${PROJECT_NAME} m pthread dl rt)
endif()

# Enable extra warnings when using g++
if(CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

