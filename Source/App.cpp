#include <App.hpp>

namespace engine
{
    void App::run()
    {
        while (!window.shouldClose())
        {
            window.processInputEsc();

            renderLoop();

            window.swapBuffers();
            glfwPollEvents();
        }
    }

    void App::renderLoop()
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}