#include <SFML/Graphics.hpp>
#include <iostream>
#include "HUD.h"
#include "Map.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Chaser.h"
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
    // Charger les textures en arrière-plan
    auto future1 = threadManager.addTask([&]() {
        textureManager.loadTextures1();
        std::cout << "Textures 1 chargées en arrière-plan" << std::endl;
        });

    auto future2 = threadManager.addTask([&]() {
        textureManager.loadTextures2();
        std::cout << "Textures 2 chargées en arrière-plan" << std::endl;
        });

    auto future3 = threadManager.addTask([&]() {
        gameMap.loadMap(1);
        std::cout << "Map 1 chargée en arrière-plan" << std::endl;
        });

    // Attendre que les textures soient chargées avant de continuer
    threadManager.waitAll();

    gameMap.setTextures(textureManager.getTexturesMap());
    manager->setTextures(textureManager.getTexturesEntities());
    hud.setTextures(textureManager.getTexturesHud());

    window.setFramerateLimit(120);
    manager->setPlayer(1000, 740);

    manager->addItem(Vector2f(0, 500), 1);
    manager->addItem(Vector2f(200, 700), 2);
    manager->addItem(Vector2f(800, 300), 3);

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

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
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

        // Mise à jour du deltaTime
        deltaTime = clock.restart().asSeconds();

        // Dessin et mise à jour du jeu
        window.clear();
        gameMap.draw(window);
        manager->update(window, deltaTime, view, gameMap.getWalls());

        hud.draw(window, manager->getInventory(), manager->getPlayer()->getHp());
        window.display();
    }

    return 0;
}
