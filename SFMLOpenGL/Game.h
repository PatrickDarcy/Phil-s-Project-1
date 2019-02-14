#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>
#include <GLFW/glfw3.h>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include <Debug.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

using namespace std;
using namespace sf;
using namespace glm;

class Game
{
public:
	Game();
	Game(sf::ContextSettings settings);
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();

	glm::vec3 position = glm::vec3(0, 0, 5);

	float horizontalAngle = 3.14f;
	float verticalAngle = 0.0f;
	float intialFoV = 45.0f;

	float speed = 3.0f;
	float mouseSpeed = 0.005f;
	int xpos, ypos;
	int glGetMousePos(int &xpos, int &ypos);
};
#endif