#version 330 core

in vec3 vPos;
in vec3 vNormal;
in vec2 vTexCoords;

out vec4 fColor;


struct PointLight {
    vec3 position;

    vec3 ambiant;
    vec3 diffuse;
    vec3 specular;

    float attenuation_kc;
    float attenuation_kl;
    float attenuation_kq;
};


uniform vec3 eyePos;
uniform sampler2D diffuse;
uniform sampler2D specular;
uniform float shininess;
uniform PointLight light;


// -----------------------------------------------------------------------------
// Methods
// -----------------------------------------------------------------------------


// Phong Illumination. (PointLight)
// I = Ia + Id + Is
vec3 phong_illumination_point_light(PointLight light, vec3 N, vec3 E) {
    // Parameters
    vec3 l      = light.position - vPos;
    vec3 L      = normalize(l);
    float NdotL = max(dot(N, L), 0.0);
    vec3 R      = (2 * NdotL * N) - L; // R + L = 2*(N.L)
    float RdotE = max(dot(R, E), 0.0);

    // Light attenuation
    float d     = length(l);
    float la    = light.attenuation_kl * d;
    float qa    = light.attenuation_kq * d * d;
    float att   = 1.0 / (light.attenuation_kc + la + qa);

    // PHONG Ambiant: Ia = ka * ia
    float ka    = 1;
    vec3 ia     = light.ambiant * texture(diffuse, vTexCoords).rgb;
    vec3 Ia     = ka * ia;

    // PHONG Diffuse: Id = kd * (L.N) * id
    float kd    = 1;
    vec3 id     = light.diffuse * texture(diffuse, vTexCoords).rgb;
    vec3 Id     = kd * NdotL * id;

    // PHONG Specular: Is = ks * (R.E)^n * is
    float ks    = 0.5;
    vec3 is     = light.specular * texture(specular, vTexCoords).rgb;
    vec3 Is     = ks * pow(RdotE, shininess) * is;

    // PHONG Final
    return ((Ia + Id + Is) * att);
}

void main() {
    // Parameters
    vec3 N = normalize(vNormal);
    vec3 E = normalize(eyePos - vPos);

    vec3 I = phong_illumination_point_light(light, N, E);

    fColor = vec4(I, 1.0);
}

