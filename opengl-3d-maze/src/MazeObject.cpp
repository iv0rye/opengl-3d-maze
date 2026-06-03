#include "MazeObject.h"

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
