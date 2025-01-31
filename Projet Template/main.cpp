#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Chaser.h"
#include "Menu.h"

RenderWindow window(VideoMode(1440, 1080), "Zelda Like");

Map gameMap;

Player* player = new Player(720, 540);
Chaser* chaser = new Chaser(Vector2f(100, 100), 50); // Position (100, 100), speed 50, detection range 200, stop range 50
float deltatime;
View view = window.getView();
Menu menu(window);

int main()
{

    Clock clock;
    while (window.isOpen())
    {
        menu.menuDisplay(window, 0);

        bool isRunning = true;
        bool isPause = false;

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
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Escape) {
                        std::cout << "Touche Echap pressee !" << std::endl;
                        isPause = true;
                    }
                }
            }

            deltatime = clock.restart().asSeconds();

            window.clear();
            gameMap.draw(window);

            // Update player position (assuming the Player class has move method)
            player->handleInput(window, view, gameMap.getWalls());
            player->update(window, deltatime, view);

            // Update and draw the chaser enemy
            chaser->moveUpdate(player);
            chaser->update(window, deltatime, view);
            chaser->draw(window);

            window.display();
        }
        while (isPause)
        {
			menu.menuDisplay(window, 1);
        }
    }

    delete player;
    delete chaser;

    return 0;
}