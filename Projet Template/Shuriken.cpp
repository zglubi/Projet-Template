#include "Shuriken.h"
#include <iostream>

Shuriken::Shuriken(float x, float y) : Item(x, y) {
    if (!texture.loadFromFile("assets/Projectiles/Shuriken.png")) {
        cerr << "Error loading Shuriken texture" << endl;
    }
    sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 16, 16));
}

void Shuriken::update(RenderWindow& window, float deltatime, View& view) {
	// Update logic for Shuriken
	cout << "Updating Shuriken" << endl;
}

void Shuriken::draw(RenderWindow& window) {
    // Drawing logic for Shuriken
	window.draw(sprite);
}

void Shuriken::interact(shared_ptr<Player>& player) {
    cout << "Shuriken grabbed by player!" << endl;
}