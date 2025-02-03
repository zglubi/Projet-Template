#ifndef STAIRS_H
#define STAIRS_H

#include "Wall.h"
#include "Interactable.h"

class Stairs : public Wall, public Interactable
{
private:
    bool isOnStairs = false;

public:
    Stairs(float x, float y, char t);
    void interact(std::shared_ptr<Player>& player) override;
    bool checkPlayerOnStairs(const Sprite& playerSprite);
};

#endif // STAIRS_H