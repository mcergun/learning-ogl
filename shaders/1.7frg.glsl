#version 330 core

in vec3 myColor;
in vec2 myTexPos;

uniform sampler2D tex1;
uniform sampler2D tex2;

void main()
{
	// gl_FragColor = texture(tex1, myTexPos);
	gl_FragColor = mix(texture(tex1, myTexPos), texture(tex2, vec2(-myTexPos.x, myTexPos.y)), 0.2) * vec4(myColor, 1.0f); 
//	gl_FragColor = vec4(1.0f, 0.0f, 0.5f, 1.0f);
}