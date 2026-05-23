#include "ResourceManager.h"
#include "stb_image/stb_image.h"
#include <iostream>

ResourceManager::ResourceManager() {}

Shader ResourceManager::SetShader(const char* vShaderFile, const char* fShaderFile, std::string shaderName)
{
    return Shader();
}

Texture ResourceManager::SetTexture(const char* textureFile, std::string textureName)
{
    stbi_set_flip_vertically_on_load(true);

    int width, height, nrChannels;
    unsigned char* textureData = stbi_load(textureFile, &width, &height, &nrChannels, 0);

    if (!textureData)
        throw std::runtime_error("ERROR: Failed to load texture: " + textureName);
       
    Textures[textureName] = Texture(textureData, width, height);

    stbi_image_free(textureData);

    return Textures[textureName];
}

Shader ResourceManager::GetShader(std::string shaderName)
{
    return Shaders[shaderName];
}

Texture ResourceManager::GetTexture(std::string textureName)
{
    return Textures[textureName];
}
