#include "gameplay/PhysicEngine.h"



namespace ice{

void PhysicEngine::registerGameBall(GameBall* ball){
    _ball = ball;
}

void PhysicEngine::registerGameField(GameField* field){
    _field = field;
}

void PhysicEngine::fixedUpdate(){
    float dt = TimeManager::getInstance().getFixedDeltaTime();

    glm::vec3 ballPos = _ball->getPos();
    glm::vec3 ballTarget = _ball->getTarget();
    float ballVelocity = _ball->getVelocity();

    glm::vec3 ghostPos = mathHelper::lerp(ballPos, 
                                        ballTarget, 
                                        mathHelper::clamp01(ballVelocity));

    glm::vec2 currentPos(std::floor(ballPos.x),std::floor(ballPos.z));
    

    /*
     * Block it:
     * -1-
     * 2b3
     * -4-
     */
    int stateAround[4];
   

    /*
     * The most hard coded state machine ever
     */
    stateAround[0] = _field->getState(currentPos.x, currentPos.y+1);
    stateAround[1] = _field->getState(currentPos.x-1, currentPos.y);
    stateAround[2] = _field->getState(currentPos.x+1, currentPos.y);
    stateAround[3] = _field->getState(currentPos.x-1, currentPos.y-1);

    if(ghostPos.z >= ballPos.z + 1){
        switch(stateAround[0]){
            case 0:
                fall();
                break;
            case 2:
                ballTarget.z -= GAME_BALL_BOUNCE;
                break;
        }
    }

    if(ghostPos.x <= ballPos.x - 1){
        switch(stateAround[1]){
            case 0:
                fall();
                break;
            case 2:
                ballTarget.x += GAME_BALL_BOUNCE;
                break;
        }
    }

    if(ghostPos.x >= ballPos.x + 1){
        switch(stateAround[2]){
            case 0:
                fall();
                break;
            case 2:
                ballTarget.x -= GAME_BALL_BOUNCE;
                break;
        }
    }
    if(ghostPos.z <= ballPos.z - 1){
        switch(stateAround[3]){
            case 0:
                fall();
                break;
            case 2:
                ballTarget.z += GAME_BALL_BOUNCE;
                break;
        }
    }

    _ball->setTarget(ballTarget);
}

void PhysicEngine::fall(){
    //TODO Level end condition;
    LOG << "ball falled you win \n";
}


}


