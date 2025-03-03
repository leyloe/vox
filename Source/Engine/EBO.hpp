#pragma once

#include <glad/glad.h>

namespace engine
{
    class EBO
    {
    public:
        EBO(GLuint *indices, GLsizeiptr size);
        ~EBO();

        GLuint ID;

        void bind();
        void unbind();
    };

}