set(MODULE_NAME FnGlRender)
make_shared_module(${MODULE_NAME} .)

target_link_libraries(${MODULE_NAME} PUBLIC FnRenderDef)
target_link_libraries(${MODULE_NAME} PRIVATE glfw glad)