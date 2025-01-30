#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy : public Entity
{
public:
    float speed;

    Enemy(float x, float y, float speed);

    void update(RenderWindow& window, Time deltatime, View& view) override;
    void draw(RenderWindow& window) override;

    float getSpeed() const;
    void setSpeed(float newSpeed);
};

#endif // !ENEMY_H