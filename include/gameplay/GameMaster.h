#pragma once



namespace ice{

class GameField;

class GameMaster{
    private:
        ice::GameField* field;


    public :
        void start();
        void end();


};

}
