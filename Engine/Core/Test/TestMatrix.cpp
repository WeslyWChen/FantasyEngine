//
// Created by 30632 on 25-5-17.
//

#include "FnMatrix.h"
#include "gtest/gtest.h"

using namespace std;

TEST(FnMatrix, Base)
{
    FnMatrix mat = FnMatrix::MakeIdentity();
    EXPECT_EQ(mat.mat[0], 1.f);
    EXPECT_EQ(mat.mat[1], 0.f);
    EXPECT_EQ(mat.mat[2], 0.f);
    EXPECT_EQ(mat.mat[3], 0.f);

    EXPECT_EQ(mat.mat[4], 0.f);
    EXPECT_EQ(mat.mat[5], 1.f);
    EXPECT_EQ(mat.mat[6], 0.f);
    EXPECT_EQ(mat.mat[7], 0.f);

    EXPECT_EQ(mat.mat[8], 0.f);
    EXPECT_EQ(mat.mat[9], 0.f);
    EXPECT_EQ(mat.mat[10], 1.f);
    EXPECT_EQ(mat.mat[11], 0.f);

    EXPECT_EQ(mat.mat[12], 0.f);
    EXPECT_EQ(mat.mat[13], 0.f);
    EXPECT_EQ(mat.mat[14], 0.f);
    EXPECT_EQ(mat.mat[15], 1.f);

    mat.preConcat(FnMatrix::MakeTranslate(1, 5, 6));
    EXPECT_EQ(mat.mat[3], 1.f);
    EXPECT_EQ(mat.mat[7], 5.f);
    EXPECT_EQ(mat.mat[11], 6.f);

    auto invMat = mat.invMatrix();
    ASSERT_TRUE(invMat);
    EXPECT_TRUE(FnMatrix::MakeTranslate(-1, -5, -6) == *invMat);
}