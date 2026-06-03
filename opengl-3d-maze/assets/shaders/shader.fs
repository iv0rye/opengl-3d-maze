#version 330 core

in vec2 texCoords;
out vec4 colour;

uniform sampler2D image;
uniform vec3 objectColour;
uniform float texMultiplier;

void main()
{
	colour = vec4(objectColour, 1.0) * texture(image, texCoords * texMultiplier);
}
