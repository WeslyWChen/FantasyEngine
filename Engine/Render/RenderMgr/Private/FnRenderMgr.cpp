//
// Created by 30632 on 2025/3/9.
//

#include "FnRenderMgr.h"

#include "FnModuleMgr.h"
#include "FnWindowImpl.h"

using namespace std;

std::shared_ptr<FnRenderMgr> FnRenderMgr::Instance()
{
    struct FnRenderMgrImpl : FnRenderMgr {};
    static auto instance = make_shared<FnRenderMgrImpl>();
    return instance;
}

void FnRenderMgr::init() {}

void FnRenderMgr::unInit() {}

std::shared_ptr<FnWindow> FnRenderMgr::makeWindow() const
{
    return make_shared<FnWindowImpl>();
}