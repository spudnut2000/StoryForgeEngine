#ifndef STORYF_ENGINE
#define STORYF_ENGINE

#include "GLFW/glfw3.h"
#include <iostream>

class Engine
{

    public:
        static int SCREEN_WIDTH;
        static int SCREEN_HEIGHT;

        Engine();
        ~Engine();

        bool InitEngine();

        void Update();
        void Render();


    private:
        static GLFWwindow* window;

};


#endif // STORYF_ENGINE
