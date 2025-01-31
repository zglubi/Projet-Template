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
	Vector2f direction;
public:
	Projectile(Texture t, Vector2f position, Vector2f direction, float speed, float damage);
	~Projectile();
	void update(RenderWindow& window, float deltatime, View& view) override;
	void draw(sf::RenderWindow& window) override;
	void setDirection(Vector2f direction);
	Vector2f getDirection();
	Vector2f getPosition();
	float getDamage();
};

#endif // PROJECTILE_H