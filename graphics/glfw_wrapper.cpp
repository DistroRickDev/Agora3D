
#include "glfw_wrapper.h"
#include "GLFW/glfw3.h"

#include <iostream>

#if defined(unix) || defined(__unix) || defined(__unix__)
    #if defined(_WAYLAND)
        #define _GLFW_PLATFORM GLFW_PLATFORM_WAYLAND
    #else
        #define _GLFW_PLATFORM GLFW_PLATFORM_X11
    #endif // _WAYLAND
#elif defined(_WIN32) || defined(_WIN64)  || defined(__CYGWIN__)
    #define _GLFW_PLATFORM GLFW_PLATFORM_WIN32
#elif defined(_APPLE__) ||  defined(__MACH__)
    #define _GLFW_PLATFORM GLFW_PLATFORM_COCOA
#elif defined(PLATFORM_NULL)
    #define _GLFW_PLATFORM GLFW_PLATFORM_NULL
#else
    #define _GLFW_PLATFORM GLFW_ANY_PLATFORM
#endif // unix || __unix || __unix__
namespace
{
    bool init() {
        if(!glfwPlatformSupported(_GLFW_PLATFORM))
        {
            std::cout << "Unsuported platform\n";
            return false;
        }
        glfwInitHint(GLFW_PLATFORM, _GLFW_PLATFORM);
        return glfwInit();
    }

    void terminate()
    {
        glfwTerminate();
    }
} // namespace

GlfWWrapper::GlfWWrapper(WindowSettings window_settings) : _window_settings{std::move(window_settings)}
{
    if(!init())
    {
        std::cout << "Failed to init Glfw\n";
        return;
    }
    std::cout << "Init Glfw successfully\n";
    _is_init.store(true);
    _window = glfwCreateWindow(
        _window_settings.mWidth, 
        _window_settings.mHeight, 
        _window_settings.mTitle.c_str(), 
        glfwGetPrimaryMonitor(), 
        NULL);
}

GlfWWrapper::~GlfWWrapper()
{
    glfwDestroyWindow(_window);
    terminate();
}
