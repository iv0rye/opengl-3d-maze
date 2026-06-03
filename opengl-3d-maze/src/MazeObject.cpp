#include "MazeObject.h"

const float MazeObject::MAZE_WALL_HEIGHT = 1.0f;
const glm::vec3 MazeObject::MAZE_WALL_SIZE = glm::vec3(5.f, 6.f, 5.f);

MazeObject::MazeObject(float xPos, float zPos, Texture texture)
{
	Position = glm::vec3(xPos, MAZE_WALL_HEIGHT, zPos);
	Size = MAZE_WALL_SIZE;

	Colour = glm::vec3(1.f);
	Velocity = glm::vec3(0.f);
	Rotation = glm::vec3(0.f);

	CanCollide = true;
	Destroyed = false;

	ObjectTexture = texture;
}
