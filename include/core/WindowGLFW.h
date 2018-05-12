#pragma once

#include "utils/Singleton.h"

#include "glad/glad.h" // To place before <GLFW/glfw3.h>
#include <GLFW/glfw3.h>

namespace ice {


/**
 * The main window where to draw.
 * There is only one Window (Accessible from singleton).
 *
 * \date    May 2018
 * \author  Constantin
 */
class WindowGLFW : private Singleton<WindowGLFW> {
    private:
        WindowGLFW() = default; // Singleton
        friend Singleton<WindowGLFW>;

    public:
        // For singleton use
        using Singleton<WindowGLFW>::getInstance;

    public:
        GLFWwindow* _window;

    // -------------------------------------------------------------------------
    // Initialization
    // -------------------------------------------------------------------------

    public:

        /**
         * Startup Window.
         * Must be the first to be called in the engine (Since also initialize GLFW).
         */
        bool startup();

        /**
         * End Window.
         * Last to call (Since also stop GLFW).
         */
        bool shutdown();


    // -------------------------------------------------------------------------
    // Internal use functions
    // -------------------------------------------------------------------------

    private:
        static void resizeWindowCallback(GLFWwindow* window, int width, int height);
};


} // end namespace


