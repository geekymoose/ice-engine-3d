#pragma once

#include "engine/GameObject.h"
#include "utils/constants.h"

#include <glm/glm.hpp>


namespace ice {

class Mesh;


class GameBlock : GameObject {
    // Internal data
    private:
        /*
         * 0 is a hole
         * 1 is normal
         * 2 is a wall
         */
        int stat;

        Tag tag;
        Mesh& mesh;

    // Gameplay data
    private:
        glm::vec3 target;

    public:
        GameBlock();
        GameBlock(glm::vec3 pos);
        int getStatus(){
            return stat;
        };
        void setStatus(int status);
        void fixedUpdate() override;
        void update() override;
        void draw(ShaderProgram& shader) override;

        void isWalk(bool isWalked);

        glm::vec3 getTarget() {
            return target;
        }

        Tag getTag() {
            return tag;
        }
};


} // End Namespace


