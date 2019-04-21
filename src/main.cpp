#include "engine/Game.h"
#include "utils/log.h"

#include <iostream>


int main(int argc, char** argv) {
    LOG << "--- Start Main ---\n";

    ice::Game& game = ice::Game::getInstance();
    game.run(); // Leeet's gooo

    LOG << "--- Stop Main ---\n";
    return 0;
}
