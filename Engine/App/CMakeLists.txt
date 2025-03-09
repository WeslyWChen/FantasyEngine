set(MODULE_NAME FnApp)
make_shared_module(${MODULE_NAME} .)

target_link_libraries(${MODULE_NAME} PUBLIC glog)
target_link_libraries(${MODULE_NAME} PRIVATE glfw glad)