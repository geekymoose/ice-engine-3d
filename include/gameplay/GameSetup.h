#pragma once

#include "GameData.h"

#include "utils/log.h"
#include "engine/MeshManager.h"

#include <vector>
#include <GLFW/glfw3.h> // Kind of ugly, but to register gameplay keys

namespace ice {


/**
 * Load all the GameData.
 */
class GameSetup {

    public:
        static void loadGameData() {
            LOG << "DATA: load game data (Mesh...)\n";
            // Little bit hard coded (Little bit)

            // Add block Mesh data
            MeshManager::getInstance().createMesh(
                    "GameBlock",
                    GameData::cube_vnt_data,
                    GameData::cube_indices_data,
                    std::vector<Texture>{});

            MeshManager::getInstance().createMesh(
                    "GameBall",
                    GameData::cube_vnt_data,
                    GameData::cube_indices_data,
                    std::vector<Texture>{});

        }

        static void loadAllInputs() {
            LOG << "Register all gameplay inputs for the game\n";

            InputManager& _input = InputManager::getInstance();
            _input.registerInput("right", GLFW_KEY_D);
            _input.registerInput("left", GLFW_KEY_A);
            _input.registerInput("up", GLFW_KEY_W);
            _input.registerInput("down", GLFW_KEY_S);
        }
};


} // End namespace


