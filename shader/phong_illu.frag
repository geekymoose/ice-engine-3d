#version 330 core

in vec3 vPos;
in vec3 vNormal;
in vec2 vTexCoords;

out vec4 fColor;


uniform sampler2D diffuse;
uniform sampler2D specular;


// -----------------------------------------------------------------------------
// Methods
// -----------------------------------------------------------------------------

void main() {
    //fColor = vec4(0.2, 0.9, 0.4, 1.0);

    //TODO TMP
    fColor = mix(texture(diffuse, vTexCoords), texture(specular, vTexCoords), 0.2);
}

