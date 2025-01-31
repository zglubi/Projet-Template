#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include <SFML/System.hpp>

using namespace sf;

class Enemy : public Entity
{
public:
    Vector2f position;
    Vector2f velocity;
    float speed;

    Enemy(float x, float y, float speed);
    virtual void update(RenderWindow& window, float deltatime, View& view) = 0;
    virtual void draw(RenderWindow& window) = 0;
};

#endif // ENEMY_H