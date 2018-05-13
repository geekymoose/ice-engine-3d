#include "gameplay/GameBlock.h"
#include "engine/TimeManager.h"
#include "utils/mathHelper.h"


namespace ice {

    class GameObject;

    GameBlock::GameBlock():GameObject(){
    }

    GameBlock::GameBlock(glm::vec3 pos):GameObject(){
        position = pos;
        target = pos;
    }

    void GameBlock::update(){
    }

    void GameBlock::fixedUpdate(){
        float dt = TimeManager::getInstance().getFixedDeltaTime();
        position = mathHelper::lerp(position, target, BLOCK_SPEED * dt);
    }

    /*
     * Here status gonna juste move a block
     *
     */

    void GameBlock::setStatus(int status){
        switch (status){
            case 0:
                target.y = -5;
                break;
            case 1:
                target.y = 0;
                break;
            case 2:
                target.y = 1;
                break;
        }

        //TODO Check if the ball is not on the block

    }

}
