#pragma once

#include "utils/constants.h"
#include "WindowGLFW.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "utils/log.h"


namespace ice {


/**
 * Camera component.
 *
 * \date    May 2018
 * \author  Constantin Masson
 */
class Camera {
    private:
        float _fov              = 45.0f; // Default value

        glm::vec3 _camPos       = glm::vec3(0.0f, 10.0f, 0.0f);
        glm::vec3 _camTarget    = glm::vec3(0.01f, 0.01f, 0.01f);
        glm::vec3 _worldUp      = glm::vec3(0.0f, 1.0f, 0.0f);

        glm::vec3 _camDir;
        glm::vec3 _camRight;
        glm::vec3 _camUp;


    public:

        void updateViewData() {
            _camDir     = glm::normalize(_camTarget - _camDir);
            _camRight   = glm::normalize(glm::cross(_camDir, _worldUp));
            _camUp      = glm::normalize(glm::cross(_camRight, _camDir));
        }

        glm::mat4 getViewMatrix() const {
            return glm::lookAt(_camPos, _camTarget, _camUp);
        }

        glm::mat4 getPerspectiveMatrix() const {
            int width, height;
            glfwGetWindowSize(WindowGLFW::getInstance()._window, &width, &height);
            float ratio = (float)width / (float)height;

            return glm::perspective(glm::radians(_fov), ratio, 0.1f, 100.0f);
        }
};


} // End namespace


