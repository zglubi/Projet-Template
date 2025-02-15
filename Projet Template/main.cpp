#include <SFML/Graphics.hpp>
#include <iostream>
#include "HUD.h"
#include "Map.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Chaser.h"
#include "Boss.h"
#include "Menu.h"
#include "Shooter.h"
#include "Medipack.h"
#include "EntityManager.h"
#include "ThreadManager.h"
#include "TextureManager.h"
#include "Katana.h"
#include "Shuriken.h"

RenderWindow window(VideoMode(1440, 1080), "Zelda Like");

Map gameMap;

HUD hud;

float deltaTime;
View view = window.getView();
Menu menu(window);

EntityManager* manager = EntityManager::getInstance();

TextureManager textureManager = TextureManager();

ThreadManager threadManager;

int main()
{
    auto future1 = threadManager.addTask([&]() 
        {
        textureManager.loadTextures1();
        cout << "Textures 1 chargees en arriere-plan" << endl;
        });

    auto future2 = threadManager.addTask([&]() 
        {
        textureManager.loadTextures2();
        cout << "Textures 2 chargees en arriere-plan" << endl;
        });
     
    
    threadManager.waitAll();
    future1.wait();
    gameMap.loadMap(1, manager);


    gameMap.setTextures(textureManager.getTexturesMap());
    manager->setTextures(textureManager.getTexturesEntities());
    hud.setTextures(textureManager.getTexturesHud());

    window.setFramerateLimit(120);
    manager->setPlayer(600 + 896, 2000);

    // manager->addBoss(Vector2f(1350, 750), 50.0f);
    manager->addItem(Vector2f(700 + 1896, 2500 - 700), 1);
    manager->addItem(Vector2f(900 + 1896, 2400 - 800), 2);
    manager->addItem(Vector2f(800 + 1896, 2300 - 1000), 3);
    manager->addItem(Vector2f(1800 + 1896, 1600), 4);

    Clock clock;

    bool isRunning = true;
    bool isPause = false;
    bool gameOver = false;
    bool win = false;
    bool isOptions = false;

    // Affiche le menu principal avant de lancer le jeu
    menu.menuDisplay(window, 0);

    while (window.isOpen())
    {
        if (manager->getPlayer()->getHp() <= 0 || manager->getPlayer()->getHp() > 800)
        {
            gameOver = true;
        }
        else if (manager->getBoss())
		{
			if (manager->getBoss()->getHp() <= 0)
			{
				win = true;
			}
		}

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Escape)
                {
                    isPause = !isPause;
                }
            }
        }
        if (isPause)
        {
            menu.menuDisplay(window, 1);
            isPause = false;
            clock.restart();
            window.setView(view);
            continue;
        }
        if (gameOver)
        {
            menu.menuDisplay(window, 2);
            gameOver = false;
            clock.restart();
            window.setView(view);
            continue;
        }
        if (win)
        {
            menu.menuDisplay(window, 3);
            win = false;
            clock.restart();
            window.setView(view);
            continue;
        }
        if (isOptions)
        {
            menu.menuDisplay(window, 4);
            isOptions = false;
            clock.restart();
            window.setView(view);
            continue;
        }

        // Mise � jour du deltaTime
        deltaTime = clock.restart().asSeconds();

        // Dessin et mise � jour du jeu
        window.clear();
        gameMap.draw(window);
        manager->update(window, deltaTime, view, gameMap.getWalls(), gameMap.getDoor(), gameMap);

        hud.draw(window, manager->getInventory(), manager->getPlayer()->getHp(), manager->getBoss());
        window.display();
    }

    return 0;
}
