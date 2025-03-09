//
// Created by 30632 on 2025/3/9.
//

#include "FnWinApp.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

using namespace std;

FnWinApp::FnWinApp(int argc, char** argv) : FnApp(argc, argv) {}

void FnWinApp::setTitle(const std::string& title)
{
    mTitle = title;
}

void FnWinApp::setSize(int width, int height)
{
    mWidth = width;
    mHeight = height;
}

void FnWinApp::onRun()
{
    if (!glfwInit())
        return;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(mWidth, mHeight, mTitle.c_str(), nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
        return;

    glViewport(0, 0, mWidth, mHeight);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

        // input handle

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}