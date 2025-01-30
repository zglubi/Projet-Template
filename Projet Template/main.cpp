#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "ChaserEnemy.h"

RenderWindow window(VideoMode(1440, 1080), "Zelda Like");

Map gameMap;

Entity* player = new Player(720, 540);
ChaserEnemy* chaser = new ChaserEnemy(100, 100, 50, 200, 50); // Position (100, 100), speed 50, detection range 200, stop range 50
Time deltatime;
View view = window.getView();

int main()
{
    // Load ChaserEnemy texture
    if (!chaser->texture.loadFromFile("assets/Skeleton.png")) {
        cout << "Failed to load enemy texture!" << endl;
        return -1;
    }
    chaser->sprite.setTexture(chaser->texture);
    chaser->sprite.setPosition(chaser->position);

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
        chaser->setPlayerPosition(static_cast<Player*>(player)->sprite.getPosition());

        // Update and draw the chaser enemy
        chaser->update(window, deltatime, view);
        chaser->draw(window);

        window.display();
    }

    delete player;
    delete chaser;

    return 0;
}