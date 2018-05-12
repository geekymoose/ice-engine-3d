#pragma once

#include "utils/log.h"
#include "utils/constants.h"

#include "glad/glad.h" // To place before <GLFW/glfw3.h>
#include <GLFW/glfw3.h>

namespace ice {


/**
 * The main window where to draw.
 * There is only one Window (Accessible from singleton)
 *
 * \date    May 2018
 * \author  Constantin
 */
class WindowGLFW {
    // -------------------------------------------------------------------------
    // Data
    // -------------------------------------------------------------------------
    public:
        GLFWwindow* _window;

    //private:
    public:
        WindowGLFW() = default; // Singleton


    // -------------------------------------------------------------------------
    // Initialization
    // -------------------------------------------------------------------------

    public:

        bool startup() {
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

            LOG << "Initialize GLAD\n";
            if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
                LOG << "Unable to start GLAD!\n";
                exit(EXIT_FAILURE);
            }
            LOG << "GLAD successfully started\n";

            return true;
        }

        bool shutdown() {
            LOG << "Shutdown GLFW Window\n";
            glfwDestroyWindow(_window);
            glfwTerminate();
            return true;
        }
};


} // end namespace
