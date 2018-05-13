#pragma once

#include "GameBall.h"


namespace ice{

class GameField;


class GameMaster{
    private:
        GameBall*   gameBall;
        GameField* field;


    public :
        void start();
        void end();
};

}
