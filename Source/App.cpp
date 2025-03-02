#include <App.hpp>

namespace engine
{
    void App::run()
    {
        float vertices[] = {
            -0.5f, -0.5f, 0.0f, // bottom left
            0.5f, -0.5f, 0.0f,  // bottom right
            0.5f, 0.5f, 0.0f,   // top right
            -0.5f, 0.5f, 0.0f   // top left
        };

        unsigned int indices[] = {
            0, 1, 2, // first triangle
            2, 3, 0  // second triangle
        };

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
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

            window.swapBuffers();
            glfwPollEvents();
        }
    }

}