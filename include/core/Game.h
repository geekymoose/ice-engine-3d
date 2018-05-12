#pragma once

#include "core/WindowGLFW.h"
#include "utils/log.h"
#include "utils/constants.h"

namespace ice {


/**
 * The main Game class.
 */
class Game {

    // -------------------------------------------------------------------------
    // Initialization
    // -------------------------------------------------------------------------

    public:

        void startup() {
            LOG << "Startup game\n";
            ice::WindowGLFW w;
            w.startup();
        }

        void shutdown() {
            LOG << "Shutdown game\n";
            // Shutdown all subsystems
        }

        /**
         * Main game loop
         * TODO
         */
        void run() {
        }
};


} // End namespace
