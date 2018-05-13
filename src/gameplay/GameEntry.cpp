#include "gameplay/GameEntry.h"
#include "utils/log.h"
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

    LOG << "GameEntry setup successfully done! (Beautiful isn't it?)\n";

   _gm = new GameMaster();
   _gm->start();
}

void GameEntry::end(){
    _gm->end();
}

void GameEntry::fixedUpdate(){
    _gm->fixedUpdate();
}

}


