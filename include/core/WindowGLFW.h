#pragma once

#include "utils/log.h"
#include "utils/constants.h"

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
            _window = glfwCreateWindow(ICE_WINDOW_WIDTH,
                                 ICE_WINDOW_HEIGHT,
                                 ICE_WINDOW_TITLE,
                                 NULL, NULL);
            if(_window == NULL) {
                LOG << "Unable to create the glfw Window...\n";
                return false;
            }
            glfwMakeContextCurrent(_window);

            return true;
        }

        bool shutdown() {
            LOG << "Shutdown GLFW Window\n";
            glfwDestroyWindow(_window);
            return true;
        }
};


} // end namespace
