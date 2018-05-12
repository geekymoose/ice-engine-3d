#include "engine/Game.h"

#include "engine/Engine.h"
#include "engine/InputManager.h"

#include "utils/log.h"

#include <cassert>

namespace ice {


/*
 * Dev note:
 * This is relative to game play. I placed it here for now for simplicity.
 * This may be exported outside.
 *
 * InputManager must have been started up!!! (Undefined behavior otherwise).
 */
static void registerAllKeyInputs() {
    LOG << "Register all keys\n";

    InputManager& _input = InputManager::getInstance();
    _input.registerInput("debug1", GLFW_KEY_ESCAPE);
}

Game::Game() {
    LOG << "Create Game class\n";
    _gameObjects.reserve(ICE_INIT_GAMEOBJECT_POOL_SIZE);
}

Game::~Game() {
    LOG << "Destroy Game class\n";
    for(auto elt : _gameObjects) {
        delete elt;
    }
}

void Game::run() {
    LOG << "Run game (Main loop starting)\n";
    if(_isRunning) {
        // Can't run more than once.
        LOG << "Game is already running!\n";
        return;
    }
    _isRunning = true;

    Engine engine(*this);

    engine.startup();
    registerAllKeyInputs();

    engine.run();

    engine.shutdown();
}

void Game::update() {
    // Call update of all registered game objects

    /*
     * Dev note:
     * Maybe we could for the foreach loop once, and if marked to destroye,
     * remove from le vector. But I'm not sure this 'live' removing
     * may break the iterator or something. We don't have time for now to check
     * so this solution, though ugly, will do the job for now.
     * (GameJam style buddies, it's 4:00Pm and we have to give the game in
     * 24h!)
     */
    for(GameObject* elt : _gameObjects) {
        assert(elt != nullptr);
        if(elt->isMarkedToDestroy()) {
            delete elt;
        }
    }

    for(GameObject* elt : _gameObjects) {
        elt->update();
    }
}

void Game::fixedUpdate() {
    // Call fixedupdate of all registered game objects.
    for(GameObject* elt : _gameObjects) {
        assert(elt != nullptr);
        elt->fixedUpdate();
    }
}

void Game::registerGameObject(GameObject* o) {
    assert(o != nullptr);
    _gameObjects.push_back(o); // Yeap, the famous push_back. But size reserved
}


} // End namespace


