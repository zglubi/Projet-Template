#include "Shooter.h"

Shooter::Shooter(Texture& texture, Texture& projTexture, Vector2f startPosition, float initialSpeed)
    : Enemy(texture, startPosition.x, startPosition.y, initialSpeed), initialSpeed(initialSpeed), moveX(0), moveY(0), fireCooldown(1.3f), fireTimer(0.0f)
{
    projectileTexture = projTexture;

    sprite.setTextureRect(IntRect(0, 0, 16, 16));
    sprite.setScale(2, 2);
    sprite.setOrigin(sprite.getGlobalBounds().width / 2.f, sprite.getGlobalBounds().height / 2.f);
}

void Shooter::collisionPlayer(shared_ptr<Player>& player)
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

void Shooter::collisionWall(vector<unique_ptr<Wall>>& walls) 
{
    for (auto& projectile : projectiles)
    {
        projectile->collision(walls);
    }
}

void Shooter::update(RenderWindow& window, float deltatime, View& view)
{
    Vector2f playerPos = view.getCenter();
    Vector2f enemyPos = sprite.getPosition();
    float distanceX = abs(playerPos.x - enemyPos.x);
    float distanceY = abs(playerPos.y - enemyPos.y);
    float distance = sqrt(distanceX * distanceX + distanceY * distanceY);

    if (distance > 500.0f) {
        // S'approcher du joueur
        moveX = (playerPos.x > enemyPos.x) - (playerPos.x < enemyPos.x);
        moveY = (playerPos.y > enemyPos.y) - (playerPos.y < enemyPos.y);
    }
    else if (distance < 400.0f) {
        // Reculer du joueur
        moveX = (playerPos.x < enemyPos.x) - (playerPos.x > enemyPos.x);
        moveY = (playerPos.y < enemyPos.y) - (playerPos.y > enemyPos.y);
    }
    else {
        // Ne pas bouger
        moveX = 0;
        moveY = 0;
    }

    enemyPos.x += moveX * initialSpeed * deltatime;
    enemyPos.y += moveY * initialSpeed * deltatime;

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
    sprite.setPosition(enemyPos);

    // Update the fire timer
    fireTimer += deltatime;
    // Check if it's time to fire a new projectile
    if (fireTimer >= fireCooldown)
    {
        // Calculate the direction to the player
        Vector2f direction = playerPos - enemyPos;
        float length = sqrt(direction.x * direction.x + direction.y * direction.y);
        direction /= length; // Normalize the direction vector

        // Fire a new projectile
        fireProjectile(direction);

        // Reset the fire timer
        fireTimer = 0.0f;
    }

    // Update projectiles
    for (auto& projectile : projectiles)
    {
        projectile->update(window, deltatime, view);
    }

    // Remove projectiles that go out of the window bounds (optional)
    projectiles.erase(remove_if(projectiles.begin(), projectiles.end(),
        [&window](const unique_ptr<Projectile>& projectile) {
            return (projectile->getSprite().getPosition().x < 0 || projectile->getSprite().getPosition().y < 0 ||
                projectile->getSprite().getPosition().x > 3960 ||
                projectile->getSprite().getPosition().y > 3960) || projectile->toBeDeleted;
        }),
        projectiles.end());
    draw(window);
}




void Shooter::draw(RenderWindow& window)
{
    window.draw(sprite);

    // Draw projectiles
    for (const auto& projectile : projectiles)
    {
        projectile->draw(window);
    }
}

void Shooter::fireProjectile(Vector2f direction)
{
    Vector2f startPosition = sprite.getPosition();
    float speed = 300.0f;
    float damage = 10.0f;
    projectiles.emplace_back(make_unique<Projectile>(projectileTexture, startPosition, direction, speed, damage, 4, 24, 24));
}
