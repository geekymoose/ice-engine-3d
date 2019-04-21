#pragma once

#include "WindowGLFW.h"
#include "utils/Singleton.h"

namespace ice {


/**
 * \deprecated
 * Soo awesome, we actually don't use it!!
 *
 * The awesome Ice RenderEngine!
 * Tired of Ogre? Unreal is too 'hasbeen' and unity is not OpenSource?
 * This renderer is for you! It is soo small it almost does nothing
 * but... Don't tell that.
 *
 * \date    May 2018
 * \author  Constantin Masson
 */
class RenderEngine : private Singleton<RenderEngine> {
    private:
        RenderEngine();
        friend Singleton<RenderEngine>;
    public:
        using Singleton<RenderEngine>::getInstance;

    private:
        WindowGLFW& _window;

    public:
        void startup();
        void shutdown();
        void update();
};


} // End namespace
