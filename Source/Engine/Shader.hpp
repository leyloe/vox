#pragma once

#include <glad/glad.h>
#include <string>
#include <fstream>

std::string readFile(const std::string &filename);

namespace engine
{
    class Shader
    {
    private:
        GLuint ID;

    public:
        Shader(const std::string &vertexFile, const std::string &fragmentFile);
        ~Shader();

        void Activate();
    };
}