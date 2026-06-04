#include "GameObject.h"
#include "ResourceManager.h"

GameObject::GameObject()
{
	Position = glm::vec3(0.0f);
	Size = glm::vec3(1.0f);
	Velocity = glm::vec3(0.0f);
	Colour = glm::vec3(1.0f);
	Rotation = glm::vec3(0.0f);

	CanCollide = true;
	Destroyed = false;

	ObjectTexture = Texture();
}

GameObject::GameObject(Texture texture, glm::vec3 pos, glm::vec3 size, glm::vec3 colour, glm::vec3 velocity, glm::vec3 rotation)
{
	Position = pos;
	Size = size;
	Colour = colour;
	Velocity = velocity;
	Rotation = rotation;

	CanCollide = true;
	Destroyed = false;

	ObjectTexture = texture;
}

void GameObject::Draw(ObjectRenderer& renderer)
{
	renderer.DrawObject(ObjectTexture, Position, Size, Rotation, Colour);
}

void GameObject::Draw(ObjectRenderer& renderer, float texMultiplier, std::string shaderName)
{
	ResourceManager::GetShader(shaderName).SetFloat("texMultiplier", texMultiplier);
	renderer.DrawObject(ObjectTexture, Position, Size, Rotation, Colour);
	ResourceManager::GetShader(shaderName).SetFloat("texMultiplier", 1.0f);
}
