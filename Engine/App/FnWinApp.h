//
// Created by 30632 on 2025/3/9.
//

#ifndef FNWINAPP_H
#define FNWINAPP_H

#include "FnApp.h"
#include "FnWindow.h"

class FNAPP_API FnWinApp : public FnApp {
public:
    FnWinApp(int argc, char** argv);
    ~FnWinApp() override = default;
    FnWinApp(const FnWinApp&) = delete;
    FnWinApp& operator=(const FnWinApp&) = delete;
    FnWinApp(FnWinApp&&) = delete;
    FnWinApp& operator=(FnWinApp&&) = delete;

public:
    void setTitle(const std::string& title);
    void setSize(int width, int height);

protected:
    void onRun() override;

protected:
    virtual void onPreRun(std::shared_ptr<FnWindow> window);
    virtual void onPostRun(std::shared_ptr<FnWindow> window);

private:
    std::string mTitle = "FnWinApp";
    int mWidth = 800;
    int mHeight = 600;
};

#endif  // FNWINAPP_H
