#include "Shader.h"
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
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
	CheckCompilationError(vertex, "VERTEX");

	// generate fragment shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fragSource, NULL);
	glCompileShader(fragment);
	CheckCompilationError(vertex, "FRAGMENT");

	// generate shader
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);

	glLinkProgram(ID);
	CheckCompilationError(vertex, "PROGRAM");

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void Shader::Use()
{
	glUseProgram(ID);
}

void Shader::SetFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::SetInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::SetVec2D(const std::string& name, glm::vec2& value) const
{
	glUniform2f(glGetUniformLocation(ID, name.c_str()), value.x, value.y);
}

void Shader::SetVec3D(const std::string& name, glm::vec3& value) const
{
	glUniform3f(glGetUniformLocation(ID, name.c_str()), value.x, value.y, value.z);
}

void Shader::SetVec4D(const std::string& name, glm::vec4& value) const
{
	glUniform4f(glGetUniformLocation(ID, name.c_str()), value.x, value.y, value.z, value.w);
}

void Shader::SetMat4D(const std::string& name, glm::mat4& value) const
{
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, false, glm::value_ptr(value));
}

void Shader::CheckCompilationError(unsigned int shader, std::string type)
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
