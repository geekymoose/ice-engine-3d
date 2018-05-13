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
    GameSetup::loadAllInputs();
    GameSetup::loadGameData();

   _gm = new ice::GameMaster();
   _gm->start();
}

void GameEntry::end(){
    _gm->end();
}

}


