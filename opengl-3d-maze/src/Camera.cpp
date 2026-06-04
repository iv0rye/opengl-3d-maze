#include "Camera.h"
#include "Camera.h"
#include <glm/trigonometric.hpp>
#include <glm/ext/matrix_transform.hpp>

Camera::Camera(int width, int height, float mouseSens, float movementSens)
{
	// TODO: ideally this value should default to 0, but for testing purposes I want the player to spawn in the maze.
	Pos = glm::vec3(3.0f, 0.0f, 3.0f);
	FrontDir = glm::vec3(0.0f, 0.0f, 1.0f);
	Yaw = 90.0f;

	//Pos = glm::vec3(0.0f);
	//FrontDir = glm::vec3(0.0f, 0.0f, -1.0f);
	UpDir = glm::vec3(0.0f, 1.0f, 0.0f);

	LastX = width / 2;
	LastY = height / 2;

	Pitch = 0.0f;
	//Yaw = -90.0f;

	MouseSensitivity = mouseSens;
	MovementSensitivity = movementSens;

	FirstMouse = true;
}

void Camera::ProcessKeyboard(GLFWwindow* window, float dt)
{
	const float cameraSpeed = MovementSensitivity * dt;

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	// camera movement
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		Pos += glm::normalize(glm::vec3(FrontDir.x, 0.0f, FrontDir.z)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		Pos -= glm::normalize(glm::vec3(FrontDir.x, 0.0f, FrontDir.z)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	// We get a right facing vector with cross product (ensure normalised)
		Pos -= glm::normalize(glm::cross(glm::normalize(glm::vec3(FrontDir.x, 0.0f, FrontDir.z)), UpDir)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		Pos += glm::normalize(glm::cross(glm::normalize(glm::vec3(FrontDir.x, 0.0f, FrontDir.z)), UpDir)) * cameraSpeed;
}

void Camera::ProcessMouse(GLFWwindow* window, double xpos, double ypos)
{
	// prevent mouse jumping with initial mouse read (sets offsets to 0 effectively)
	if (FirstMouse)
	{
		LastX = xpos;
		LastY = ypos;
		FirstMouse = false;
	}

	// calculate offset of mouse movement in 2d window
	float xOffset = xpos - LastX;
	float yOffset = LastY - ypos;
	LastX = xpos;
	LastY = ypos;

	// multiply offset by a sensitivity value
	const float sensitivity = 0.1f;
	xOffset *= sensitivity;
	yOffset *= sensitivity;

	// add offset to yaw/pitch angles
	Yaw += xOffset;
	Pitch += yOffset;

	// clamp
	Pitch = std::max(-89.0f, std::min(Pitch, 89.0f));

	// calculate direction
	glm::vec3 direction;

	direction.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	direction.y = sin(glm::radians(Pitch));
	direction.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));

	FrontDir = glm::normalize(direction);
}

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(Pos, Pos + FrontDir, UpDir);
}
