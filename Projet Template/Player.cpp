#include "Player.h"
#include "Wall.h"

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

void Player::move(RenderWindow& window, View& view, vector<unique_ptr<Wall>>& walls) {
    if (Keyboard::isKeyPressed(Keyboard::Q)) {
       
        x += -vitesse;
        view.move(-vitesse, 0);

        for (auto wall = walls.begin(); wall != walls.end(); ++wall) {
            if (sprite.getGlobalBounds().intersects(wall->get()->getSprite().getGlobalBounds()))
            {
                x += +vitesse + 0.1;
                view.move(+vitesse+0.1, 0);
            }
        }
        
    }
    if (Keyboard::isKeyPressed(Keyboard::Z)) {

        y += -vitesse;
        view.move(0, -vitesse);

        for (auto wall = walls.begin(); wall != walls.end(); ++wall) {
            if (sprite.getGlobalBounds().intersects(wall->get()->getSprite().getGlobalBounds()))
            {
                y += +vitesse + 0.1;
                view.move(0, +vitesse + 0.1);
            }
        }
        
    }
    if (Keyboard::isKeyPressed(Keyboard::S)) {

        y += vitesse;
        view.move(0, vitesse);

        for (auto wall = walls.begin(); wall != walls.end(); ++wall) {
            if (sprite.getGlobalBounds().intersects(wall->get()->getSprite().getGlobalBounds()))
            {
                y += -vitesse - 0.1;
                view.move(0, -vitesse - 0.1);
            }
        }
        
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        
        x += vitesse;
        view.move(vitesse, 0);

        for (auto wall = walls.begin(); wall != walls.end(); ++wall) {
            if (sprite.getGlobalBounds().intersects(wall->get()->getSprite().getGlobalBounds()))
            {
                x += -vitesse - 0.1;
                view.move(-vitesse - 0.1, 0);
            }
        }
        
    }
    sprite.setPosition(x, y);
    window.setView(view);
}

void Player::draw(RenderWindow& window) {
    window.draw(sprite);
}

void Player::update(RenderWindow& window, Time deltatime, View& view) {

    draw(window);
}