#include <App.hpp>
#include <glm/glm.hpp>
#include <stb/stb_image.h>

namespace engine
{
    void App::run()
    {
        GLfloat vertices[] =
            {
                //     COORDINATES     /        COLORS      /   TexCoord  //
                -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // Lower left corner
                -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,  // Upper left corner
                0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,   // Upper right corner
                0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f   // Lower right corner
            };

        // Indices for vertices order
        GLuint indices[] =
            {
                0, 2, 1, // Upper triangle
                0, 3, 2  // Lower triangle
            };

        engine::Shader shaderProgram{"Shaders/Default.vert", "Shaders/Default.frag"};

        engine::VAO VAO;
        VAO.bind();

        engine::VBO VBO{vertices, sizeof(vertices)};
        engine::EBO EBO{indices, sizeof(indices)};

        VAO.LinkAttrib(VBO, 0, 3, GL_FLOAT, 8 * sizeof(float), (void *)0);
        VAO.LinkAttrib(VBO, 1, 3, GL_FLOAT, 8 * sizeof(float), (void *)(3 * sizeof(float)));
        VAO.LinkAttrib(VBO, 2, 2, GL_FLOAT, 8 * sizeof(float), (void *)(6 * sizeof(float)));

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
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

            window.swapBuffers();
            glfwPollEvents();
        }
    }

}