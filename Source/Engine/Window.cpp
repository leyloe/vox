
#include <Engine/Window.hpp>
#include "Window.hpp"

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

namespace engine
{
    Window::Window(int w, int h, std::string name) : width{w}, height{h}, windowName{name}
    {
        initWindow(w, h, name);
    }

    Window::~Window()
    {
        glfwDestroyWindow(_window);

        glfwTerminate();
    }

    bool Window::shouldClose()
    {
        return glfwWindowShouldClose(_window);
    }

    void Window::setFramebufferSizeCallback()
    {
        glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);
    }

    void Window::swapBuffers()
    {
        return glfwSwapBuffers(_window);
    }

    void Window::initWindow(int w, int h, std::string name)
    {
        glfwInit();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        _window = glfwCreateWindow(w, h, name.c_str(), nullptr, nullptr);

        if (!_window)
            throw std::runtime_error("Failed to create GLFW window");

        glfwMakeContextCurrent(_window);
    }

}
