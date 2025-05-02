#ifndef WINDOW__HH
#define WINDOW__HH

#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

class Window{
private:
    GLFWwindow* window;
    bool fullscreen;

    int8_t init();
    void execute();
    int8_t terminate();
    
    static void glErrorCallback(int error, const char* const description);
public:
    Window(bool fullscreen);
    ~Window();

    void run();
};

#endif