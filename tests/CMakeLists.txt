cmake_minimum_required(VERSION 3.10)

# Set include directories for tests
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/googletest/googletest/include
)

# Create test executable
add_executable(composite_tests 
    test_composite.cpp
    ../src/component.cpp
    ../src/leaf.cpp
    ../src/composite.cpp
)

# Link with Google Test libraries
target_link_libraries(composite_tests 
    PRIVATE 
    gtest 
    gtest_main
)

# Add test
add_test(NAME composite_tests COMMAND composite_tests)