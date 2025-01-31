#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

Menu::Menu() 
{
	Texture buttonPlayTexture;
	buttonPlayTexture.loadFromFile("Assets/player.png");

	Texture buttonExitTexture;
	buttonExitTexture.loadFromFile("Assets/player.png");

	Texture buttonResumeTexture;
	buttonResumeTexture.loadFromFile("Assets/player.png");

	Texture buttonOptionsTexture;
	buttonOptionsTexture.loadFromFile("Assets/player.png");

	buttons.push_back(Button(buttonPlayTexture, Vector2f(540, 200)));
	buttons.push_back(Button(buttonExitTexture, Vector2f(540, 400)));
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
	if (type == 0)
	{
		bool menu = true;
		while (menu)
		{
			Event event;
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
			buttons[0].draw(window);
			buttons[1].draw(window);
			window.display();
		}
	}
}