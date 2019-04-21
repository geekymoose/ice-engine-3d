#pragma once


namespace ice {


struct DirLight {
    glm::vec3 direction;

    glm::vec3 ambiant;
    glm::vec3 diffuse;
    glm::vec3 specular;
};

// Examples http://wiki.ogre3d.org/tiki-index.php?page=-Point+Light+Attenuation
struct PointLight {
    glm::vec3 position;

    glm::vec3 ambiant;
    glm::vec3 diffuse;
    glm::vec3 specular;

    float attenuation_kc;
    float attenuation_kl;
    float attenuation_kq;
};


} // End namespace


