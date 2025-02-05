#include "Boss.h"

Boss::Boss(Texture& texture, Texture& projTexture, Vector2f startPosition, float initialSpeed)
    : Enemy(texture, startPosition.x, startPosition.y, initialSpeed), initialSpeed(initialSpeed), moveX(0), moveY(0), fireCooldown(1.3f), fireTimer(0.0f) 
{
	projectileTexture = projTexture;

	sprite.setTextureRect(IntRect(0, 0, 25, 25));
	sprite.setScale(2, 2);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2.f, sprite.getGlobalBounds().height / 2.f);

	moveX = 0;
	moveY = 0;
}

void Boss::collisionPlayer(shared_ptr<Player>& player) 
{
	if (sprite.getGlobalBounds().intersects(player->getSprite().getGlobalBounds()))
	{
		player->diminishHp(1);
		hp -= 1;
	}
	for (auto& projectile : projectiles)
	{
		projectile->collisionPlayer(player);
	}
}

void Boss::update(RenderWindow& window, float deltatime, View& view) 
{
	Vector2f playerPos = view.getCenter();
	Vector2f enemyPos = sprite.getPosition();
	float distanceX = abs(playerPos.x - enemyPos.x);
	float distanceY = abs(playerPos.y - enemyPos.y);
	float distance = sqrt(distanceX * distanceX + distanceY * distanceY);
}

void Boss::draw(RenderWindow& window) 
{
	window.draw(sprite);

	// Draw projectiles
	for (const auto& projectile : projectiles)
	{
		projectile->draw(window);
	}
}

void Boss::fireProjectile(Vector2f direction) 
{
	Vector2f startPosition = sprite.getPosition();
	float speed = 200.0f;
	float damage = 15.0f;
	projectiles.emplace_back(make_unique<Projectile>(projectileTexture, startPosition, direction, speed, damage, 4, 24, 24));
}