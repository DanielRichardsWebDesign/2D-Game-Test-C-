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

	//Limit Framerate
	this->window->setFramerateLimit(144);
}

void Game::initEnemies()
{
	this->enemy.setPosition(10.f, 10.f);
	this->enemy.setSize(sf::Vector2f(100.f, 100.f));
	this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
	this->enemy.setFillColor(sf::Color::Cyan);
	this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(1.f);
}

//Constructor
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initEnemies();
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

	//Update Mouse Position
	//Relative to the Screen
	//std::cout << "Mouse pos: " << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << "\n";
	//Relative to the window
	std::cout << "Mouse pos: " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << "\n";
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

	this->window->clear();

	//Draw Game Objects
	this->window->draw(this->enemy);

	this->window->display();
}
