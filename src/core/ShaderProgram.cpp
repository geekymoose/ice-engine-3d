#include "core/ShaderProgram.h"

#include "utils/log.h"

#include <cassert>
#include <fstream>
#include <sstream>
#include <iostream>

namespace ice {


ShaderProgram::ShaderProgram(const GLchar* vertexPath, const GLchar* fragmentPath) {
    // Retrieve the vertex/fragment source code from filePath
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    // Ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        std::stringstream vShaderStream, fShaderStream;

        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);

        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        vShaderFile.close();
        fShaderFile.close();

        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch(std::ifstream::failure e) {
        LOG << "[ERROR::SHADER] Unable to read file.";
    }

    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    // Compile shaders
    unsigned int vertex, fragment;
    int success;
    char infoLog[512];

    // Vertex Shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        LOG << "[ERROR::SHADER::VERTEX] Compilation failed\n" << infoLog << "\n";
    };

    // Fragment Shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        LOG << "[ERROR::SHADER::FRAGMENT] Compilation failed\n" << infoLog << "\n";
    };

    // Shader Program
    this->ID = glCreateProgram();
    glAttachShader(this->ID, vertex);
    glAttachShader(this->ID, fragment);
    glLinkProgram(this->ID);
    glGetProgramiv(this->ID, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(this->ID, 512, NULL, infoLog);
        LOG << "[ERROR::SHADER] Linking failed\n" << infoLog << "\n";
    }

    // delete the shaders as they're linked into our program now and no longer necessery
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void ShaderProgram::use() {
    glUseProgram(this->ID);
}

void ShaderProgram::setBool(const std::string &name, bool value) const {
    GLint id = glGetUniformLocation(ID, name.c_str());
    assert(id != -1);
    glUniform1i(id, (int)value);
}

void ShaderProgram::setInt(const std::string &name, int value) const {
    GLint id = glGetUniformLocation(ID, name.c_str());
    assert(id != -1);
    glUniform1i(id, value);
}

void ShaderProgram::setFloat(const std::string &name, float value) const {
    GLint id = glGetUniformLocation(ID, name.c_str());
    assert(id != -1);
    glUniform1f(id, value);
}

void ShaderProgram::setVec2(const std::string &name, const glm::vec2 &value) const {
    GLint id = glGetUniformLocation(ID, name.c_str());
    assert(id != -1);
    glUniform2fv(id, 1, &value[0]);
}

void ShaderProgram::setVec2(const std::string &name, float x, float y) const {
    GLint id = glGetUniformLocation(ID, name.c_str());
    assert(id != -1);
    glUniform2f(id, x, y);
}

void ShaderProgram::setVec3(const std::string &name, const glm::vec3 &value) const {
    GLint id = glGetUniformLocation(ID, name.c_str());
    assert(id != -1);
    glUniform3fv(id, 1, &value[0]);
}

void ShaderProgram::setVec3(const std::string &name, float x, float y, float z) const {
    GLint id = glGetUniformLocation(ID, name.c_str());
    assert(id != -1);
    glUniform3f(id, x, y, z);
}

void ShaderProgram::setVec4(const std::string &name, const glm::vec4 &value) const {
    GLint id = glGetUniformLocation(ID, name.c_str());
    assert(id != -1);
    glUniform4fv(id, 1, &value[0]);
}

void ShaderProgram::setVec4(const std::string &name, float x, float y, float z, float w) const {
    GLint id = glGetUniformLocation(ID, name.c_str());
    assert(id != -1);
    glUniform4f(id, x, y, z, w);
}

void ShaderProgram::setMat2(const std::string &name, const glm::mat2 &mat) const {
    GLint id = glGetUniformLocation(ID, name.c_str());
    assert(id != -1);
    glUniformMatrix2fv(id, 1, GL_FALSE, &mat[0][0]);
}

void ShaderProgram::setMat3(const std::string &name, const glm::mat3 &mat) const {
    GLint id = glGetUniformLocation(ID, name.c_str());
    assert(id != -1);
    glUniformMatrix3fv(id, 1, GL_FALSE, &mat[0][0]);
}

void ShaderProgram::setMat4(const std::string &name, const glm::mat4 &mat) const {
    GLint id = glGetUniformLocation(ID, name.c_str());
    assert(id != -1);
    glUniformMatrix4fv(id, 1, GL_FALSE, &mat[0][0]);
}


} // End namespace


