//
// Created by 30632 on 2025/3/9.
//

#ifndef FNAPP_H
#define FNAPP_H

#include <memory>

#include "FnAppApi.h"

class FNAPP_API FnApp
{
protected:
    FnApp(int argc, char** argv);
    virtual ~FnApp() = default;
    FnApp(const FnApp&) = delete;
    FnApp& operator=(const FnApp&) = delete;
    FnApp(FnApp&&) = delete;
    FnApp& operator=(FnApp&&) = delete;

public:
    void run();

protected:
    virtual void onRun() = 0;

private:
    struct Impl;
    std::shared_ptr<Impl> mImpl = nullptr;
};

#endif  // FNAPP_H
