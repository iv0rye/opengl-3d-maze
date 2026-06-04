#pragma once
#include <vector>
#include "GameObject.h"
// ABC of game level
class GameLevel
{
public:
	std::vector<GameObject> LevelObjects;

	GameLevel() {};

	virtual void Draw(ObjectRenderer& renderer);

	virtual void Load(const char* file, unsigned int levelWidth, unsigned int levelHeight);
	// below function mainly exists to support auto gen levels not needing a file input
	virtual void Load(unsigned int levelWidth, unsigned int levelHeight);

protected:
	// init class that intialises a level, which is abstract.
	virtual void init(
		std::vector<std::vector<unsigned int>> levelData,
		unsigned int levelWidth,
		unsigned int levelHeight
	) = 0;
};


