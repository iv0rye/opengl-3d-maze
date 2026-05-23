#pragma once
class Texture
{
public:
	Texture(unsigned char* imageData, int width, int height);

	unsigned int GetTextureId() const;

	void Bind() const;

private:
	unsigned int textureId;
};

