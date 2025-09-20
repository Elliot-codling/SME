cmake_minimum_required(VERSION 3.14)
project(SME)

# Build SFML from source in external/src (explicit binary dir to avoid error)
add_subdirectory(${CMAKE_SOURCE_DIR}/external/sfml ${CMAKE_BINARY_DIR}/external/sfml-build)

# Grab all cpp files from src
file(GLOB_RECURSE ENGINE_SRC CONFIGURE_DEPENDS src/*.cpp)

# Make SME a static library
add_library(SME STATIC ${ENGINE_SRC})

# Include engine headers
target_include_directories(SME PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Force SFML to be static (except on Linux)
if(NOT CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_definitions(SME PUBLIC SFML_STATIC)
endif()

# Link SFML - must be public for game to use
target_link_libraries(SME PUBLIC sfml-graphics sfml-window sfml-system)
