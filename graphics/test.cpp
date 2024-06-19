//
// Created by ditrorickdev on 17/05/24.
//

// #include "glfw_wrapper.h"
#include "logger/logger.h"  

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

#include <vector>

struct VulkanWrapper
{
    public:
    void run() {
        _initWindow();
        _initVulkan();
        _loop();
        _clean_up();
    }

    private:
        void _initWindow()
        {
            //TODO(): replace with wrapper 
            /// we need to tell it to not create an OpenGL context
            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
            /// handling resized windows takes special care that we'll look into later
            glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

            if(!glfwInit())
            {
                throw std::runtime_error("failed to init glfw!");
            }

            _window = glfwCreateWindow(800, 600, "Vulkan", nullptr, nullptr);
        } 
        void _initVulkan() 
        {
            _createInstance();
        }
        void _loop()
        {
            while (!glfwWindowShouldClose(_window)) {
                glfwPollEvents();
            }
        }
        void _clean_up()
        {
            glfwDestroyWindow(_window);
            glfwTerminate();
        }

        void _createInstance()  
        {
            if (enableValidationLayers && !_checkValidationLayerSupport()) {
                throw std::runtime_error("validation layers requested, but not available!");
            }

            /// provide some useful information to the driver in order to optimize our specific application
            VkApplicationInfo appInfo{};
            appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
            appInfo.pApplicationName = "Hello Triangle";
            appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
            appInfo.pEngineName = "No Engine";
            appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
            appInfo.apiVersion = VK_API_VERSION_1_0;

            /// Tells the Vulkan driver which global extensions and validation layers we want to use.
            VkInstanceCreateInfo createInfo{};
            createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
            createInfo.pApplicationInfo = &appInfo;
            
            if (enableValidationLayers) {
                createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
                createInfo.ppEnabledLayerNames = validationLayers.data();
            }
            else {
                createInfo.enabledLayerCount = 0;
            }

            uint32_t glfwExtensionCount = 0;
            const char** glfwExtensions;

            glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

            createInfo.enabledExtensionCount = glfwExtensionCount;
            createInfo.ppEnabledExtensionNames = glfwExtensions;

            createInfo.enabledLayerCount = 0;

            if (vkCreateInstance(&createInfo, nullptr, &_vk_instance) != VK_SUCCESS) {
                throw std::runtime_error("failed to create instance!");
            }
        }

        bool _checkValidationLayerSupport() {
            uint32_t layerCount;
            vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

            std::vector<VkLayerProperties> availableLayers(layerCount);
            vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

            bool layerFound {false};
            for (auto const layerName : validationLayers) {

                for (const auto& layerProperties : availableLayers) {
                    if (std::string(layerName) == std::string(layerProperties.layerName)) 
                    {
                        layerFound = true;
                        break;
                    }
                }
            }
            return layerFound;
        }

        VkInstance _vk_instance;
        GLFWwindow* _window{};
        std::vector<const char*> const validationLayers = {
            "VK_LAYER_KHRONOS_validation"
        };
#ifdef NDEBUG
        const bool enableValidationLayers = false;
#else
        const bool enableValidationLayers = true;
#endif

};

int main()
{
    VulkanWrapper vulkan;
    LOG_DEBUG("Test debug log")
    try {
        vulkan.run();
    } catch (const std::exception& e) {
        LOG_ERROR(e.what());
        return EXIT_FAILURE;
    }
    LOG_INFO("Successfully ran vulkan")
    return EXIT_SUCCESS;
}