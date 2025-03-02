#include "VAO.hpp"

namespace engine
{
    VAO::VAO()
    {
        glGenVertexArrays(1, &ID);
    }

    VAO::~VAO()
    {
        glDeleteVertexArrays(1, &ID);
    }

    void VAO::LinkAttrib(VBO &VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void *offset)
    {
        VBO.bind();
        glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
        glEnableVertexAttribArray(layout);
        VBO.unbind();
    }

    void VAO::bind()
    {
        glBindVertexArray(ID);
    }

    void VAO::unbind()
    {
        glBindVertexArray(0);
    }
}
