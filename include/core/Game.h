#pragma once

#include "utils/Singleton.h"

namespace ice {


/**
 * The main Game class.
 * Currently mix the engine, main loop and game data.
 * (GameJam stuff buddies)
 *
 *
 * \date    May 2018
 * \author  Constantin
 */
class Game : private Singleton<Game> {
    private:
        Game() = default; // Singleton
        ~Game() = default;
        friend Singleton<Game>;
    public:
        using Singleton<Game>::getInstance;

    private:
        bool _isRunning = false;


    // -------------------------------------------------------------------------
    // Core methods
    // -------------------------------------------------------------------------

    public:
        void run();
};


} // End namespace
