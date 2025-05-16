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

#define DEFINE_MODULE_INSTANCE(className)                                                \
    static std::shared_ptr<className> Instance()                                         \
    {                                                                                    \
        struct className##Impl : public className {};                                    \
        struct className##ImplImpl {                                                     \
            std::shared_ptr<className##Impl> impl = std::make_shared<className##Impl>(); \
            className##ImplImpl()                                                        \
            {                                                                            \
                FnModuleMgr::Instance()->registerModule(impl);                           \
            }                                                                            \
            ~className##ImplImpl() = default;                                            \
        };                                                                               \
        static className##ImplImpl instance;                                             \
        return instance.impl;                                                            \
    }

#endif  // FNMODULEMGR_H
