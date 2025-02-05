#include "Projectile.h"
#include "Player.h"
#include "Enemy.h"

Projectile::Projectile(Texture& texture, Vector2f position, Vector2f direction, float speed, float damage, size_t maxF, size_t w, size_t h) : Entity(texture, position.x, position.y)
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
	sprite.setTexture(texture);
	
	sprite.setTextureRect(IntRect(0, 0, texture.getSize().x / maxF, texture.getSize().y));
	sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);
	sprite.setScale(Vector2f(2, 2));

	frame = 0;
	maxFrame = maxF;
	height = h;
	width = w;
	float angle = std::atan2(direction.y, direction.x) * 180 / 3.14159f;
	sprite.setRotation(angle+90);
}

Projectile::~Projectile() {}

void Projectile::update(sf::RenderWindow& window, float deltatime, sf::View& view)
{

	x += direction.x * speed * deltatime;
	y += direction.y * speed * deltatime;
	sprite.setPosition(x, y);

	if (frame / 10 > maxFrame - 1)
	{
		frame = 0;
	}
	else
	{
		frame++;
	}

	sprite.setTextureRect(IntRect(0 + width * (frame / 10), 0, width, height));

	draw(window);
}

void Projectile::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

void Projectile::setDirection(sf::Vector2f direction)
{
    this->direction = direction;
}

sf::Vector2f Projectile::getDirection()
{
    return direction;
}

float Projectile::getDamage()
{
    return damage;
}

void Projectile::collision(std::vector<unique_ptr<Wall>>& walls)
{
	for (size_t i = 0; i < walls.size(); i++)
	{
		if (sprite.getGlobalBounds().intersects(walls[i]->getSprite().getGlobalBounds()))
		{
			setToBeDeleted(true);
			break;
		}
	}
}

void Projectile::collisionEnemies(std::vector<shared_ptr<Enemy>>& enemies)
{
	for (size_t i = 0; i < enemies.size(); i++)
	{
		if (sprite.getGlobalBounds().intersects(enemies[i]->getSprite().getGlobalBounds()))
		{
			enemies[i]->setToBeDeleted(true);
			setToBeDeleted(true);
			break;
		}
	}
}

void Projectile::collisionPlayer(shared_ptr<Player>& player)
{
	if (sprite.getGlobalBounds().intersects(player->getSprite().getGlobalBounds()))
	{
		player->diminishHp(damage);
		setToBeDeleted(true);
	}
}

Vector2f Projectile::getPosition()
{
	return Vector2f(x, y);
}