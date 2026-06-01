#pragma once
#include "Shader.h"
class ObjectRenderer
{
public:
	ObjectRenderer(Shader& shader);
	~ObjectRenderer();

private:
	Shader shader;
	unsigned int VAO;

	void initRenderData();
};

