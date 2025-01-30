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
Chaser* chaser = new Chaser(Vector2f(500, 500), 200.f);
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
        player->update(window, deltatime, view);

        // Set the player's position for the chaser enemy
        chaser->setPlayerPosition(static_cast<Player*>(player)->getSprite().getPosition());

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