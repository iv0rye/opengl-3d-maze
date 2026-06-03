#pragma once

#include <glm/ext/vector_float3.hpp>
#include <glm/ext/matrix_float4x4.hpp>

class Camera
{
public:
	// 3 vectors to form lookat matrix
	glm::vec3 Pos;
	glm::vec3 FrontDir;
	glm::vec3 UpDir;

	// mouse movement related
	float LastX, LastY, Pitch, Yaw;

	float CameraSpeed, MouseSensitivity;

	bool FirstMouse;

	Camera(int width = 800, int height = 400, float mouseSens = 0.1f);
};

