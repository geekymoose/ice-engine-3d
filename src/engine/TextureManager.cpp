#include "engine/TextureManager.h"

#include "utils/log.h"


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

    // TODO OpenGL Texture generation
    /*
    Mesh patate(vertices, indices, textures);
    auto coco = std::make_pair(name, patate); // A mesh copy is done anyway here.
    auto res = _meshes.emplace(coco);
    return res.second; // See unordered_map doc
    */
    return false;
}

Texture& TextureManager::getTexture(const char* name) {
    return _textures.at(name);
}



} // End namespace
