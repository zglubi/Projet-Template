#include "ChaserEnemy.h"

ChaserEnemy::ChaserEnemy(float x, float y, float speed, float detectionRange, float stopRange)
    : Enemy(x, y, speed), detectionRange(detectionRange), stopRange(stopRange) {
}

void ChaserEnemy::update(RenderWindow& window, Time deltatime, View& view)
{
    Vector2f direction = playerPosition - position;
    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance < detectionRange && distance > stopRange) {
        direction /= distance; // Normalize the direction vector
        velocity = direction * speed * deltatime.asSeconds();
        position += velocity;
        sprite.setPosition(position);
    }
    else {
        velocity = Vector2f(0, 0);
    }
}

void ChaserEnemy::draw(RenderWindow& window)
{
    window.draw(sprite);
}

void ChaserEnemy::setPlayerPosition(const Vector2f& position)
{
    playerPosition = position;
}