set(MODULE_NAME FnRenderMgr)
make_shared_module(${MODULE_NAME} .)

target_link_libraries(${MODULE_NAME} PUBLIC FnEngine)

target_link_libraries(${MODULE_NAME} PUBLIC FnRenderDef)
target_link_libraries(${MODULE_NAME} PRIVATE FnGlRender)