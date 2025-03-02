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

        void LinkAttrib(VBO &VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void *offset);

        void bind();
        void unbind();
    };

}