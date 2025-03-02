#pragma once

#include <Engine/GraphicsContext.hpp>
#include <Engine/Window.hpp>

namespace engine
{
    class App
    {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();

    private:
        Window window{WIDTH, HEIGHT, "window"};
        GraphicsContext context{window};

        void preRender();
        void renderLoop();
    };

}