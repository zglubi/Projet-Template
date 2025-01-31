#include "Katana.h"
#include <iostream>

Katana::Katana(float x, float y) : Item(x, y) {
    if (!texture.loadFromFile("assets/Items/Katana_Sprite.png")) {
        cerr << "Error loading shooter texture" << endl;
    }
    sprite.setTexture(texture);
}

void Katana::update(RenderWindow& window, float deltatime, View& view) {
    // Update logic for Katana
	cout << "Updating Katana" << endl;
}

void Katana::draw(RenderWindow& window) {
    window.draw(sprite);
}

void Katana::interact(shared_ptr<Player>& player) {
    cout << "Katana grabbed by player!" << endl;
}