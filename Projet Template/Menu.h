#ifndef MENU_H
#define MENU_H

#include "Button.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum class MenuType {
    MainMenu,
    PauseMenu,
    GameOver,
    Win
};

class Menu
{
private:
    vector<Button> buttons;
    MenuType menuType;

public:
    Menu(MenuType type);

    void draw(RenderWindow& window);
    int handleInput(const RenderWindow& window, Event event);
};

#endif
