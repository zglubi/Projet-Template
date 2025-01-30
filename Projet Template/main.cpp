#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"
using namespace std;
using namespace sf;


RenderWindow window(VideoMode(1440, 1080), "Zelda Like");

Map gameMap;

int main()
{
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		gameMap.draw(window);
		window.display();
	}
	
	return 0;
}