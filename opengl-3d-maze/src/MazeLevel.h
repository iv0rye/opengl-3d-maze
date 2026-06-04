#pragma once
#include "GameLevel.h"
class MazeLevel :
    public GameLevel
{
public:
	GameObject Baseplate;

	void Draw(ObjectRenderer& renderer, std::string shaderName);

protected:
	void init(std::vector<std::vector<unsigned int>> levelData, unsigned int levelWidth, unsigned int levelHeight) override;
};

