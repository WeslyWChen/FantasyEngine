//
// Created by 30632 on 2025/3/9.
//

#ifndef FNRENDERMGR_H
#define FNRENDERMGR_H

#include <memory>

#include "FnModule.h"
#include "FnRenderMgrApi.h"
#include "FnWindow.h"

class FNRENDERMGR_API FnRenderMgr : public FnModule {
public:
    static std::shared_ptr<FnRenderMgr> Instance();

private:
    FnRenderMgr() = default;
    ~FnRenderMgr() override = default;
    FnRenderMgr(const FnRenderMgr&) = delete;
    FnRenderMgr& operator=(const FnRenderMgr&) = delete;
    FnRenderMgr(FnRenderMgr&&) = delete;
    FnRenderMgr& operator=(FnRenderMgr&&) = delete;

private:
    void init() override;
    void unInit() override;

public:
    std::shared_ptr<FnWindow> makeWindow() const;
};

#endif  // FNRENDERMGR_H
