# Setup project
cmake_minimum_required(VERSION 3.14)
project(main)

# Gather source and header files
file(GLOB SOURCE
        src/*.cpp
        include/*.h
        runtime/*.h
        runtime/*.cpp
        main.cpp
)

# Add all the files for the engine
add_executable(main ${SOURCE})

# Make everything in the library static
# Static link gcc runtime and c++ standard library
if((CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")  AND CMAKE_SYSTEM_NAME STREQUAL "Windows")
    # GNU SPECIFIC WINDOWS SPECIFIC
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++")
endif()

# Link with SME, else #include <SME> will not work
target_link_libraries(main PRIVATE SME)

# Include the assets required to run the project - change if necessary
add_custom_command(
        TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/bin/assets
)