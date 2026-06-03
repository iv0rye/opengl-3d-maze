#include "Camera.h"
#include "Camera.h"

Camera::Camera(int width, int height, float mouseSens)
{
	Pos = glm::vec3(0.0f);
	FrontDir = glm::vec3(0.0f, 0.0f, -1.0f);
	UpDir = glm::vec3(0.0f, 1.0f, 0.0f);

	LastX = width / 2;
	LastY = height / 2;

	Pitch = 0.0f;
	Yaw = -90.0f;

	MouseSensitivity = mouseSens;

	FirstMouse = true;
}
