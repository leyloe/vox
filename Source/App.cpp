#include <App.hpp>

namespace engine
{
    void App::run()
    {
        while (!window.shouldClose())
        {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            window.swapBuffers();
            glfwPollEvents();
        }
    }
}