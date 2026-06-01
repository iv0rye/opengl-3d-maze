#pragma once
#include "Shader.h"
#include "Texture.h"
class ObjectRenderer
{
public:
	ObjectRenderer(Shader& shader);
	~ObjectRenderer();

	void DrawSprite(
		Texture& texture,
		glm::vec3 position,
		glm::vec3 size = glm::vec3(10.0f),
		glm::vec3 rotate = glm::vec3(0.0f),
		glm::vec3 colour = glm::vec3(1.0f),
	);

private:
	Shader shader;
	unsigned int VAO;

	void initRenderData();
};

