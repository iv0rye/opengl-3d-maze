#pragma once
#include <string>
#include <glm/glm.hpp>

class Shader
{
public:
	unsigned int ID;

	Shader(const char* vertexSource, const char* fragSource);

	void use();

	// setters
	void setFloat(const std::string& name, float& value) const;
	void setInt(const std::string& name, int& value) const;

	void setVec1D(const std::string& name, glm::vec1& value) const;
	void setVec2D(const std::string& name, glm::vec2& value) const;
	void setVec3D(const std::string& name, glm::vec3& value) const;
	void setVec4D(const std::string& name, glm::vec4& value) const;

	void setMat4D(const std::string& name, glm::mat4& value) const;

	void checkCompilationError(unsigned int shader, std::string type);
};

