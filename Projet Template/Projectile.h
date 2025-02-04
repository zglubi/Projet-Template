#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "Wall.h"


class Enemy;

class Player;

class Projectile : public Entity
{
private:
	float speed;
	float damage;
	Vector2f direction;
	size_t frame;
	size_t maxFrame;
	size_t height;
	size_t width;

public:
	Projectile(Texture t, Vector2f position, Vector2f direction, float speed, float damage, size_t maxF, size_t w, size_t h);
	~Projectile();
	void update(RenderWindow& window, float deltatime, View& view) override;
	void collision(std::vector<unique_ptr<Wall>>& walls);
	void collisionEnemies(std::vector<shared_ptr<Enemy>>& enemies);
	void collisionPlayer(shared_ptr<Player>& player);
	void draw(sf::RenderWindow& window) override;
	void setDirection(Vector2f direction);
	Vector2f getDirection();
	Vector2f getPosition();
	float getDamage();
};

#endif // PROJECTILE_H