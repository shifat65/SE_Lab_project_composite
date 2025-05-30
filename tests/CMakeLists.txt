cmake_minimum_required(VERSION 3.10)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

# Locate GTest
find_package(GTest REQUIRED)

# Add test executable
add_executable(composite_tests 
    test_composite.cpp
    ../src/component.cpp
    ../src/leaf.cpp
    ../src/composite.cpp
)

# Link with GTest
target_link_libraries(composite_tests GTest::GTest GTest::Main)

# Add test
add_test(NAME composite_tests COMMAND composite_tests)