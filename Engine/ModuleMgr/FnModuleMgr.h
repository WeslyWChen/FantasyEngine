//
// Created by 30632 on 2025/3/11.
//

#ifndef FNMODULEMGR_H
#define FNMODULEMGR_H

#include <memory>

#include "FnModule.h"
#include "FnModuleMgrApi.h"

class FNMODULEMGR_API FnModuleMgr {
public:
    static std::shared_ptr<FnModuleMgr> Instance();

private:
    FnModuleMgr();
    ~FnModuleMgr();
    FnModuleMgr(const FnModuleMgr&) = delete;
    FnModuleMgr& operator=(const FnModuleMgr&) = delete;
    FnModuleMgr(FnModuleMgr&&) = delete;
    FnModuleMgr& operator=(FnModuleMgr&&) = delete;

public:
    void registerModule(std::shared_ptr<FnModule> module);

private:
    struct Impl;
    std::shared_ptr<Impl> mImpl = nullptr;
};

#endif  // FNMODULEMGR_H
