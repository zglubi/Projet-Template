#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Chaser.h"

RenderWindow window(VideoMode(1440, 1080), "Zelda Like");

Map gameMap;

Player* player = new Player(720, 540);
ChaserEnemy* chaser = new ChaserEnemy(100, 100, 50, 200, 50); // Position (100, 100), speed 50, detection range 200, stop range 50
Time deltatime;
View view = window.getView();

int main()
{

    Clock clock;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        deltatime = clock.restart();

        window.clear();
        gameMap.draw(window);

        // Update player position (assuming the Player class has move method)
        player->move(window, view, gameMap.getWalls());
        player->update(window, deltatime, view);

        // Update and draw the chaser enemy
		chaser->moveUpdate(player);
        chaser->update(window, deltatime, view);
        chaser->draw(window);

        window.display();
    }

    delete player;
    delete chaser;

    return 0;
}