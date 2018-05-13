#include "gameplay/GameMaster.h"
#include "gameplay/GameField.h"


namespace ice{

void GameMaster::start(){

    field = new ice::GameField();
}

void GameMaster::update(){

    

}

void GameMaster::end(){

    field->~GameField();
}

}
