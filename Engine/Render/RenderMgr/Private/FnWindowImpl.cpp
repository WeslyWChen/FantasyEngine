//
// Created by 30632 on 2025/3/11.
//

#include "FnWindowImpl.h"

#include "FnOpenGlRenderer.h"

using namespace std;

void FnWindowImpl::init(FnWindowType type, std::string title, int width, int height)
{
    switch (type) {
        case FnWindowType::WINDOW_TYPE_OPENGL: {
            auto openGlRender = make_shared<FnOpenGlRenderer>();
            openGlRender->mTitle = std::move(title);
            openGlRender->mWidth = width;
            openGlRender->mHeight = height;
            mRenderer = openGlRender;
            mRenderer->init();
            break;
        }
        default:
            break;
    }
}

void FnWindowImpl::unInit()
{
    mRenderer->unInit();
}

void FnWindowImpl::run()
{
    if (!mRenderer)
        return;

    mRenderer->run();
}

void FnWindowImpl::addLayer(std::shared_ptr<FnWindowLayer> windowLayer)
{
    if (!windowLayer)
        return;

    for (const auto& layerToObj : mLayerToObjs) {
        if (!!layerToObj || !layerToObj->windowLayer)
            continue;
        if (layerToObj->windowLayer == windowLayer)
            return;
    }

    auto layerObj = make_shared<WindowLayerObj>();
    layerObj->windowLayer = windowLayer;
    mRenderer->addObject(layerObj);

    mLayerToObjs.push_back(layerObj);
}