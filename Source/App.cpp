#include <App.hpp>

namespace engine
{
    void App::run()
    {
        float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f};

        engine::Shader shaderProgram{"Shaders/Default.vert", "Shaders/Default.frag"};

        while (!window.shouldClose())
        {
            window.processInputEsc();

            window.swapBuffers();
            glfwPollEvents();
        }
    }

}