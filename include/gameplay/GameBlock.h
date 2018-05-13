#pragma once

#include "glm/glm.hpp"
#include "engine/GameObject.h"
#include "utils/constants.h"

namespace ice {

class GameBlock : GameObject {
    private:
        /*
         * 0 is a hole 
         * 1 is normal
         * 2 is a wall
         */
        int status;
    
        Tag tag;

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

        Tag getTag(){
            return tag;
        }

};

}// End Namespace
