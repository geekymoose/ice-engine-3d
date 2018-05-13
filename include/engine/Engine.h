#pragma once

#include "Game.h"
#include "WindowGLFW.h"
#include "TimeManager.h"
#include "RenderEngine.h"
#include "InputManager.h"
#include "MeshManager.h"

#include "utils/log.h"

namespace ice {


/**
 * The beautiful ice engine.
 *
 * \date    May 2018
 * \author  Constantin
 */
class Engine {

    // -------------------------------------------------------------------------
    // Data / Attributes
    // -------------------------------------------------------------------------

    private:
        bool            _isInit     = false;
        bool            _isRunning  = false;

    private:
        Game&           _game;
        TimeManager&    _timeManager;
        WindowGLFW&     _window;
        InputManager&   _inputManager;
        MeshManager&    _meshManager;


    // -------------------------------------------------------------------------
    // Core methods
    // -------------------------------------------------------------------------

    public:

        /**
         * Create new Engine for a game.
         */
        Engine(Game& game);

        /**
         * Startup ice engine.
         * Must be called first.
         */
        void startup();

        /**
         * Shutdown ice engine.
         * To call at the end.
         * Release all used resources.
         */
        void shutdown();

        /**
         * Run the engine.
         * This actually start the main loop and call update and fixedUpdate
         * of the game.
         */
        void run();
};


} // End namespace


