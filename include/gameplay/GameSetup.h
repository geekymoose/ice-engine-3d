#pragma once

#include "GameData.h"
#include "utils/log.h"
#include "engine/MeshManager.h"
#include "engine/TextureManager.h"

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
            // A little bit hard coded (Just a little bit)

            // TMP variables
            TextureManager& texture = TextureManager::getInstance();
            MeshManager& mesh       = MeshManager::getInstance();

            // Loads all textures
            texture.createTexture("trollface", "./resources/textures/trollface.png");
            texture.createTexture("rune-diffuse", "./resources/textures/rune-diffuse.png");
            texture.createTexture("rune-specular", "./resources/textures/rune-specular.png");

            // Loads all mesh
            std::vector<Texture> textures1 = {
                texture.getTexture("rune-diffuse"),
                texture.getTexture("rune-specular")
            };
            mesh.createMesh(
                "GameBlock",
                GameData::cube_vnt_data,
                GameData::cube_indices_data,
                textures1);

            std::vector<Texture> textures2 = {
                texture.getTexture("trollface"),
                texture.getTexture("trollface")
            };
            mesh.createMesh(
                "GameBall",
                GameData::cube_vnt_data,
                GameData::cube_indices_data,
                textures2);
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


