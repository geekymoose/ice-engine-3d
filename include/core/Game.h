#pragma once

#include "utils/log.h"

namespace ice {


/**
 * The main Game class.
 */
class Game {
    // -------------------------------------------------------------------------
    // Data
    // -------------------------------------------------------------------------


    public:

        Game() {
            LOG << "Create game\n";
        }

        ~Game() {
        }


        /**
         * Main game loop
         */
        void run() {
        }
};


} // End namespace
