#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <functional>

namespace vpg {
    
  class Window
  {
  private:
    GLFWwindow* window;

    typedef std::function< void(GLFWwindow*, int, int, int, int) > key_handler_fn;
    typedef std::function< void(void) > resize_handler_fn;

  public:
    Window(int width, int height, bool fullscreen, resize_handler_fn resizeCallback);
    ~Window();

    bool shouldClose();
    void pollEvents();
    void createSurface(VkInstance instance, VkSurfaceKHR* surface);

    void getWindowSize(int* width, int* height);
  };

}