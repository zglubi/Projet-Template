#include "Shooter.h"

Shooter::Shooter(sf::Vector2f startPosition, float initialSpeed)
    : Enemy(startPosition.x, startPosition.y, initialSpeed), initialSpeed(initialSpeed), moveX(0), moveY(0), fireCooldown(1.0f), fireTimer(0.0f)
{
    if (!texture.loadFromFile("assets/enemy_assets/shooter.png")) {
        std::cerr << "Error loading shooter texture" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(startPosition);
    sprite.setOrigin(16, 16);
    sprite.setScale(2, 2);
}

void Shooter::moveUpdate(Player* player)
{
    sf::Vector2f playerPos = player->getSprite().getPosition();
    sf::Vector2f enemyPos = sprite.getPosition();
    moveX = (playerPos.x > enemyPos.x) - (playerPos.x < enemyPos.x);
    moveY = (playerPos.y > enemyPos.y) - (playerPos.y < enemyPos.y);
}

void Shooter::update(sf::RenderWindow& window, float deltatime, sf::View& view)
{
    sf::Vector2f playerPos = view.getCenter();
    sf::Vector2f enemyPos = sprite.getPosition();
    moveX = (playerPos.x > enemyPos.x) - (playerPos.x < enemyPos.x);
    moveY = (playerPos.y > enemyPos.y) - (playerPos.y < enemyPos.y);

    enemyPos.x += moveX * initialSpeed * deltatime;
    enemyPos.y += moveY * initialSpeed * deltatime;
    sprite.setPosition(enemyPos);

    // Update the fire timer
    fireTimer += deltatime;
    // Check if it's time to fire a new projectile
    if (fireTimer >= fireCooldown)
    {
        // Calculate the direction to the player
        sf::Vector2f direction = playerPos - enemyPos;
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
    projectiles.erase(std::remove_if(projectiles.begin(), projectiles.end(),
        [&window](const std::unique_ptr<Projectile>& projectile) {
            return projectile->getSprite().getPosition().x < 0 || projectile->getSprite().getPosition().y < 0 ||
                projectile->getSprite().getPosition().x > window.getSize().x ||
                projectile->getSprite().getPosition().y > window.getSize().y;
        }),
        projectiles.end());
}

void Shooter::draw(sf::RenderWindow& window)
{
    window.draw(sprite);

    // Draw projectiles
    for (const auto& projectile : projectiles)
    {
        projectile->draw(window);
    }
}

void Shooter::fireProjectile(sf::Vector2f direction)
{
    sf::Vector2f startPosition = sprite.getPosition();
    float speed = 300.0f; // Example speed value
    float damage = 10.0f; // Example damage value
    projectiles.emplace_back(std::make_unique<Projectile>(projectileTexture, startPosition, direction, speed, damage));
}
