#pragma once

#include "engine/GameObject.h"

namespace ice {


/**
 * The famouse and beautiful GameBall, moving arround the field.
 * Soo much emotions.
 */
class GameBall : public GameObject {

    public:

        void update() override;
        void fixedUpdate() override;
};


} // End namespace
