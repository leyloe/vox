#pragma once

#include <glad/glad.h>
#include <Engine/Shader.hpp>
#include <stb/stb_image.h>

namespace engine
{
    class Texture
    {
    public:
        GLuint ID;
        GLenum type;

        Texture(const char *image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);
        ~Texture();

        void texUnit(Shader &shader, const char *uniform, GLuint unit);
        void bind();
        void unbind();
    };

}