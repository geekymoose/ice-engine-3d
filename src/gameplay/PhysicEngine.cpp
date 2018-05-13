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

    glm::vec2 currentPos(std::floor(ballPos.x),std::floor(ballPos.z));
    _field->getGB(currentPos.x  , currentPos.y)->isWalk(true);
    

    
    GameBlock* blockAround[4];
   
    blockAround[0] = _field->getGB(currentPos.x  , currentPos.y+1);
    blockAround[1] = _field->getGB(currentPos.x-1, currentPos.y);
    blockAround[2] = _field->getGB(currentPos.x+1, currentPos.y);
    blockAround[3] = _field->getGB(currentPos.x-1, currentPos.y-1);

    for (int i =0; i<4;++i){
        blockAround[i]->isWalk(false);
    }


/*

    //LOG << "coucou";

    glm::vec3 ballTarget = _ball->getTarget();
    float ballVelocity = _ball->getVelocity();

    glm::vec3 d(ballTarget.x - ballPos.x, ballTarget.y - ballPos.y, ballTarget.z - ballPos.z);
        glm::vec3 direction = glm::normalize(d);

    //LOG << "Direction : (" << direction.x << ", " << direction.y << ", " << direction.z << ") \n";

    glm::vec2 currentPos(std::floor(ballPos.x),std::floor(ballPos.z));
    LOG << "case : " << currentPos.x << "," << currentPos.y << "\n";

    
      Block it:
      -1-
      2b3
      -4-
     
    GameBlock* blockAround[4];
   

    blockAround[0] = _field->getGB(currentPos.x  , currentPos.y+1);
    blockAround[1] = _field->getGB(currentPos.x-1, currentPos.y);
    blockAround[2] = _field->getGB(currentPos.x+1, currentPos.y);
    blockAround[3] = _field->getGB(currentPos.x-1, currentPos.y-1);



    if(ballPos.z + direction.z * ballVelocity >= currentPos.y+1 - .5f){
        switch(blockAround[0]->getStatus()){
            case 0:
                fall();
                break;
            case 2:
                //LOG << "TOP collid \n";
                _ball->setVelocity(1);
                ballTarget.z = currentPos.y;
                ballTarget.x = currentPos.x;
                _ball->setTarget(ballTarget);
                break;
        }
    }
    if(ballPos.z + direction.z * ballVelocity <= currentPos.y-1 + .5f){
        switch(blockAround[1]->getStatus()){
            case 0:
                fall();
                break;
            case 2:
                //LOG << "BOT collid \n";
                ballTarget.z = currentPos.y;
                ballTarget.x = currentPos.x;                
                _ball->setTarget(ballTarget);
                _ball->setVelocity(1);
                break;
        }
    }  
    if(ballPos.x + direction.x * ballVelocity >= currentPos.x+1 - .5f){
        switch(blockAround[2]->getStatus()){
            case 0:
                fall();
                break;
            case 2:
                //LOG << "RIGHT collid \n";
                ballTarget.x = currentPos.x;
                ballTarget.z = currentPos.y;                
                _ball->setTarget(ballTarget);
                _ball->setVelocity(1);
                break;
        }
    }  
    if(ballPos.x + direction.x * ballVelocity <= currentPos.x-1 + .5f){
        switch(blockAround[3]->getStatus()){
            case 0:
                fall();
                break;
            case 2:
                //LOG << "LEFT collid \n";
                ballTarget.x = currentPos.x;
                ballTarget.z = currentPos.y;                                
                _ball->setTarget(ballTarget);
                _ball->setVelocity(1);                
                break;
        }
    }
    */
}

void PhysicEngine::fall(){
    //TODO Level end condition;
    LOG << "ball falled you win \n";
}


}


