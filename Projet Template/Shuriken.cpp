#include "Shuriken.h"
#include <iostream>

Shuriken::Shuriken(Texture& texture, float x, float y) : Item(texture, x, y) {
    if (!texture.loadFromFile("assets/Projectiles/Shuriken.png")) {
        cerr << "Error loading Shuriken texture" << endl;
    }
    sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 16, 16));
    sprite.setPosition(Vector2f(x, y));
}

void Shuriken::update(RenderWindow& window, float deltatime, View& view) {
	// Update logic for Shuriken
    draw(window);
}

void Shuriken::draw(RenderWindow& window) {
    // Drawing logic for Shuriken
	window.draw(sprite);
}

void Shuriken::interact(shared_ptr<Player>& player) {
    if (player->getSprite().getGlobalBounds().intersects(sprite.getGlobalBounds()))
    {
        player->addToInventory(1);
        setToBeDeleted(true);
    }
}