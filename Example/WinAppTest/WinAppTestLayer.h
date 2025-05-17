//
// Created by 30632 on 25-5-17.
//

#ifndef WINAPPTESTLAYER_H
#define WINAPPTESTLAYER_H

#include "FnWindowLayer.h"

class WinAppTestLayer final : public FnWindowLayer {
public:
    void draw(std::shared_ptr<FnPainter> painter) override;
};

#endif  // WINAPPTESTLAYER_H
