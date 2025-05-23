//
// Created by 30632 on 25-5-17.
//

#include "FnMatrix.h"

#include <cassert>
#include <limits>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

using namespace std;

namespace FnMatrixUtil
{
    static glm::vec2 convert(const FnPoint& point)  // NOLINT
    {
        return glm::vec2(point.x, point.y);
    }
    static glm::vec3 convert(const FnPoint3& point)  // NOLINT
    {
        return glm::vec3(point.x, point.y, point.z);
    }
    static glm::vec4 convert(const FnPoint4& point)
    {
        return glm::vec4(point.x, point.y, point.z, point.w);
    }
    static glm::mat4 convert(const FnMatrix& matrix)
    {
        return glm::make_mat4(matrix.mat.data());
    }

    static FnPoint convert(const glm::vec2& point)  // NOLINT
    {
        return FnPoint::Make(point.x, point.y);
    }
    static FnPoint3 convert(const glm::vec3& point)  // NOLINT
    {
        return FnPoint3::Make(point.x, point.y, point.z);
    }
    static FnPoint4 convert(const glm::vec4& point)
    {
        return FnPoint4::Make(point.x, point.y, point.z, point.w);
    }
    static FnMatrix convert(const glm::mat4& matrix)
    {
        return FnMatrix::Make(matrix[0][0],
                              matrix[0][1],
                              matrix[0][2],
                              matrix[0][3],
                              matrix[1][0],
                              matrix[1][1],
                              matrix[1][2],
                              matrix[1][3],
                              matrix[2][0],
                              matrix[2][1],
                              matrix[2][2],
                              matrix[2][3],
                              matrix[3][0],
                              matrix[3][1],
                              matrix[3][2],
                              matrix[3][3]);
    }
}  // namespace FnMatrixUtil

FnMatrix FnMatrix::MakeScale(float scale)
{
    FnMatrix mat;
    mat.setScale(scale);
    return mat;
}

FnMatrix FnMatrix::MakeScale(float xScale, float yScale, float zScale)
{
    FnMatrix mat;
    mat.setScale(xScale, yScale, zScale);
    return mat;
}

FnMatrix FnMatrix::MakeTranslate(float x, float y, float z)
{
    FnMatrix mat;
    mat.setTranslate(x, y, z);
    return mat;
}

FnMatrix FnMatrix::MakeTranslate(int x, int y, int z)
{
    return MakeTranslate(static_cast<float>(x), static_cast<float>(y), static_cast<float>(z));
}

FnMatrix FnMatrix::MakeTranslate(const FnVector3& pt)
{
    return MakeTranslate(pt.x, pt.y, pt.z);
}

FnMatrix FnMatrix::MakeRotate(float radians, const FnVector3& axis)
{
    FnMatrix mat;
    mat.setRotate(radians, axis);
    return mat;
}

FnMatrix FnMatrix::MakeLookAt(const FnVector3& eye, const FnVector3& center, const FnVector3& up)
{
    auto glmMat = glm::lookAt(glm::vec3(eye.x, eye.y, eye.z), glm::vec3(center.x, center.y, center.z), glm::vec3(up.x, up.y, up.z));
    return FnMatrixUtil::convert(glmMat);
}

bool FnMatrix::isFinite() const
{
    return std::all_of(mat.begin(), mat.end(), [](float val) { return std::isfinite(val); });
}

float FnMatrix::getTranslateX() const
{
    return mat[3];
}

float FnMatrix::getTranslateY() const
{
    return mat[7];
}

float FnMatrix::getTranslateZ() const
{
    return mat[11];
}

float FnMatrix::getTranslateW() const
{
    return mat[15];
}

float FnMatrix::getScaleX() const
{
    return mat[0];
}

float FnMatrix::getScaleY() const
{
    return mat[5];
}

float FnMatrix::getScaleZ() const
{
    return mat[10];
}

float FnMatrix::getScaleW() const
{
    return mat[15];
}

std::optional<FnMatrix> FnMatrix::invMatrix() const
{
    auto glmMat = FnMatrixUtil::convert(*this);
    float determinant = glm::determinant(glmMat);
    if (std::fabs(determinant) < std::numeric_limits<float>::epsilon())
        return std::nullopt;
    return FnMatrixUtil::convert(glm::inverse(glmMat));
}

FnMatrix FnMatrix::transpose() const
{
    return FnMatrixUtil::convert(glm::transpose(FnMatrixUtil::convert(*this)));
}

FnVector4 FnMatrix::mapPt(float x, float y, float z, float w) const
{
    return FnMatrixUtil::convert(glm::vec4(x, y, z, w) * FnMatrixUtil::convert(*this));
}

FnVector4 FnMatrix::operator*(const FnVector4& v) const
{
    return FnMatrixUtil::convert(FnMatrixUtil::convert(*this) * FnMatrixUtil::convert(v));
}

FnVector3 FnMatrix::operator*(const FnVector3& v) const
{
    auto v4 = FnMatrixUtil::convert(*this) * glm::vec4(v.x, v.y, v.z, 0.f);
    return FnVector3(v4.x, v4.y, v4.z);
}

