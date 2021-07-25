#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition;

uniform mat4 mvp;

void main(){
    gl_Position = mvp * vec4(vertexPosition, 1.0);
}
