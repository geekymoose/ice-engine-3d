#pragma once

#include "Mesh.h"
#include "utils/Singleton.h"

#include <unordered_map>
#include <string>

namespace ice {


/**
 * Manager for all loaded meshes.
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
         * Create new mesh and register it in MeshManager.
         *
         * If mesh is already present (Name already exists in MeshManager),
         * do nothing and return false.
         *
         * Dev note: everything is passed by copy.
         * We may thing of better ways. (But GameJam Style guys!)
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
         * Get mesh by name.
         * For now, unvalid name return an execption.
         *
         * \param name The Mesh name as registered in the MeshManager.
         */
        const Mesh& getMesh(const char* name) const;
};


} // End namespace
