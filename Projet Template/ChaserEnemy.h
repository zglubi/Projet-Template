#pragma once
#ifndef CHASERENEMY_H
#define CHASERENEMY_H

#include "Enemy.h"

class ChaserEnemy : public Enemy
{
public:
    float detectionRange;
    float stopRange;
    Vector2f playerPosition;

    ChaserEnemy(float x, float y, float speed, float detectionRange, float stopRange);
    void update(RenderWindow& window, Time deltatime, View& view) override;
    void draw(RenderWindow& window) override;
    void setPlayerPosition(const Vector2f& position);
};

#endif // CHASERENEMY_H