#include "gameplay/GameField.h"

#include "utils/constants.h"
#include "utils/log.h"
#include "engine/Game.h"

#include <glm/glm.hpp>
#include <fstream>
#include <cassert>
#include <string>


namespace ice {


GameField::GameField(){
   currentLevel = 1;

    for(int i=0; i<GAME_FIELD_SIZE_X; ++i){
        for (int j=0; j<GAME_FIELD_SIZE_Y; ++j){
            blockList[i][j] = new GameBlock(glm::vec3(i,0,j));
            GameObject* o = (GameObject*)blockList[i][j];
            Game::getInstance().registerGameObject(o);
        }
    }
}

void GameField::initLevel(const int level){
    cleanLevel();

    std::string strList[GAME_FIELD_SIZE_Y];
    std::ifstream map(ICE_PATH_TO_MAP + std::to_string(level) + ".gmap");

    if(map.is_open()){
        for(int i = 0; i < GAME_FIELD_SIZE_Y; ++i){
            std::getline(map, strList[i]);

            for(int j = 0; j<GAME_FIELD_SIZE_X; ++j){
                blockList[j][i]->setStatus(parse(strList[i][j]));
            }
        }
    }else{
        LOG << "Map hasn't been open \n";
    }
}

GameBlock* GameField::getGB(int x, int y){
    return blockList[x][y];
}

/*
 *  Parses a char to int
 *  Returns -1 for error
 */
int GameField::parse(char const c){
    int backer = -1;

    switch(c){
        case '0':
            backer = 0;
            break;
        case '1':
            backer = 1;
            break;
        case '2':
            backer = 2;
            break;
        case '3':
            backer = 3;
            break;
        case '4':
            backer = 4;
            break;
        case '5':
            backer = 5;
            break;
        case '6':
            backer = 6;
            break;
        case 7:
            backer = 7;
            break;
        case 8:
            backer = 8;
            break;
        case 9 :
            backer = 9;
            break;
        default:
            assert(backer != -1);
    }

    return backer;
}

/*
 * Cleans the field by set all status to 2 (wall).
 */
void GameField::cleanLevel(){
    for (int i = 0; i<GAME_FIELD_SIZE_X; ++i){
        for(int j = 0; j<GAME_FIELD_SIZE_Y; ++j){
            blockList[i][j]->setStatus(2);
        }
    }
}


} // End namespace


