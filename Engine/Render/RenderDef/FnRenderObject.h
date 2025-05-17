//
// Created by 30632 on 25-5-17.
//

#ifndef FNRENDEROBJECT_H
#define FNRENDEROBJECT_H

#include <memory>

#include "FnPainter.h"

struct FnRenderObject {
    virtual ~FnRenderObject() = default;
    virtual void draw(std::shared_ptr<FnPainter> painter) = 0;
};

#endif  // FNRENDEROBJECT_H
