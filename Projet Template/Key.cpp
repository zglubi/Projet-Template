#include "Key.h"

Key::Key(Texture& texture, float x, float y) : Item(texture, x, y) {
    if (!texture.loadFromFile("assets/Items/GoldKey.png")) {
        std::cerr << "Erreur : impossible de charger 'Key'" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
    sprite.setScale(Vector2f(2, 2));
    sprite.setPosition(x, y);
}


void Key::draw(RenderWindow& window) {
    window.draw(sprite);
}

void Key::update(RenderWindow& window, float deltatime, View& view) {
    draw(window);
}

void Key::interact(shared_ptr<Player>& player) {

    if (player->getSprite().getGlobalBounds().intersects(sprite.getGlobalBounds()))
    {
        player->addToInventory(4);
        setToBeDeleted(true);
    }
}


