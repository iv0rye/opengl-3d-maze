#include "Shader.h"
#include <glad/glad.h>

Shader::Shader(const char* vertexSource, const char* fragSource)
{
	unsigned int vertex;
	unsigned int fragment;
	int success;
	char infoLog[512];

	// generate vertex shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vertexSource, NULL);
	glCompileShader(vertex);

	// generate fragment shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fragSource, NULL);
	glCompileShader(fragment);

	// generate shader
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);

	glLinkProgram(ID);

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void Shader::use()
{
	glUseProgram(ID);
}

void Shader::setFloat(const std::string& name, float& value) const
{
}

void Shader::setInt(const std::string& name, int& value) const
{
}

void Shader::setVec1D(const std::string& name, glm::vec1& value) const
{
}

void Shader::setVec2D(const std::string& name, glm::vec2& value) const
{
}

void Shader::setVec3D(const std::string& name, glm::vec3& value) const
{
}

void Shader::setVec4D(const std::string& name, glm::vec4& value) const
{
}

void Shader::setMat4D(const std::string& name, glm::mat4& value) const
{
}

void Shader::checkCompilationError(unsigned int shader, std::string type)
{
}
