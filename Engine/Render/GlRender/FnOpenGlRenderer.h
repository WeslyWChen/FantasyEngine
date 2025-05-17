//
// Created by 30632 on 2025/3/11.
//

#ifndef FNOPENGLRENDERER_H
#define FNOPENGLRENDERER_H

#include <string>
#include <vector>

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

public:  // FnRenderer
    void init() override;
    void unInit() override;
    void run() override;
    void addObject(std::shared_ptr<FnRenderObject> object) override;

private:
    void inputHandle();
    void drawHandle();

public:
    std::string mTitle {};
    int mWidth {};
    int mHeight {};

private:
    struct Impl;
    std::shared_ptr<Impl> mImpl = nullptr;
};

#endif  // FNOPENGLRENDERER_H
