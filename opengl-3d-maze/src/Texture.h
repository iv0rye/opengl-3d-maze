#pragma once
class Texture
{
public:
	unsigned int textureId;

	Texture(unsigned char* imageData, int width, int height);

	unsigned int getTextureId();
};

