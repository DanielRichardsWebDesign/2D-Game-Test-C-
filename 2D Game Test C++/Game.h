#pragma once

#include <iostream>
#include <vector>
#include <ctime>

//Include SFML Libraries
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/*
	Game Engine Class. Contains functions that allow the game to function. 
	This is a Wrapper Class.
*/


class Game
{
private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Mouse Positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Game Logic
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;

	//Game Objects
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;


	//Private Functions
	void initVariables();
	void initWindow();
	void initEnemies();

public:
	//Constructors and Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;

	//Functions
	void spawnEnemy();

	void pollEvents();
	void updateMousePositions();
	void updateEnemies();
	void update();

	void renderEnemies();
	void render();
};