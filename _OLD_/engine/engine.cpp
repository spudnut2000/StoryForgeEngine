#include "engine.h"

int Engine::SCREEN_WIDTH = 1024;
int Engine::SCREEN_HEIGHT = 768;
GLFWwindow* Engine::window = NULL;

Engine::Engine(){}

Engine::~Engine(){}

bool Engine::InitEngine(const char* title, int s_width, int s_height)
{
    //Check if GLFW Initialized
    if(!glfwInit())
    {
        std::cout << "Error Initializing GLFW" << std::endl;
        return false;
    }

    //Create window
    window = glfwCreateWindow(s_width, s_height, title, NULL, NULL);

    //Check if window exists
    if (window == NULL)
    {
        std::cout << "Something went wrong creating the window." << std::endl;
        return false;
    }

    //GLFW Setup
    glfwMakeContextCurrent(window);
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glfwSwapInterval(1);

    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    int xPos = (mode->width - SCREEN_WIDTH) / 2;
    int yPos = (mode->height - SCREEN_HEIGHT) / 2;
    glfwSetWindowPos(window, xPos, yPos);

    //GL Setup
    //Viewport
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -10, 10);
    glDepthRange(-10, 10);
    glMatrixMode(GL_MODELVIEW);

    //Alpha blending
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    return true;
}

//Update
void Engine::Update()
{
    glfwPollEvents();
}

//Render
void Engine::Render()

{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glfwSwapBuffers(window);
}
