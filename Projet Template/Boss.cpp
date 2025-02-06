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

}

void Boss::update(RenderWindow& window, float deltatime, View& view) 
{
	Vector2f playerPos = view.getCenter();
	Vector2f enemyPos = sprite.getPosition();
	float distanceX = abs(playerPos.x - enemyPos.x);
	float distanceY = abs(playerPos.y - enemyPos.y);
	float distance = sqrt(distanceX * distanceX + distanceY * distanceY);

    moveX = (playerPos.x > enemyPos.x) - (playerPos.x < enemyPos.x);
    moveY = (playerPos.y > enemyPos.y) - (playerPos.y < enemyPos.y);

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
	float speed = 200.0f;
	float damage = 15.0f;
	projectiles.emplace_back(make_unique<Projectile>(projectileTexture, startPosition, direction, 600, 10, 2, 16, 16));
}

//Vector2f normalize(const Vector2f& source)
//{
//    float length = sqrt(source.x * source.x + source.y * source.y);
//    if (length != 0)
//        return Vector2f(source.x / length, source.y / length);
//    else
//        return source;
//}
//
//float dotProduct(const Vector2f& v1, const Vector2f& v2)
//{
//    return v1.x * v2.x + v1.y * v2.y;
//}
//
//float magnitude(const Vector2f& v) {
//    return sqrt(v.x * v.x + v.y * v.y);
//}
//
//float calculateAngle(const Vector2f& direction) {
//    Vector2f normalizedDirection = normalize(direction);
//    Vector2f reference(1.0f, 0.0f); // Vecteur de référence (axe des x)
//    float dot = dotProduct(normalizedDirection, reference);
//    float angle = acos(dot); // Angle en radians
//
//    // Déterminer le signe de l'angle en utilisant le produit vectoriel
//    float cross = reference.x * normalizedDirection.y - reference.y * normalizedDirection.x;
//    if (cross < 0)
//    {
//        angle = -angle;
//    }
//
//    return angle * 180 / 3.14159265;
//}

void Boss::slash(RenderWindow& window, shared_ptr<Player>& player)
{
    if (slashFrame == 0)
    {
        slashDir = player->getSprite().getPosition() - getSprite().getPosition();
        slashDir = normalize(slashDir);
    }

    if (slashFrame / 10 > 3)
    {
        katanaAttack = false;
        attacking = false;
        slashFrame = 0;
        return;
    }
    else
    {
        slashFrame++;
    }

    slashSprite.setPosition(Vector2f(x, y) + (slashDir * 50));
    slashSprite.setRotation(calculateAngle(slashDir));
    slashSprite.setTextureRect(IntRect(0 + 32 * (slashFrame / 10), 0, 32, 32));
    window.draw(slashSprite);


    if (slashSprite.getGlobalBounds().intersects(player->getSprite().getGlobalBounds()))
    {
        player->diminishHp(1);
    }
}