#include "Chaser.h"
#include <iostream>

Chaser::Chaser(Vector2f startPosition, float initialSpeed)
	: initialSpeed(initialSpeed), Enemy(startPosition.x, startPosition.y, initialSpeed) {
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


void Chaser::update(RenderWindow& window, float deltatime, View& view) 
{
	Vector2f playerPos = view.getCenter();
	Vector2f enemyPos = sprite.getPosition();
	moveX = (playerPos.x > enemyPos.x) - (playerPos.x < enemyPos.x);
	moveY = (playerPos.y > enemyPos.y) - (playerPos.y < enemyPos.y);

	velocity.x = moveX * speed;
	velocity.y = moveY * speed;
	sprite.move(velocity * deltatime);

	draw(window);
}

void Chaser::draw(RenderWindow& window) {
	window.draw(sprite);
}