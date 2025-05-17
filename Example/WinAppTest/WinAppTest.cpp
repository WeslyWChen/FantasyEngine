//
// Created by 30632 on 25-5-17.
//

#include "WinAppTest.h"

#include "FnRenderMgr.h"

using namespace std;

void WinAppTest::init()
{
    setTitle("WinAppTest");
    setSize(960, 540);

    mLayer = make_shared<WinAppTestLayer>();
}

void WinAppTest::onPreRun(std::shared_ptr<FnWindow> window)
{
    if (!window)
        return;

    window->addLayer(mLayer);
}

void WinAppTest::onPostRun(std::shared_ptr<FnWindow> window)
{
    FnWinApp::onPostRun(window);
}