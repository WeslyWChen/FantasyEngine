//
// Created by 30632 on 25-5-17.
//

#ifndef FNPOINT3_H
#define FNPOINT3_H

#include <cmath>

#include "FnPoint.h"

struct FnPoint3 final {
    float x = 0.f;
    float y = 0.f;
    float z = 0.f;

    FnPoint3() = default;
    ~FnPoint3() = default;
    FnPoint3(const FnPoint3&) = default;
    FnPoint3& operator=(const FnPoint3&) = default;
    FnPoint3(FnPoint3&&) = default;
    FnPoint3& operator=(FnPoint3&&) = default;

    FnPoint3(float x, float y, float z) { set(x, y, z); }
    FnPoint3(FnPoint pt2, float z) { set(pt2.x, pt2.y, z); }

    static constexpr FnPoint3 Make(float x, float y, float z) { return FnPoint3 {x, y, z}; }

    static float Distance(const FnPoint3& lhs, const FnPoint3& rhs) { return (lhs - rhs).length(); }
    static float DotProduct(const FnPoint3& lhs, const FnPoint3& rhs) { return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z; }
    static FnPoint3 CrossProduct(const FnPoint3& lhs, const FnPoint3& rhs)
    {
        return FnPoint3::Make(lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x);
    }
    static FnPoint3 Normalize(const FnPoint3& pt)
    {
        FnPoint3 ret = pt;
        ret.normalize();
        return ret;
    }

    bool isZero() const { return x == 0.f && y == 0.f && z == 0.f; }
    bool isFinite() const { return std::isfinite(x) && std::isfinite(y) && std::isfinite(z); }

    float length() const
    {
        float magSq = x * x + y * y + z * z;
        if (std::isfinite(magSq))
            return std::sqrt(magSq);

        double xx = x;
        double yy = y;
        double zz = z;
        return std::sqrt(xx * xx + yy * yy + zz * zz);
    }

    float distanceToOrigin() const { return length(); }

    void set(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void set(int x, int y, int z)
    {
        this->x = static_cast<float>(x);
        this->y = static_cast<float>(y);
        this->z = static_cast<float>(z);
    }

    void setAbs(const FnPoint3& pt)
    {
        this->x = std::abs(pt.x);
        this->y = std::abs(pt.y);
        this->z = std::abs(pt.z);
    }

    void offset(float x, float y, float z)
    {
        this->x += x;
        this->y += y;
        this->z += z;
    }

    void offset(const FnPoint3& pt) { offset(pt.x, pt.y, pt.z); }

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

        return true;
    }

    FnPoint3 operator-() const { return FnPoint3(-x, -y, -z); }

    void operator+=(const FnPoint3& pt)
    {
        x += pt.x;
        y += pt.y;
        z += pt.z;
    }

    void operator-=(const FnPoint3& pt)
    {
        x -= pt.x;
        y -= pt.y;
        z -= pt.z;
    }

    void operator*=(float scale)
    {
        x *= scale;
        y *= scale;
        z *= scale;
    }

    void operator/=(float scale)
    {
        if (std::fabs(scale) < std::numeric_limits<float>::epsilon()) {
            x = 0.f;
            y = 0.f;
            z = 0.f;
        } else {
            x /= scale;
            y /= scale;
            z /= scale;
        }
    }

    friend bool operator==(const FnPoint3& lhs, const FnPoint3& rhs) = default;
    friend bool operator!=(const FnPoint3& lhs, const FnPoint3& rhs) = default;

    friend FnPoint3 operator+(const FnPoint3& lhs, const FnPoint3& rhs) { return FnPoint3::Make(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z); }
    friend FnPoint3 operator-(const FnPoint3& lhs, const FnPoint3& rhs) { return FnPoint3::Make(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z); }

    friend FnPoint3 operator+(const FnPoint3& lhs, float rhs) { return FnPoint3::Make(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs); }
    friend FnPoint3 operator-(const FnPoint3& lhs, float rhs) { return FnPoint3::Make(lhs.x - rhs, lhs.y - rhs, lhs.z - rhs); }
    friend FnPoint3 operator*(const FnPoint3& lhs, float rhs) { return FnPoint3::Make(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs); }
    friend FnPoint3 operator/(const FnPoint3& lhs, float rhs) { return FnPoint3::Make(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs); }
};

#endif  // FNPOINT3_H
