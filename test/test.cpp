#include "gtest/gtest.h"
#include "../include/Hailstone.h"
using sequence::satisfiesHailstone;


/*TEST(HailstoneTests, testZero) {
 * *     Triangle *aTriangle = new Triangle(3,3,3);
 * *         EXPECT_FALSE (aTriangle->getPerimeter(),false);
 * *         }
 * *         */

TEST(HailstoneTests, testZero) {
    EXPECT_FALSE (satisfiesHailstone(0));
}

TEST(HailstoneTests, testOne) {
    EXPECT_TRUE (satisfiesHailstone(1));
}

TEST(HailstoneTests, testFour) {
    EXPECT_TRUE (satisfiesHailstone(4));
}

TEST(HailstoneTests, testThree) {
    EXPECT_TRUE (satisfiesHailstone(3));
}
