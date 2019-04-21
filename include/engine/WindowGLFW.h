#pragma once

#include "utils/Singleton.h"

#include <glad/glad.h> // To place before <GLFW/glfw3.h>
#include <GLFW/glfw3.h>

namespace ice {


/**
 * The main window where to draw.
 * There is only one window (accessible from the singleton).
 *
 * \date    May 2018
 * \author  Constantin
 */
class WindowGLFW : private Singleton<WindowGLFW> {
    // For singleton use
    private:
        WindowGLFW() = default;
        friend Singleton<WindowGLFW>;
    public:
        using Singleton<WindowGLFW>::getInstance;

    public:
        // Yes! It's not the best way, but other (e.g., InputManager) access window.
        GLFWwindow* _window;


    // -------------------------------------------------------------------------
    // Initialization
    // -------------------------------------------------------------------------

    public:

        /**
         * Startups window.
         * Must be the very first to be called in the engine
         * (since it also initializes GLFW).
         *
         * \return True if successfully started up, otherwise, false.
         */
        bool startup();

        /**
         * Ends window.
         * Last to call (since it also stops GLFW).
         */
        void shutdown();

        /**
         * Updates the window buffers.
         * Usually to call at the end of the game loop.
         */
        void update();


    // -------------------------------------------------------------------------
    // Initialization
    // -------------------------------------------------------------------------

    public:

        /**
         * Closes the window.
         */
        void close();

        /**
         * Checks whether the window is closed.
         *
         * \return True if closed, otherwise, return false.
         */
        bool isClosed() const;

        /**
         * Clears the window content.
         * Usually to call before the update in the main game loop.
         */
        void clear();


    // -------------------------------------------------------------------------
    // Internal use functions
    // -------------------------------------------------------------------------

    private:
        static void resizeWindowCallback(GLFWwindow* window, int width, int height);
};


} // end namespace


