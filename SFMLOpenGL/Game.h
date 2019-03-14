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
	GLboolean CheckPlayerAndObstacleCollision(Player &player, Obstacle &obstacle) // AABB - AABB collision
	{
		// Collision x-axis?
		bool collisionX = player.getPosition().x + 2 >= obstacle.getPosition().x &&
			obstacle.getPosition().x + 2 >= player.getPosition().x;
		// Collision y-axis?
		bool collisionY = player.getPosition().y + 2 >= obstacle.getPosition().y &&
			obstacle.getPosition().y + 2 >= player.getPosition().y;
		// Collision only if on both axes
		return collisionX && collisionY;
	}
private:
	Player * player;
	Obstacle * obstacle[40];
	Ground * ground[100];
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