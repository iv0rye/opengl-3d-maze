#pragma once
class Texture
{
public:
	Texture(unsigned char* imageData, int width, int height);

	unsigned int getTextureId();

private:
	unsigned int textureId;
};

