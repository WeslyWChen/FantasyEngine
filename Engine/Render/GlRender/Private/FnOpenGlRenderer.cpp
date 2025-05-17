//
// Created by 30632 on 2025/3/11.
//

#include "FnOpenGlRenderer.h"

#include "FnGlRender.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

using namespace std;

struct FnOpenGlRenderer::Impl {
    shared_ptr<FnGlRender> mRenderer = make_shared<FnGlRender>();
    std::vector<std::weak_ptr<FnRenderObject>> mObjects {};
};

void FnOpenGlRenderer::init()
{
    mImpl = make_shared<FnOpenGlRenderer::Impl>();
}

void FnOpenGlRenderer::unInit()
{
    mImpl = nullptr;
}

void FnOpenGlRenderer::run()
{
    if (!glfwInit())
        return;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(mWidth, mHeight, mTitle.c_str(), nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
        return;

    glViewport(0, 0, mWidth, mHeight);

    while (!glfwWindowShouldClose(window)) {
        // input handle
        inputHandle();

        // clear back buffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw handle
        drawHandle();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}

void FnOpenGlRenderer::addObject(std::shared_ptr<FnRenderObject> object)
{
    if (!mImpl)
        return;
    if (!object)
        return;

    mImpl->mObjects.push_back(object);
}

void FnOpenGlRenderer::inputHandle() {}

void FnOpenGlRenderer::drawHandle()
{
    if (!mImpl)
        return;

    auto objIt = mImpl->mObjects.begin();
    while (objIt != mImpl->mObjects.end()) {
        auto obj = objIt->lock();
        if (!obj) {
            objIt = mImpl->mObjects.erase(objIt);
        } else {
            obj->draw(mImpl->mRenderer);
            ++objIt;
        }
    }
}