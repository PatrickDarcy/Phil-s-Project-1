#ifndef GAME_H
#define GAME_H

#include <string>
#include <sstream>

#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include <Debug.h>

#include "Player.h"
#include "Obstacle.h"
#include "Ground.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <GameObject.h>

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
	void initialize();
	void update();
	void render();
	void unload();
private:
	Player * player;
	Obstacle * obstacle[40];
	Ground * ground;
	RenderWindow window;
	Clock clock;
	Time time;
	bool animate = false;
	vec3 animation = vec3(0.0f);
	float rotation = 0.0f;
	bool isRunning = false;

	enum gravity 
	{
		JUMPING,
		FALLING,
		GROUNDED
	};

	gravity m_playerGravity = GROUNDED;

	bool m_spacePressed = false;
};

#endif  // ! GAME_H