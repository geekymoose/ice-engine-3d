#include "game/GameField.h"
#include "glm"

namespace ice {

GameField::GameField(){
    
    for(int i=0; i<GAME_FIELD_SIZE_X; ++i){
        for (int j=0; j<GAME_FIELD_SIZE_Y; ++j){
        
            blockList[i][j] = ice::GameBlock(glm::vec3(i,0,j));
        }
    }
    
}

}


