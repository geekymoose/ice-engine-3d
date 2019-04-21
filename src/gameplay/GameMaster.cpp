#include "gameplay/GameMaster.h"

#include "gameplay/GameField.h"
#include "gameplay/GameBall.h"
#include "gameplay/PhysicEngine.h"
#include "engine/Game.h"
#include "engine/InputManager.h"
#include "engine/WindowGLFW.h"


namespace ice {


void GameMaster::start() {
    _field = new GameField();
    _field->initLevel(1);

    GameBall * gameBall = new GameBall();

    Game::getInstance().registerGameObject(gameBall); // Game will call "delete gameBall"

    _physicEngine = new PhysicEngine();
    _physicEngine->registerGameBall(gameBall);
    _physicEngine->registerGameField(_field);
}

void GameMaster::fixedUpdate() {
    _physicEngine->fixedUpdate();
    InputManager& input = InputManager::getInstance();
    if(input.isKeyDown("stop")) {
        WindowGLFW::getInstance().close();
    }
}

void GameMaster::end() {
    delete _field;
    delete _physicEngine;
}


} // End namespace


