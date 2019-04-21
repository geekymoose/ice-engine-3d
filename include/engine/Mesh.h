#pragma once

#include "Texture.h"

#include <glm/glm.hpp>
#include <vector>
#include <string>


namespace ice {

class ShaderProgram;


/**
 * Structure of a vertex data.
 * Vertex3P3N2UV (position, normal, textureUV)
 */
struct Vertex {
    glm::vec3   _position;
    glm::vec3   _normal;
    glm::vec2   _textureUV;
};


/**
 * The famous Mesh class!
 *
 * \date    May 2018
 * \author  Constantin Masson
 */
class Mesh {
    private:
        unsigned int _VAO;
        unsigned int _VBO;
        unsigned int _EBO;


    private:
        std::vector<Vertex>         _vertices;
        std::vector<unsigned int>   _indices;
        std::vector<Texture>        _textures;


    public:
        Mesh(std::vector<Vertex> vertices,
             std::vector<unsigned int> indices,
             std::vector<Texture> textures);

    private:

        /**
         * Loads all the GPU data required to render this mesh.
         */
        void setup(); // Internal call

    public:

        /**
         * Draws this mesh using the given ShaderProgram.
         */
        void draw(ShaderProgram& shaderProgram);
};


} // End namespace


