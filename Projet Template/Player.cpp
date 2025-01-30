#include "Player.h"

Player::Player(int x, int y) : Entity(x, y) {

    if (!texture.loadFromFile("assets\\player.png")) {
        std::cerr << "Erreur : impossible de charger 'playersprite'" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
    sprite.setScale(Vector2f(2, 2));

    vitesse = 1;
}


void Player::draw(RenderWindow& window) {

    window.draw(sprite);
}


void Player::update(RenderWindow& window, Time deltatime, View& view) {
 
    if (Keyboard::isKeyPressed(Keyboard::Q) && x - vitesse - texture.getSize().x > 0) {
        x += -vitesse;
        view.move(-1, 0);
    }
    if (Keyboard::isKeyPressed(Keyboard::Z) && y - vitesse - texture.getSize().y - 10 > 200) {
        y += -vitesse;
        view.move(0, -1);
    }
    if (Keyboard::isKeyPressed(Keyboard::S) && y + vitesse + texture.getSize().y + 15 < window.getSize().y) {
        y += vitesse;
        view.move(0, 1);
    }
    if (Keyboard::isKeyPressed(Keyboard::D) && x + vitesse + texture.getSize().x < window.getSize().x) {
        x += vitesse;
        view.move(1, 0);
    }


    sprite.setPosition(x, y);
    window.setView(view);
    draw(window);



}