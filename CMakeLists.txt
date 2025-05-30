cmake_minimum_required(VERSION 3.10)
project(CompositePattern)

set(CMAKE_CXX_STANDARD 17)

# Main executable
add_executable(composite_demo 
    src/main.cpp
    src/component.cpp
    src/leaf.cpp
    src/composite.cpp
)

# Testing
enable_testing()
add_subdirectory(tests)