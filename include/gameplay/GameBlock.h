#pragma once

#include "glm/glm.hpp"
#include "engine/GameObject.h"

namespace ice {

class GameBlock : GameObject {
    private:
        /*
         * 0 is a hole 
         * 1 is normal
         * 2 is a wall
         */
        int status;


        glm::vec3 target;

    public :
        GameBlock();
        GameBlock(glm::vec3 pos);
        int getStatus(){
            return status;
        };
        void setStatus(int status);
        void fixedUpdate() override;
        void update() override;


};

}// End Namespace
