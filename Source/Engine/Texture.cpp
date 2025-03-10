#include <Engine/Texture.hpp>

namespace engine
{

    void Texture::texUnit(Shader &shader, const char *uniform, GLuint unit)
    {
        GLuint texUni = glGetUniformLocation(shader.ID, uniform);
        shader.activate();
        glUniform1i(texUni, unit);
    }

    void Texture::bind()
    {
        glActiveTexture(GL_TEXTURE0 + unit);
        glBindTexture(type, ID);
    }

    void Texture::unbind()
    {
        glBindTexture(type, 0);
    }

    Texture::~Texture()
    {
        glDeleteTextures(1, &ID);
    }
    Texture::Texture(const char *image, GLenum texType, GLuint slot, GLenum format, GLenum pixelType)
    {
        type = texType;

        int widthImg, heightImg, numColCh;
        stbi_set_flip_vertically_on_load(true);
        unsigned char *bytes = stbi_load(image, &widthImg, &heightImg, &numColCh, 0);

        glGenTextures(1, &ID);
        glActiveTexture(GL_TEXTURE0 + slot);
        unit = slot;
        glBindTexture(texType, ID);

        glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
        glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

        /* if you use GL_CLAMP_TO_BORDER */
        // float flatColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
        // glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, flatColor);

        glTexImage2D(texType, 0, GL_RGBA, widthImg, heightImg, 0, format, pixelType, bytes);
        glGenerateMipmap(texType);

        stbi_image_free(bytes);

        glBindTexture(texType, 0);
    }
}