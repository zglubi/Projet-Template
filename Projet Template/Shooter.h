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
    sf::Texture texture;
    sf::Sprite sprite;
    float initialSpeed;
    int moveX;
    int moveY;
    std::vector<unique_ptr<Projectile>> projectiles; // Store the projectiles
	Texture projectileTexture;
    float fireCooldown; // Cooldown time between shots
    float fireTimer; // Timer to track time since last shot

public:
    Shooter(sf::Vector2f startPosition, float initialSpeed);
    void moveUpdate(Player* player);
    void update(sf::RenderWindow& window, float deltatime, sf::View& view) override;
    void draw(sf::RenderWindow& window) override;
    void fireProjectile(sf::Vector2f direction); // New method to fire projectiles
};

#endif // SHOOTER_H