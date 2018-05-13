#pragma once


#include "engine/GameObject.h"

namespace ice {


/**
 * The famouse and beautiful GameBall, moving arround the field.
 * Soo much emotions.
 */
class GameBall : public GameObject {
    private:
        float velocity;
        glm::vec3 target;

    public:
        void update() override;
        void fixedUpdate() override;

        void accelerate();
        void decelerate();
};


} // End namespace
