#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ArrayHandler.h"
#include <iostream>

TEST(TestGroupName, Subtest_1) {
    ArrayHandler<uint8_t> arrayHandler;
    arrayHandler.AppendElem(10);
    ASSERT_TRUE(arrayHandler.GetMax() == 10);
}

TEST(TestGroupName, Subtest_2) {
    ArrayHandler<uint8_t> arrayHandler;
    arrayHandler.AppendElem(10);
    arrayHandler.AppendElem(-10);
    EXPECT_EQ(arrayHandler.GetMin(), -10);
    std::cout << ::testing::UnitTest::GetInstance()->current_test_info()->name() << std::endl;
}

TEST(TestGroupName, Subtest_3) {
    ArrayHandler<uint8_t> arrayHandler;
    arrayHandler.AppendElem(10);
    ASSERT_TRUE(arrayHandler.GetMax() == 10);
}

TEST(TestGroupName, Subtest_4) {
    ArrayHandler<uint8_t> arrayHandler;
    arrayHandler.AppendElem(10);
    ASSERT_TRUE(arrayHandler.GetMax() == 10);
}

TEST(TestGroupName, Subtest_5) {
  ASSERT_FALSE('b' == 'b');
}