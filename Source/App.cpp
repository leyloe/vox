#include <App.hpp>

#include <Engine/Shader.hpp>

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
        engine::Shader shader{"Shaders/Default.vert", "Shaders/Default.frag"};

        float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f};
    }

    void App::renderLoop()
    {
    }
}