#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

Menu::Menu(RenderWindow& window)
{
	// Background du menu principal
	mainMenuBGTexture.loadFromFile("Assets/MainMenuBG.jpg");
	mainMenuBGSprite.setTexture(mainMenuBGTexture);
	Vector2u windowSizeM = window.getSize();
	Vector2u textureSizeM = mainMenuBGTexture.getSize();

	float scaleMX = static_cast<float>(windowSizeM.x) / textureSizeM.x;
	float scaleMY = static_cast<float>(windowSizeM.y) / textureSizeM.y;

	mainMenuBGSprite.setScale(scaleMX, scaleMY);

	// Background du menu pause
	pauseMenuBGTexture.loadFromFile("Assets/PauseMenuBG.jpg");
	pauseMenuBGSprite.setTexture(pauseMenuBGTexture);
	Vector2u windowSizeP = window.getSize();
	Vector2u textureSizeP = pauseMenuBGTexture.getSize();

	float scalePX = static_cast<float>(windowSizeP.x) / textureSizeP.x;
	float scalePY = static_cast<float>(windowSizeP.y) / textureSizeP.y;

	pauseMenuBGSprite.setScale(scalePX, scalePY);

	// Background du Game Over
	gameOverBGTexture.loadFromFile("Assets/GameOverBG.jpg");
	gameOverBGSprite.setTexture(gameOverBGTexture);
	Vector2u windowSizeG = window.getSize();
	Vector2u textureSizeG = gameOverBGTexture.getSize();

	float scaleGX = static_cast<float>(windowSizeG.x) / textureSizeG.x;
	float scaleGY = static_cast<float>(windowSizeG.y) / textureSizeG.y;

	gameOverBGSprite.setScale(scaleGX, scaleGY);

	// Background du Win
	winBGTexture.loadFromFile("Assets/WinBG.jpg");
	winBGSprite.setTexture(winBGTexture);
	Vector2u windowSizeW = window.getSize();
	Vector2u textureSizeW = winBGTexture.getSize();

	float scaleWX = static_cast<float>(windowSizeW.x) / textureSizeW.x;
	float scaleWY = static_cast<float>(windowSizeW.y) / textureSizeW.y;

	winBGSprite.setScale(scaleWX, scaleWY);

	// Titre
	font.loadFromFile("Assets/SquadaOne-Regular.ttf");

	// Boutons
	buttonPlayTexture.loadFromFile("Assets/PlayButton.png");
;
	buttonExitTexture.loadFromFile("Assets/ExitButton.png");

	buttonResumeTexture.loadFromFile("Assets/ResumeButton.png");

	buttonOptionsTexture.loadFromFile("Assets/OptionsButton.png");

	buttons.push_back(Button(buttonPlayTexture, Vector2f(540, 200)));
	buttons.push_back(Button(buttonExitTexture, Vector2f(620, 600)));
	buttons.push_back(Button(buttonResumeTexture, Vector2f(620, 200)));
	buttons.push_back(Button(buttonOptionsTexture, Vector2f(620, 400)));
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
			window.draw(mainMenuBGSprite);
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
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Escape)
					{
						pause = false;
					}
				}
			}

			window.clear();
			window.draw(pauseMenuBGSprite);
			buttons[2].draw(window); // Reprendre
			buttons[3].draw(window); // Option
			buttons[1].draw(window); // Quitter
			window.display();
		}
	}
	if (type == 2)
	{
		bool gameOver = true;
		while (gameOver)
		{
			window.setView(window.getDefaultView());

			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					window.close();
				}
				if (buttons[1].isClicked(window, event))  // Bouton "Quitter"
				{
					window.close();
					gameOver = false;
				}
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Escape)
					{
						gameOver = false;
					}
				}
			}
			window.clear();
			window.draw(gameOverBGSprite);
			buttons[1].draw(window); // Quitter
			window.display();
		}
	}
	if (type == 3)
	{
		bool Win = true;
		while (Win)
		{
			window.setView(window.getDefaultView());

			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					window.close();
				}
				if (buttons[1].isClicked(window, event))  // Bouton "Quitter"
				{
					window.close();
					Win = false;
				}
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Escape)
					{
						Win = false;
					}
				}
			}
			window.clear();
			window.draw(winBGSprite);
			buttons[1].draw(window); // Quitter
			window.display();
		}
	}
}