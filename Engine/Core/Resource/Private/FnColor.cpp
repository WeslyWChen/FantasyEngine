//
// Created by 30632 on 25-5-17.
//

#include "FnColor.h"

#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

FnColor FnColorUtil::convertToColor(const FnColorF& colorF)
{
    assert(colorF.a >= 0.f && colorF.a <= 1.f && colorF.b >= 0.f && colorF.b <= 1.f && colorF.g >= 0.f && colorF.g <= 1.f && colorF.r >= 0.f &&
           colorF.r <= 1.f);
    return FnColorMakeARGB(static_cast<std::uint8_t>(colorF.a * 255),
                           static_cast<std::uint8_t>(colorF.r * 255),
                           static_cast<std::uint8_t>(colorF.g * 255),
                           static_cast<std::uint8_t>(colorF.b * 255));
}

FnColor FnColorUtil::convertToColor(const FnHSV& hsv)
{
    float s = std::clamp(hsv.s, 0.f, 1.f);
    float v = std::clamp(hsv.v, 0.f, 1.f);

    std::uint8_t vByte = static_cast<std::uint8_t>(v * 255 + 0.5f);
    if (s < std::numeric_limits<float>::epsilon())
        return FnColorMakeRGB(vByte, vByte, vByte);

    float hx = (hsv.h < 0 || hsv.h >= 360.f) ? 0.f : hsv.h / 60.f;
    float w = std::floor(hx);
    float f = hx - w;

    std::uint8_t pByte = static_cast<std::uint8_t>(v * (1.f - s) * 255 + 0.5f);
    std::uint8_t qByte = static_cast<std::uint8_t>(v * (1.f - s * f) * 255 + 0.5f);
    std::uint8_t tByte = static_cast<std::uint8_t>(v * (1.f - s * (1.f - f)) * 255 + 0.5f);

    auto wByte = static_cast<std::uint8_t>(w);
    assert(wByte < 6);

    std::uint8_t r, g, b;
    switch (wByte) {
        case 0: {
            r = vByte;
            g = tByte;
            b = pByte;
            break;
        }
        case 1: {
            r = qByte;
            g = vByte;
            b = pByte;
            break;
        }
        case 2: {
            r = pByte;
            g = vByte;
            b = tByte;
            break;
        }
        case 3: {
            r = pByte;
            g = qByte;
            b = vByte;
            break;
        }
        case 4: {
            r = tByte;
            g = pByte;
            b = vByte;
            break;
        }
        default: {
            r = vByte;
            g = pByte;
            b = qByte;
            break;
        }
    }

    return FnColorMakeRGB(r, g, b);
}

FnColorF FnColorUtil::convertToColorF(const FnColor& color)
{
    return FnColorF {
            .r = FnColorGetR(color) / 255.f, .g = FnColorGetG(color) / 255.f, .b = FnColorGetB(color) / 255.f, .a = FnColorGetA(color) / 255.f};
}

FnColorF FnColorUtil::convertToColorF(const FnHSV& hsv)
{
    auto color = convertToColor(hsv);
    return convertToColorF(color);
}

FnHSV FnColorUtil::convertToHsv(const FnColor& color)
{
    std::uint8_t r = FnColorGetR(color);
    std::uint8_t g = FnColorGetG(color);
    std::uint8_t b = FnColorGetB(color);

    std::uint8_t min = std::min(std::min(r, g), b);
    std::uint8_t max = std::max(std::max(r, g), b);
    std::uint8_t delta = max - min;

    float v = max / 255.f;
    assert(v >= 0.f && v <= 1.f);

    if (delta == 0)
        return FnHSV {0.f, 0.f, v};

    float s = delta / max;
    assert(s >= 0.f && s <= 1.f);

    float h = 0.f;
    if (r == max)
        h = (g - b) / delta;
    else if (g == max)
        h = 2.f + (b - r) / delta;
    else
        h = 4.f + (r - g) / delta;

    h *= 60.f;
    if (h < 0.f)
        h += 360.f;
    assert(h >= 0.f && h <= 360.f);

    return FnHSV {h, s, v};
}

FnHSV FnColorUtil::convertToHsv(const FnColorF& colorF)
{
    auto color = convertToColor(colorF);
    return convertToHsv(color);
}