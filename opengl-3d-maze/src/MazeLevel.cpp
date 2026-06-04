#include "MazeLevel.h"
#include <iostream>
#include "ResourceManager.h"
#include "MazeObject.h"

void MazeLevel::Draw(ObjectRenderer& renderer, std::string shaderName)
{
	this->Baseplate.Draw(renderer, ((levelWidth + levelHeight) / 2), shaderName); // width + height / 2 finds avg size to multiply texture

	for (GameObject mazeWall : LevelObjects)
	{
		mazeWall.Draw(renderer, 2.f, shaderName);
	}
}

void MazeLevel::Load(unsigned int levelWidth, unsigned int levelHeight)
{
	std::vector<std::vector<unsigned int>> levelData = 
	{
		{1, 1, 1, 1, 1, 1, 1},
		{1, 0, 1, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 0, 1},
		{1, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 0, 1},
		{1, 1, 0, 1, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1}
	};

	MazeLevel::init(levelData, levelHeight, levelHeight);
}

void MazeLevel::init(std::vector<std::vector<unsigned int>> levelData, unsigned int levelWidth, unsigned int levelHeight)
{
	if (levelData.size() <= 0 || levelWidth <= 0 || levelHeight <= 0)
	{
		std::cout << "Could not render maze due to invalid args";
		return;
	}

	this->Baseplate = GameObject(
		ResourceManager::GetTexture("floor"),
		glm::vec3(0.0f, -2.0f, 0.0f),
		glm::vec3(levelWidth, 1.0f, levelHeight),
		glm::vec3(0.0f),
		glm::vec3(1.0f)
	);

	for (unsigned int z = 0; z < levelHeight; z++)
	{
		for (unsigned int x = 0; x < levelWidth; x++)
		{
			// if data at z/x is solid:
			if (levelData[z][x] == 1)
			{
				MazeObject mazeWall = MazeObject(
					(x * 2) + 1, // multiply coord value by 2 (size of maze wall), then offset by 1 as pos represents center of object
					(z * 2) + 1,
					ResourceManager::GetTexture("concrete")
				);

				LevelObjects.push_back(mazeWall);
			}
		}
	}
}
