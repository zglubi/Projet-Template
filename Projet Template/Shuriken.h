#pragma once
#ifndef SHURIKEN_H
#define SHURIKEN_H

#include "Item.h"
#include "Player.h"

class Shuriken : public Item
{
public:
    Shuriken(float x, float y);
    void update(RenderWindow& window, float deltatime, View& view) override;
    void draw(RenderWindow& window) override;
    void interact(shared_ptr<Player>& player)override;
};

#endif // SHURIKEN_H