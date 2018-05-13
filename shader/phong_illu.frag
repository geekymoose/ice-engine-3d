#version 330 core

in vec3 vPos;
in vec3 vNormal;
in vec2 vTexCoords;

out vec4 fColor;


uniform sampler2D texture1;
uniform sampler2D texture2;


// -----------------------------------------------------------------------------
// Methods
// -----------------------------------------------------------------------------

void main() {
    //fColor = vec4(0.2, 0.9, 0.4, 1.0);

    //TODO TMP
    fColor = texture(texture1, vTexCoords);
}

