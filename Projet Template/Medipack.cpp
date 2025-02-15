#include "Medipack.h"

Medipack::Medipack(Texture& texture, float x, float y) : Item(texture, x, y) {
    if (!texture.loadFromFile("assets/Items/Medipack.png")) {
        cerr << "Erreur : impossible de charger 'Medipack'" << endl;
    }
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
    sprite.setScale(Vector2f(2, 2));
    sprite.setPosition(x, y);
}


void Medipack::draw(RenderWindow& window) {
    window.draw(sprite);
}

void Medipack::update(RenderWindow& window, float deltatime, View& view){
    draw(window);
}

void Medipack::interact(shared_ptr<Player>& player) {

    if (player->getSprite().getGlobalBounds().intersects(sprite.getGlobalBounds()))
    {
        player->addToInventory(3);
        setToBeDeleted(true);
    }
}


