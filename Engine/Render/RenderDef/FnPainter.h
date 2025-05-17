//
// Created by 30632 on 25-5-17.
//

#ifndef FNPAINTER_H
#define FNPAINTER_H

#include "FnColor.h"

struct FnPainter {
    virtual ~FnPainter() = default;
    virtual void clear(FnColor color) = 0;
};

#endif  // FNPAINTER_H
