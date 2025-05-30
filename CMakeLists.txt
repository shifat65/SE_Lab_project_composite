cmake_minimum_required(VERSION 3.10)
project(CompositePattern)

set(CMAKE_CXX_STANDARD 17)

# Set include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

# Add Google Test as a subdirectory (if using local copy)
add_subdirectory(googletest)

# Main executable
add_executable(file_system_demo 
    src/main.cpp
    src/file_system_component.cpp
    src/file.cpp
    src/directory.cpp
)

# Testing
enable_testing()
add_subdirectory(tests)