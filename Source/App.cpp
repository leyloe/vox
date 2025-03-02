#include <App.hpp>

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

        engine::Shader shaderProgram{"../Shaders/Default.vert", "../Shaders/Default.frag"};

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

        int widthImg, heightImg, numColCh;
        stbi_set_flip_vertically_on_load(true);
        unsigned char *bytes = stbi_load("../Textures/grass_side.png", &widthImg, &heightImg, &numColCh, 0);

        GLuint texture;
        glGenTextures(1, &texture);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthImg, heightImg, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(bytes);
        glBindTexture(GL_TEXTURE_2D, 0);

        GLuint tex0Uni = glGetUniformLocation(shaderProgram.ID, "tex0");
        shaderProgram.activate();
        glUniform1i(tex0Uni, 0);

        while (!window.shouldClose())
        {
            window.processInputEsc();

            glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            shaderProgram.activate();

            glUniform1f(uniID, 0.5f);

            glBindTexture(GL_TEXTURE_2D, texture);

            VAO.bind();

            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

            window.swapBuffers();
            glfwPollEvents();
        }

        glDeleteTextures(1, &texture);
    }

}