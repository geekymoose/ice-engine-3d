#pragma once

#include "gameplay/GameBlock.h"
#include "utils/constants.h"
#include "utils/log.h"

#include <iostream>
#include <fstream>

namespace ice {


class GameField {
    private:
        GameBlock* blockList[GAME_FIELD_SIZE_X][GAME_FIELD_SIZE_Y];
        int currentLevel;

    public:
        GameField();
        void initLevel(int level);

        // Returns the state of the block at xy
        GameBlock* getGB(int x, int y);

    private:
        void cleanLevel();
        static int parse(char const s);
};


} // End namespace


