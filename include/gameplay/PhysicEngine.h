#pragma once

#include "engine/TimeManager.h"
#include "gameplay/GameBall.h"
#include "gameplay/GameField.h"
#include "utils/constants.h"
#include "utils/mathHelper.h"
#include "utils/log.h"

#include <cmath>

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

        void fall();


    public:
        void fixedUpdate();

        void registerGameBall(GameBall* ball);
        void registerGameField(GameField* field);

};
}

