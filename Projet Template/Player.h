#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Map.h"
#include "Projectile.h"
#include "Katana.h"
#include "Shuriken.h"
#include "Enemy.h"

class Player : public Entity
{
public:
    float getVitesse() const;
    void setVitesse(float newVitesse);
    bool canmove = true;
	bool isOnStairs = false;
    const Sprite& getSprite() const;
    void setSprite(const Sprite& newSprite);

    Player(int x, int y);

    void update(RenderWindow& window, float deltatime, View& view) override;
    void draw(RenderWindow& window) override;
    void handleInput(RenderWindow& window, View& view, vector<unique_ptr<Wall>>& walls, vector<shared_ptr<Enemy>>& enemies, float deltatime);
	void shoot(RenderWindow& window, View& view);
    void meleeAttack(RenderWindow& window, View& view);
    void katanaSlash(RenderWindow& window, vector<shared_ptr<Enemy>>& enemies);
    void addToInventory(int item);
private:
    int frame;
    float vitesse;
    Sprite sprite;
    char hand1;
    char hand2;
    int dir;
    vector<int> inventory;

	Texture projectileTexture;
	vector<unique_ptr<Projectile>> projectiles;
	Clock cooldownProjectile;

    int frameKatanaSlash;
    Texture katanaSlashTexture;
    Sprite katanaSlashSprite;
    bool katanaAttack = false;
    Clock cooldownKatanaSlash;
    Vector2f slashDir;
};

#endif // !PLAYER_H