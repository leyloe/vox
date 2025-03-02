#include <App.hpp>

namespace engine
{
    void App::run()
    {
        preRender();

        while (!window.shouldClose())
        {
            window.processInputEsc();

            renderLoop();

            window.swapBuffers();
            glfwPollEvents();
        }
    }

    void App::preRender()
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    }

    void App::renderLoop()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }
}