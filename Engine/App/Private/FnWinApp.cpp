//
// Created by 30632 on 2025/3/9.
//

#include "FnWinApp.h"

#include "FnRenderMgr.h"

using namespace std;

FnWinApp::FnWinApp(int argc, char** argv) : FnApp(argc, argv) {}

void FnWinApp::setTitle(const std::string& title)
{
    mTitle = title;
}

void FnWinApp::setSize(int width, int height)
{
    mWidth = width;
    mHeight = height;
}

void FnWinApp::onRun()
{
    auto window = FnRenderMgr::Instance()->makeWindow();
    if (!window)
        return;

    window->init(FnWindowType::WINDOW_TYPE_OPENGL, mTitle, mWidth, mHeight);
    onPreRun(window);
    window->run();
    onPostRun(window);
    window->unInit();
}

void FnWinApp::onPreRun(std::shared_ptr<FnWindow> window) {}

void FnWinApp::onPostRun(std::shared_ptr<FnWindow> window) {}