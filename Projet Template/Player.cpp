#include "Player.h"

Player::Player(int x, int y) : Entity(x, y) {

    if (!texture.loadFromFile("assets\\player.png")) {
        std::cerr << "Erreur : impossible de charger 'playersprite'" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
    sprite.setScale(Vector2f(2, 2));

    vitesse = 2;
}


void Player::draw(RenderWindow& window) {

    window.draw(sprite);
}


void Player::update(RenderWindow& window, Time deltatime) {
 
    if (Keyboard::isKeyPressed(Keyboard::Q) && x - vitesse - texture.getSize().x > 0) {
        x += -vitesse;
    }
    if (Keyboard::isKeyPressed(Keyboard::Z) && y - vitesse - texture.getSize().y - 10 > 200) {
        y += -vitesse;
    }
    if (Keyboard::isKeyPressed(Keyboard::S) && y + vitesse + texture.getSize().y + 15 < window.getSize().y) {
        y += vitesse;
    }
    if (Keyboard::isKeyPressed(Keyboard::D) && x + vitesse + texture.getSize().x < window.getSize().x) {
        x += vitesse;
    }


    sprite.setPosition(x, y);
    draw(window);


}