#version 330 core

layout (location = 0) in vec3 vtxPos;
layout (location = 1) in vec2 vtxTexPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 myColor;
out vec2 myTexPos;

void main()
{
    gl_Position = projection * view * model * vec4(vtxPos, 1.0f);
    myColor = (gl_Position.xyz / 2 + 1);
    myTexPos = vtxTexPos;
}