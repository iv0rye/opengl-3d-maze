#include "Game.h"
#include "ResourceManager.h"
#include "MazeObject.h"
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
	ResourceManager::SetTexture("assets/textures/Floor.png", "floor");

	// shader config
	float fov = glm::radians(70.0f);

	glm::mat4 projection = glm::perspective(fov, (float)Width / (float)Height, 0.1f, 100.0f);

	glm::mat4 view = glm::mat4(1.f);

	shader.Use();
	shader.SetInt("image", 0);
	shader.SetMat4D("projection", projection);
	shader.SetMat4D("view", view);
	shader.SetFloat("texMultiplier", 1.0f);

	Renderer = new ObjectRenderer(shader);

	// testing maze wall
	MazeWall = MazeObject(5.f, 5.f, ResourceManager::GetTexture("concrete"));

	AMazeLevel = MazeLevel();
	AMazeLevel.Load(100.f, 100.f);
}

void Game::ProcessInput(float dt)
{
}

void Game::Update(float dt)
{
}

void Game::Render()
{
	AMazeLevel.Draw(*Renderer, "object");
}

// camera class testing purposes
void Game::SetViewMatrix(glm::mat4 view)
{
	Shader shader = ResourceManager::GetShader("object");

	shader.SetMat4D("view", view);
}
