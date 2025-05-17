//
// Created by 30632 on 25-5-17.
//

#ifndef FNPAINTER_H
#define FNPAINTER_H

struct FnPainter {
    virtual ~FnPainter() = default;
    virtual void clear() = 0;
};

#endif  // FNPAINTER_H
