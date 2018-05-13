#pragma once

#include "engine/ShaderProgram.h"

#include <glm/glm.hpp>

namespace ice {


/**
 * The GameObject interface.
 * Any in the game is a GameObject.
 *
 * \date    May 2018
 * \author  Constantin Masson
 */
class GameObject {
    private:
        bool _toDestroy = false;

    protected:
        glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);;
        glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);


    // -------------------------------------------------------------------------
    // Core methods
    // -------------------------------------------------------------------------

    public:

        /**
         * Called at each frame.
         * (Use deltaTime).
         */
        virtual void update() = 0;

        /**
         * Called at each fixed frame (Usually for physics).
         * (Use fixed deltaTime).
         */
        virtual void fixedUpdate() = 0;

        /**
         * Draw Gameobject using given shader.
         */
        virtual void draw(ShaderProgram& shader) = 0;

    public:

        /**
         * Tag object to be destroyed.
         * Object is tagged and is removed (Memory free etc) at next frame.
         */
        void destroy() {
            _toDestroy = true;
        }


    // -------------------------------------------------------------------------
    // Getters - Setters
    // -------------------------------------------------------------------------

    public:
        bool isMarkedToDestroy() const {
            return _toDestroy;
        }
        glm::vec3 getPos() const{
            return position;
        }
};


} // End namespace


