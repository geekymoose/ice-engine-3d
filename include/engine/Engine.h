#pragma once

#include "Game.h"
#include "WindowGLFW.h"
#include "TimeManager.h"
#include "RenderEngine.h"
#include "InputManager.h"
#include "MeshManager.h"
#include "TextureManager.h"
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
        TextureManager& _textureManager;


    // -------------------------------------------------------------------------
    // Core methods
    // -------------------------------------------------------------------------

    public:

        /**
         * Creates a new Engine for the given game.
         */
        Engine(Game& game);

        /**
         * Startups ice engine.
         * This must be called first.
         */
        void startup();

        /**
         * Shutdowns ice engine.
         * To call at the end.
         * Release all used resources.
         */
        void shutdown();

        /**
         * Runs the engine.
         * This actually starts the main loop and calls update and fixedUpdate
         * of the game.
         */
        void run();
};


} // End namespace


