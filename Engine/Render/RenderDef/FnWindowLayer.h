//
// Created by 30632 on 25-5-17.
//

#ifndef FNWINDOWLAYER_H
#define FNWINDOWLAYER_H

#include <memory>

#include "FnPainter.h"

struct FnWindowLayer {
    virtual ~FnWindowLayer() = default;
    virtual void draw(std::shared_ptr<FnPainter> painter) = 0;
};

#endif  // FNWINDOWLAYER_H
