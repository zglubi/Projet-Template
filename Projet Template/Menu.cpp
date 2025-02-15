#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;
using namespace sf;

Menu::Menu(RenderWindow& window)
{
	// Background du menu Principal
	mainMenuBGTexture.loadFromFile("Assets/Backgrounds/MainMenuBG.jpg");
	mainMenuBGSprite.setTexture(mainMenuBGTexture);
	Vector2u windowSizeM = window.getSize();
	Vector2u textureSizeM = mainMenuBGTexture.getSize();

	float scaleMX = static_cast<float>(windowSizeM.x) / textureSizeM.x;
	float scaleMY = static_cast<float>(windowSizeM.y) / textureSizeM.y;

	mainMenuBGSprite.setScale(scaleMX, scaleMY);

	// Background du menu Pause
	pauseMenuBGTexture.loadFromFile("Assets/Backgrounds/PauseMenuBG.jpg");
	pauseMenuBGSprite.setTexture(pauseMenuBGTexture);
	Vector2u windowSizeP = window.getSize();
	Vector2u textureSizeP = pauseMenuBGTexture.getSize();

	float scalePX = static_cast<float>(windowSizeP.x) / textureSizeP.x;
	float scalePY = static_cast<float>(windowSizeP.y) / textureSizeP.y;

	pauseMenuBGSprite.setScale(scalePX, scalePY);

	// Background du Game Over
	gameOverBGTexture.loadFromFile("Assets/Backgrounds/GameOverBG.jpg");
	gameOverBGSprite.setTexture(gameOverBGTexture);
	Vector2u windowSizeG = window.getSize();
	Vector2u textureSizeG = gameOverBGTexture.getSize();

	float scaleGX = static_cast<float>(windowSizeG.x) / textureSizeG.x;
	float scaleGY = static_cast<float>(windowSizeG.y) / textureSizeG.y;

	gameOverBGSprite.setScale(scaleGX, scaleGY);

	// Background du Win
	winBGTexture.loadFromFile("Assets/Backgrounds/WinBG.jpg");
	winBGSprite.setTexture(winBGTexture);
	Vector2u windowSizeW = window.getSize();
	Vector2u textureSizeW = winBGTexture.getSize();

	float scaleWX = static_cast<float>(windowSizeW.x) / textureSizeW.x;
	float scaleWY = static_cast<float>(windowSizeW.y) / textureSizeW.y;

	winBGSprite.setScale(scaleWX, scaleWY);

	// Background du menu Options
	optionsMenuBGTexture.loadFromFile("Assets/Backgrounds/OptionsMenuBG.jpg");
	optionsMenuBGSprite.setTexture(optionsMenuBGTexture);
	Vector2u windowSizeO = window.getSize();
	Vector2u textureSizeO = optionsMenuBGTexture.getSize();

	float scaleOX = static_cast<float>(windowSizeO.x) / textureSizeO.x;
	float scaleOY = static_cast<float>(windowSizeO.y) / textureSizeO.y;

	optionsMenuBGSprite.setScale(scaleOX, scaleOY);

	// Texte Titre
	font.loadFromFile("Assets/SquadaOne-Regular.ttf");
	title.setFont(font);
	title.setString("Ninja Quest");
	title.setCharacterSize(150);
	title.setFillColor(Color::White);
	title.setPosition(380, 200);

	// Texte Game Over
	font.loadFromFile("Assets/SquadaOne-Regular.ttf");
	gameOverTexte.setFont(font);
	gameOverTexte.setString("GAME OVER");
	gameOverTexte.setCharacterSize(150);
	gameOverTexte.setFillColor(Color::Red);
	gameOverTexte.setPosition(400, 200);

	// Texte Win
	font.loadFromFile("Assets/SquadaOne-Regular.ttf");
	win.setFont(font);
	win.setString("You Win !");
	win.setCharacterSize(150);
	win.setFillColor(Color::Yellow);
	win.setPosition(450, 200);

	// Boutons
	buttonPlayTexture.loadFromFile("Assets/Buttons/PlayButton.png");
;
	buttonExitTexture.loadFromFile("Assets/Buttons/ExitButton.png");

	buttonResumeTexture.loadFromFile("Assets/Buttons/ResumeButton.png");

	buttonOptionsTexture.loadFromFile("Assets/Buttons/OptionsButton.png");

	buttonReturnTexture.loadFromFile("Assets/Buttons/ReturnButton.png");

	buttons.push_back(Button(buttonPlayTexture, Vector2f(540, 450)));
	buttons.push_back(Button(buttonExitTexture, Vector2f(620, 700)));
	buttons.push_back(Button(buttonResumeTexture, Vector2f(620, 200)));
	buttons.push_back(Button(buttonOptionsTexture, Vector2f(620, 450)));
	buttons.push_back(Button(buttonReturnTexture, Vector2f(50, 50)));

	if (!menuMusic.openFromFile("Assets/Audio/MainMenuMusic.ogg"))
	{
		cout << "Erreur lors du chargement de la musique du menu" << endl;
	}
	menuMusic.setLoop(true);

	if (!gameMusic.openFromFile("Assets/Audio/Willderness.ogg"))
	{
		cout << "Erreur lors du chargement de la musique du menu" << endl;
	}
	gameMusic.setLoop(true);

	if (!gameOverMusic.openFromFile("Assets/Audio/GameOver.ogg"))
	{
		cout << "Erreur lors du chargement de la musique du menu" << endl;
	}
	gameOverMusic.setLoop(true);
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
	bool pause = true;
	bool gameOver = true;
	bool Win = true;
	bool Options = false;
	Event event;
	while (type < 5)
	{
		if (type == 0) // Menu Principal
		{
			menuMusic.play();
			gameMusic.pause();

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
					if (event.type == Event::KeyPressed)
					{
						if (event.key.code == Keyboard::Escape)
						{
							window.close();
							menu = false;
						}
					}

					else if (buttons[0].isClicked(window, event))
					{
						type = 5;
						menu = false;
					}
				}
				window.clear();
				window.draw(mainMenuBGSprite);
				window.draw(title);
				buttons[0].draw(window);
				buttons[1].draw(window);
				window.display();
			}
			menuMusic.stop();
		}
		if (type == 1) // Menu Pause
		{
			gameMusic.pause();

			while (pause)
			{
				window.setView(window.getDefaultView());

				while (window.pollEvent(event))
				{
					if (event.type == Event::Closed)
					{
						window.close();
					}
					if (buttons[2].isClicked(window, event))
					{
						pause = false;
						type = 5;
					}
					if (buttons[3].isClicked(window, event))
					{
						type = 4;
						Options = true;
						pause = false;
					}
					if (buttons[1].isClicked(window, event))
					{
						window.close();
						pause = false;
					}
					if (event.type == Event::KeyPressed)
					{
						if (event.key.code == Keyboard::Escape)
						{
							type = 5;
							pause = false;
						}
					}
				}

				window.clear();
				window.draw(pauseMenuBGSprite);
				buttons[2].draw(window);
				buttons[3].draw(window);
				buttons[1].draw(window);
				window.display();
			}
		}
		if (type == 2) // Game Over
		{
			gameOverMusic.play();
			gameMusic.pause();

			while (gameOver)
			{
				window.setView(window.getDefaultView());

				while (window.pollEvent(event))
				{
					if (event.type == Event::Closed)
					{
						window.close();
					}
					if (buttons[1].isClicked(window, event))
					{
						window.close();
						gameOver = false;
					}
					if (event.type == Event::KeyPressed)
					{
						if (event.key.code == Keyboard::Escape)
						{
							type = 5;
							gameOver = false;
						}
					}
				}
				window.clear();
				window.draw(gameOverBGSprite);
				window.draw(gameOverTexte);
				buttons[1].draw(window);
				window.display();
			}
			gameOverMusic.play();
		}
		if (type == 3) // Win
		{
			gameMusic.pause();

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
					if (buttons[1].isClicked(window, event))
					{
						window.close();
						Win = false;
					}
					if (event.type == Event::KeyPressed)
					{
						if (event.key.code == Keyboard::Escape)
						{
							type = 5;
							Win = false;
						}
					}
				}
				window.clear();
				window.draw(winBGSprite);
				window.draw(win);
				buttons[1].draw(window);
				window.display();
			}
		}
		if (type == 4) // Options
		{
			gameMusic.pause();

			while (Options)
			{
				window.setView(window.getDefaultView());

				while (window.pollEvent(event))
				{
					if (event.type == Event::Closed)
					{
						window.close();
					}
					if (buttons[4].isClicked(window, event))
					{
						type = 1;
						pause = true;
						Options = false;
					}
					if (event.type == Event::KeyPressed)
					{
						if (event.key.code == Keyboard::Escape)
						{
							type = 1;
							pause = true;
							Options = false;
						}
					}
				}
				window.clear();
				window.draw(optionsMenuBGSprite);
				buttons[4].draw(window);
				window.display();
			}
		}
	}

	if (type == 5) // Jeu actif
	{
		menuMusic.stop();
		gameMusic.play();
	}
}