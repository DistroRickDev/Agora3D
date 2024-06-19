project(open_gl_wrapper)

find_package(OpenGL REQUIRED)
find_package(Vulkan REQUIRED)

add_library(${PROJECT_NAME} STATIC glfw_wrapper.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_include_directories(${PROJECT_NAME} PRIVATE ${GLOBAL_DIR}/external/glfw/include)

add_executable(test test.cpp)
target_link_libraries(test PRIVATE glfw fmt vulkan)
target_include_directories(test PRIVATE ${GLOBAL_DIR})

add_subdirectory(window_manager)