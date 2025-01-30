#include "Projectile.h"

Projectile::Projectile(Vector2f position, Vector2f direction, float speed, float damage) : Entity(position.x, position.y)
{
	this->direction = direction;
	this->speed = speed;
	this->damage = damage;
	texture.loadFromFile("assets/projectile.png");
	sprite.setTexture(texture);
	sprite.setPosition(position);
}

Projectile::~Projectile()
{
}

void Projectile::update(RenderWindow& window, Time deltatime, View& view)
{
	x += direction.x * speed * deltatime.asSeconds();
	y += direction.y * speed * deltatime.asSeconds();
	sprite.setPosition(x, y);
}

void Projectile::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Projectile::setDirection(Vector2f direction)
{
	this->direction = direction;
}

Vector2f Projectile::getDirection()
{
	return direction;
}

float Projectile::getDamage()
{
	return damage;
}