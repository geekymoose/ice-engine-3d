#include "gameplay/GameEntry.h"


/*
 *
 * Each of the function of Game entry must be called by Game
 * And NOBOBY ELSE
 * bitches
 *
 */

namespace ice{


void GameEntry::start(){
    // GameObject* o = new Blabla();
    // Game::getInstance().registerGameObject(o);

   _gm = new ice::GameMaster();
   _gm->start();
}

void GameEntry::end(){
    _gm->end();
}

}


