#include <glad/glad.h>
#include <App.hpp>

namespace engine
{
    void App::run()
    {
        if (!gladLoadGL())
        {
            throw std::runtime_error("Failed to initialize GLAD");
        }

        while (!window.shouldClose())
        {
            glfwPollEvents();
        }
    }
}