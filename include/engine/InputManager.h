#pragma once

#include "utils/Singleton.h"
#include "utils/log.h"

#include <unordered_map>
#include <string>

namespace ice {


class InputManager : private Singleton<InputManager> {
    private:
        InputManager() = default;
        friend Singleton<InputManager>;
    public:
        using Singleton<InputManager>::getInstance;

    private:
        bool _isInit;
        std::unordered_map<std::string, int> _keys;


    public:

        /**
         * Startup the Ice Input Manager.
         */
        void startup();

        /**
         * Shutdown the Ice Input Manager.
         */
        void shutdown();

        /**
         * Update inputs
         */
        void update();

        /**
         * Register a key to the input manager.
         * Do nothing if already exists.
         *
         * \param keyName   Name of the key to add.
         * \param scancode  Input code (ex: GLFW scancode)
         */
        void registerInput(const char* keyName, const int scancode);

        /**
         * Check whether key is pressed.
         * Undefined behavior if keyName doesn't exists.
         *
         * \param The input name
         */
        bool isKeyDown(const char* keyName) const;

        /**
         * Check whether key is released.
         * Undefined behavior if keyName doesn't exists.
         *
         * \param The input name
         */
        bool isKeyRelease(const char* keyName) const;
};


}
