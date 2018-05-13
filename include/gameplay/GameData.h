#pragma once

#include "engine/Mesh.h" // For Vertex structure info

#include <vector>


namespace ice {


/**
 * Hard coded set of data.
 */
class GameData {

    public:

        static const std::vector<float>         cube_vnt_data;
        static const std::vector<unsigned int>  cube_indices_data;
};


// -----------------------------------------------------------------------------
// Static data
// -----------------------------------------------------------------------------

const std::vector<float> GameData::cube_vnt_data = {
    // Position             // Normal           // Texture UV

    // Face 1
    -0.5f, -0.5f, -0.5f,    0.0f, 0.0f, -1.0f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,    0.0f, 0.0f, -1.0f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,    0.0f, 0.0f, -1.0f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,    0.0f, 0.0f, -1.0f,  0.0f, 1.0f,

    // Face 2
    -0.5f, -0.5f,  0.5f,    0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,    0.0f, 0.0f, 1.0f,   1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 1.0f,   1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 1.0f,   0.0f, 1.0f,

    // Face 3
    -0.5f,  0.5f, -0.5f,    -1.0f, 0.0f, 0.0f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,    -1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,    -1.0f, 0.0f, 0.0f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,    -1.0f, 0.0f, 0.0f,  1.0f, 0.0f,

    // Face 4
     0.5f,  0.5f, -0.5f,    1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,    1.0f, 0.0f, 0.0f,   0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,    1.0f, 0.0f, 0.0f,   0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,    1.0f, 0.0f, 0.0f,   1.0f, 0.0f,

    // Face 5
     0.5f, -0.5f, -0.5f,    0.0f, -1.0f, 0.0f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,    0.0f, -1.0f, 0.0f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,    0.0f, -1.0f, 0.0f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,    0.0f, -1.0f, 0.0f,  0.0f, 1.0f,

    // Face 6
     0.5f,  0.5f, -0.5f,    0.0f, 1.0f, 0.0f,   1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,    0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,    0.0f, 1.0f, 0.0f,   0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,    0.0f, 1.0f, 0.0f,   0.0f, 1.0f,
};


const std::vector<unsigned int> GameData::cube_indices_data = {
    // note that we start from 0

    // Face 1
    0, 1, 3,
    1, 2, 3,

    // Face 2
    4, 5, 7,
    5, 6, 7,

    // Face 3
    8, 9, 11,
    9, 10, 11,

    // Face 4
    12, 13, 15,
    13, 14, 15,

    // Face 5
    16, 17, 19,
    17, 18, 19,

    // Face 6
    20, 21, 23,
    21, 22, 23,
};

} // End namespace


