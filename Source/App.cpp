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

        engine::VAO VAO;
        VAO.bind();

        engine::VBO VBO{vertices, sizeof(vertices)};
        VBO.bind();

        VAO.linkVBO(VBO, 0);

        VAO.unbind();
        VBO.unbind();

        while (!window.shouldClose())
        {
            window.processInputEsc();

            glClear(GL_COLOR_BUFFER_BIT);

            shaderProgram.Activate();
            VAO.bind();
            glDrawArrays(GL_TRIANGLES, 0, 3);

            window.swapBuffers();
            glfwPollEvents();
        }
    }

}