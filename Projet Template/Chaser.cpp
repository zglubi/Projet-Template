#include "Chaser.h"
#include <iostream>

Chaser::Chaser(Vector2f startPosition, float initialSpeed)
	: initialSpeed(initialSpeed), Enemy(startPosition.x, startPosition.y, initialSpeed) {
	if (!texture.loadFromFile("assets/Enemies/Slime3/Slime3.png")) {
		cout << "Failed to load enemy texture!" << endl;
	}
	sprite.setTextureRect(IntRect(0, 0, 16, 16));
	sprite.setTexture(texture);
	sprite.setScale(2, 2);
	sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
	sprite.setPosition(startPosition);
	
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


	if (frame / 10 > 1)
	{
		frame = 0;
	}
	else
	{
		frame++;
	}

	sprite.setTextureRect(IntRect(0 , 0 + 16 * (frame / 10), 16, 16));



	sprite.move(velocity * deltatime);

	draw(window);
}

void Chaser::draw(RenderWindow& window) {
	window.draw(sprite);
}