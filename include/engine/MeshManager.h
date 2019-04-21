#pragma once

#include "Mesh.h"
#include "utils/Singleton.h"

#include <unordered_map>
#include <string>

namespace ice {


/**
 * Manager for all the loaded meshes.
 *
 * \date    May 2018
 * \author  Constantin Masson
 */
class MeshManager : Singleton<MeshManager> {
    private:
        MeshManager() = default;
        friend Singleton<MeshManager>;
    public:
        using Singleton<MeshManager>::getInstance;

    private:
        std::unordered_map<std::string, Mesh> _meshes;


    public:
        void startup();
        void shutdown();


    public:
        /**
         * Creates a new mesh and register it in this MeshManager.
         *
         * If mesh is already present (name already exists in MeshManager),
         * does nothing and returns false.
         *
         * Warning: everything is passed by copy.
         * We may thing of better ways (but GameJam style guys)!
         *
         * \param name Mesh name
         * \param vertices
         * \param indices
         * \param textures
         * \return True if added, otherwise, return false.
         */
        bool createMesh(const char* name,
                        std::vector<Vertex> vertices,
                        std::vector<unsigned int> indices,
                        std::vector<Texture> textures);


        /**
         * Gets mesh by name.
         * For now, invalid name returns an exception.
         *
         * \param name The Mesh name as registered in the MeshManager.
         */
        Mesh& getMesh(const char* name);
};


} // End namespace
