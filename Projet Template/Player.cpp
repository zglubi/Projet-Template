#include "Player.h"

Player::Player(int x, int y) : Entity(x, y) {

    if (!texture.loadFromFile("assets\\player.png")) {
        std::cerr << "Erreur : impossible de charger 'playersprite'" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
    sprite.setScale(Vector2f(2, 2));

    vitesse = 0.25;
}

float Player::getVitesse() const {
    return vitesse;
}

void Player::setVitesse(float newVitesse) {
    vitesse = newVitesse;
}

const Sprite& Player::getSprite() const {
    return sprite;
}

void Player::setSprite(const Sprite& newSprite) {
    sprite = newSprite;
}

bool canMove() {


}

void Player::draw(RenderWindow& window) {
    window.draw(sprite);
}

void Player::update(RenderWindow& window, Time deltatime, View& view) {

    if (Keyboard::isKeyPressed(Keyboard::Q)) {
        x += -vitesse;
        view.move(-vitesse, 0);
    }
    if (Keyboard::isKeyPressed(Keyboard::Z)) {
        y += -vitesse;
        view.move(0, -vitesse);
    }
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        y += vitesse;
        view.move(0, vitesse);
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        x += vitesse;
        view.move(vitesse, 0);
    }

    sprite.setPosition(x, y);
    window.setView(view);
    draw(window);
}