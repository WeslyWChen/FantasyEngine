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

void FnWindowImpl::run()
{
    if (!mRenderer)
        return;

    mRenderer->run();
}

void FnWindowImpl::unInit()
{
    mRenderer->unInit();
}