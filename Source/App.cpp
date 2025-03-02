#include <App.hpp>
#include <glm/glm.hpp>

namespace engine
{
    void App::run()
    {
        GLfloat vertices[] =
            {
                //               COORDINATES                  /     COLORS           //
                -0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f, 0.8f, 0.3f, 0.02f,  // Lower left corner
                0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f, 0.8f, 0.3f, 0.02f,   // Lower right corner
                0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, 1.0f, 0.6f, 0.32f,    // Upper corner
                -0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f, 0.9f, 0.45f, 0.17f, // Inner left
                0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f, 0.9f, 0.45f, 0.17f,  // Inner right
                0.0f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f, 0.8f, 0.3f, 0.02f    // Inner down
            };

        // Indices for vertices order
        GLuint indices[] =
            {
                0, 3, 5, // Lower left triangle
                3, 2, 4, // Lower right triangle
                5, 4, 1  // Upper triangle
            };

        engine::Shader shaderProgram{"Shaders/Default.vert", "Shaders/Default.frag"};

        engine::VAO VAO;
        VAO.bind();

        engine::VBO VBO{vertices, sizeof(vertices)};
        engine::EBO EBO{indices, sizeof(indices)};

        VAO.LinkAttrib(VBO, 0, 3, GL_FLOAT, 6 * sizeof(float), (void *)0);
        VAO.LinkAttrib(VBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void *)(3 * sizeof(float)));

        VAO.unbind();
        VBO.unbind();
        EBO.unbind();

        GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

        while (!window.shouldClose())
        {
            window.processInputEsc();

            glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            shaderProgram.Activate();
            glUniform1f(uniID, 0.5f);
            VAO.bind();
            glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

            window.swapBuffers();
            glfwPollEvents();
        }
    }

}