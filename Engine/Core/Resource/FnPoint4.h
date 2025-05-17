//
// Created by 30632 on 25-5-17.
//

#ifndef FNPOINT4_H
#define FNPOINT4_H

#include <cmath>

#include "FnPoint3.h"

struct FnPoint4 final {
    float x = 0.f;
    float y = 0.f;
    float z = 0.f;
    float w = 0.f;

    FnPoint4() = default;
    ~FnPoint4() = default;
    FnPoint4(const FnPoint4&) = default;
    FnPoint4& operator=(const FnPoint4&) = default;
    FnPoint4(FnPoint4&&) = default;
    FnPoint4& operator=(FnPoint4&&) = default;

    FnPoint4(float x, float y, float z, float w) { set(x, y, z, w); }
    FnPoint4(FnPoint3 pt3, float w) { set(pt3.x, pt3.y, pt3.z, w); }

    static constexpr FnPoint4 Make(float x, float y, float z, float w) { return FnPoint4 {x, y, z, w}; }

    static float Distance(const FnPoint4& lhs, const FnPoint4& rhs) { return (lhs - rhs).length(); }
    static float DotProduct(const FnPoint4& lhs, const FnPoint4& rhs) { return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w; }
    static FnPoint4 Normalize(const FnPoint4& pt)
    {
        FnPoint4 ret = pt;
        ret.normalize();
        return ret;
    }

    bool isZero() const { return x == 0.f && y == 0.f && z == 0.f && w == 0.f; }
    bool isFinite() const { return std::isfinite(x) && std::isfinite(y) && std::isfinite(z) && std::isfinite(w); }

    float length() const
    {
        float magSq = x * x + y * y + z * z + w * w;
        if (std::isfinite(magSq))
            return std::sqrt(magSq);

        double xx = x;
        double yy = y;
        double zz = z;
        double ww = w;
        return std::sqrt(xx * xx + yy * yy + zz * zz + ww * ww);
    }

    float distanceToOrigin() const { return length(); }

    void set(float x, float y, float z, float w)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }

    void set(int x, int y, int z, int w)
    {
        this->x = static_cast<float>(x);
        this->y = static_cast<float>(y);
        this->z = static_cast<float>(z);
        this->w = static_cast<float>(w);
    }

    void setAbs(const FnPoint4& pt)
    {
        this->x = std::abs(pt.x);
        this->y = std::abs(pt.y);
        this->z = std::abs(pt.z);
        this->w = std::abs(pt.w);
    }

    bool normalize()
    {
        if (isZero())
            return false;

        auto len = length();
        if (len < std::numeric_limits<float>::epsilon())
            return false;

        float scale = 1.f / len;
        x *= scale;
        y *= scale;
        z *= scale;
        w *= scale;

        return true;
    }

    FnPoint4 operator-() const { return FnPoint4(-x, -y, -z, -w); }

    void operator+=(const FnPoint4& pt)
    {
        x += pt.x;
        y += pt.y;
        z += pt.z;
        w += pt.w;
    }

    void operator-=(const FnPoint4& pt)
    {
        x -= pt.x;
        y -= pt.y;
        z -= pt.z;
        w -= pt.w;
    }

    void operator*=(float scale)
    {
        x *= scale;
        y *= scale;
        z *= scale;
        w *= scale;
    }

    void operator/=(float scale)
    {
        if (std::fabs(scale) < std::numeric_limits<float>::epsilon()) {
            x = 0.f;
            y = 0.f;
            z = 0.f;
            w = 0.f;
        } else {
            x /= scale;
            y /= scale;
            z /= scale;
            w /= scale;
        }
    }

    friend bool operator==(const FnPoint4& lhs, const FnPoint4& rhs) = default;
    friend bool operator!=(const FnPoint4& lhs, const FnPoint4& rhs) = default;

    friend FnPoint4 operator+(const FnPoint4& lhs, const FnPoint4& rhs)
    {
        return FnPoint4 {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w};
    }

    friend FnPoint4 operator-(const FnPoint4& lhs, const FnPoint4& rhs)
    {
        return FnPoint4 {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w};
    }

    friend FnPoint4 operator+(const FnPoint4& lhs, float rhs) { return FnPoint4 {lhs.x + rhs, lhs.y + rhs, lhs.z + rhs, lhs.w + rhs}; }
    friend FnPoint4 operator-(const FnPoint4& lhs, float rhs) { return FnPoint4 {lhs.x - rhs, lhs.y - rhs, lhs.z - rhs, lhs.w - rhs}; }
    friend FnPoint4 operator*(const FnPoint4& lhs, float rhs) { return FnPoint4 {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs}; }
    friend FnPoint4 operator/(const FnPoint4& lhs, float rhs) { return FnPoint4 {lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs}; }
};

#endif  // FNPOINT4_H
