#include "gameplay/GameBall.h"

#include "gameplay/GameData.h"

#include "engine/TimeManager.h"
#include "engine/MeshManager.h"
#include "engine/InputManager.h"

#include "utils/mathHelper.h"
#include "utils/log.h"
#include "utils/constants.h"

#include <glm/gtc/matrix_transform.hpp>

namespace ice {


GameBall::GameBall() : mesh(MeshManager::getInstance().getMesh("GameBall")){
    LOG << " Player (GameBall) created\n";

    position.x = 1;
    position.y = 1;
    position.z = 1;

    target = position;
}

void GameBall::update() {
    static bool growing = true;

    // A little ugly animation
    float dt = TimeManager::getInstance().getDeltaTime();

    // Move player
    InputManager& input = InputManager::getInstance();
    if(input.isKeyDown("right")) {
        accelerate();
        target.x += dt * GAME_SOAP_GROUND;
    }
    if(input.isKeyDown("left")) {
        accelerate();
        target.x -= dt * GAME_SOAP_GROUND;
    }
    if(input.isKeyDown("up")) {
        accelerate();
        target.z -= dt * GAME_SOAP_GROUND;
    }
    if(input.isKeyDown("down")) {
        accelerate();
        target.z += dt * GAME_SOAP_GROUND;        
    }

    PointLight& l = GameData::pLight;
    l.position.x = position.x;
    l.position.z = position.z;
}

void GameBall::fixedUpdate() {
    float dt = TimeManager::getInstance().getFixedDeltaTime();
    position = mathHelper::lerp(position,
                                target,
                                mathHelper::clamp01(velocity * dt));
}

void GameBall::draw(ShaderProgram& shader) {
    shader.use();
    glm::mat4 model(1.0f);
    model = glm::translate(model, position);
    //model = glm::rotate(model, glm::radians(50.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    model = glm::scale(model, scale);
    shader.setMat4("model", model);

    mesh.draw(shader);
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


