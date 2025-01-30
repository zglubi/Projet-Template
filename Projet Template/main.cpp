#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"	

RenderWindow window(VideoMode(1440, 1080), "Zelda Like");


Map gameMap;

Player* p = new Player(720, 540);
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
		p->move(window, view, gameMap.getWalls());
		window.display();
	}
	
	return 0;
}