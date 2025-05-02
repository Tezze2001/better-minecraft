#include <window.hh>
#include <debug.hh>
#include <cstddef>
#include <const.hh>
#include <shader_prog.hh>

Window::Window(bool fullscreen) {
    this->fullscreen = fullscreen;
}

void Window::glErrorCallback(int error, const char* const description) {
    Debug::error(description);
}

int8_t Window::init(){
    if (!glfwInit()) {
        Debug::error("Impossible to initiate the GLFW library.");
        return ERROR_CODE;
    }   
    
    glfwSetErrorCallback(glErrorCallback);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if (this->fullscreen){
        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);
        this->window = glfwCreateWindow(mode->width, mode->height, "Minecraft copy", glfwGetPrimaryMonitor(), nullptr);
    } else {
        this->window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "Minecraft copy", nullptr, nullptr);
    }

    if (!window) {
        Debug::error("Window or OpenGL context creation failed.");

        glfwTerminate();

        return ERROR_CODE;
    }

    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        Debug::log("premuto");
    });

    glfwMakeContextCurrent(window);

    if (!gladLoadGL(glfwGetProcAddress)) {
        Debug::error("Failed to initialize GLAD");
        exit(EXIT_FAILURE);
    }
     
}

void Window::execute(){
    Debug::log((char*) glGetString(GL_VERSION));

    float vertices[] = {
            // Triangle coordinates (x, y, z)
            0.0f,  0.5f, 0.0f,  // top
        -0.5f, -0.5f, 0.0f,  // bottom left
            0.5f, -0.5f, 0.0f   // bottom right
    };
    
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    // Bind VAO
    glBindVertexArray(VAO);
    
    // Bind VBO and copy data
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    // Set vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    // Unbind (optional)
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
    ShaderProg shaders("./shaders/default.vert", "", "", "", "./shaders/default.frag"); 
        
    
    while (!glfwWindowShouldClose(this->window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        shaders.useProgram();    

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);


        glfwSwapBuffers(window);
        glfwPollEvents();

        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    }
}

int8_t Window::terminate(){
    if (!window) {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    return SUCCESS_CODE;    
}

void Window::run(){
    this->init();
    this->execute();
}

Window::~Window(){
    terminate();
}