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
	sprite.setOrigin(sprite.getGlobalBounds().width / 2.f, sprite.getGlobalBounds().height / 2.f);
	sprite.setPosition(startPosition);
	
	moveX = 0;
	moveY = 0;
}

void Chaser::collisionPlayer(shared_ptr<Player>& player)
{
	if (sprite.getGlobalBounds().intersects(player->getSprite().getGlobalBounds()))
	{
		player->setToBeDeleted(true);
		setToBeDeleted(true);
	}
}

void Chaser::update(RenderWindow& window, float deltatime, View& view) 
{
	Vector2f playerPos = view.getCenter();
	Vector2f enemyPos = sprite.getPosition();
	moveX = (playerPos.x > enemyPos.x) - (playerPos.x < enemyPos.x);
	moveY = (playerPos.y > enemyPos.y) - (playerPos.y < enemyPos.y);

	velocity.x = moveX * speed;
	velocity.y = moveY * speed;

	float distanceX = abs(playerPos.x - enemyPos.x);
	float distanceY = abs(playerPos.y - enemyPos.y);

	if (frame / 10 > 3)
	{
		frame = 0;
	}
	else
	{
		frame++;
	}
	
	if (distanceX > distanceY) { // Mouvement principalement horizontal
		if (moveX > 0) {
			// Vers la droite
			sprite.setTextureRect(IntRect(16 * 3, 0 + 16 * (frame / 10), 16, 16));
		}
		else {
			// Vers la gauche
			sprite.setTextureRect(IntRect(16 * 2, 0 + 16 * (frame / 10), 16, 16));
		}
	}
	else { // Mouvement principalement vertical
		if (moveY > 0) {
			// Vers le bas
			sprite.setTextureRect(IntRect(0, 0 + 16 * (frame / 10), 16, 16));
		}
		else {
			// Vers le haut
			sprite.setTextureRect(IntRect(16, 0 + 16 * (frame / 10), 16, 16));
		}
	}
	sprite.move(velocity * deltatime);

	draw(window);
}

void Chaser::draw(RenderWindow& window) {
	window.draw(sprite);
}