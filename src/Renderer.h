#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vector>

namespace vpg {
  class Renderer
  {
  public:
    Renderer(bool enableValidationLayers);
    ~Renderer();

    VkInstance& getInstance();

    bool checkValidationLayerSupport();

  protected:
    /// <summary> create the VkInstance </summary>
    void createInstance(bool enableValidationSupport);

    /// <summary> get a list of all vulkan extensions needed </summary>
    std::vector<const char*> getRequiredExtensions(bool enableValidationLayers);

    void setupDebugCallback();

  private:
    VkInstance instance;
    VkDebugReportCallbackEXT callback;

    const std::vector<const char*> validationLayers = {
      "VK_LAYER_LUNARG_standard_validation"
    };

    const std::vector<const char*> deviceExtensions = {
      VK_KHR_SWAPCHAIN_EXTENSION_NAME
    };
  };

  static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objType, uint64_t obj, size_t location, int32_t code, const char* layerPrefix, const char* msg, void* userData);
  static VkResult CreateDebugReportCallbackEXT(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback);
  void DestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator);
}