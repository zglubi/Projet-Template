#ifndef BOSS_H
#define BOSS_H

#include "Enemy.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

class Boss : public Enemy {
private:
    float initialSpeed;
    int moveX;
    int moveY;

public:
    Boss(Vector2f startPosition, float initialSpeed);

    void collisionPlayer(shared_ptr<Player>& player) override;
    void update(RenderWindow& window, float deltatime, View& view) override;
    void draw(RenderWindow& window) override;
};

#endif // BOSS_H