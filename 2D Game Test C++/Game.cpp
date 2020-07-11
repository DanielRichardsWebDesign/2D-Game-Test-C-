#include "Game.h"

//Private Functions
void Game::initVariables()
{
	this->window = nullptr;

	//Game Logic	
	this ->points = 0;
	this->enemySpawnTimerMax = 1000.0f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 5;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "Game 1", sf::Style::Titlebar | sf::Style::Close);

	//Limit Framerate
	this->window->setFramerateLimit(60);
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
void Game::spawnEnemy()
{
	/**
		@return void

		Spawns enemies and sets their colour and positions.
		-Sets a random position on the window.
		-Sets a random colour.
		-Adds enemy to the vector.
	*/

	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		0.f
	);

	this->enemy.setFillColor(sf::Color::Green);

	//Spawns the enemy
	this->enemies.push_back(this->enemy);
}

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

void Game::updateMousePositions()
{
	/*
		@ return void

		Updates the mouse positions:
		- Mouse position relative to window (Vector2i)
	*/
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

void Game::updateEnemies()
{
	/**
		@ return void

		Updates the enemy spawn timer and spawns enemies
		when the total amount of enemies is smaller than the maximum amount.
		Moves the enemies downwards as well.
		Also removes enemies at the edge of the screen. //TO DO
	*/

	//Updating timer for enemy spawning.
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			//Spawn enemy and reset timer.
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}			
		else
		{
			this->enemySpawnTimer += 1.f;
		}			
	}

	//Move the enemies
	for (auto &e : this->enemies)
	{
		e.move(0.f, 1.f);
	}
}

//Update Function - Handles everything that is not drawing.
void Game::update()
{	
	this->pollEvents();

	this->updateMousePositions();

	this->updateEnemies();
}

void Game::renderEnemies()
{
	//Rendering all the enemies
	for (auto& e : this->enemies)
	{
		this->window->draw(e);
	}
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
	this->renderEnemies();

	this->window->display();
}
