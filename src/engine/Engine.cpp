#include "engine/Engine.h"

namespace ice {


Engine::Engine(Game& game)
    : _game(game),
      _window(WindowGLFW::getInstance()),
      _timeManager(TimeManager::getInstance()),
      _inputManager(InputManager::getInstance())
    {
}

void Engine::startup() {
    // Startup all subsystems (Order is important)
    if(!_isInit) {
        _isInit = true;
        LOG << "Startup ice Engine\n";
        _window.startup(); // FIRST ONE

        _timeManager.startup();
        _inputManager.startup();
    }
}

void Engine::shutdown() {
    // Shutdown all subsystems (Order is important)
    if(_isInit) {
        LOG << "Shutdown ice Engine\n";
        _timeManager.shutdown();
        _inputManager.shutdown();

        _window.shutdown(); // LAST ONE
        _isInit = false;
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
        _inputManager.update();

        //LOG << "FPS: " << _timeManager.getCurrentFPS() << "\n";

        _game.update();
        if(_timeManager.hasFixedUpdate()) {
            _game.fixedUpdate();
        }

        // TODO: call render engine

        if(_window.isClosed()) {
            _isRunning = false;
        }
    }
}


} // End namespace


