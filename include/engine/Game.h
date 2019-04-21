#pragma once

#include "GameObject.h"
#include "Camera.h"
#include "utils/constants.h"
#include "utils/Singleton.h"
#include "gameplay/GameEntry.h" // Gameplay in engine. Yes! Gamejam is king!

#include <vector>


namespace ice {


/*
 * This is the predefined number of GameObjects initially in the game.
 * This is not the actual number of game objects or the max value etc, but
 * only used as a little 'optimization' to 'reserve' a better initial
 * size for the vector of game objects.
 */
#define ICE_INIT_GAMEOBJECT_POOL_SIZE   210


/**
 * The main Game class.
 * Currently mixes the engine, main loop and game data.
 * It's like your milkshake, but in code.
 * (GameJam stuff buddies)
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
         * Starts the game! Yoooloooo let's gooo!
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
         * Registers a new gameobject in the game.
         * The object must have been created on the heap (new) since, when
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


