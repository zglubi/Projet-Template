#include "Enemy.h"

Enemy::Enemy(float x, float y, float speed) : Entity(x, y), speed(speed) {
    if (!texture.loadFromFile("assets\\enemy.png")) {
        std::cerr << "Error: unable to load 'enemy.png'" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
    sprite.setScale(Vector2f(1.5, 1.5));
}

void Enemy::update(RenderWindow& window, Time deltatime, View& view) {
    // Logic to update enemy position or behavior
    sprite.setPosition(x, y);
}

void Enemy::draw(RenderWindow& window) {
    window.draw(sprite);
}

float Enemy::getSpeed() const {
    return speed;
}

void Enemy::setSpeed(float newSpeed) {
    speed = newSpeed;
}