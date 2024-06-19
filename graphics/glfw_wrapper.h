#ifndef GLFW_WRAPPER_H
#define GLFW_WRAPPER_H

#include <atomic>
#include <string>

struct GLFWwindow;

struct WindowSettings
{
    std::string mTitle{};
    std::uint16_t mWidth{}; 
    std::uint16_t mHeight{};
};

struct GlfWWrapper {
    GlfWWrapper(WindowSettings window_settings);
    ~GlfWWrapper();
    private:
        WindowSettings _window_settings{};
        GLFWwindow* _window{};
        std::atomic<bool> _is_init{false};
};

#endif //GLFW_WRAPPER_H
