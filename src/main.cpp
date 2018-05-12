#include "core/Game.h"
#include "utils/log.h"

#include <iostream>


int main(int argc, char** argv) {
    LOG << "--- Start Main ---\n";

    // Create the window
    ice::Game::getInstance().startup();
    ice::Game::getInstance().run();

    LOG << "--- Stop Main ---\n";
    return 0;
}
