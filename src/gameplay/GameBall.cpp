#include "gameplay/GameBall.h"
#include "utils/mathHelper.h"
#include "utils/log.h"
#include "utils/constants.h"
#include "engine/TimeManager.h"

namespace ice {


void GameBall::update() {
    // TODO
}

void GameBall::fixedUpdate() {
    float dt = TimeManager::getInstance().getFixedDeltaTime();
    position = mathHelper::lerp(position, 
                                target,
                                mathHelper::clamp01(velocity * dt));

}

void GameBall::accelerate(){
    if (velocity + GAME_BALL_ACCELERATION <= GAME_BALL_MAX_SPEED){
        velocity += GAME_BALL_ACCELERATION;
    } else {
        velocity = GAME_BALL_ACCELERATION;
    }
}

void GameBall::decelerate(){
    if(velocity - GAME_BALL_ACCELERATION >= 0){
        velocity -= GAME_BALL_ACCELERATION;
    }else{
        velocity = 0;
        target = position;
    }
}

} // End namespace


