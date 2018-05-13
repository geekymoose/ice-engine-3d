#pragma once


#include "gameplay/GameBall.h"
#include "gameplay/GameField.h"



/*
 * Dev note:
 * Home made physic engine
 * like your mom's pies
 * it's better when it's home made 
 * with LOVE
 * 
 * it's also a stateMachine
 * like a banana chocolate pies
 * better when you mix
 */

namespace ice {

class PhysicEngine{
    private:
        GameBall*   _ball;
        GameField*  _field;

    public:
        void fixedUpdate();

        void registerGameBall(GameBall* ball);
        void registerGameField(GameBall* field);

};
}

