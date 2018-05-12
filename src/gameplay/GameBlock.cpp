#include "gameplay/GameBlock.h"


namespace ice {

    GameBlock::GameBlock():GameObject(){
    }

    GameBlock::GameBlock(glm::vec3 pos):GameObject(){
        this->position = pos;
    }


}
