#pragma once

#include "engine/Mesh.h" // For Vertex structure info
#include "engine/InputManager.h"
#include "engine/Lights.h"

#include <vector>
#include <glm/glm.hpp>


namespace ice {


/**
 * Hard coded set of data.
 */
class GameData {

    public:
        static const std::vector<Vertex>        cube_vnt_data;
        static const std::vector<unsigned int>  cube_indices_data;
        static PointLight                       pLight;
};


} // End namespace


