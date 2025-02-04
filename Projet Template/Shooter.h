#pragma once
#ifndef SHOOTER_H
#define SHOOTER_H

#include "Enemy.h"
#include "Player.h"
#include "Projectile.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Shooter : public Enemy {
private:
    float initialSpeed;
    int moveX;
    int moveY;
    vector<unique_ptr<Projectile>> projectiles; // Store the projectiles
	Texture projectileTexture;
    float fireCooldown; // Cooldown time between shots
    float fireTimer; // Timer to track time since last shot

public:
    Shooter(Vector2f startPosition, float initialSpeed);
    void collisionPlayer(shared_ptr<Player>& player) override;
    void update(RenderWindow& window, float deltatime, View& view) override;
    void draw(RenderWindow& window) override;
    void fireProjectile(Vector2f direction); // New method to fire projectiles
};

#endif // SHOOTER_H