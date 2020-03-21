#version 330 core

in vec3 myColor;
in vec2 myTexPos;

uniform sampler2D tex1;

void main()
{
	gl_FragColor = texture(tex1, myTexPos);
}