#pragma once

#include <GLFW/glfw3.h>
#include <string>
#include <stdexcept>

namespace engine
{
    class Window
    {
    private:
        GLFWwindow *window;
        std::string windowName;

        void initWindow(int w, int h, std::string name);

    public:
        const int width;
        const int height;

        Window(int w, int h, std::string name);
        ~Window();

        bool shouldClose();
    };
}