#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Map.h"
#include "Projectile.h"

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
    void katanaSlash(RenderWindow& window);
private:
    int frame;
    float vitesse;
    Sprite sprite;
    char hand1;
    char hand2;
    int dir;

	Texture projectileTexture;
	vector<unique_ptr<Projectile>> projectiles;
	Clock cooldownProjectile;

    int frameKatanaSlash;
    Texture katanaSlashTexture;
    Sprite katanaSlashSprite;
    bool katanaAttack = false;
    Clock cooldownKatanaSlash;
};

#endif // !PLAYER_H