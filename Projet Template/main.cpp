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
#include "EntityManager.h"
#include "Katana.h"
#include "Shuriken.h"

RenderWindow window(VideoMode(1440, 1080), "Zelda Like");

Map gameMap;

float deltaTime;
View view = window.getView();
Menu menu;

EntityManager* manager = EntityManager::getInstance();

int main()
{
    
    manager->setPlayer(720, 540);

    manager->addChaser(Vector2f(100, 100), 50);
    manager->addShooter(Vector2f(200, 200), 50.0f);
    manager->addItem(Vector2f(0, 500), 1);

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

            deltaTime = clock.restart().asSeconds();

            window.clear();
            gameMap.draw(window);
            manager->update(window, deltaTime, view, gameMap.getWalls());

            window.display();
        }
    }

    return 0;
}