#include "core/Game.h"

#include "utils/constants.h"
#include "utils/log.h"
#include "core/WindowGLFW.h"

namespace ice {


void Game::startup() {
    LOG << "Startup game\n";
    // Startup all subsystems (Order is important)
    ice::WindowGLFW::getInstance().startup();;
}

void Game::shutdown() {
    LOG << "Shutdown game\n";
    // Shutdown all subsystems (Order is important)
    ice::WindowGLFW::getInstance().shutdown();;
}

/**
 * Main game loop
 * TODO
 */
void Game::run() {
    LOG << "Run game (Main loop starting)\n";
    if(_isRunning) {
        // Can't run more than once.
        return;
    }
    _isRunning = true;
    while(_isRunning) {
        // Main loop
    }
}


} // End namespace


