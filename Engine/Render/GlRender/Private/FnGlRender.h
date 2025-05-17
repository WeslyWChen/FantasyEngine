//
// Created by 30632 on 2025/3/9.
//

#ifndef FNGLRENDER_H
#define FNGLRENDER_H

#include "FnPainter.h"

class FnGlRender final : public FnPainter {
public:
    FnGlRender() = default;
    ~FnGlRender() override = default;
    FnGlRender(const FnGlRender&) = delete;
    FnGlRender& operator==(const FnGlRender&) = delete;
    FnGlRender(FnGlRender&&) = delete;
    FnGlRender& operator==(FnGlRender&&) = delete;

public:
    void clear() override;

public:
};

#endif  // FNGLRENDER_H
