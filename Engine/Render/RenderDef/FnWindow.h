//
// Created by 30632 on 2025/3/9.
//

#ifndef FNWINDOW_H
#define FNWINDOW_H

#include <cstdint>
#include <string>

#include "FnWindowLayer.h"

enum class FnWindowType : std::uint8_t {
    WINDOW_TYPE_WIN32,
    WINDOW_TYPE_GLFW,
    WINDOW_TYPE_SDL,
    WINDOW_TYPE_VULKAN,
    WINDOW_TYPE_DX12,
    WINDOW_TYPE_DX11,
    WINDOW_TYPE_METAL,
    WINDOW_TYPE_OPENGL,
};

struct FnWindow {
    virtual ~FnWindow() = default;
    virtual void init(FnWindowType type, std::string title, int width, int height) = 0;
    virtual void unInit() = 0;
    virtual void addLayer(std::shared_ptr<FnWindowLayer> windowLayer) = 0;
    virtual void run() = 0;
};

#endif  // FNWINDOW_H
