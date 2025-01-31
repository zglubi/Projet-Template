#include "Chaser.h"
#include <iostream>

Chaser::Chaser(Vector2f startPosition, float initialSpeed)
	: Enemy(startPosition.x, startPosition.y, initialSpeed) {
	if (!texture.loadFromFile("assets/Skeleton.png")) {
		cout << "Failed to load enemy texture!" << endl;
	}
	sprite.setTexture(texture);
	sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
	sprite.setPosition(startPosition);
	sprite.setScale(0.125, 0.125);
	moveX = 0;
	moveY = 0;
}

void Chaser::moveUpdate(shared_ptr<Player> player)
{
	if (player->getSprite().getPosition().x > sprite.getPosition().x) 
	{
		moveX = 1;
	}
	else if (player->getSprite().getPosition().x < sprite.getPosition().x) 
	{
		moveX = -1;
	}
	else {
		moveX = 0;
	}

	if (player->getSprite().getPosition().y > sprite.getPosition().y) 
	{
		moveY = 1;
	}
	else if (player->getSprite().getPosition().y < sprite.getPosition().y) 
	{
		moveY = -1;
	}
	else 
	{
		moveY = 0;
	}
}

void Chaser::update(RenderWindow& window, float deltatime, View& view) 
{
	velocity.x = moveX * speed;
	velocity.y = moveY * speed;
	sprite.move(velocity * deltatime);
}

void Chaser::draw(RenderWindow& window) {
	window.draw(sprite);
}