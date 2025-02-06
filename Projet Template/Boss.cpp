#include "Boss.h"

Boss::Boss(Texture& texture, Texture& projTexture, Texture& SlashTexture, Vector2f startPosition, float initialSpeed)
    : Enemy(texture, startPosition.x, startPosition.y, initialSpeed), initialSpeed(initialSpeed), moveX(0), moveY(0), fireCooldown(1.3f), fireTimer(0.0f)
{
    projectileTexture = projTexture;
    slashTexture = SlashTexture;

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

void Boss::collisionWall(vector<unique_ptr<Wall>>& walls)
{
    for (auto& projectile : projectiles)
    {
        projectile->collision(walls);
    }
}

void Boss::collisionWall(vector<unique_ptr<Wall>>& walls)
{
    for (auto& projectile : projectiles)
    {
        projectile->collision(walls);
    }
}

void Boss::update(RenderWindow& window, float deltatime, View& view)
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

    animationTimer += deltatime;
    if (animationTimer >= 0.1f) { // 100ms
        currentFrame = (currentFrame + 1) % 6; // 6 frames dans le sprite
        animationTimer = 0.0f;
    }

    sprite.setTextureRect(IntRect(96 * currentFrame, 0, 96, 48));
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
    projectiles.erase(std::remove_if(projectiles.begin(), projectiles.end(),
        [&window](const std::unique_ptr<Projectile>& projectile) {
            return (projectile->getSprite().getPosition().x < 0 || projectile->getSprite().getPosition().y < 0 ||
                projectile->getSprite().getPosition().x > window.getSize().x ||
                projectile->getSprite().getPosition().y > window.getSize().y) || projectile->toBeDeleted;
        }),
        projectiles.end());
    draw(window);
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
    float speed = 500.0f;
    float damage = 15.0f;
    projectiles.emplace_back(make_unique<Projectile>(projectileTexture, startPosition, direction, speed, damage, 4, 24, 24));
}