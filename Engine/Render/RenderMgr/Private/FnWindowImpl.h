//
// Created by 30632 on 2025/3/11.
//

#ifndef FNWINDOWIMPL_H
#define FNWINDOWIMPL_H

#include <memory>
#include <vector>

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
    void unInit() override;
    void run() override;
    void addLayer(std::shared_ptr<FnWindowLayer> windowLayer) override;

private:
    std::shared_ptr<FnRenderer> mRenderer = nullptr;

private:
    struct WindowLayerObj final : public FnRenderObject {
        std::shared_ptr<FnWindowLayer> windowLayer = nullptr;
        void draw(std::shared_ptr<FnPainter> painter) override
        {
            if (!windowLayer)
                return;
            windowLayer->draw(painter);
        }
    };
    std::vector<std::shared_ptr<WindowLayerObj>> mLayerToObjs;
};

#endif  // FNWINDOWIMPL_H
