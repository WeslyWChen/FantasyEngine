//
// Created by 30632 on 25-5-17.
//

#ifndef FNMATRIX_H
#define FNMATRIX_H

#include <array>
#include <optional>

#include "FnResourceApi.h"
#include "FnVector.h"

class FNRESOURCEAPI_H FnMatrix final {
public:
    std::array<float, 16> mat;

public:
    static constexpr FnMatrix MakeIdentity();

    static constexpr FnMatrix Make(float m00,
                                   float m01,
                                   float m02,
                                   float m03,
                                   float m10,
                                   float m11,
                                   float m12,
                                   float m13,
                                   float m20,
                                   float m21,
                                   float m22,
                                   float m23,
                                   float m30,
                                   float m31,
                                   float m32,
                                   float m33);

    static constexpr FnMatrix Make(const std::array<float, 16>& mat);

    static constexpr FnMatrix Make(const FnVector4& v0, const FnVector4& v1, const FnVector4& v2, const FnVector4& v3);

    static FnMatrix MakeScale(float scale);

    static FnMatrix MakeScale(float xScale, float yScale, float zScale);

    static FnMatrix MakeTranslate(float x, float y, float z);

    static FnMatrix MakeTranslate(const FnVector3& pt);

    static FnMatrix MakeRotate(float radians, const FnVector3& axis);

    static FnMatrix MakeLookAt(const FnVector3& eye, const FnVector3& center, const FnVector3& up);

public:
    constexpr FnMatrix();
    constexpr explicit FnMatrix(const std::array<float, 16>& mat);
    ~FnMatrix() = default;
    FnMatrix(const FnMatrix&) = default;
    FnMatrix& operator=(const FnMatrix&) = default;
    FnMatrix(FnMatrix&&) = default;
    FnMatrix& operator=(FnMatrix&&) = default;

public:
    bool isFinite() const;
    std::optional<FnMatrix> invMatrix() const;
    FnMatrix transpose() const;

    FnVector4 mapPt(float x, float y, float z, float w) const;
    FnVector4 operator*(const FnVector4& v) const;
    FnVector3 operator*(const FnVector3& v) const;

public:
    void setIdentity();
    void setScale(float scale);
    void setScale(float xScale, float yScale, float zScale);
    void setTranslate(float x, float y, float z);
    void setRotate(float radians, const FnVector3& axis);
    void setConcat(const FnMatrix& lhs, const FnMatrix& rhs);

public:
    FnMatrix& preConcat(const FnMatrix& mat);
    FnMatrix& postConcat(const FnMatrix& mat);
    FnMatrix& preTranslate(float x, float y, float z);
    FnMatrix& postTranslate(float x, float y, float z);
    FnMatrix& preTranslate(const FnVector3& pt);
    FnMatrix& postTranslate(const FnVector3& pt);
    FnMatrix& preScale(float scale);
    FnMatrix& postScale(float scale);
    FnMatrix& preScale(float xScale, float yScale, float zScale);
    FnMatrix& postScale(float xScale, float yScale, float zScale);

public:
    void operator+=(const FnMatrix& rhs);
    void operator-=(const FnMatrix& rhs);
    void operator*=(const FnMatrix& rhs);

    friend FnMatrix operator+(const FnMatrix& lhs, const FnMatrix& rhs);
    friend FnMatrix operator-(const FnMatrix& lhs, const FnMatrix& rhs);
    friend FnMatrix operator*(const FnMatrix& lhs, const FnMatrix& rhs);

    friend FnMatrix operator+(const FnMatrix& lhs, float rhs);
    friend FnMatrix operator-(const FnMatrix& lhs, float rhs);
    friend FnMatrix operator*(const FnMatrix& lhs, float rhs);
    friend FnMatrix operator/(const FnMatrix& lhs, float rhs);
};

#endif  // FNMATRIX_H
