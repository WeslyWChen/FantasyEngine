//
// Created by 30632 on 2025/3/9.
//

#include "FnApp.h"
#include "glog/logging.h"

class AppTest final : public FnApp
{
public:
    AppTest(int argc, char** argv) : FnApp(argc, argv) {}
    ~AppTest() override = default;

protected:
    void onRun() override
    {
        LOG(INFO) << "Run AppTest Info";
        LOG(WARNING) << "Run AppTest Warning";
        LOG(ERROR) << "Run AppTest Error";
        LOG(FATAL) << "Run AppTest Fatal";
    }
};

int main(int argc, char** argv)
{
    AppTest app(argc, argv);
    app.run();
    return 0;
}