#include "GameLevel.h"

#include <fstream>
#include <sstream>

void GameLevel::Draw(ObjectRenderer& renderer)
{
	for (GameObject& object : LevelObjects)
	{
		object.Draw(renderer);
	}
}

void GameLevel::Load(const char* file, unsigned int levelWidth, unsigned int levelHeight)
{
	LevelObjects.clear();

	// load data from file
	unsigned int objectValue;
	std::string line;
	std::ifstream fstream(file);
	std::vector<std::vector<unsigned int>> objectData;

	if (!fstream)
		return;

	// get each line -> word then push into object data
	while (std::getline(fstream, line))
	{
		std::istringstream sstream(line);
		std::vector<unsigned int> row;

		while (sstream >> objectValue)
			row.push_back(objectValue);

		objectData.push_back(row);
	}

	if (objectData.size() > 0)
		init(objectData, levelWidth, levelHeight);
}

void GameLevel::Load(unsigned int levelWidth, unsigned int levelHeight)
{
	LevelObjects.clear();
	
	std::vector<std::vector<unsigned int>> objectData;

	init(objectData, levelWidth, levelHeight);
}
