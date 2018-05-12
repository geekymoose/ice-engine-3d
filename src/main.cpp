#include "glad/glad.h" // Must be at the beginning

#include "core/Game.h"
#include "core/WindowGLFW.h"
#include "utils/log.h"
#include "utils/constants.h"

#include "glm/glm.hpp"
#include <GLFW/glfw3.h>
#include <iostream>


/**
 * Startup GLFW (To call once at the beginning)
 */
void initGLFW() {
    LOG << "Initialize GLFW\n";

    if(!glfwInit()) {
        LOG << "Unable to start glfw!\n";
        exit(EXIT_FAILURE);
    }
    LOG << "GLFW successfully started\n";

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    LOG << "Initialize GLAD\n";
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        LOG << "Unable to start GLAD!\n";
        exit(EXIT_FAILURE);
    }
    LOG << "GLAD successfully started\n";
}

/**
 * Stop GLFW (To call once at the end)
 */
void stopGLFW() {
    LOG << "Stop GLFW\n";
    glfwTerminate();
}

int main(int argc, char** argv) {
    LOG << "--- Start Main ---\n";

    initGLFW();

    ice::WindowGLFW w;
    w.startup();

    stopGLFW();

    LOG << "--- Stop Main ---\n";
    return 0;
}
