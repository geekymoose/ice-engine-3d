#pragma once

#include "engine/TimeManager.h"
#include "gameplay/GameBall.h"
#include "gameplay/GameField.h"
#include "utils/constants.h"
#include "utils/mathHelper.h"
#include "utils/log.h"

#include <cmath>

namespace ice {


/*
 * Home made physic engine.
 * Like your mom's pies, it's better when it's home made with LOVE.
 * It's also a state machine, like a banana chocolate pies: better when you mix.
 */
class PhysicEngine{
    private:
        GameBall*   _ball;
        GameField*  _field;

    private:
        void fall();

    public:
        void fixedUpdate();
        void registerGameBall(GameBall* ball);
        void registerGameField(GameField* field);
};


} // End namespace


