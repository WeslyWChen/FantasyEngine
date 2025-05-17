set(MODULE_NAME FnEngine)
make_shared_module(${MODULE_NAME} .)

target_link_libraries(${MODULE_NAME} PUBLIC FnModuleMgr)
target_link_libraries(${MODULE_NAME} PUBLIC FnResource)