#pragma once
#include "GameObject.h"
class MazeObject :
    public GameObject
{
public:
    MazeObject(float xPos, float yPos, Texture texture);

private:
    // maze wall constants
    const float MAZE_WALL_HEIGHT = 1.0f;
    const glm::vec3 MAZE_WALL_SIZE = glm::vec3(5.f, 6.f, 5.f);
};

