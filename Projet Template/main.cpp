#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Chaser.h"
#include "Menu.h"
#include "Shooter.h"
#include "Medipack.h"

RenderWindow window(VideoMode(1440, 1080), "Zelda Like");

Map gameMap;

shared_ptr<Player> player = make_shared<Player>(720, 540);
Chaser* chaser = new Chaser(Vector2f(100, 100), 50); // Position (100, 100), speed 50, detection range 200, stop range 50
Shooter* shooter = new Shooter(Vector2f(200, 200), 50.0f); // Position (200, 200), speed 50
Medipack* med = new Medipack(200, 200);
float deltatime;
View view = window.getView();
Menu menu;

int main()
{

    Clock clock;
    while (window.isOpen())
    {
        menu.menuDisplay(window, 0);

        bool isRunning = true;

        while (isRunning)
        {

            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                {
                    window.close();
					isRunning = false;
                }
            }

            deltatime = clock.restart().asSeconds();

            window.clear();
            gameMap.draw(window);

            // Update player position (assuming the Player class has move method)
            player->handleInput(window, view, gameMap.getWalls());
            player->update(window, deltatime, view);


            med->update(window, deltatime, view);
            med->interact(player);

            // Update and draw the chaser enemy
            chaser->moveUpdate(player);
            chaser->update(window, deltatime, view);
			shooter->moveUpdate(player);
			shooter->update(window, deltatime, view);
            chaser->draw(window);
			shooter->draw(window);

            window.display();
        }
    }

	player = nullptr;
    delete chaser;

    return 0;
}