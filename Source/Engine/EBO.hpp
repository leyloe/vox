#pragma once

#include <glad/glad.h>

namespace engine
{
    class EBO
    {
    private:
        GLuint ID;

    public:
        EBO(GLfloat *vertices, GLsizeiptr size);
        ~EBO();

        void bind();
        void unbind();
    };

}