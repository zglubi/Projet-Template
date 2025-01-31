#include "Projectile.h"

Projectile::Projectile(Texture t, Vector2f position, Vector2f direction, float speed, float damage) : Entity(position.x, position.y)
{
	if (abs(direction.x) > abs(direction.y))
	{
		direction /= abs(direction.x);
	}
	else if (abs(direction.y) > abs(direction.x))
	{
		direction /= abs(direction.y);
	}
	this->direction = direction;
	this->speed = speed;
	this->damage = damage;
	texture = t;
	sprite.setTexture(texture);
	sprite.setPosition(position);
	sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
	sprite.setScale(Vector2f(2, 2));
	frame = 0;
}

Projectile::~Projectile() {}

void Projectile::update(RenderWindow& window, float deltatime, View& view)
{
	x += direction.x * speed * deltatime;
	y += direction.y * speed * deltatime;
	sprite.setPosition(x, y);

	draw(window);

	if (frame / 10 > 1)
	{
		frame = 0;
	}
	else
	{
		frame++;
	}

	sprite.setTextureRect(IntRect(0 + 16 * (frame / 10), 0, 16, 16));
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