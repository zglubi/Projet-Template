#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Map.h"
#include "Projectile.h"
#include "Katana.h"
#include "Shuriken.h"
#include "Useful.h"
#include "Door.h"

class Boss;

class Player : public Entity
{
public:
    float getVitesse() const;
    void setVitesse(float newVitesse);
    bool canmove = true;
	bool isOnStairs = false;
    void setSprite(const Sprite& newSprite);

    Player(Texture& texture, Texture& projTexture, Texture& katanaSlashTexture, int x, int y);

    void update(RenderWindow& window, float deltatime, View& view) override;
    void draw(RenderWindow& window) override;
    void handleInput(RenderWindow& window, View& view, vector<unique_ptr<Wall>>& walls, vector<unique_ptr<Door>>& doors, vector<shared_ptr<Enemy>>& enemies, float deltatime, Map& gamemap, shared_ptr<Boss> boss);
	void shoot(RenderWindow& window, View& view);
    void katanaSlash(RenderWindow& window, vector<shared_ptr<Enemy>>& enemies, shared_ptr<Boss> boss);
    void addToInventory(int item);
	vector<int> getInventory();
    bool getWilderness() const;
    void diminishHp(int damage);
    size_t getHp() const;
    void hpUp();

private:
    int frame;
    float vitesse;
    size_t hp;
    int dir;
    bool attacking;
    vector<int> inventory;
    bool isWilderness = true;

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