#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aCol;

uniform float xOffset;

out vec3 Color;

void main()
{
    gl_Position = vec4(aPos.x + xOffset, -1 * aPos.y, aPos.z, 1.0);
    Color = aCol + xOffset;
}