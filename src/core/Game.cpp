#include "core/Game.h"

#include "utils/log.h"
#include "core/Engine.h"

#include <cassert>

namespace ice {


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
        return;
    }
    _isRunning = true;

    // Create engine used for the game.
    Engine engine(*this);

    engine.startup();
    engine.run();
    engine.shutdown();
}

void Game::update() {
    // TODO
    // Call update of all registered game objects
    for(auto elt : _gameObjects) {
        elt->update();
    }
}

void Game::fixedUpdate() {
    // Call fixedupdate of all registered game objects.
    for(auto elt : _gameObjects) {
        elt->fixedUpdate();
    }
}

void Game::registerGameObject(GameObject* o) {
    assert(o != nullptr);
    _gameObjects.push_back(o); // Yeap, the famous push_back. But size reserved
}


} // End namespace


