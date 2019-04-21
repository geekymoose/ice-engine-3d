#include "engine/Game.h"

#include "engine/Engine.h"
#include "engine/InputManager.h"
#include "engine/ShaderProgram.h"
#include "engine/MeshManager.h"
#include "utils/log.h"

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
        LOG << "Game is already running!\n";
        return;
    }
    _isRunning = true;

    Engine engine(*this);

    engine.startup();
    _gameEntry.start();

    engine.run();

    _gameEntry.end();
    engine.shutdown();
}

void Game::update() {
    // Calls update of all registered game objects

    /*
     * TODO: Dev note
     *
     *
     * Maybe we could do only one foreach loop, and remove the deleted objects
     * from the vector (i.e., marked "to destroy").
     * I'm not sure if this 'live' removing would break the iterator or something.
     * We don't have enough time to check this now, so this solution, though ugly,
     * will do the job for now.
     * (GameJam style buddies, it's 4:00Pm and we have to give the game in 24h!)
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
    // Calls fixedupdate of all registered game objects.
    for(GameObject* elt : _gameObjects) {
        assert(elt != nullptr);
        elt->fixedUpdate();
    }
    _gameEntry.fixedUpdate();
}

void Game::drawAll() {
    _cctv.updateViewData();

    glm::mat4 view          = _cctv.getViewMatrix();
    glm::mat4 projection    = _cctv.getPerspectiveMatrix();

    static ShaderProgram shader("./shaders/cube.vert", "./shaders/phong_illu.frag");

    shader.use();
    shader.setMat4("view", view);
    shader.setMat4("projection", projection);
    shader.setVec3("eyePos", _cctv.getPosition());
    shader.setFloat("shininess", 32.0f);

    for(GameObject* elt : _gameObjects) {
        assert(elt != nullptr); // We love asserts (its actually useless here)

        elt->draw(shader);
    }
}

void Game::registerGameObject(GameObject* o) {
    assert(o != nullptr);
    _gameObjects.push_back(o); // Yeap, the famous push_back. But size reserved
}


} // End namespace


