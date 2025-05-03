cmake_minimum_required(VERSION 3.10)
project(CalculatorProject)

# --- Application Executable ---
add_executable(CalculatorApp src/main.cpp src/CalculatorAPP.cpp) # Link both main and Calculator implementation
target_include_directories(CalculatorApp PRIVATE include)

# --- Unit Tests (Separate Executable) ---
enable_testing()
add_executable(UnitTests unittest/CalculatorTest.cpp src/CalculatorAPP.cpp) # Link test and Calculator implementation

find_package(GTest REQUIRED)
target_link_libraries(UnitTests GTest::gtest_main)
target_include_directories(UnitTests PRIVATE include unittest)

# Add tests to the test runner
include(CTest)
add_test(NAME UnitTestsRunner COMMAND UnitTests)