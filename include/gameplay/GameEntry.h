#pragma once
#include "gameplay/GameMaster.h"

namespace ice {


class GameEntry {
    public:
       void start();
       void end();

    private:
       GameMaster* _gm;

};


}
