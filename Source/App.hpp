#pragma once

#include <Engine/GraphicsContext.hpp>
#include <Engine/Window.hpp>
#include <Engine/VAO.hpp>
#include <Engine/EBO.hpp>
#include <Engine/Shader.hpp>

namespace engine
{
    class App
    {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 800;

        void run();

    private:
        Window window{WIDTH, HEIGHT, "window"};
        GraphicsContext context{window};
    };

}