
#include <Engine/Window.hpp>

namespace engine
{
    Window::Window(int w, int h, std::string name) : width{w}, height{h}, windowName{name}
    {
        initWindow(w, h, name);
    }

    Window::~Window()
    {
        glfwDestroyWindow(window);

        glfwTerminate();
    }

    bool Window::shouldClose()
    {
        return glfwWindowShouldClose(window);
    }

    void framebuffer_size_callback(GLFWwindow *window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    void Window::SetFramebufferSizeCallback()
    {
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    }

    void Window::initWindow(int w, int h, std::string name)
    {
        glfwInit();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(w, h, name.c_str(), nullptr, nullptr);

        if (!window)
        {
            throw std::runtime_error("Failed to create GLFW window");
        }

        glfwMakeContextCurrent(window);
    }
}
