#include <Engine/GraphicsContext.hpp>

namespace engine
{
    void GraphicsContext::initGraphicsContext(int w, int h)
    {
        if (!gladLoadGL())
        {
            throw std::runtime_error("Failed to initialize GLAD");
        }

        glViewport(0, 0, w, h);
    }

    GraphicsContext::GraphicsContext(int w, int h)
    {
        initGraphicsContext(w, h);
    }
}
