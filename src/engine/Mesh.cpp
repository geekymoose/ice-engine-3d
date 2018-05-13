#include "engine/Mesh.h"

#include "engine/ShaderProgram.h"

#include <cstddef>

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
    glGenVertexArrays(1, &_VAO);
    glGenBuffers(1, &_VBO);
    glGenBuffers(1, &_EBO);

    glBindVertexArray(_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);

    auto sizeVertices = _vertices.size() * sizeof(Vertex);
    auto sizeIndices = _indices.size() * sizeof(unsigned int);

    glBufferData(GL_ARRAY_BUFFER, sizeVertices, &_vertices[0], GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeIndices, &_indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    void* offset0 = (void*) offsetof(Vertex, _position);
    void* offset1 = (void*) offsetof(Vertex, _normal);
    void* offset2 = (void*) offsetof(Vertex, _textureUV);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), offset0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), offset1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), offset2);

    // Cleanup
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Mesh::draw(ShaderProgram& shaderProgram) {
    shaderProgram.use();

    // Hard coded: we know there is always 2 textures (diffuse, specular)
    Texture& t1 = _textures.at(0);
    Texture& t2 = _textures.at(1);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, t1._id);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, t2._id);

    glBindVertexArray(_VAO);

    // Note: since using EBO, size should actually be smaller that this: todo
    glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}


} // End namespace


