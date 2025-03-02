#include "VBO.hpp"

namespace engine
{
    VBO::VBO(GLfloat *vertices, GLsizeiptr size)
    {
        glGenBuffers(1, &ID);
        glBindBuffer(GL_ARRAY_BUFFER, ID);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }

    VBO::~VBO()
    {
        glDeleteBuffers(1, &ID);
    }

    void VBO::bind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, ID);
    }

    void VBO::unbind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}
