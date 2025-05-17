//
// Created by 30632 on 25-5-17.
//

#ifndef WINAPPTEST_H
#define WINAPPTEST_H

#include "FnWinApp.h"
#include "WinAppTestLayer.h"

class WinAppTest final : public FnWinApp {
public:
    WinAppTest(int argc, char** argv) : FnWinApp(argc, argv) {}

public:
    void init();

protected:
    void onPreRun(std::shared_ptr<FnWindow> window) override;
    void onPostRun(std::shared_ptr<FnWindow> window) override;

private:
    std::shared_ptr<WinAppTestLayer> mLayer = nullptr;
};

#endif  // WINAPPTEST_H
