#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"

class Projectile : public Entity
{
private:
    float speed;
    float damage;
    sf::Vector2f direction;
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Projectile(sf::Vector2f position, sf::Vector2f direction, float speed, float damage);
    ~Projectile();
    void update(sf::RenderWindow& window, float deltatime, sf::View& view) override;
    void draw(sf::RenderWindow& window) override;
    void setDirection(sf::Vector2f direction);
    sf::Vector2f getDirection();
    float getDamage();
    sf::Vector2f getPosition() const { return sprite.getPosition(); } // Added to get position
};

#endif // PROJECTILE_H