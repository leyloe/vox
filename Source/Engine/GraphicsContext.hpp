#pragma once

#include <glad/glad.h>
#include <stdexcept>

namespace engine
{
    class GraphicsContext
    {
    private:
        void initGraphicsContext(int w, int h);

    public:
        GraphicsContext(int w, int h);
    };

}