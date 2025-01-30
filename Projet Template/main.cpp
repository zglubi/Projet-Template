#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"
#include "Entity.h"
#include "Player.h"
using namespace std;
using namespace sf;


RenderWindow window(VideoMode(1440, 1080), "Zelda Like");


Map gameMap;

Entity* p = new Player(500, 500);
Time deltatime;
View view = window.getView();
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
		p->update(window, deltatime, view);
		window.display();
	}
	
	return 0;
}