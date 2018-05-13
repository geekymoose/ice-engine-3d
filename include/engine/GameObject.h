#pragma once

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
        glm::vec3 position;
        glm::vec3 scale;
        glm::vec3 rotation;


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
};


} // End namespace


