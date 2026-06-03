#include <glad/glad.h> 
#include <GLFW/glfw3.h>

#include <iostream>
#include "Game.h"
#include "Camera.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
// TEMP!!!!!! I will be implenting window AND camera in its own classes. this is for testing purposes
const int WIDTH = 1920;
const int HEIGHT = 1080;

Game game = Game(WIDTH, HEIGHT);

Camera camera = Camera(WIDTH, HEIGHT);
void processInput(GLFWwindow* window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

// delta time variables
float deltaTime = 0.0f;
float lastTime = 0.0f;
// end temp
int main() 
{
	// initialising glfw and creating window
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Game", NULL, NULL);

	// window error check
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		return -1;
	}

	// making the window's context current
	glfwMakeContextCurrent(window);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// initalising glad to get driver compatibility
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		return -1;
	}

	// set viewport and callback for window resizing
	glViewport(0, 0, WIDTH, HEIGHT);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	
	// enable depth testing
	glEnable(GL_DEPTH_TEST);

	game.Init();

	// TEMP!!!!!! I will be implenting window AND camera in its own classes. this is for testing purposes
	glfwSetCursorPosCallback(window, mouse_callback);

	// game loop
	while (!glfwWindowShouldClose(window))
	{
		// TEMP!!!!!! I will be implenting window AND camera in its own classes. this is for testing purposes
		// calculate delta time
		float currentTime = glfwGetTime();
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		processInput(window);

		// color buffer
		glClearColor(0.5f, 0.8f, 0.9f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		game.Render();

		// rendering
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

// below functions temp
void processInput(GLFWwindow* window)
{
	camera.ProcessKeyboard(window, deltaTime);
	
	game.SetViewMatrix(camera.GetViewMatrix());
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	camera.ProcessMouse(window, xpos, ypos);

	game.SetViewMatrix(camera.GetViewMatrix());
}