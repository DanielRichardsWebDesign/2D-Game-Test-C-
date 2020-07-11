#include "Game.h"

//Private Functions
void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "Game 1", sf::Style::Titlebar | sf::Style::Close);
}

//Constructor
Game::Game()
{
	this->initVariables();
	this->initWindow();
}

//Destructor
Game::~Game()
{
	delete this->window;
}

//Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}




//Public Functions
void Game::pollEvents()
{
	//Event Polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case::sf::Event::Closed:
			this->window->close();
			break;
		case::sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

//Update Function - Handles everything that is not drawing.
void Game::update()
{
	this->pollEvents();
}

//Render Function - Renders all the points on screen.
void Game::render()
{
	/*
		@return void
		- Clear old frame
		- render objects
		- display frame in window

		Renders the Game Objects
	*/

	this->window->clear(sf::Color(255, 0, 0, 255));

	//Draw Game Objects

	this->window->display();
}
