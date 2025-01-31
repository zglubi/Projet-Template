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
    vector<Button> buttons;

public:
    Menu();

    void draw(RenderWindow& window);
	void menuDisplay(RenderWindow& window, int type);
    int handleInput(const RenderWindow& window, Event event);
};

#endif
