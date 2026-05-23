#pragma once
#include <map>
#include <string>
#include "Shader.h"
#include "Texture.h"

// singleton class -> all methods static, constructor private!
class ResourceManager
{
public:
	static std::map<std::string, Shader> Shaders;
	static std::map<std::string, Texture> Textures;

	static Shader GetShader(std::string shaderName);
	static Texture GetTexture(std::string textureName);

	// set from file paths into shader/texture data (shader code string, texture data byte array)
	static Shader SetShader(const char* vShaderFile, const char* fShaderFile, std::string shaderName);
	static Texture SetTexture(const char* textureFile, std::string textureName);
private:
	ResourceManager() {}
};

