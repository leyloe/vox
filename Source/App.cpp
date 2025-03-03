#include <App.hpp>

namespace engine
{
    void App::run()
    {
        GLfloat vertices[] =
            {//     COORDINATES     /        COLORS      /   TexCoord  //
             -0.5f, 0.0f, 0.5f, 0.83f, 0.70f, 0.44f, 0.0f, 0.0f,
             -0.5f, 0.0f, -0.5f, 0.83f, 0.70f, 0.44f, 5.0f, 0.0f,
             0.5f, 0.0f, -0.5f, 0.83f, 0.70f, 0.44f, 0.0f, 0.0f,
             0.5f, 0.0f, 0.5f, 0.83f, 0.70f, 0.44f, 5.0f, 0.0f,
             0.0f, 0.8f, 0.0f, 0.92f, 0.86f, 0.76f, 2.5f, 5.0f};

        // Indices for vertices order
        GLuint indices[] =
            {
                0, 1, 2,
                0, 2, 3,
                0, 1, 4,
                1, 2, 4,
                2, 3, 4,
                3, 0, 4};

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

        Texture texture{"../Textures/sandstone_normal.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE};
        texture.texUnit(shaderProgram, "tex0", 0);

        glEnable(GL_DEPTH_TEST);

        engine::Camera camera{WIDTH, HEIGHT, glm::vec3(0.0f, 0.0f, 2.0f)};

        GLFWwindow *_window = window.window;

        while (!window.shouldClose())
        {
            window.processInputEsc();

            glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            shaderProgram.activate();

            camera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");

            texture.bind();

            VAO.bind();

            glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);

            window.swapBuffers();
            glfwPollEvents();
        }
    }

}