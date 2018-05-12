#pragma once

#include "glm"

namespace ice {

class GameBlock{
    private:
        glm::vec2<int> position(0,0);
    
    public :
        GameBlock();
        GameBlock(glm::vec2 pos);
        glm::vec2 getPos();

}

}// End Namespace
