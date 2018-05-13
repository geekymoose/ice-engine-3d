#pragma once

#include "gameplay/PhysicEngine.h"
#include "GameBall.h"


namespace ice{

class GameField;


class GameMaster{
    private:
        GameBall*   gameBall;
        GameField*  field;

        PhysicEngine* physicEngine;


    public :
        void start();
        void fixedUpdate();
        void end();
};

}
