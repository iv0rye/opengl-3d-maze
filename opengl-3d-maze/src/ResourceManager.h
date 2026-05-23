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

private:
	ResourceManager() {}
};

