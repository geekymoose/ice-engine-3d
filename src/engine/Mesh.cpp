#include "engine/Mesh.h"

namespace ice {


Mesh::Mesh(std::vector<Vertex> vertices,
           std::vector<unsigned int> indices,
           std::vector<Texture> textures) 
                : _vertices(vertices),
                  _indices(indices),
                  _textures(textures) {
    this->setup();
}

void Mesh::setup() {
    // TODO
}


} // End namespace
