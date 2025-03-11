//
// Created by 30632 on 2025/3/11.
//

#ifndef FNMODULE_H
#define FNMODULE_H

#include "FnModuleMgrApi.h"

struct FnModule {
    virtual ~FnModule() = default;
    virtual void init() {};
    virtual void unInit() {};
};

#endif  // FNMODULE_H
