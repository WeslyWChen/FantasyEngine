//
// Created by 30632 on 25-5-17.
//

#include "FnColor.h"
#include "gtest/gtest.h"

using namespace std;

TEST(FnColor, FnColor)
{
    ASSERT_EQ(0x00, FnColorMakeARGB(0, 0, 0, 0));

    ASSERT_EQ(0xFF000000, FnColorMakeARGB(0xFF, 0, 0, 0));

    ASSERT_EQ(0xFF0000FF, FnColorMakeARGB(0xFF, 0, 0, 0xFF));

    ASSERT_EQ(0xFFFF0000, FnColorMakeARGB(0xFF, 0xFF, 0, 0));

    FnHSV hsv = FnColorUtil::convertToHsv(FnColorTransparent);
    EXPECT_EQ(hsv.h, 0);
    EXPECT_EQ(hsv.s, 0);
    EXPECT_EQ(hsv.v, 0);

    hsv = FnColorUtil::convertToHsv(FnColorWhite);
    EXPECT_EQ(hsv.h, 0);
    EXPECT_EQ(hsv.s, 0);
    EXPECT_EQ(hsv.v, 1);

    hsv = FnColorUtil::convertToHsv(FnColorBlack);
    EXPECT_EQ(hsv.h, 0);
    EXPECT_EQ(hsv.s, 0);
    EXPECT_EQ(hsv.v, 0);

    hsv = FnColorUtil::convertToHsv(FnColorRed);
    EXPECT_EQ(hsv.h, 0);
    EXPECT_EQ(hsv.s, 1);
    EXPECT_EQ(hsv.v, 1);

    hsv = FnColorUtil::convertToHsv(FnColorGreen);
    EXPECT_EQ(hsv.h, 120);
    EXPECT_EQ(hsv.s, 1);
    EXPECT_EQ(hsv.v, 1);

    hsv = FnColorUtil::convertToHsv(FnColorBlue);
    EXPECT_EQ(hsv.h, 240);
    EXPECT_EQ(hsv.s, 1);
    EXPECT_EQ(hsv.v, 1);

    FnColorF colorF = FnColorUtil::convertToColorF(FnColorTransparent);
    EXPECT_EQ(colorF.r, 0);
    EXPECT_EQ(colorF.g, 0);
    EXPECT_EQ(colorF.b, 0);
    EXPECT_EQ(colorF.a, 0);

    colorF = FnColorUtil::convertToColorF(FnColorBlack);
    EXPECT_EQ(colorF.r, 0);
    EXPECT_EQ(colorF.g, 0);
    EXPECT_EQ(colorF.b, 0);
    EXPECT_EQ(colorF.a, 1);

    colorF = FnColorUtil::convertToColorF(FnColorWhite);
    EXPECT_EQ(colorF.r, 1);
    EXPECT_EQ(colorF.g, 1);
    EXPECT_EQ(colorF.b, 1);
    EXPECT_EQ(colorF.a, 1);

    colorF = FnColorUtil::convertToColorF(FnColorRed);
    EXPECT_EQ(colorF.r, 1);
    EXPECT_EQ(colorF.g, 0);
    EXPECT_EQ(colorF.b, 0);
    EXPECT_EQ(colorF.a, 1);

    colorF = FnColorUtil::convertToColorF(FnColorGreen);
    EXPECT_EQ(colorF.r, 0);
    EXPECT_EQ(colorF.g, 1);
    EXPECT_EQ(colorF.b, 0);
    EXPECT_EQ(colorF.a, 1);

    colorF = FnColorUtil::convertToColorF(FnColorBlue);
    EXPECT_EQ(colorF.r, 0);
    EXPECT_EQ(colorF.g, 0);
    EXPECT_EQ(colorF.b, 1);
    EXPECT_EQ(colorF.a, 1);
}