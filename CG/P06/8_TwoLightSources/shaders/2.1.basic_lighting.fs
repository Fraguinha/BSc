#version 330 core
out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;

uniform vec3 lightPos1;
uniform vec3 lightColor1;
uniform vec3 lightPos2;
uniform vec3 lightColor2;
uniform vec3 objectColor;
uniform vec3 viewPos;

void main()
{
    // ambient
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor1 * lightColor2;

    // diffuse 1
    vec3 norm1 = normalize(Normal);
    vec3 lightDir1 = normalize(lightPos1 - FragPos);
    float diff1 = max(dot(norm1, lightDir1), 0.0);
    vec3 diffuse1 = diff1 * lightColor1;

    // diffuse 2
    vec3 norm2 = normalize(Normal);
    vec3 lightDir2 = normalize(lightPos2 - FragPos);
    float diff2 = max(dot(norm2, lightDir2), 0.0);
    vec3 diffuse2 = diff2 * lightColor2;


    // specular
    float specularStrength1 = 0.5;
    vec3 viewDir1 = normalize(viewPos - FragPos);
    vec3 reflectDir1 = reflect(-lightDir1, norm1);
    float spec1 = pow(max(dot(viewDir1, reflectDir1), 0.0), 32);
    vec3 specular1 = specularStrength1 * spec1 * lightColor1;

    // specular
    float specularStrength2 = 0.5;
    vec3 viewDir2 = normalize(viewPos - FragPos);
    vec3 reflectDir2 = reflect(-lightDir2, norm2);
    float spec2 = pow(max(dot(viewDir2, reflectDir2), 0.0), 32);
    vec3 specular2 = specularStrength2 * spec2 * lightColor2;

    vec3 result = (ambient + diffuse1 + diffuse2 + specular1 + specular2) * objectColor;
    FragColor = vec4(result, 1.0);
}
