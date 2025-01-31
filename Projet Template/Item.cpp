#include "Item.h"

Item::Item(float x, float y) : Entity(x, y) {
	if (!texture.loadFromFile("assets/Item.png")) {
		cerr << "Erreur : impossible de charger 'Item'" << endl;
	}
	sprite.setTexture(texture);
	sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
	sprite.setScale(Vector2f(2, 2));
}
