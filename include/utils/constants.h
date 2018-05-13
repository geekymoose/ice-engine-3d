#pragma once

// General constances here


#define ICE_WINDOW_HEIGHT       500
#define ICE_WINDOW_WIDTH        1000
#define ICE_WINDOW_TITLE        "Runic-ice Game"

#define ICE_FIXED_DELTATIME     0.022 // Physics run at 45 fps
#define ICE_FIXED_FPS           60

#define ICE_WORLD_UP_VEC        glm::vec3(0.0f, 1.0f, 0.0f)


// Game Constances
#define GAME_FIELD_SIZE_X       20
#define GAME_FIELD_SIZE_Y       10
#define BLOCK_SPEED             5
#define GAME_BALL_ACCELERATION  0.2
#define GAME_BALL_MAX_SPEED     3


// System Path

#define ICE_PATH_TO_MAP       "resources/tilemaps/level"


// TAG 
namespace ice{
    enum class Tag{ Block, Ball};

}
