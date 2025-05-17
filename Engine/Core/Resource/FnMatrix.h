//
// Created by 30632 on 25-5-17.
//

#ifndef FNMATRIX_H
#define FNMATRIX_H

#include <array>
#include <optional>

#include "FnResourceApi.h"
#include "FnVector.h"

class FNRESOURCE_API FnMatrix final {
public:
    std::array<float, 16> mat {};

public:
    static constexpr FnMatrix MakeIdentity() { return FnMatrix {}; }

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
                                   float m33)
    {
        return FnMatrix {std::array {m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33}};
    }

    static constexpr FnMatrix Make(const std::array<float, 16>& mat) { return FnMatrix(mat); }

    static constexpr FnMatrix Make(const FnVector4& v0, const FnVector4& v1, const FnVector4& v2, const FnVector4& v3)
    {
        return Make(std::array {v0.x, v0.y, v0.z, v0.w, v1.x, v1.y, v1.z, v1.w, v2.x, v2.y, v2.z, v2.w, v3.x, v3.y, v3.z, v3.w});
    }

    static FnMatrix MakeScale(float scale);

    static FnMatrix MakeScale(float xScale, float yScale, float zScale);

    static FnMatrix MakeTranslate(float x, float y, float z);

    static FnMatrix MakeTranslate(int x, int y, int z);

    static FnMatrix MakeTranslate(const FnVector3& pt);

    static FnMatrix MakeRotate(float radians, const FnVector3& axis);

    static FnMatrix MakeLookAt(const FnVector3& eye, const FnVector3& center, const FnVector3& up);

public:
    constexpr FnMatrix() { mat = {1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f}; }
    constexpr explicit FnMatrix(const std::array<float, 16>& mat) { this->mat = mat; }
    ~FnMatrix() = default;
    FnMatrix(const FnMatrix&) = default;
    FnMatrix& operator=(const FnMatrix&) = default;
    FnMatrix(FnMatrix&&) = default;
    FnMatrix& operator=(FnMatrix&&) = default;

public:
    bool isFinite() const;

    float getTranslateX() const;
    float getTranslateY() const;
    float getTranslateZ() const;
    float getTranslateW() const;
    float getScaleX() const;
    float getScaleY() const;
    float getScaleZ() const;
    float getScaleW() const;

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

    friend bool operator==(const FnMatrix&, const FnMatrix&) = default;
    friend bool operator!=(const FnMatrix&, const FnMatrix&) = default;
};

#endif  // FNMATRIX_H
