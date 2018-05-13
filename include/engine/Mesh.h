#pragma once

#include "ShaderProgram.h"

#include <vector>
#include <string>

namespace ice {


/**
 * Structure of a vertex data.
 *
 * position, normal, textureUV
 */
struct Vertex {
    glm::vec3   _position;
    glm::vec3   _normal;
    glm::vec2   _textureUV;
};


/**
 * Structure of a texture.
 */
struct Texture {
    unsigned int _id;
    std::string type;
};


/**
 * The famouse Mesh class!
 *
 * \date    May 2018
 * \author  Constantin Masson
 */
class Mesh {
    private:
        unsigned int VAO, VBO, EBO;


    public:
        /** List of all vertices for this Mesh. */
        std::vector<Vertex> _vertices;

        /** Indices of triangles. */
        std::vector<unsigned int> _indices;

        /** Textures. */
        std::vector<Texture> _textures;


    public:
        Mesh(std::vector<Vertex> vertices,
             std::vector<unsigned int> indices,
             std::vector<Texture> textures);

        void setup();
};


} // End namespace


