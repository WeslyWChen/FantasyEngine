//
// Created by 30632 on 2025/3/11.
//

#ifndef FNRENDERER_H
#define FNRENDERER_H

#include <memory>

#include "FnRenderObject.h"

struct FnRenderer {
    virtual ~FnRenderer() = default;
    virtual void init() = 0;
    virtual void unInit() = 0;
    virtual void run() = 0;
    virtual void addObject(std::shared_ptr<FnRenderObject> object) = 0;
};

#endif  // FNRENDERER_H
