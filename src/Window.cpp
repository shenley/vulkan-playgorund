#include "Window.h"

#include <memory>
#include <stdexcept>

namespace vpg {

  void handle_key(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
      glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
  }

  static void onWindowResized(GLFWwindow* window, int width, int height) {
    if (width == 0 || height == 0) return;

    //HelloTriangleApplication* app = reinterpret_cast<HelloTriangleApplication*>(glfwGetWindowUserPointer(window));
    // app->recreateSwapChain();
  }

  Window::Window(int width, int height, bool fullscreen, resize_handler_fn resizeCallback) {
    GLFWmonitor* mon = nullptr;


    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    if (fullscreen) {
      mon = glfwGetPrimaryMonitor();
    }

    window = glfwCreateWindow(width, height, "Vulkan Playground!", mon, nullptr);

    //glfwSetWindowUserPointer(window, resizeCallback);
    //glfwSetWindowSizeCallback(window, onWindowResized);

    glfwSetKeyCallback(window, handle_key);
  }

  Window::~Window()
  {
    glfwDestroyWindow(window);
  }

  bool Window::shouldClose() {
    return glfwWindowShouldClose(window);
  }

  void Window::pollEvents() {
    glfwPollEvents();
  }

  void Window::createSurface(VkInstance& instance, VkSurfaceKHR* surface) {
    if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
      throw std::runtime_error("failed to create window surface!");
    }
  }

  void Window::getWindowSize(int* width, int* height) {
    glfwGetWindowSize(window, width, height);
  }


}



// TODO
// surface creation outside
