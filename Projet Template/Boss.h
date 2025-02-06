#ifndef BOSS_H
#define BOSS_H

#include "Enemy.h"
#include "Player.h"
#include "Projectile.h"
#include "Useful.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Boss : public Enemy {
private:
    float initialSpeed;
    int moveX;
    int moveY;
    vector<unique_ptr<Projectile>> projectiles;
    Texture projectileTexture;
    Texture slashTexture;
    Sprite slashSprite;
    size_t slashFrame;
    Vector2f slashDir;
    bool katanaAttack = false;
    bool attacking = false;
    Clock cooldownslash;

    float fireCooldown;
    float fireTimer;

public:
    Boss(Texture& texture, Texture& projTexture, Texture& SlashTexture, Vector2f startPosition, float initialSpeed);
    void collisionPlayer(shared_ptr<Player>& player) override;
    void collisionWall(vector<unique_ptr<Wall>>& walls) override;
    void update(RenderWindow& window, float deltatime, View& view) override;
    void draw(RenderWindow& window) override;
    void fireProjectile(Vector2f direction);
    void slash(RenderWindow& window, shared_ptr<Player>& player);
};

#endif // BOSS_H