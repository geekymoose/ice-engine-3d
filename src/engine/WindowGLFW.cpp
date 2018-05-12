#include "engine/WindowGLFW.h"

#include "utils/log.h"
#include "utils/constants.h"

namespace ice {


bool WindowGLFW::startup() {
    LOG << "Startup GLFW Window\n";

    // Init GLFW
    LOG << "Initialize GLFW\n";
    if(!glfwInit()) {
        LOG << "Unable to start glfw!\n";
        exit(EXIT_FAILURE);
    }
    LOG << "GLFW successfully started\n";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create the window
    _window = glfwCreateWindow(ICE_WINDOW_WIDTH,
                         ICE_WINDOW_HEIGHT,
                         ICE_WINDOW_TITLE,
                         NULL, NULL);
    if(_window == NULL) {
        LOG << "Unable to create the glfw Window...\n";
        return false;
    }
    glfwMakeContextCurrent(_window);
    glfwSetFramebufferSizeCallback(_window, resizeWindowCallback);

    LOG << "Initialize GLAD\n";
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        LOG << "Unable to start GLAD!\n";
        exit(EXIT_FAILURE);
    }
    LOG << "GLAD successfully started\n";

    return true;
}

bool WindowGLFW::shutdown() {
    LOG << "Shutdown GLFW Window\n";
    glfwDestroyWindow(_window);
    glfwTerminate();
    return true;
}

void WindowGLFW::close() {
    glfwSetWindowShouldClose(_window, true);
}

bool WindowGLFW::isClosed() {
    return glfwWindowShouldClose(_window);
}

void WindowGLFW::resizeWindowCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

} // End namespace
