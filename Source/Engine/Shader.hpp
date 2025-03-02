#pragma once

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <iostream>

std::string readFile(const std::string &filename);

namespace engine
{
    class Shader
    {

    private:
        void compileErrors(unsigned int shader, const char *type);

    public:
        GLuint ID;

        Shader(const std::string &vertexFile, const std::string &fragmentFile);
        ~Shader();

        void Activate();
    };
}