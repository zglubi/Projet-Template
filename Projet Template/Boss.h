#ifndef BOSS_H
#define BOSS_H

#include "Enemy.h"
#include "Player.h"
#include "Projectile.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Boss : public Enemy {
private:
    float initialSpeed;
    int moveX;
    int moveY;
    vector<unique_ptr<Projectile>> projectiles;
    Texture projectileTexture;
    float fireCooldown;
    float fireTimer;

public:
    Boss(Texture& texture, Vector2f startPosition, float initialSpeed);
    void collisionPlayer(shared_ptr<Player>& player) override;
    void update(RenderWindow& window, float deltatime, View& view) override;
    void draw(RenderWindow& window) override;
    void fireProjectile(Vector2f direction);
};

#endif // BOSS_H