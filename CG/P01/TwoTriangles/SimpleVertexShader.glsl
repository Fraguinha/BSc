#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexColor;

out vec3 fragmentColor;

void main(){

    gl_Position.xyz = vertexPosition;
    gl_Position.w = 1.0;

    fragmentColor = vertexColor;
}
