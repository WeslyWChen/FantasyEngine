//
// Created by 30632 on 25-5-17.
//

#ifndef FNPOINT_H
#define FNPOINT_H

#include <cmath>

struct FnPoint final {
    float x = 0.f;
    float y = 0.f;

    static constexpr FnPoint Make(float x, float y) { return FnPoint {x, y}; }

    static float Distance(const FnPoint& lhs, const FnPoint& rhs) { return (lhs - rhs).length(); }
    static float DotProduct(const FnPoint& lhs, const FnPoint& rhs) { return lhs.x * rhs.x + lhs.y * rhs.y; }
    static float CrossProduct(const FnPoint& lhs, const FnPoint& rhs) { return lhs.x * rhs.y - lhs.y * rhs.x; }
    static FnPoint Normalize(const FnPoint& pt)
    {
        FnPoint ret = pt;
        ret.normalize();
        return ret;
    }

    bool isZero() const { return x == 0.f && y == 0.f; }
    bool isFinite() const { return std::isfinite(x) && std::isfinite(y); }

    float length() const
    {
        float mag2 = x * x + y * y;
        if (std::isfinite(mag2))
            return std::sqrt(x * x + y * y);

        double xx = x;
        double yy = y;
        return std::sqrt(xx * xx + yy * yy);
    }

    float distanceToOrigin() const { return length(); }

    void set(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    void set(int x, int y)
    {
        this->x = static_cast<float>(x);
        this->y = static_cast<float>(y);
    }

    void setAbs(const FnPoint& pt)
    {
        this->x = std::fabs(pt.x);
        this->y = std::fabs(pt.y);
    }

    void offset(float x, float y)
    {
        this->x += x;
        this->y += y;
    }

    void offset(const FnPoint& pt) { offset(pt.x, pt.y); }

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

        return true;
    }

    FnPoint operator-() const { return FnPoint {-x, -y}; }

    void operator+=(const FnPoint& point)
    {
        x += point.x;
        y += point.y;
    }

    void operator-=(const FnPoint& point)
    {
        x -= point.x;
        y -= point.y;
    }

    void operator*=(float scale)
    {
        x *= scale;
        y *= scale;
    }

    void operator/=(float scale)
    {
        if (std::fabs(scale) < std::numeric_limits<float>::epsilon()) {
            x = 0.f;
            y = 0.f;
        } else {
            x /= scale;
            y /= scale;
        }
    }

    friend bool operator==(const FnPoint&, const FnPoint&) = default;
    friend bool operator!=(const FnPoint&, const FnPoint&) = default;

    friend FnPoint operator+(const FnPoint& lhs, const FnPoint& rhs) { return FnPoint {lhs.x + rhs.x, lhs.y + rhs.y}; }
    friend FnPoint operator-(const FnPoint& lhs, const FnPoint& rhs) { return FnPoint {lhs.x - rhs.x, lhs.y - rhs.y}; }

    friend FnPoint operator+(const FnPoint& lhs, float rhs) { return FnPoint {lhs.x + rhs, lhs.y + rhs}; }
    friend FnPoint operator-(const FnPoint& lhs, float rhs) { return FnPoint {lhs.x - rhs, lhs.y - rhs}; }
    friend FnPoint operator*(const FnPoint& lhs, float rhs) { return FnPoint {lhs.x * rhs, lhs.y * rhs}; }
    friend FnPoint operator/(const FnPoint& lhs, float rhs) { return FnPoint {lhs.x / rhs, lhs.y / rhs}; }
};

#endif  // FNPOINT_H
