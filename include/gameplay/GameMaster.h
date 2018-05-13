#pragma once



namespace ice{

class GameField;

class GameMaster{
    private:
        GameField* field;


    public :
        void start();
        void update();
        void end();


};

}
