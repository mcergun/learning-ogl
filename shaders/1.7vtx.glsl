#version 330 core

layout (location = 0) in vec3 vtxPos;
layout (location = 1) in vec3 vtxCol;
layout (location = 2) in vec2 vtxTexPos;

uniform mat4 transform;

out vec3 myColor;
out vec2 myTexPos;

void main()
{
    gl_Position = transform * vec4(vtxPos, 1.0f);
    myColor = ((gl_Position.xyz / 2 + 1) + vtxCol) / 2;
    myTexPos = vtxTexPos;
}