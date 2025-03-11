//
// Created by 30632 on 2025/3/11.
//

#ifndef FNOPENGLRENDERER_H
#define FNOPENGLRENDERER_H

#include <string>

#include "FnGlRenderApi.h"
#include "FnRenderer.h"

class FNGLRENDER_API FnOpenGlRenderer final : public FnRenderer {
public:
    FnOpenGlRenderer() = default;
    ~FnOpenGlRenderer() override = default;
    FnOpenGlRenderer(const FnOpenGlRenderer&) = delete;
    FnOpenGlRenderer& operator=(const FnOpenGlRenderer&) = delete;
    FnOpenGlRenderer(FnOpenGlRenderer&&) = delete;
    FnOpenGlRenderer& operator=(FnOpenGlRenderer&&) = delete;

public:
    void init() override;
    void run() override;
    void unInit() override;

public:
    std::string mTitle {};
    int mWidth {};
    int mHeight {};
};

#endif  // FNOPENGLRENDERER_H
