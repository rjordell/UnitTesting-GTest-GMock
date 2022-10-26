#include "gtest/gtest.h"
#include "../include/Triangle.h"
#include <math.h>
using shapes::Triangle;


TEST(TriangleTests, testPerimeter1) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->getPerimeter(),9);
}

TEST(TriangleTests, testPerimeter2) {
    Triangle *aTriangle = new Triangle(5,4,3);
    EXPECT_EQ (aTriangle->getPerimeter(),12);
}

TEST(TriangleTests, testArea1) {
    Triangle *aTriangle = new Triangle(3,3,3);
    double halfPerimeter = aTriangle->getPerimeter() / 2.0;
    double radicand = halfPerimeter
                    * (halfPerimeter - 3)
                    * (halfPerimeter - 3)
                    * (halfPerimeter - 3);
    double are = sqrt(radicand);
    EXPECT_EQ (aTriangle->getArea(),are);
}

TEST(TriangleTests, testArea2) {
    Triangle *aTriangle = new Triangle(5,4,3);
    EXPECT_EQ (aTriangle->getArea(),6);
}

TEST(TriangleTests, testKindE) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->getKind(),Triangle::Kind::EQUILATERAL);
}

TEST(TriangleTests, testKindI) {
    Triangle *aTriangle = new Triangle(5,5,3);
    EXPECT_EQ (aTriangle->getKind(),Triangle::Kind::ISOSCELES);
}

TEST(TriangleTests, testKindS) {
    Triangle *aTriangle = new Triangle(4,3,2);
    EXPECT_EQ (aTriangle->getKind(),Triangle::Kind::SCALENE);
}

TEST(TriangleTests, testInvalidOrder) {
    EXPECT_DEATH ({Triangle *aTriangle = new Triangle(2,4,3);},"First side is not the longest");	
}

TEST(TriangleTests, testInvalidEquality) {
    EXPECT_DEATH ({Triangle *aTriangle = new Triangle(9,1,1);},"Does not satisfy triangle inequality");	
}