#pragma once

#include "gameplay/GameBlock.h"
#include "utils/constants.h"

#include <iostream>
#include <fstream>

namespace ice {


class GameField {
    private: 
        ice::GameBlock blockList[GAME_FIELD_SIZE_X][GAME_FIELD_SIZE_Y];
        int currentLevel;
        void cleanLevel();
        static int parse(char const s);
    
    public:
        GameField();
        ~GameField();
        void initLevel(int level);


};
} // End namespace
