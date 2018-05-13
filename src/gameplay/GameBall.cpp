#include "gameplay/GameBall.h"

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
}

void GameBall::update() {
    static bool growing = true;

    // A little ugly animation
    float dt = TimeManager::getInstance().getDeltaTime();
    float speed = 0.5;
    float newScale = speed * dt;
    if(growing) {
        scale.x += newScale;
        scale.y += newScale;
        scale.z += newScale;

        if(scale.x >= 1.3) {
            growing = false;
        }
    }
    else {
        scale.x -= newScale;
        scale.y -= newScale;
        scale.z -= newScale;

        if(scale.x <= 0.8) {
            growing = true;
        }
    }

    InputManager& input = InputManager::getInstance();
    if(input.isKeyDown("right")) {
    }
    else if(input.isKeyDown("left")) {
    }
    else if(input.isKeyDown("up")) {
    }
    else if(input.isKeyDown("down")) {
    }
}

void GameBall::fixedUpdate() {
    float dt = TimeManager::getInstance().getFixedDeltaTime();
    position = mathHelper::lerp(position,
                                target,
                                mathHelper::clamp01(velocity * dt));
}

void GameBall::draw(ShaderProgram& shader) {
    position = glm::vec3(0.0f, 0.0f, 0.0f); //TODO: TMP

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


