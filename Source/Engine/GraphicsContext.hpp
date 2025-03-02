#pragma once

#include <glad/glad.h>
#include <Engine/Window.hpp>
#include <stdexcept>

namespace engine
{
    class GraphicsContext
    {
    private:
        void initGraphicsContext(Window &window);

    public:
        GraphicsContext(Window &window);
    };

}