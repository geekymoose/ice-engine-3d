#pragma once

#include "engine/GameObject.h"

namespace ice {

class Mesh;


/**
 * The famouse and beautiful GameBall, moving arround the field.
 * Soo much emotions.
 */
class GameBall : public GameObject {
    private:
        glm::vec3 target;
        Mesh& mesh;

        float velocity;
        float moveSpeed;

    public:
        GameBall();

    public:
        void update() override;
        void fixedUpdate() override;
        void draw(ShaderProgram& shader) override;

        void accelerate();
        void decelerate();

        glm::vec3 getTarget(){
            return target;
        }
        void setTarget(glm::vec3 newTarget){
            target = newTarget;
        }
        glm::vec3 getPos(){
            return position;
        }
        float getVelocity(){
            return velocity;
        }
};


} // End namespace
