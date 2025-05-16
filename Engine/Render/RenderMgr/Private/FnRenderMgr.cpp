//
// Created by 30632 on 2025/3/9.
//

#include "FnRenderMgr.h"

#include "FnWindowImpl.h"

using namespace std;

void FnRenderMgr::init() {}

void FnRenderMgr::unInit() {}

std::shared_ptr<FnWindow> FnRenderMgr::makeWindow() const
{
    return make_shared<FnWindowImpl>();
}