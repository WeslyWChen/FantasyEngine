//
// Created by 30632 on 2025/3/9.
//

#include "FnGlRender.h"

#include "glad/glad.h"

using namespace std;

void FnGlRender::clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}