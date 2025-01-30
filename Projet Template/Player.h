#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"


class Player : public Entity
{
public:

    float vitesse;

    Player(int x, int y);

    void update(RenderWindow& window, Time deltatime) override;
    void draw(RenderWindow& window) override;

};


#endif // !PLAYER_H
