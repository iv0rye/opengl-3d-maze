#include "ResourceManager.h"

ResourceManager::ResourceManager() {}

Shader ResourceManager::SetShader(const char* vShaderFile, const char* fShaderFile, std::string shaderName)
{
    return Shader();
}

Texture ResourceManager::SetTexture(const char* textureFile, std::string textureName)
{
    return Texture();
}

Shader ResourceManager::GetShader(std::string shaderName)
{
    return Shaders[shaderName];
}

Texture ResourceManager::GetTexture(std::string textureName)
{
    return Textures[textureName];
}
