#include <glad/glad.h>
#include <App.hpp>

namespace engine
{
    void App::run()
    {
        while (!window.shouldClose())
        {
            glfwPollEvents();
        }
    }
}