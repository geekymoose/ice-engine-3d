#include "engine/MeshManager.h"

#include "utils/log.h"

#include <utility> // std::pair

namespace ice {


void MeshManager::startup() {
    LOG << "Startup MeshManager\n";
    _meshes.clear();
    // Things to do?
}

void MeshManager::shutdown() {
    LOG << "Shutdown MeshManager\n";
    _meshes.clear();
    // Things to do?
}

bool MeshManager::createMesh(const char* name,
                             std::vector<Vertex> vertices,
                             std::vector<unsigned int> indices,
                             std::vector<Texture> textures) {
    LOG << "MeshManager: register new mesh: " << name << "\n";
    Mesh patate(vertices, indices, textures);
    auto coco = std::make_pair(name, patate); // A mesh copy is done anyway here.
    auto res = _meshes.emplace(coco);
    return res.second; // See unordered_map doc
}

Mesh& MeshManager::getMesh(const char* name) {
    return _meshes.at(name);
}



} // End namespace
