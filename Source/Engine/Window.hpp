#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <stdexcept>

namespace engine
{
    class Window
    {
    private:
        std::string windowName;
        GLFWwindow *_window;

        void initWindow(int w, int h, std::string name);

    public:
        const int width;
        const int height;

        Window(int w, int h, std::string name);
        ~Window();

        bool shouldClose();
        void setFramebufferSizeCallback();
        void swapBuffers();
    };
}