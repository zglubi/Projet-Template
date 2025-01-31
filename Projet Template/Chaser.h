#pragma once
#ifndef CHASER_H
#define CHASER_H

#include "Enemy.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

class Chaser : public Enemy {
private:
    Texture texture;
    Sprite sprite;
    float initialSpeed;
    int moveX;
    int moveY;

public:
    Chaser(Vector2f startPosition, float initialSpeed);

    void moveUpdate(Player* player);
    void update(RenderWindow& window, float deltatime, View& view) override;
    void draw(RenderWindow& window) override;
};


#endif // CHASER_H