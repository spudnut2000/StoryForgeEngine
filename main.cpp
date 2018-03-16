#include "engine/engine.h"

#include <GLFW/glfw3.h>

int main(void)
{
    std::cout << "StoryForge Engine" << std::endl;

    Engine engine;

    engine.InitEngine("Storyforge", 1024, 768);

    while (true)
    {
        engine.Update();
        engine.Render();
    }

    return 0;
}
