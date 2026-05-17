#include "Shader.h"
#include <glad/glad.h>
#include <iostream>

Shader::Shader(const char* vertexSource, const char* fragSource)
{
	// TODO: implement geography shader source (havent learnt what that is)

	// declare shader ids
	unsigned int vertex;
	unsigned int fragment;

	// generate vertex shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vertexSource, NULL);
	glCompileShader(vertex);
	checkCompilationError(vertex, "VERTEX");

	// generate fragment shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fragSource, NULL);
	glCompileShader(fragment);
	checkCompilationError(vertex, "FRAGMENT");

	// generate shader
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);

	glLinkProgram(ID);
	checkCompilationError(vertex, "PROGRAM");

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
	int success;
	char infoLog[512];

	if (type != "PROGRAM")
	{	
		// if getting shader successful, no compile-time error and return early, otherwise print error
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

		if (success)
			return;

		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "error: compilation error on type: " + type + "\n" + infoLog << std::endl;
	}
	else
	{
		// if getting program successful, no link-time error and return early, otherwise print error
		glGetProgramiv(shader, GL_LINK_STATUS, &success);

		if (success)
			return;

		glGetProgramInfoLog(shader, 512, NULL, infoLog);
		std::cout << "error: link-time error on type: " + type + "\n" + infoLog << std::endl;
	}
}
