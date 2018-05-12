#include "core/Engine.h"

#include "core/ShaderProgram.h"


namespace ice {


Engine::Engine(Game& game)
    : _game(game),
      _window(WindowGLFW::getInstance()),
      _timeManager(TimeManager::getInstance()) {
}

void Engine::startup() {
    if(!_isInit) {
        _isInit = true;
        LOG << "Startup ice Engine\n";
        // Startup all subsystems (Order is important)
        _timeManager.startup();
        _window.startup();
    }
}

void Engine::shutdown() {
    if(_isInit) {
        LOG << "Shutdown ice Engine\n";
        // Shutdown all subsystems (Order is important)
        _timeManager.shutdown();
        _window.shutdown();
    }
}

void Engine::run() {
    LOG << "Start running the ice engine\n";
    if(!_isInit) {
        LOG << "Engine must be started up before run call\n";
        return;
    }
    if(_isRunning) {
        LOG << "Engine is already running\n";
        return;
    }

    // The main loop
    _isRunning = true;
    while(_isRunning) {
        _timeManager.update();

        LOG << "FPS: " << _timeManager.getCurrentFPS() << "\n";
        if(_timeManager.hasFixedUpdate()) {
            LOG << "FIXE UPDATE\n";
        }
    }
}


} // End namespace
