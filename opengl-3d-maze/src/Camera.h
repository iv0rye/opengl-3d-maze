#pragma once

#include <glm/ext/vector_float3.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include <GLFW/glfw3.h>

class Camera
{
public:
	// 3 vectors to form lookat matrix
	glm::vec3 Pos;
	glm::vec3 FrontDir;
	glm::vec3 UpDir;

	// mouse movement related
	float LastX, LastY, Pitch, Yaw;

	float MouseSensitivity;
	float MovementSensitivity;

	bool FirstMouse;

	Camera(int width = 800, int height = 400, float mouseSens = 0.1f, float movementSens = 3.5f);

	void ProcessKeyboard(GLFWwindow* window, float dt);

	void ProcessMouse(GLFWwindow* window, double xpos, double ypos);

	glm::mat4 GetViewMatrix();
};

