#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cvijet.h"
using namespace sf;

int main()
{
	//antialiasing
	sf::ContextSettings settings;
	settings.antialiasingLevel = 10;
	
	RenderWindow window(VideoMode(800, 600), "Cvijet!", sf::Style::Default, settings);
	window.setFramerateLimit(60);

	Cvijet cvijet(&window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			//mogucnost zatvaranja prozora uz pomoc ESC-a
			if (Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
		}
		window.clear();
		cvijet.draw();
		window.display();
	}

	return 0;
}