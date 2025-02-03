#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

Menu::Menu(RenderWindow& window)
{
	// Background du menu principal
	MainMenuBGTexture.loadFromFile("Assets/MenuBG.jpg");
	MainMenuBGSprite.setTexture(MainMenuBGTexture);
	Vector2u windowSizeM = window.getSize();
	Vector2u textureSizeM = MainMenuBGTexture.getSize();

	float scaleMX = static_cast<float>(windowSizeM.x) / textureSizeM.x;
	float scaleMY = static_cast<float>(windowSizeM.y) / textureSizeM.y;

	MainMenuBGSprite.setScale(scaleMX, scaleMY);

	// Background du menu pause

	PauseMenuBGTexture.loadFromFile("Assets/PauseMenuBG.jpg");
	PauseMenuBGSprite.setTexture(PauseMenuBGTexture);
	Vector2u windowSizeP = window.getSize();
	Vector2u textureSizeP = PauseMenuBGTexture.getSize();

	float scalePX = static_cast<float>(windowSizeP.x) / textureSizeP.x;
	float scalePY = static_cast<float>(windowSizeP.y) / textureSizeP.y;

	PauseMenuBGSprite.setScale(scalePX, scalePY);

	// Boutons

	buttonPlayTexture.loadFromFile("Assets/player.png");
;
	buttonExitTexture.loadFromFile("Assets/player.png");

	buttonResumeTexture.loadFromFile("Assets/player.png");

	buttonOptionsTexture.loadFromFile("Assets/player.png");

	buttons.push_back(Button(buttonPlayTexture, Vector2f(540, 200)));
	buttons.push_back(Button(buttonExitTexture, Vector2f(540, 600)));
	buttons.push_back(Button(buttonResumeTexture, Vector2f(540, 200)));
	buttons.push_back(Button(buttonOptionsTexture, Vector2f(540, 400)));
}

void Menu::draw(RenderWindow& window)
{
    for (auto& button : buttons) 
	{
        button.draw(window);
    }
}

int Menu::handleInput(const RenderWindow& window, Event event) 
{
    for (size_t i = 0; i < buttons.size(); ++i)
	{
        if (buttons[i].isClicked(window, event)) 
		{
            return static_cast<int>(i);
        }
    }
    return -1;
}

void Menu::menuDisplay(RenderWindow& window, int type)
{
	bool menu = true;
	Event event;
	if (type == 0)
	{
		while (menu)
		{
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					window.close();
					menu = false;
				}
				if (buttons[1].isClicked(window, event))
				{
					window.close();
					menu = false;
				}

				else if (buttons[0].isClicked(window, event))
				{
					menu = false;
				}
			}
			window.clear();
			window.draw(MainMenuBGSprite);
			buttons[0].draw(window);
			buttons[1].draw(window);
			window.display();
		}
	}
	if (type == 1)
	{
		bool pause = true;
		while (pause)
		{
			window.setView(window.getDefaultView());

			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					window.close();
				}

				if (buttons[2].isClicked(window, event))  // Bouton "Reprendre"
				{
					pause = false;
				}

				if (buttons[3].isClicked(window, event))  // Option inutilisée pour l'instant
				{
					// Code pour une option supplémentaire
				}

				if (buttons[1].isClicked(window, event))  // Bouton "Quitter"
				{
					window.close();
					pause = false;
				}
			}

			window.clear();
			window.draw(PauseMenuBGSprite);
			buttons[2].draw(window); // Reprendre
			buttons[3].draw(window); // Option
			buttons[1].draw(window); // Quitter
			window.display();
		}
	}
}