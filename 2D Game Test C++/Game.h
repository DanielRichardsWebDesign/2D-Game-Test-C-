#pragma once

#include <iostream>

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

	//Game Objects
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
	void pollEvents();
	void update();
	void render();
};