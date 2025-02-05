#include "Chaser.h"
#include <iostream>

Chaser::Chaser(Texture& texture, Vector2f startPosition, float initialSpeed)
	: initialSpeed(initialSpeed), Enemy(texture, startPosition.x, startPosition.y, initialSpeed) 
{
	sprite.setTextureRect(IntRect(0, 0, 16, 16));
	sprite.setScale(2, 2);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2.f, sprite.getGlobalBounds().height / 2.f);
	
	moveX = 0;
	moveY = 0;
}

void Chaser::collisionPlayer(shared_ptr<Player>& player)
{
	if (sprite.getGlobalBounds().intersects(player->getSprite().getGlobalBounds()))
	{
		player->diminishHp(1);
		hp -= 1;
	}
}

void Chaser::collisionWall(vector<unique_ptr<Wall>>& walls)
{

}

void Chaser::update(RenderWindow& window, float deltatime, View& view) 
{
	if (hp <= 0 || hp > 10) {
		setToBeDeleted(true);
	}
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
	
	if (distanceX > distanceY) { 
		if (moveX > 0) {
			
			sprite.setTextureRect(IntRect(16 * 3, 0 + 16 * (frame / 10), 16, 16));
		}
		else {
			sprite.setTextureRect(IntRect(16 * 2, 0 + 16 * (frame / 10), 16, 16));
		}
	}
	else { 
		if (moveY > 0) {

			sprite.setTextureRect(IntRect(0, 0 + 16 * (frame / 10), 16, 16));
		}
		else {

			sprite.setTextureRect(IntRect(16, 0 + 16 * (frame / 10), 16, 16));
		}
	}
	sprite.move(velocity * deltatime);

	draw(window);
}

void Chaser::draw(RenderWindow& window) {
	window.draw(sprite);
}