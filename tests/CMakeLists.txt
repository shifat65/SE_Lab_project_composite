cmake_minimum_required(VERSION 3.10)

# Set include directories for tests
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/googletest/googletest/include
)

# Create test executable
add_executable(file_system_tests 
    test_file_system.cpp
    ../src/file_system_component.cpp
    ../src/file.cpp
    ../src/directory.cpp
)

# Link with Google Test libraries
target_link_libraries(file_system_tests 
    PRIVATE 
    gtest 
    gtest_main
)

# Add test
add_test(NAME file_system_tests COMMAND file_system_tests)