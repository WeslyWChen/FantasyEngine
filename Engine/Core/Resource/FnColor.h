//
// Created by 30632 on 25-5-17.
//

#ifndef FNCOLOR_H
#define FNCOLOR_H

#include <cassert>
#include <cstdint>

#include "FnResourceApi.h"

using FnAlpha = std::uint8_t;
using FnColor = std::uint32_t;
using FnPMColor = std::uint32_t;

static constexpr inline FnColor FnColorMakeARGB(std::uint8_t a, std::uint8_t r, std::uint8_t g, std::uint8_t b)
{
    assert(a <= 255 && r <= 255 && g <= 255 && b <= 255);
    return (a << 24) | (r << 16) | (g << 8) | (b << 0);
}

static constexpr inline FnColor FnColorMakeRGBA(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a)
{
    return FnColorMakeARGB(a, r, g, b);
}

static constexpr inline FnColor FnColorMakeRGB(std::uint8_t r, std::uint8_t g, std::uint8_t b)
{
    return FnColorMakeARGB(255, r, g, b);
}

static constexpr inline std::uint8_t FnColorGetA(FnColor color)
{
    return (color >> 24) & 0xFF;
}

static constexpr inline std::uint8_t FnColorGetR(FnColor color)
{
    return (color >> 16) & 0xFF;
}

static constexpr inline std::uint8_t FnColorGetG(FnColor color)
{
    return (color >> 8) & 0xFF;
}

static constexpr inline std::uint8_t FnColorGetB(FnColor color)
{
    return color & 0xFF;
}

static constexpr inline FnColor FnColorSetA(FnColor color, std::uint8_t a)
{
    return (color & 0x00FFFFFF) | (a << 24);
}

static constexpr inline FnColor FnColorSetR(FnColor color, std::uint8_t r)
{
    return (color & 0xFF00FFFF) | (r << 16);
}

static constexpr inline FnColor FnColorSetG(FnColor color, std::uint8_t g)
{
    return (color & 0xFFFF00FF) | (g << 8);
}

static constexpr inline FnColor FnColorSetB(FnColor color, std::uint8_t b)
{
    return (color & 0xFFFFFF00) | (b << 0);
}

constexpr FnColor FnColorTransparent = FnColorMakeARGB(0, 0, 0, 0);

constexpr FnColor FnColorBlack = FnColorMakeARGB(255, 0, 0, 0);
constexpr FnColor FnColorDkGray = FnColorMakeARGB(255, 68, 68, 68);
constexpr FnColor FnColorGray = FnColorMakeARGB(255, 136, 136, 136);
constexpr FnColor FnColorLtGray = FnColorMakeARGB(255, 204, 204, 204);
constexpr FnColor FnColorWhite = FnColorMakeARGB(255, 255, 255, 255);

constexpr FnColor FnColorRed = FnColorMakeARGB(255, 255, 0, 0);
constexpr FnColor FnColorGreen = FnColorMakeARGB(255, 0, 255, 0);
constexpr FnColor FnColorBlue = FnColorMakeARGB(255, 0, 0, 255);
constexpr FnColor FnColorYellow = FnColorMakeARGB(255, 255, 255, 0);
constexpr FnColor FnColorCyan = FnColorMakeARGB(255, 0, 255, 255);
constexpr FnColor FnColorMagenta = FnColorMakeARGB(255, 255, 0, 255);

struct FnColorF {
    float r = 0.f;
    float g = 0.f;
    float b = 0.f;
    float a = 0.f;
};

struct FnHSV {
    float h = 0.f;
    float s = 0.f;
    float v = 0.f;
};

namespace FnColorUtil
{
    FNRESOURCE_API FnColor convertToColor(const FnColorF& colorF);
    FNRESOURCE_API FnColor convertToColor(const FnHSV& hsv);

    FNRESOURCE_API FnColorF convertToColorF(const FnColor& color);
    FNRESOURCE_API FnColorF convertToColorF(const FnHSV& hsv);

    FNRESOURCE_API FnHSV convertToHsv(const FnColor& color);
    FNRESOURCE_API FnHSV convertToHsv(const FnColorF& colorF);
}  // namespace  FnColorUtil

#endif  // FNCOLOR_H
