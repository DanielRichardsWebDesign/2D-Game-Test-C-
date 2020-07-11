#include <iostream>
#include "Game.h"

int main()
{
	//Initialising seed for random numbers
	std::srand(static_cast<unsigned>(time(NULL)));

	//Init Game Engine
	Game game;

	//Game Loop
	while (game.running())
	{		
		//Update		
		game.update();

		//Render
		game.render();
	}

	//End of Application
	return 0;
}