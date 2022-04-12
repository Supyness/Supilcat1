//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>

TEST(A1, B1) {
    ASSERT_EQ(true, IsLeap(400));
    ASSERT_EQ(false, IsLeap(100));
    ASSERT_EQ(true, IsLeap(4));
    ASSERT_EQ(false, IsLeap(3));
    ASSERT_EQ(false, IsLeap(200));
    ASSERT_EQ(29, GetMonthDays(400, 2));
    ASSERT_EQ(28, GetMonthDays(200, 2));
    ASSERT_EQ(30, GetMonthDays(200, 4));
    ASSERT_EQ(30, GetMonthDays(200, 6));
    ASSERT_EQ(30, GetMonthDays(200, 9));
    ASSERT_EQ(30, GetMonthDays(200, 11));
    ASSERT_EQ(31, GetMonthDays(100, 3));
    try {
        IsLeap(-5);
    }
    catch (...) {

    }
    try {
        GetMonthDays(5, -3);
    }
    catch (...) {

    }
}