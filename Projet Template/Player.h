#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Map.h"
#include "Projectile.h"
#include "Katana.h"
#include "Shuriken.h"

class Player : public Entity
{
public:
    float getVitesse() const;
    void setVitesse(float newVitesse);
    bool canmove = true;
    const Sprite& getSprite() const;
    void setSprite(const Sprite& newSprite);

    Player(int x, int y);

    void update(RenderWindow& window, float deltatime, View& view) override;
    void draw(RenderWindow& window) override;
    void handleInput(RenderWindow& window, View& view, vector<unique_ptr<Wall>>& walls);
    void shoot(RenderWindow& window, View& view);
    void meleeAttack(RenderWindow& window, View& view);

    void setHasKatana(bool value);
    void setHasShuriken(bool value);

    bool checkCollisionWithItem(Item& item);

private:
    float vitesse;
    Sprite sprite;
    Texture projectileTexture;
    vector<unique_ptr<Projectile>> projectiles;
    Clock cooldownProjectile;
    bool hasKatana = false;
    bool hasShuriken = false;
};

#endif // !PLAYER_H