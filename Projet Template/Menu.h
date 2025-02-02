#ifndef MENU_H
#define MENU_H

#include "Button.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Menu
{
private:

	Sprite PauseMenuBGSprite;
	Texture PauseMenuBGTexture;
	Sprite MainMenuBGSprite;
	Texture MainMenuBGTexture;
	Texture buttonPlayTexture;
	Texture buttonExitTexture;
	Texture buttonResumeTexture;
	Texture buttonOptionsTexture;
    vector<Button> buttons;

public:
    Menu(RenderWindow& window);

    void draw(RenderWindow& window);
	void menuDisplay(RenderWindow& window, int type);
    int handleInput(const RenderWindow& window, Event event);
};

#endif
