//
// Created by 30632 on 2025/3/11.
//

#ifndef FNWINDOWIMPL_H
#define FNWINDOWIMPL_H

#include <memory>

#include "FnRenderer.h"
#include "FnWindow.h"

class FnWindowImpl final : public FnWindow {
public:
    FnWindowImpl() = default;
    ~FnWindowImpl() override = default;
    FnWindowImpl(const FnWindowImpl&) = delete;
    FnWindowImpl& operator=(const FnWindowImpl&) = delete;
    FnWindowImpl(FnWindowImpl&&) = delete;
    FnWindowImpl& operator=(FnWindowImpl&&) = delete;

public:
    void init(FnWindowType type, std::string title, int width, int height) override;
    void run() override;
    void unInit() override;

private:
    std::shared_ptr<FnRenderer> mRenderer = nullptr;
};

#endif  // FNWINDOWIMPL_H
