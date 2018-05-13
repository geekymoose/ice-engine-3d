#include "gameplay/GameMaster.h"
#include "gameplay/GameField.h"


namespace ice{

void GameMaster::start(){

    field = new ice::GameField();
    field->initLevel(1);

}


void GameMaster::end(){

    field->~GameField();
}
}
