#pragma once

#include "gameplay/GameMaster.h"


namespace ice {


class GameEntry {
    public:
       void start();
       void fixedUpdate();
       void end();

    private:
       GameMaster* _gm;

};


} // End namespace


