#include "engine/InputManager.h"

#include "engine/WindowGLFW.h"

#include <GLFW/glfw3.h>


namespace ice {


void InputManager::startup() {
    if(!_isInit) {
        _isInit = true;
        LOG << "Startup Input Manager\n";
    }
}

void InputManager::shutdown() {
    if(_isInit) {
        LOG << "Shutdown Input Manager\n";
        _isInit = false;
    }
}

void InputManager::update() {
    glfwPollEvents();
}

void InputManager::registerInput(const char* keyName, const int scancode) {
    LOG << "InputManager: register input (" << keyName << "=" << scancode << ")\n";
    _keys.emplace(keyName, scancode);
}

bool InputManager::isKeyDown(const char* keyName) const {
    int scancode = _keys.at(keyName);
    return glfwGetKey(WindowGLFW::getInstance()._window, scancode) == GLFW_PRESS;
}

bool InputManager::isKeyRelease(const char* keyName) const {
    int scancode = _keys.at(keyName);
    return glfwGetKey(WindowGLFW::getInstance()._window, scancode) == GLFW_RELEASE;
}


} // End namespace


