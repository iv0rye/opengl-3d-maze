#pragma once
#include <string>
#include <glm/glm.hpp>

class Shader
{
public:
	unsigned int ID;

	Shader(const char* vertexSource, const char* fragSource);

	void Use();

	// setters
	void SetFloat(const std::string& name, float value) const;
	void SetInt(const std::string& name, int value) const;

	void SetVec2D(const std::string& name, glm::vec2& value) const;
	void SetVec3D(const std::string& name, glm::vec3& value) const;
	void SetVec4D(const std::string& name, glm::vec4& value) const;

	void SetMat4D(const std::string& name, glm::mat4& value) const;

private:
	void CheckCompilationError(unsigned int shader, std::string type);
};

