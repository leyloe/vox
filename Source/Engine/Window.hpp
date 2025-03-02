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
        const int width;
        const int height;

        void initWindow(int w, int h, std::string name);

    public:
        Window(int w, int h, std::string name);
        ~Window();

        bool shouldClose();
    };
}