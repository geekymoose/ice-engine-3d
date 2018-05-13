#include "engine/Engine.h"

namespace ice {


Engine::Engine(Game& game)
    : _game(game),
      _window(WindowGLFW::getInstance()),
      _timeManager(TimeManager::getInstance()),
      _inputManager(InputManager::getInstance()),
      _meshManager(MeshManager::getInstance()),
      _textureManager(TextureManager::getInstance())
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
        _meshManager.startup();
    }
}

void Engine::shutdown() {
    // Shutdown all subsystems (Order is important)
    if(_isInit) {
        LOG << "Shutdown ice Engine\n";
        _timeManager.shutdown();
        _inputManager.shutdown();
        _meshManager.shutdown();

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
        _window.clear();

        _game.update();
        if(_timeManager.hasFixedUpdate()) {
            _game.fixedUpdate();
        }

        _game.drawAll();
        _window.update();

        if(_window.isClosed()) {
            _isRunning = false;
        }
    }
}


} // End namespace


