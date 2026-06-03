#pragma once
#include "GameObject.h"
class MazeObject :
    public GameObject
{
public:
    MazeObject() : GameObject() {};

    MazeObject(float xPos, float yPos, Texture texture);

private:
    // maze wall constants
    static const float MAZE_WALL_HEIGHT;
    static const glm::vec3 MAZE_WALL_SIZE;
};

