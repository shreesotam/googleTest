#include <gtest/gtest.h>
#include "MyMathLib.h"

TEST(TestSuiteSample, TestSample)
{
    int s = sum(2, 4);
    ASSERT_EQ(6,s);
}

TEST(TestSuiteSample, AddsNegativeNumbers) {
    ASSERT_EQ(-7, sum(-2, -5));
}

int main(int argc, char**argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
