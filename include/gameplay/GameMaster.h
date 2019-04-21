#pragma once


namespace ice{

class GameField;
class PhysicEngine;


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


