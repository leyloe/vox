#pragma once

#include <glad/glad.h>
#include <Engine/VBO.hpp>

namespace engine
{
    class VAO
    {
    private:
        GLuint ID;

    public:
        VAO();
        ~VAO();

        void linkVBO(VBO &VBO, GLuint layout);

        void bind();
        void unbind();
    };

}