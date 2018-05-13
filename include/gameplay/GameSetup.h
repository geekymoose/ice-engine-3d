#pragma once

#include "GameData.h"

#include "utils/log.h"
#include "engine/MeshManager.h"

#include <vector>

namespace ice {


/**
 * Load all the GameData.
 */
class GameSetup {

    public:
        static void loadGameData() {
            LOG << "DATA: load game data (Mesh...)\n";
            // Little bit hard coded (Little bit)

            std::vector<Vertex>         gameBlock_vertices;
            std::vector<unsigned int>   gameBlock_indices;
            std::vector<Texture>        gameBlock_textures;


            // Add block Mesh data
            MeshManager::getInstance().createMesh(
                    "GameBlock",
                    gameBlock_vertices,
                    gameBlock_indices,
                    gameBlock_textures);
        }
};


} // End namespace


