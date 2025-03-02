#include "Shader.hpp"

std::string readFile(const std::string &filepath)
{
    std::ifstream file{filepath, std::ios::binary};

    if (!file.is_open())
        throw std::runtime_error("failed to open file: " + filepath);

    std::string contents;

    file.seekg(0, std::ios::end);
    contents.resize(file.tellg());

    if (!contents.size())
        throw std::runtime_error(filepath + " is empty");

    file.seekg(0, std::ios::beg);
    file.read(&contents[0], contents.size());

    file.close();
    return contents;
}

namespace engine
{
    void Shader::compileErrors(unsigned int shader, const char *type)
    {
        GLint hasCompiled;
        char infoLog[1024];
        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
            if (hasCompiled == GL_FALSE)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "SHADER_COMPILATION_ERROR for:" << type << "\n"
                          << infoLog << std::endl;
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &hasCompiled);
            if (hasCompiled == GL_FALSE)
            {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "SHADER_LINKING_ERROR for:" << type << "\n"
                          << infoLog << std::endl;
            }
        }
    }

    Shader::Shader(const std::string &vertexFile, const std::string &fragmentFile)
    {
        std::string vertexCode = readFile(vertexFile);
        std::string fragmentCode = readFile(fragmentFile);

        const char *vertexSource = vertexCode.c_str();
        const char *fragmentSource = fragmentCode.c_str();

        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexSource, NULL);
        glCompileShader(vertexShader);
        compileErrors(vertexShader, "VERTEX");

        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
        glCompileShader(fragmentShader);
        compileErrors(fragmentShader, "FRAGMENT");

        ID = glCreateProgram();
        glAttachShader(ID, vertexShader);
        glAttachShader(ID, fragmentShader);
        glLinkProgram(ID);
        compileErrors(ID, "PROGRAM");

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    Shader::~Shader()
    {
        glDeleteProgram(ID);
    }

    void Shader::Activate()
    {
        glUseProgram(ID);
    }
}