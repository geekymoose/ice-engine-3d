#pragma once

#include "gameplay/PhysicEngine.h"


namespace ice{

class GameField;


class GameMaster{
    private:
        GameField*      _field;
        PhysicEngine*   _physicEngine;

    public:
        void start();
        void fixedUpdate();
        void end();
};


} // End namespace


