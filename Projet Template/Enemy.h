#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "Player.h"
#include <SFML/System.hpp>

using namespace sf;

class Enemy : public Entity
{
public:
    Vector2f position;
    Vector2f velocity;
    size_t hp;
    float speed;
    int frame = 0;
    Enemy(float x, float y, float speed);
    virtual void collisionPlayer(shared_ptr<Player>& player) = 0;
    virtual void collisionWall(vector<unique_ptr<Wall>>& walls) = 0;
    virtual void update(RenderWindow& window, float deltatime, View& view) = 0;
    virtual void draw(RenderWindow& window) = 0;
};

#endif // ENEMY_H