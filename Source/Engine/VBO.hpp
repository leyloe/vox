#include <glad/glad.h>

namespace engine
{
    class VBO
    {
    private:
        GLuint ID;

    public:
        VBO(GLfloat *vertices, GLsizeiptr size);
        ~VBO();

        void bind();
        void unbind();
    };

}