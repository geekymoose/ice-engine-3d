#include "gameplay/GameBlock.h"

#include "gameplay/GameData.h"
#include "engine/TimeManager.h"
#include "engine/MeshManager.h"
#include "utils/mathHelper.h"
#include "utils/log.h"

#include <glm/gtc/matrix_transform.hpp>


namespace ice {

class GameObject;


GameBlock::GameBlock(): GameObject(), mesh(MeshManager::getInstance().getMesh("GameBlock")) {
}

GameBlock::GameBlock(glm::vec3 pos) : GameBlock() {
    position = pos;
    target = pos;
}

void GameBlock::update() {
}

void GameBlock::isWalk(bool isWalk) {
    if(isWalk && stat != 2) {
        setStatus(0);
        target.y = PLAYER_WEIGHT;
    } else if (stat == 0) {
        target.y = 0;
        setStatus(1);
    }
}

void GameBlock::fixedUpdate(){
    float dt = TimeManager::getInstance().getFixedDeltaTime();
    position = mathHelper::lerp(position, target, mathHelper::clamp01(BLOCK_SPEED * dt));
}

void GameBlock::draw(ShaderProgram& shader) {
    shader.use();
    glm::mat4 model(1.0f);
    model = glm::translate(model, position);
    model = glm::scale(model, scale);
    shader.setMat4("model", model);

    PointLight& l = GameData::pLight;

    shader.setVec3("light.position", l.position);

    shader.setVec3("light.ambiant",  l.ambiant);
    shader.setVec3("light.diffuse",  l.diffuse);
    shader.setVec3("light.specular", l.specular);

    shader.setFloat("light.attenuation_kc", l.attenuation_kc);
    shader.setFloat("light.attenuation_kl", l.attenuation_kl);
    shader.setFloat("light.attenuation_kq", l.attenuation_kq);

    mesh.draw(shader);
}

void GameBlock::setStatus(int status){
    switch (status){
        case 0:
            this->stat = 0;
            target.y = PLAYER_WEIGHT;
            break;
        case 1:
            this->stat = 1;
            target.y = 0;
            break;
        case 2:
            this->stat = 2;
            target.y = 1;
            break;
    }

    //TODO Check if the ball is not on the block
}


} // End namespace


