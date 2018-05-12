#include "core/TimeManager.h"

#include "utils/log.h"

namespace ice {


void TimeManager::startup() {
    LOG << "Startup TimeManager\n";
    _currentStartFrame = Clock::now();
    _lastFixedFrame = _currentStartFrame;
}

void TimeManager::shutdown() {
    LOG << "Shutdown TimeManager\n";
}


void TimeManager::update() {
    TimePoint previous = _currentStartFrame;
    _currentStartFrame = Clock::now();

    std::chrono::duration<float> elapsed = _currentStartFrame - previous;
    std::chrono::duration<float> elapsedFixed = _currentStartFrame - _lastFixedFrame;

    _currentDeltaTime = elapsed.count();
    _currentFPS = static_cast<int>(1 / _currentDeltaTime);

    _hasFixedUpdate = false;
    if(elapsedFixed.count() >= _fixedDeltaTime) {
        _lastFixedFrame = _currentStartFrame;
        _hasFixedUpdate = true;
    }
}


} // End namespace
