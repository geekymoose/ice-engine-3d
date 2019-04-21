#include "engine/RenderEngine.h"

#include "utils/log.h"


namespace ice {


RenderEngine::RenderEngine() : _window(WindowGLFW::getInstance()) {
    // Best component ever!
}

void RenderEngine::startup() {
    LOG << "Startup Render engine\n";
}

void RenderEngine::shutdown() {
    LOG << "Shutdown Render engine\n";
}


} // End namespace


