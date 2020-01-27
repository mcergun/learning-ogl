#version 330 core

layout (location = 0) in vec3 vtxPos;
layout (location = 1) in vec3 vtxCol;
layout (location = 2) in vec2 vtxTexPos;

uniform float xOffset;

out vec3 myColor;
out vec2 myTexPos;

void main()
{
    gl_Position = vec4(vtxPos.x + xOffset, -1 * vtxPos.y, vtxPos.z, 1.0);
    myColor = vtxCol + xOffset;
    myTexPos = vtxTexPos;
}