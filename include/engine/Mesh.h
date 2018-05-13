#pragma once

#include <glm/glm.hpp>
#include <vector>
#include <string>

namespace ice {

class ShaderProgram;


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
        unsigned int _VAO;
        unsigned int _VBO;
        unsigned int _EBO;


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

    private:

        /**
         * Load all GPU data to render this mesh.
         */
        void setup(); // interan call

        /**
         * Draw Mesh using given ShaderProgram.
         */
        void draw(ShaderProgram& shaderProgram) const;
};


} // End namespace


