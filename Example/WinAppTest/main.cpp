//
// Created by 30632 on 2025/3/9.
//

#include "FnWinApp.h"

int main(int argc, char** argv)
{
    FnWinApp app(argc, argv);
    app.setTitle("WinAppTest");
    app.setSize(960, 540);
    app.run();
    return 0;
}