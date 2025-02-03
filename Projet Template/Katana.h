#pragma once
#ifndef KATANA_H
#define KATANA_H

#include "Item.h"
#include "Player.h"

class Katana : public Item
{
public:
    Katana(float x, float y);
    void update(RenderWindow& window, float deltatime, View& view) override;
    void draw(RenderWindow& window) override;
    void interact(shared_ptr<Player>& player) override;
};

#endif // KATANA_H