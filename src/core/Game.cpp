#include "core/Game.h"

#include "utils/constants.h"
#include "utils/log.h"
#include "core/Engine.h"

namespace ice {


/**
 * The famouse Game.
 *
 * \date May 2018
 */
void Game::run() {
    LOG << "Run game (Main loop starting)\n";
    if(_isRunning) {
        // Can't run more than once.
        return;
    }
    _isRunning = true;

    Engine engine(*this);
    engine.startup();
    engine.run();
    engine.shutdown();
}


} // End namespace


