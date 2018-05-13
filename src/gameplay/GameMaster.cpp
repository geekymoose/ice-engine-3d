#include "gameplay/GameMaster.h"
#include "gameplay/GameField.h"
#include "engine/Game.h"

namespace ice{


void GameMaster::start(){

    field = new GameField();
    field->initLevel(1);


    gameBall = new GameBall();

    Game::getInstance().registerGameObject(gameBall);

    physicEngine = new PhysicEngine();
    physicEngine->registerGameBall(gameBall);
    physicEngine->registerGameField(field);
}

void GameMaster::fixedUpdate(){
    physicEngine->fixedUpdate();
}

void GameMaster::end(){
    delete field;
}


}
