#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include "BitField.h"
#include "Set.h"

TEST(TestGroupName, Subtest_1) {
    BitField bf(INT_MAX);
    ASSERT_ANY_THROW(bf.SetBit(size_t(INT_MAX) + 10));
}

TEST(TestGroupName, Subtest_2) {
    BitField bf(INT_MAX);
    EXPECT_EQ(INT_MAX, bf.GetLength());
}

TEST(TestGroupName, Subtest_3) {

    const size_t size = 4;
    BitField bf1(size), bf2(size), expBf(size);
    // bf1 = 0011
    bf1.SetBit(2);
    bf1.SetBit(3);
    // bf2 = 0101
    bf2.SetBit(1);
    bf2.SetBit(3);

    // expBf = 0111
    expBf.SetBit(1);
    expBf.SetBit(2);
    expBf.SetBit(3);

    EXPECT_EQ(expBf, bf1 | bf2);
}

TEST(TestGroupName, Subtest_4) {

    const size_t size = 38;
    BitField bf(size), negBf(size), expNegBf(size);

    std::vector<uint64_t> bits;
    bits.push_back(0);
    bits.push_back(1);
    bits.push_back(14);
    bits.push_back(16);
    bits.push_back(33);
    bits.push_back(37);

    for (size_t i = 0; i < bits.size(); i++)
      bf.SetBit(bits[i]);

    negBf = ~bf;

    for(size_t i = 0; i < size; i++)
      expNegBf.SetBit(i);
    for (size_t i = 0; i < bits.size(); i++)
      expNegBf.ClrBit(bits[i]);

    EXPECT_EQ(expNegBf, negBf);
}

TEST(TestGroupName, Subtest_5) {

    const size_t size1 = 5, size2 = 7;
    Set set1(size1), set2(size2), set3(size1), expSet(size2);
    set1.InsElem(1);
    set1.InsElem(2);
    set1.InsElem(4);
    set2.InsElem(0);
    set2.InsElem(1);
    set2.InsElem(2);
    set2.InsElem(4);
    set2.InsElem(6);
    set3 = set1 * set2;
    expSet.InsElem(1);
    expSet.InsElem(2);
    expSet.InsElem(4);
    EXPECT_EQ(expSet, set3);
}

TEST(TestGroupName, Subtest_6) {
    const size_t size = 4;
    Set set(size), set1(size), expSet(size);
    // set1 = {1, 3}
    set.InsElem(1);
    set.InsElem(3);
    set1 = ~set;
    // expSet = {0, 2}
    expSet.InsElem(0);
    expSet.InsElem(2);
    EXPECT_EQ(expSet, set1);
}

TEST(TestGroupName, Subtest_7) {
    const size_t size = 5;
    Set set1(size), set2(size), set3(size), expSet(size);
    // set1 = {1, 2, 4}
    set1.InsElem(1);
    set1.InsElem(2);
    set1.InsElem(4);
    // set2 = {0, 1, 2}
    set2.InsElem(0);
    set2.InsElem(1);
    set2.InsElem(2);
    set3 = set1 + set2;
    // expSet = {0, 1, 2, 4}
    expSet.InsElem(0);
    expSet.InsElem(1);
    expSet.InsElem(2);
    expSet.InsElem(4);

    EXPECT_EQ(expSet, set3);
}

TEST(TestGroupName, Subtest_8) {
    std::vector<uint64_t> simple = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139,
    149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
     353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577,
      587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821,
       823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049,
        1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259,
         1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373, 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 1453, 1459, 1471, 1481,
          1483, 1487, 1489, 1493, 1499};

    Set set(1500);
    for (size_t i = 0; i < 1500; i++) {
      set.InsElem(i);
    }

    std::vector<uint64_t> simple_bitfield = set.GetPrimary();

    if (simple_bitfield.size() != simple.size()) {
      EXPECT_TRUE(false);
    }

    bool flag = true;
    for (size_t i = 0; i < simple_bitfield.size(); i++) {
      if (simple_bitfield[i] != simple[i]) {
        flag = false;
        break;
      }
    }

    EXPECT_TRUE(flag);
}

TEST(TestGroupName, Subtest_9) {
  const size_t size1 = 2, size2 = 5;
  BitField bf1(size1), bf2(size2);
  for (size_t i = 0; i < size1; i++)
  {
    bf1.SetBit(i);
  }
  bf2 = bf1;

  EXPECT_EQ(bf1.GetLength(), bf2.GetLength());
}


TEST(TestGroupName, Subtest_10) {
  const size_t size = 4;
  Set set1(size), set2(size);
  // set1 = {1, 3}
  set1.InsElem(1);
  set1.InsElem(3);
  // set2 = {1, 2}
  set2.InsElem(1);
  set2.InsElem(2);

  EXPECT_EQ(1, set1 != set2);
}

