#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ArrayHandler.h"
#include <iostream>
#include <fstream>
#include <chrono>

void appenddata(const char* test_name, int value) {
  std::ofstream myfile;
  myfile.open("../report.txt", std::ios::app);
  myfile << test_name << ":" << value << "\n";
  myfile.close();
}

TEST(TestGroupName, Subtest_1) {
    ArrayHandler<uint8_t> arrayHandler;
    arrayHandler.AppendElem(10);
    bool res = arrayHandler.GetMax() == 10;
    EXPECT_TRUE(res);
    appenddata(::testing::UnitTest::GetInstance()->current_test_info()->name(),
                res);
}

TEST(TestGroupName, Subtest_2) {
    ArrayHandler<uint8_t> arrayHandler;
    arrayHandler.AppendElem(10);
    arrayHandler.AppendElem(-10);
    bool res = arrayHandler.GetMin() == -10;
    EXPECT_TRUE(res); // _EQ(arrayHandler.GetMin(), -10);
    appenddata(::testing::UnitTest::GetInstance()->current_test_info()->name(),
                res);
}

TEST(TestGroupName, Subtest_3) {
  bool res = true;
    srand((unsigned)time(0)); 
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    int check_count = 0;
    auto t1 = high_resolution_clock::now();
    while (check_count < 100) {
      ArrayHandler<uint32_t> arrayHandler;
      size_t elem_count = 0;
      while (elem_count < 1000000)
      {
        arrayHandler.AppendElem(rand()%100000000 + 1);
        elem_count++;
      }
      arrayHandler.AppendElem(0);
      arrayHandler.AppendElem(1000000010);
      if (arrayHandler.GetMax() != 1000000010
          && arrayHandler.GetMin() != 0) {
            res = false;
            break;
      }
      check_count++;
    }
    auto t2 = high_resolution_clock::now();
    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    EXPECT_TRUE(res); // _EQ(arrayHandler.GetMin(), -10);
    if (res)
      appenddata(::testing::UnitTest::GetInstance()->current_test_info()->name(),
                ms_int.count());
    else 
      appenddata(::testing::UnitTest::GetInstance()->current_test_info()->name(),
                0);
}