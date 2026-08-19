#pragma once
#include "GameLevel.h"
class MazeLevel :
    public GameLevel
{
public:
	GameObject Baseplate;
	GameObject Roof;

	void Draw(ObjectRenderer& renderer, std::string shaderName);

	virtual void Load(unsigned int levelWidth, unsigned int levelHeight) override;

protected:
	std::vector<std::vector<unsigned int>> GenerateDFSLevelData(unsigned int levelWidth, unsigned int levelHeight) const;
	virtual void init(std::vector<std::vector<unsigned int>> levelData, unsigned int levelWidth, unsigned int levelHeight) override;

	unsigned int LevelWidth;
	unsigned int LevelHeight;
};
