#include "Game.h"
#include "ResourceManager.h"
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <iostream>

Game::Game(unsigned int width, unsigned int height)
{
	this->State = GAME_ACTIVE;
	this->Width = width;
	this->Height = height;
}

Game::~Game()
{
	delete Renderer;
}

void Game::Init()
{
	Shader shader = ResourceManager::SetShader(VERTEX_SHADER_PATH.c_str(), FRAGMENT_SHADER_PATH.c_str(), "object");

	ResourceManager::SetTexture("assets/textures/Concrete.png", "concrete");

	// shader config
	float fov = glm::radians(45.0f);

	glm::mat4 projection = glm::perspective(fov, (float)Width / (float)Height, 0.1f, 100.0f);

	glm::mat4 view = glm::translate(glm::mat4(1.f), glm::vec3(0.f, 0.f, -10.f));

	shader.Use();
	shader.SetInt("image", 0);
	shader.SetMat4D("projection", projection);
	shader.SetMat4D("view", view);

	Renderer = new ObjectRenderer(shader);
}

void Game::ProcessInput(float dt)
{
}

void Game::Update(float dt)
{
}

void Game::Render()
{
	Texture texture = ResourceManager::GetTexture("concrete");

	std::cout << "Shader ID: " << Renderer->GetShaderId() << std::endl;
	std::cout << "Texture ID: " << texture.GetTextureId() << std::endl;

	Renderer->DrawObject(
		texture,
		glm::vec3(0.f, 0.f, 0.f),
		glm::vec3(1.f, 1.f, 1.f),
		glm::vec3(0.5f, 0.5f, 0.5f),
		glm::vec3(1.f)
	);
}
