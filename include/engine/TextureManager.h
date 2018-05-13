#pragma once

#include "Texture.h"
#include "utils/Singleton.h"

#include <unordered_map>
#include <string>


namespace ice {


/**
 * The texture manager.
 *
 * \date    May 2018
 * \author  Constantin Masson
 */
class TextureManager : private Singleton<TextureManager> {
    private:
        TextureManager() = default;
        friend Singleton<TextureManager>;
    public:
        using Singleton<TextureManager>::getInstance;

    private:
        std::unordered_map<std::string, Texture> _textures;


    public:
        void startup();
        void shutdown();


    public:
        /**
         * Create new Texture and register it in TextureManager.
         *
         * If Texture is already present (Name already exists in TextureManager),
         * do nothing and return false.
         *
         * \param name Texture's name
         * \return True if added, otherwise, return false.
         */
        bool createTexture(const char* name, const char* path);

        /**
         * Get texture by name.
         * For now, unvalid name return an execption.
         *
         * \param name The Texture's name as registered in the TextureManager.
         */
        Texture& getTexture(const char* name);
};


} // End namespace
