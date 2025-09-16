cmake_minimum_required(VERSION 3.14)
project(SME)
set(CMAKE_CXX_STANDARD 17)

# Use local SFML instead of fetching from GitHub
if (MSVC)
    set(SFML_DIR ${CMAKE_SOURCE_DIR}/external/SFML-MSVC/lib/cmake/SFML)
else(GCC)
    set(SFML_DIR ${CMAKE_SOURCE_DIR}/external/SFML-GCC/lib/cmake/SFML)
endif()



# Force static SFML on non-Linux systems
if(NOT CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(SFML_STATIC_LIBRARIES TRUE CACHE BOOL "Use SFML as static" FORCE)
endif()

# Find SFML (looks inside SFML_DIR path)
find_package(SFML 2.6 COMPONENTS system window graphics REQUIRED)

# Grab all cpp files from src
file(GLOB_RECURSE ENGINE_SRC CONFIGURE_DEPENDS src/*.cpp)

# Make SME a static library
add_library(SME STATIC ${ENGINE_SRC})

# Include engine headers
target_include_directories(SME PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Keep public - SFML static must be known to all files
target_compile_definitions(SME PUBLIC SFML_STATIC)

# Link SFML - must be public for game to use
target_link_libraries(SME PUBLIC sfml-graphics sfml-window sfml-system)
