//
// Created by 30632 on 25-5-17.
//

#include "FnPoint4.h"
#include "gtest/gtest.h"

using namespace std;

TEST(FnPoint, FnPoint)
{
    auto pt = FnPoint::Make(1.f, 2.f);
    EXPECT_TRUE(pt.isFinite());
    EXPECT_TRUE(pt.length() == 2.23606797749979f);

    pt.normalize();
    EXPECT_TRUE(std::fabs(pt.length() - 1.f) < std::numeric_limits<float>::epsilon());

    pt.set(1.f, 2.f);
    EXPECT_EQ(FnPoint::Make(1.f, 2.f), pt);

    auto dotV = FnPoint::DotProduct(pt, pt);
    EXPECT_TRUE(std::fabs(dotV - 5.f) < std::numeric_limits<float>::epsilon());

    dotV = FnPoint::CrossProduct(pt, pt);
    EXPECT_TRUE(std::fabs(dotV) < std::numeric_limits<float>::epsilon());
}

TEST(FnPoint, FnPoint3)
{
    FnPoint3 pt = FnPoint3::Make(1.f, 2.f, 3.f);
    EXPECT_EQ(FnPoint3::Make(1.f, 2.f, 3.f), pt);
    EXPECT_TRUE(pt.normalize());
    EXPECT_TRUE(std::fabs(pt.length() - 1.f) < std::numeric_limits<float>::epsilon());

    pt.set(1.f, 2.f, 3.f);
    EXPECT_EQ(FnPoint3::Make(1.f, 2.f, 3.f), pt);

    pt.offset(1.f, 2.f, 3.f);
    EXPECT_EQ(FnPoint3::Make(2.f, 4.f, 6.f), pt);

    pt = FnPoint3::Normalize(pt);
    EXPECT_TRUE(std::fabs(pt.length() - 1.f) < std::numeric_limits<float>::epsilon());

    auto pt2 = FnPoint3::CrossProduct(pt, FnPoint3::Make(1.f, 2.f, 3.f));
    EXPECT_EQ(FnPoint3::Make(0.f, 0.f, 0.f), pt2);

    auto dotV = FnPoint3::Distance(pt, FnPoint3::Make(0.f, 0.f, 0.f));
    EXPECT_TRUE(std::fabs(dotV - 1.f) < std::numeric_limits<float>::epsilon());

    auto dotP = FnPoint3::DotProduct(pt, FnPoint3::Make(1.f, 2.f, 3.f));
    EXPECT_TRUE(std::fabs(dotP - 3.74165726f) < std::numeric_limits<float>::epsilon());
}

TEST(FnPoint, FnPoint4)
{
    FnPoint4 pt(1.f, 2.f, 3.f, 4.f);
    EXPECT_EQ(FnPoint4::Make(1.f, 2.f, 3.f, 4.f), pt);
    EXPECT_EQ(pt.x, 1.f);
    EXPECT_EQ(pt.y, 2.f);
    EXPECT_EQ(pt.z, 3.f);
    EXPECT_EQ(pt.w, 4.f);

    auto len = pt.length();
    EXPECT_TRUE(std::fabs(len - 5.47722578f) < std::numeric_limits<float>::epsilon());

    pt.normalize();
    EXPECT_TRUE(std::fabs(pt.length() - 1.f) < std::numeric_limits<float>::epsilon());

    auto dotV = FnPoint4::DotProduct(pt, FnPoint4::Make(1.f, 2.f, 3.f, 4.f));
    EXPECT_TRUE(std::fabs(dotV - 5.4772253f) < std::numeric_limits<float>::epsilon());
}