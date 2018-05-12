#pragma once

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <string>

namespace ice {


/**
 * Manage a shader program.
 *
 * Inspired from learnopengl (Shader.h)
 */
class ShaderProgram {
    public:
        unsigned int ID;

    public:

        /**
         * Create a shader from its source path.
         *
         * \param 
         */
        ShaderProgram(const GLchar* vertexPath, const GLchar* fragmentPath);

        /**
         * Use / Activate the shader.
         */
        void use();


    // -------------------------------------------------------------------------
    // Set data functions
    // -------------------------------------------------------------------------

    public:

        void setBool(const std::string &name, bool value) const;
        void setInt(const std::string &name, int value) const;
        void setFloat(const std::string &name, float value) const;

        void setVec2(const std::string &name, const glm::vec2 &value) const;
        void setVec2(const std::string &name, float x, float y) const;

        void setVec3(const std::string &name, const glm::vec3 &value) const;
        void setVec3(const std::string &name, float x, float y, float z) const;

        void setVec4(const std::string &name, const glm::vec4 &value) const;
        void setVec4(const std::string &name, float x, float y, float z, float w) const;

        void setMat2(const std::string &name, const glm::mat2 &mat) const;
        void setMat3(const std::string &name, const glm::mat3 &mat) const;
        void setMat4(const std::string &name, const glm::mat4 &mat) const;
};


} // End namespace


