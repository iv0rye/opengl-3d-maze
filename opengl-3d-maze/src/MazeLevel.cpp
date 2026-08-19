#include "MazeLevel.h"
#include <iostream>
#include <algorithm>
#include <array>
#include <random>
#include <stack>
#include "ResourceManager.h"
#include "MazeObject.h"

void MazeLevel::Draw(ObjectRenderer& renderer, std::string shaderName)
{
	this->Baseplate.Draw(renderer, ((LevelWidth + LevelHeight) / 2), shaderName); // width + height / 2 finds avg size to multiply texture
	this->Roof.Draw(renderer, ((LevelWidth + LevelHeight) / 2), shaderName); // width + height / 2 finds avg size to multiply texture

	for (GameObject mazeWall : LevelObjects)
	{
		mazeWall.Draw(renderer, 2.f, shaderName);
	}
}

void MazeLevel::Load(unsigned int levelWidth, unsigned int levelHeight)
{
	LevelObjects.clear();
	std::vector<std::vector<unsigned int>> levelData = GenerateDFSLevelData(levelWidth, levelHeight);
	MazeLevel::init(levelData, static_cast<unsigned int>(levelData[0].size()), static_cast<unsigned int>(levelData.size()));
}

std::vector<std::vector<unsigned int>> MazeLevel::GenerateDFSLevelData(unsigned int levelWidth, unsigned int levelHeight) const
{
	const unsigned int mazeWidth = std::max(3u, (levelWidth % 2 == 0 ? levelWidth + 1 : levelWidth));
	const unsigned int mazeHeight = std::max(3u, (levelHeight % 2 == 0 ? levelHeight + 1 : levelHeight));
	std::vector<std::vector<unsigned int>> levelData(mazeHeight, std::vector<unsigned int>(mazeWidth, 1));
	std::stack<std::pair<unsigned int, unsigned int>> path;
	std::random_device randomDevice;
	std::mt19937 randomEngine(randomDevice());
	const std::array<std::pair<int, int>, 4> directions = { std::make_pair(0, -2), std::make_pair(2, 0), std::make_pair(0, 2), std::make_pair(-2, 0) };

	levelData[1][1] = 0;
	path.push({ 1, 1 });

	while (!path.empty())
	{
		const std::pair<unsigned int, unsigned int> current = path.top();
		std::vector<std::pair<unsigned int, unsigned int>> unvisitedNeighbors;

		for (const auto& direction : directions)
		{
			const int neighborX = static_cast<int>(current.first) + direction.first;
			const int neighborY = static_cast<int>(current.second) + direction.second;

			if (neighborX > 0
				&& neighborY > 0
				&& neighborX < static_cast<int>(mazeWidth - 1)
				&& neighborY < static_cast<int>(mazeHeight - 1)
				&& levelData[neighborY][neighborX] == 1)
			{
				unvisitedNeighbors.push_back({ static_cast<unsigned int>(neighborX), static_cast<unsigned int>(neighborY) });
			}
		}

		if (unvisitedNeighbors.empty())
		{
			path.pop();
			continue;
		}

		std::shuffle(unvisitedNeighbors.begin(), unvisitedNeighbors.end(), randomEngine);
		const std::pair<unsigned int, unsigned int> nextCell = unvisitedNeighbors.front();
		const unsigned int betweenX = (current.first + nextCell.first) / 2;
		const unsigned int betweenY = (current.second + nextCell.second) / 2;

		levelData[betweenY][betweenX] = 0;
		levelData[nextCell.second][nextCell.first] = 0;
		path.push(nextCell);
	}

	levelData[1][0] = 0;
	levelData[mazeHeight - 2][mazeWidth - 1] = 0;

	return levelData;
}

void MazeLevel::init(std::vector<std::vector<unsigned int>> levelData, unsigned int levelWidth, unsigned int levelHeight)
{
	if (levelData.size() <= 0 || levelWidth <= 0 || levelHeight <= 0)
	{
		std::cout << "Could not render maze due to invalid args";
		return;
	}

	this->LevelWidth = levelWidth;
	this->LevelHeight = levelHeight;

	this->Baseplate = GameObject(
		ResourceManager::GetTexture("floor"),
		glm::vec3(0.0f, -2.0f, 0.0f),
		glm::vec3(levelWidth, 1.0f, levelHeight),
		glm::vec3(1.0f),
		glm::vec3(0.0f),
		glm::vec3(0.0f)
	);
	this->Roof = GameObject(
		ResourceManager::GetTexture("roof"),
		glm::vec3(0.0f, 2.0f, 0.0f),
		glm::vec3(levelWidth, 1.0f, levelHeight),
		glm::vec3(1.0f),
		glm::vec3(0.0f),
		glm::vec3(0.0f)
	);
	
	for (unsigned int z = 0; z < levelData.size(); z++)
	{
		for (unsigned int x = 0; x < levelData[0].size(); x++)
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
