#pragma once

#include "GameObject.h"
#include "Camera.h"

#include "utils/constants.h"
#include "utils/Singleton.h"

#include "gameplay/GameEntry.h"

#include <vector>

namespace ice {


/*
 * This is the predefined number of gameobject initially in the game.
 * This is not the number of game object or the max value etc.
 * This is only used for little 'optimization' to 'reserve' a better initial
 * size for the vector of game objects in the game.
 */
#define ICE_INIT_GAMEOBJECT_POOL_SIZE   210


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
    // Singleton
    private:
        Game();
        ~Game();
        friend Singleton<Game>;
    public:
        using Singleton<Game>::getInstance;

    private:
        std::vector<GameObject*> _gameObjects; // All registered game objects.
        bool        _isRunning = false;
        Camera      _cctv;
        GameEntry   _gameEntry;


    // -------------------------------------------------------------------------
    // Core methods
    // -------------------------------------------------------------------------

    public:
        /**
         * Start the game! Yoooloooo let's gooo!
         */
        void run();

        /**
         * Called at each render frame
         * (Use DeltaTime inside)
         */
        void update();

        /**
         * Called at each fixed frame.
         * (Use FixedDetaTime inside)
         */
        void fixedUpdate();

        /**
         * Register a new gameobject in the game.
         * Object must have been created on the heap (new) because, when 
         * destroyed, free(o) is called.
         */
        void registerGameObject(GameObject* o);

        /**
         * Draw all game objects.
         */
        void drawAll();


    // -------------------------------------------------------------------------
    // Getter / Setters
    // -------------------------------------------------------------------------

    public:

        bool isRunning() const {
            return _isRunning;
        }
};


} // End namespace
