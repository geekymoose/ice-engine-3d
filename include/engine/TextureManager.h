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
         * Creates a new Texture and registers it in the TextureManager.
         *
         * If the Texture is already present (name already exists in the TextureManager),
         * does nothing and returns false.
         *
         * \param name Texture's name
         * \return True if added, otherwise, return false.
         */
        bool createTexture(const char* name, const char* path);

        /**
         * Gets a texture by name.
         * For now, invalid name returns an exception.
         *
         * \param name The Texture's name as registered in the TextureManager.
         */
        Texture& getTexture(const char* name);
};


} // End namespace


