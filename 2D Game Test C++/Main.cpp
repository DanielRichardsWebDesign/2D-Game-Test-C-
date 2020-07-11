#include <iostream>
//Include SFML Libraries
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main()
{
	//Window Logic
	sf::RenderWindow window(sf::VideoMode(640, 480), "2D Game Test", sf::Style::Titlebar | sf::Style::Close);
	sf::Event ev;

	//Game Loop
	while (window.isOpen())
	{
		//Event Polling
		while (window.pollEvent(ev))
		{
			switch (ev.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::Escape)
					window.close();
				break;
			}
		}
		//Update

		
		
		//Render
		window.clear(sf::Color::Blue); //Clears old frame

		//Draw Game


		window.display(); //Tell application that the window is done drawing

	}

	//End of Application
	return 0;
}