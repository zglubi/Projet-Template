#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include "Map.h"

class Player : public Entity
{
public:
    float getVitesse() const;
    void setVitesse(float newVitesse);
    bool canmove = true;
    const Sprite& getSprite() const;
    void setSprite(const Sprite& newSprite);

    Player(int x, int y);

    void update(RenderWindow& window, Time deltatime, View& view) override;
    void draw(RenderWindow& window) override;
    void move(RenderWindow& window, View& view, vector<unique_ptr<Wall>>& walls);
private:
    float vitesse;
    Sprite sprite;
};

#endif // !PLAYER_H