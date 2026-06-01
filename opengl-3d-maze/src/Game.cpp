#include "Game.h"
#include "ResourceManager.h"
#include <glm/ext/matrix_clip_space.hpp>

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

	// shader config
	float fov = glm::radians(45.0f);

	glm::mat4 projection = glm::perspective(fov, (float)Width / (float)Height, 0.1f, 100.0f);
	glm::mat4 view = glm::mat4(0.0f);

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
}
