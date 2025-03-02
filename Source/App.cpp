#include <App.hpp>

namespace engine
{
    void App::run()
    {
        float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f};

        unsigned int indices[] = {
            0, 1, 3,
            1, 2, 3};

        engine::Shader shaderProgram{"Shaders/Default.vert", "Shaders/Default.frag"};

        engine::VAO VAO;
        VAO.bind();

        engine::VBO VBO{vertices, sizeof(vertices)};
        engine::EBO EBO{indices, sizeof(indices)};

        VAO.linkVBO(VBO, 0);

        VAO.unbind();
        VBO.unbind();
        EBO.unbind();

        while (!window.shouldClose())
        {
            window.processInputEsc();

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            shaderProgram.Activate();
            VAO.bind();
            glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

            window.swapBuffers();
            glfwPollEvents();
        }
    }

}