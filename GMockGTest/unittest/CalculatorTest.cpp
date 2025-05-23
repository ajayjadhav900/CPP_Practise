#include "gtest/gtest.h"
#include "Calculator.hpp"
#include "gmock/gmock.h"

// Mock class for Calculator
class MockCalculator {
public:
    MOCK_METHOD(int, add, (int a, int b), ());
    MOCK_METHOD(int, subtract, (int a, int b), ());
    MOCK_METHOD(int, multiply, (int a, int b), ());
    MOCK_METHOD(int, divide, (int a, int b), ());
};

// Test fixture for the Calculator class
class CalculatorTest : public ::testing::Test {
protected:
    Calculator calculator_;
}; 

// Test case for the add function
TEST_F(CalculatorTest, AddPositiveNumbers) {
    ASSERT_EQ(5, calculator_.add(2, 3));
    ASSERT_EQ(10, calculator_.add(7, 3));
}

TEST_F(CalculatorTest, AddNegativeNumbers) {
    ASSERT_EQ(-5, calculator_.add(-2, -3));
    ASSERT_EQ(-1, calculator_.add(-5, 4));
}

// Test case for the subtract function
TEST_F(CalculatorTest, SubtractPositiveNumbers) {
    ASSERT_EQ(1, calculator_.subtract(3, 2));
    ASSERT_EQ(5, calculator_.subtract(10, 5));
}

TEST_F(CalculatorTest, SubtractNegativeNumbers) {
    ASSERT_EQ(-1, calculator_.subtract(-3, -2));
    ASSERT_EQ(-9, calculator_.subtract(-5, 4));
}

// Test case for the multiply function
TEST_F(CalculatorTest, MultiplyPositiveNumbers) {
    ASSERT_EQ(6, calculator_.multiply(2, 3));
    ASSERT_EQ(21, calculator_.multiply(7, 3));
}

TEST_F(CalculatorTest, MultiplyWithZero) {
    ASSERT_EQ(0, calculator_.multiply(5, 0));
    ASSERT_EQ(0, calculator_.multiply(0, -3));
}

// Test case for the divide function
TEST_F(CalculatorTest, DividePositiveNumbers) {
    ASSERT_EQ(2, calculator_.divide(6, 3));
    ASSERT_EQ(3, calculator_.divide(9, 3));
}

TEST_F(CalculatorTest, DivideNegativeNumbers) {
    ASSERT_EQ(2, calculator_.divide(-6, -3));
    ASSERT_EQ(-2, calculator_.divide(6, -3));
    ASSERT_EQ(-2, calculator_.divide(-6, 3));
}

TEST_F(CalculatorTest, DivideByZeroThrowsException) {
    ASSERT_THROW(calculator_.divide(5, 0), std::invalid_argument);
}

// Example test case using the mock class
TEST(MockCalculatorTest, AddFunction) {
    MockCalculator mockCalculator;

    //Set expectation for the add method
    EXPECT_CALL(mockCalculator, add(2, 3))
        .Times(1)
        .WillOnce(::testing::Return(5));

    // Call the mock method
   EXPECT_EQ(mockCalculator.add(2, 3), 5);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
