#include "engine/TextureManager.h"
#include "engine/ShaderProgram.h"

#include "utils/log.h"

#include <stb/stb_image.h>
#include <utility> // std::pair

namespace ice {


void TextureManager::startup() {
    LOG << "Startup TextureManager\n";
    _textures.clear();
}

void TextureManager::shutdown() {
    LOG << "Shutdown TextureManager\n";
    _textures.clear();
}

bool TextureManager::createTexture(const char* name, const char* path) {
    LOG << "TextureManager: register new texture: " << name << "\n";

    unsigned int texture;
    glGenTextures(1, &texture);

    int width, height, channels;
    unsigned char* data = stbi_load(path, &width, &height, &channels, 0);

    if(data != nullptr) {
        GLenum format;
        switch(channels) {
            case 1:
                format = GL_RED;
                break;
            case 3:
                format = GL_RGB;
                break;
            case 4:
                format = GL_RGBA;
                break;
        }

        glBindTexture(GL_TEXTURE_2D, texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        LOG << "Unable to load texture (" << path << ")\n";
    }
    stbi_image_free(data);

    Texture tx = {texture};
    auto coco = std::make_pair(name, tx);
    auto res = _textures.emplace(coco);
    return res.second; // See unordered_map doc
}

Texture& TextureManager::getTexture(const char* name) {
    return _textures.at(name);
}



} // End namespace
