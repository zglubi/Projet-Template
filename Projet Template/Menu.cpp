#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

Menu::Menu(MenuType type) : menuType(type) {
    if (type == MenuType::MainMenu) {
        buttons.emplace_back("Play", Vector2f(300, 200), Vector2f(200, 50));
        buttons.emplace_back("Exit", Vector2f(300, 300), Vector2f(200, 50));
    }
    else if (type == MenuType::PauseMenu) {
        buttons.emplace_back("Resume", Vector2f(300, 200), Vector2f(200, 50));
        buttons.emplace_back("Options", Vector2f(300, 300), Vector2f(200, 50));
        buttons.emplace_back("Exit", Vector2f(300, 400), Vector2f(200, 50));
    }
    else if (type == MenuType::GameOver) {
        buttons.emplace_back("Retry", Vector2f(300, 200), Vector2f(200, 50));
        buttons.emplace_back("Exit", Vector2f(300, 300), Vector2f(200, 50));
    }
    else if (type == MenuType::Win) {
        buttons.emplace_back("Exit", Vector2f(300, 200), Vector2f(200, 50));
    }
}

void Menu::draw(RenderWindow& window) {
    for (auto& button : buttons) {
        button.draw(window);
    }
}

int Menu::handleInput(const RenderWindow& window, Event event) {
    for (size_t i = 0; i < buttons.size(); ++i) {
        if (buttons[i].isClicked(window, event)) {
            return static_cast<int>(i);
        }
    }
    return -1;
}