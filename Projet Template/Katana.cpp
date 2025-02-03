#include "Katana.h"
#include <iostream>

Katana::Katana(float x, float y) : Item(x, y) {
    if (!texture.loadFromFile("assets\\Items\\Weapons\\Katana.png")) {
        cerr << "Error loading shooter texture" << endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(Vector2f(x, y));
    sprite.setScale(Vector2f(2, 2));
}

void Katana::update(RenderWindow& window, float deltatime, View& view) 
{
    draw(window);
}

void Katana::draw(RenderWindow& window) {
    window.draw(sprite);
}

void Katana::interact(shared_ptr<Player>& player) {
    if (player->getSprite().getGlobalBounds().intersects(sprite.getGlobalBounds()))
    {
        setToBeDeleted(true);
    }
}