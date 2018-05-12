#pragma once

#include "gameplay/GameBlock.h"
#include "utils/Constants.h"

#include <iostream>
#include <fstream>

namespace ice {


class GameField {
    private: 
        ice::GameBlock[GAME_FIELD_SIZE_X][GAME_FIELD_SIZE_Y] blocList;
        int currentLevel;

    public:
        GameField();
        ~GameField();
        initLevel(int level);


}
} // End namespace
