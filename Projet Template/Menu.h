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

	Font font;
	Text title;
	Text gameOverTexte;
	Text win;

	Sprite pauseMenuBGSprite;
	Texture pauseMenuBGTexture;
	Sprite mainMenuBGSprite;
	Texture mainMenuBGTexture;
	Sprite gameOverBGSprite;
	Texture gameOverBGTexture;
	Sprite winBGSprite;
	Texture winBGTexture;
	Sprite optionsMenuBGSprite;
	Texture optionsMenuBGTexture;
	Texture buttonPlayTexture;
	Texture buttonExitTexture;
	Texture buttonResumeTexture;
	Texture buttonOptionsTexture;
	Texture buttonReturnTexture;
    vector<Button> buttons;

public:
    Menu(RenderWindow& window);

    void draw(RenderWindow& window);
	void menuDisplay(RenderWindow& window, int type);
    int handleInput(const RenderWindow& window, Event event);
};

#endif // MENU_H
