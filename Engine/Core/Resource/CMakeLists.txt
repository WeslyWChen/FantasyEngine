set(MODULE_NAME FnResource)
make_shared_module(${MODULE_NAME} .)

target_link_libraries(${MODULE_NAME} PRIVATE glm)