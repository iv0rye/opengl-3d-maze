#pragma once
#include "src/Shader.h"
class ObjectRenderer
{
public:
	ObjectRenderer(Shader& shader);
	~ObjectRenderer();

private:
	Shader shader;
	unsigned int quadVAO;

	void initRenderData();
};

