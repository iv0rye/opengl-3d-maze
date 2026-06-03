#include "ResourceManager.h"
#include "stb_image/stb_image.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::map<std::string, Shader> ResourceManager::Shaders;  
std::map<std::string, Texture> ResourceManager::Textures;

Shader& ResourceManager::SetShader(const char* vShaderFile, const char* fShaderFile, std::string shaderName)
{
    // read file
    std::string vertexCode;
    std::string fragmentCode;

    std::ifstream vertexShaderFile;
    std::ifstream fragmentShaderFile;

    vertexShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fragmentShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        // open and read into string streams
        vertexShaderFile.open(vShaderFile);
        fragmentShaderFile.open(fShaderFile);

        std::stringstream vShaderStream;
        std::stringstream fShaderStream;

        vShaderStream << vertexShaderFile.rdbuf();
        fShaderStream << fragmentShaderFile.rdbuf();

        vertexShaderFile.close();
        fragmentShaderFile.close();

        // string streams -> strings
        vertexCode = vShaderStream.str();  
        fragmentCode = fShaderStream.str(); 
    }
    catch (std::ifstream::failure& e)
    {
        std::cout << "ERROR: Shader file unsucessfully read" << std::endl;
    }

    // generate shader with c string (array of char)
    Shaders[shaderName] = Shader(vertexCode.c_str(), fragmentCode.c_str());

    return Shaders[shaderName];
}

Texture& ResourceManager::SetTexture(const char* textureFile, std::string textureName)
{
    stbi_set_flip_vertically_on_load(true);

    // create texture data
    int width, height, nrChannels;
    // TODO: handling for rgb channels rather than forcing RGBA
    unsigned char* textureData = stbi_load(textureFile, &width, &height, &nrChannels, 4);
    
    // error handling for if stbi doesnt load texture file
    if (!textureData)
        throw std::runtime_error("ERROR: Failed to load texture: " + textureName);
     
    // set texture, free memory and return texture
    Textures[textureName] = Texture(textureData, width, height);

    stbi_image_free(textureData);

    return Textures[textureName];
}

Shader& ResourceManager::GetShader(std::string shaderName)
{
    return Shaders[shaderName];
}

Texture& ResourceManager::GetTexture(std::string textureName)
{
    return Textures[textureName];
}
