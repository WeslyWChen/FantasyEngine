//
// Created by 30632 on 25-5-17.
//

#include "WinAppTestLayer.h"

using namespace std;

void WinAppTestLayer::draw(std::shared_ptr<FnPainter> painter)
{
    if (!painter)
        return;

    painter->clear();
}