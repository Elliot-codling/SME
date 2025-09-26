cmake_minimum_required(VERSION 3.14)
project(SME)
set(CMAKE_CXX_STANDARD 20)

# Build SFML from source in thirdparty/sfml (explicit binary dir to avoid error)
add_subdirectory(${CMAKE_SOURCE_DIR}/thirdparty/sfml ${CMAKE_BINARY_DIR}/thirdparty/sfml-build)

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
    set(SFML_STATIC_LIBRARIES TRUE)
endif()

# Link SFML - must be public for game to use
target_link_libraries(SME PUBLIC sfml-graphics sfml-window sfml-system)

# Include the assets required for the core engine
add_custom_command(
        TARGET SME POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/external ${CMAKE_BINARY_DIR}/bin/external
)