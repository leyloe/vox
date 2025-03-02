#include <Engine/GraphicsContext.hpp>

namespace engine
{
    void GraphicsContext::initGraphicsContext(Window &window)
    {
        if (!gladLoadGL())
        {
            throw std::runtime_error("Failed to initialize GLAD");
        }

        glViewport(0, 0, window.width, window.height);

        window.setFramebufferSizeCallback();
    }

    GraphicsContext::GraphicsContext(Window &window)
    {
        initGraphicsContext(window);
    }

}
