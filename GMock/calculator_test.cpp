#include "calculator.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class MockDependency : public Dependency {
public:
  MOCK_METHOD(int, getValue, (), (override));
  MOCK_METHOD(bool, process, (int data), (override));
};

class CalculatorTest : public ::testing::Test {
protected:
    static void SetUpTestCase() {
        // Class-level setup code, if needed
    }

    static void TearDownTestCase() {
        // Class-level cleanup code, if needed
    }

    void SetUp() override {
        // Per-test setup code
        mock_dep = new MockDependency();
        calculator = new Calculator(mock_dep);
    }

    void TearDown() override {
        // Per-test cleanup code
        delete calculator;
        delete mock_dep;
    }

    MockDependency* mock_dep;
    Calculator* calculator;
};

TEST_F(CalculatorTest, AddWithValueFromDependency) {
    EXPECT_CALL(*mock_dep, getValue())
        .Times(1)
        .WillOnce(::testing::Return(5));

    int result = calculator->addWithValueFromDependency(3);

    EXPECT_EQ(8, result);
}

TEST_F(CalculatorTest, ProcessDataAndGetValueTrue) {
    EXPECT_CALL(*mock_dep, process(::testing::Eq(10)))
        .Times(1)
        .WillOnce(::testing::Return(true));

    EXPECT_CALL(*mock_dep, getValue())
        .Times(1)
        .WillOnce(::testing::Return(10));

    bool result = calculator->processDataAndGetValue();

    EXPECT_TRUE(result);
}

TEST_F(CalculatorTest, ProcessDataAndGetValueFalseProcessFails) {
    EXPECT_CALL(*mock_dep, process(10))
        .Times(1)
        .WillOnce(::testing::Return(false));

    EXPECT_CALL(*mock_dep, getValue())
        .Times(0);

    bool result = calculator->processDataAndGetValue();

    EXPECT_FALSE(result);
}

TEST_F(CalculatorTest, ProcessDataAndGetValueFalseValueTooLow) {
    EXPECT_CALL(*mock_dep, process(10))
        .Times(1)
        .WillOnce(::testing::Return(true));

    EXPECT_CALL(*mock_dep, getValue())
        .Times(1)
        .WillOnce(::testing::Return(3));

    bool result = calculator->processDataAndGetValue();

    EXPECT_FALSE(result);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}