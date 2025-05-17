//
// Created by 30632 on 2025/3/11.
//

#include "FnModuleMgr.h"

#include <memory>
#include <stack>

using namespace std;

struct FnModuleMgr::Impl {
    stack<shared_ptr<FnModule>> modules;
};

std::shared_ptr<FnModuleMgr> FnModuleMgr::Instance()
{
    struct FnModuleMgrImpl : public FnModuleMgr {};
    static auto instance = make_shared<FnModuleMgrImpl>();
    return instance;
}

FnModuleMgr::FnModuleMgr()
{
    mImpl = make_unique<Impl>();
}

FnModuleMgr::~FnModuleMgr()
{
    while (!mImpl->modules.empty()) {
        if (auto module = mImpl->modules.top())
            module->unInit();
        mImpl->modules.pop();
    }
}

void FnModuleMgr::registerModule(std::shared_ptr<FnModule> module)
{
    module->init();
    mImpl->modules.push(std::move(module));
}