#include "Projectile.h"

Projectile::Projectile(Texture t, Vector2f position, Vector2f direction, float speed, float damage) : Entity(position.x, position.y)
{
	this->direction = direction;
	this->speed = speed;
	this->damage = damage;
	texture = t;
	sprite.setTexture(texture);
	sprite.setPosition(position);
}

Projectile::~Projectile()
{
}

void Projectile::update(sf::RenderWindow& window, float deltatime, sf::View& view)
{
    x += direction.x * speed * deltatime;
    y += direction.y * speed * deltatime;
    sprite.setPosition(x, y);
}

void Projectile::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

void Projectile::setDirection(sf::Vector2f direction)
{
    this->direction = direction;
}

sf::Vector2f Projectile::getDirection()
{
    return direction;
}

float Projectile::getDamage()
{
    return damage;
}

Vector2f Projectile::getPosition()
{
	return Vector2f(x, y);
}