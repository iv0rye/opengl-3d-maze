#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "ObjectRenderer.h"

enum GameState
{
	GAME_ACTIVE,
	GAME_MENU
};

class Game
{
public:
	unsigned int Width, Height;

	Game(unsigned int width, unsigned int height);
	~Game();

	// initialise game -> load obj
	void Init();

	GameState State;

	// arr to process input
	bool Keys[1024];

	// game loop
	void ProcessInput(float dt);
	void Update(float dt);
	void Render();

private:
	ObjectRenderer* Renderer;
};

