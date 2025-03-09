//
// Created by 30632 on 2025/3/9.
//

#include "FnApp.h"

#include <filesystem>

#include "glog/logging.h"

using namespace std;

struct FnApp::Impl
{
    int argc = 0;
    char** argv = nullptr;
};

FnApp::FnApp(int argc, char** argv) : mImpl(make_shared<Impl>())
{
    mImpl->argc = argc;
    mImpl->argv = argv;
}

void FnApp::run()
{
    google::InitGoogleLogging(mImpl->argv[0]);
    auto loggerPath = filesystem::current_path().string() + "\\logs";
    if (!filesystem::exists(loggerPath))
        filesystem::create_directory(loggerPath);
    FLAGS_log_dir = loggerPath;
    FLAGS_v = 2;

    onRun();

    google::ShutdownGoogleLogging();
}