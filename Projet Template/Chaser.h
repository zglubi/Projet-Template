#pragma once
#ifndef CHASER_H
#define CHASER_H

#include "Enemy.h"
#include "Player.h"
#include "HUD.h"
#include <SFML/Graphics.hpp>

class Chaser : public Enemy {
private:
    float initialSpeed;
    int moveX;
    int moveY;

public:
    Chaser(Texture& texture, Vector2f startPosition, float initialSpeed);

    void collisionPlayer(shared_ptr<Player>& player) override;
    void collisionWall(vector<unique_ptr<Wall>>& walls) override;
    void update(RenderWindow& window, float deltatime, View& view) override;
    void draw(RenderWindow& window) override;
};


#endif // CHASER_H