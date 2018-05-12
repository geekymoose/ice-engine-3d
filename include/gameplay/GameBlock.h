#pragma once

#include "glm"
#include "engine/GameObject"

namespace ice {

class GameBlock : GameObject {
    private:
        int stat;
    public :
        GameBlock();
        GameBlock(glm::vec3 pos);
        int getStat();

}

}// End Namespace
