#include "Medipack.h"

Medipack::Medipack(float x, float y) : Item(x, y) {
    if (!texture.loadFromFile("assets/Items/Medipack.png")) {
        std::cerr << "Erreur : impossible de charger 'Medipack'" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
    /*sprite.setScale(Vector2f(2, 2));*/
}


void Medipack::draw(RenderWindow& window) {
    window.draw(sprite);
}

void Medipack::update(RenderWindow& window, float deltatime, View& view){
    draw(window);
}

void Medipack::interact(Player& player) {

    if (player.getSprite().getGlobalBounds().intersects(sprite.getGlobalBounds()))
        cout << "touch�";
}


