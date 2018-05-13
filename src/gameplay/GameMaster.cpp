#include "gameplay/GameMaster.h"
#include "gameplay/GameField.h"
#include "engine/Game.h"


namespace ice{

void GameMaster::start(){

    field = new GameField();
    field->initLevel(1);


    gameBall = new GameBall();

    Game::getInstance().registerGameObject(gameBall);
}


void GameMaster::end(){
    delete field;
}


}
