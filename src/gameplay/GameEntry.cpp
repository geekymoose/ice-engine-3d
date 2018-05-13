#include "gameplay/GameEntry.h"

#include "gameplay/GameSetup.h"


/*
 *
 * Each of the function of Game entry must be called by Game
 * And NOBOBY ELSE
 * bitches
 *
 */

namespace ice{


void GameEntry::start(){
    GameSetup::loadGameData();
    // GameObject* o = new Blabla();
    // Game::getInstance().registerGameObject(o);

   _gm = new ice::GameMaster();
   _gm->start();
}

void GameEntry::end(){
    _gm->end();
}

}