void FnMatrix::setIdentity()
{
    mat = {1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f};
}

void FnMatrix::setScale(float scale)
{
    setScale(scale, scale, scale);
}

void FnMatrix::setScale(float xScale, float yScale, float zScale)
{
    mat = {xScale, 0.f, 0.f, 0.f, 0.f, yScale, 0.f, 0.f, 0.f, 0.f, zScale, 0.f, 0.f, 0.f, 0.f, 1.f};
}

void FnMatrix::setTranslate(float x, float y, float z)
{
    mat = {1.f, 0.f, 0.f, x, 0.f, 1.f, 0.f, y, 0.f, 0.f, 1.f, z, 0.f, 0.f, 0.f, 1.f};
}

void FnMatrix::setRotate(float radians, const FnVector3& axis)
{
    auto len = axis.length();
    if (len > std::numeric_limits<float>::epsilon() && std::isfinite(len)) {
        auto glmMat = glm::identity<glm::mat4>();
        *this = FnMatrixUtil::convert(glm::rotate(glmMat, radians, glm::vec3(axis.x, axis.y, axis.z)));
    } else {
        setIdentity();
    }
}

void FnMatrix::setConcat(const FnMatrix& lhs, const FnMatrix& rhs)
{
    glm::mat4 aMat = FnMatrixUtil::convert(lhs);
    glm::mat4 bMat = FnMatrixUtil::convert(rhs);
    mat = std::move(FnMatrixUtil::convert(aMat * bMat).mat);
}

FnMatrix& FnMatrix::preConcat(const FnMatrix& mat)
{
    auto glmThis = FnMatrixUtil::convert(*this);
    auto glmMat = FnMatrixUtil::convert(mat);
    *this = FnMatrixUtil::convert(glmMat * glmThis);
    return *this;
}

FnMatrix& FnMatrix::postConcat(const FnMatrix& mat)
{
    auto glmThis = FnMatrixUtil::convert(*this);
    auto glmMat = FnMatrixUtil::convert(mat);
    *this = FnMatrixUtil::convert(glmThis * glmMat);
    return *this;
}

FnMatrix& FnMatrix::preTranslate(float x, float y, float z)
{
    return preConcat(MakeTranslate(x, y, z));
}

FnMatrix& FnMatrix::postTranslate(float x, float y, float z)
{
    return postConcat(MakeTranslate(x, y, z));
}

FnMatrix& FnMatrix::preTranslate(const FnVector3& pt)
{
    return preTranslate(pt.x, pt.y, pt.z);
}

FnMatrix& FnMatrix::postTranslate(const FnVector3& pt)
{
    return postTranslate(pt.x, pt.y, pt.z);
}

FnMatrix& FnMatrix::preScale(float scale)
{
    return preScale(scale, scale, scale);
}

FnMatrix& FnMatrix::postScale(float scale)
{
    return postScale(scale, scale, scale);
}

FnMatrix& FnMatrix::preScale(float xScale, float yScale, float zScale)
{
    return preConcat(MakeScale(xScale, yScale, zScale));
}

FnMatrix& FnMatrix::postScale(float xScale, float yScale, float zScale)
{
    return postConcat(MakeScale(xScale, yScale, zScale));
}

void FnMatrix::operator+=(const FnMatrix& rhs)
{
    for (int i = 0; i < 16; ++i)
        mat[i] += rhs.mat[i];
}

void FnMatrix::operator-=(const FnMatrix& rhs)
{
    for (int i = 0; i < 16; ++i)
        mat[i] -= rhs.mat[i];
}

void FnMatrix::operator*=(const FnMatrix& rhs)
{
    setConcat(*this, rhs);
}

FnMatrix operator+(const FnMatrix& lhs, const FnMatrix& rhs)
{
    FnMatrix mat(lhs);
    for (int i = 0; i < 16; ++i)
        mat.mat[i] += rhs.mat[i];
    return mat;
}

FnMatrix operator-(const FnMatrix& lhs, const FnMatrix& rhs)
{
    FnMatrix mat(lhs);
    for (int i = 0; i < 16; ++i)
        mat.mat[i] -= rhs.mat[i];
    return mat;
}

FnMatrix operator*(const FnMatrix& lhs, const FnMatrix& rhs)
{
    FnMatrix mat;
    mat.setConcat(lhs, rhs);
    return mat;
}

FnMatrix operator-(const FnMatrix& lhs, float rhs)
{
    FnMatrix mat(lhs);
    for (int i = 0; i < 16; ++i)
        mat.mat[i] -= rhs;
    return mat;
}

FnMatrix operator*(const FnMatrix& lhs, float rhs)
{
    FnMatrix mat(lhs);
    for (int i = 0; i < 16; ++i)
        mat.mat[i] *= rhs;
    return mat;
}

FnMatrix operator/(const FnMatrix& lhs, float rhs)
{
    if (std::fabs(rhs) < std::numeric_limits<float>::epsilon())
        return FnMatrix::MakeIdentity();
    FnMatrix mat(lhs);
    for (int i = 0; i < 16; ++i)
        mat.mat[i] /= rhs;
    return mat;
}