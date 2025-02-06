#pragma once
#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include <vector>
#include <memory>
#include "Player.h"
#include "Enemy.h"
#include "Chaser.h"
#include "Shooter.h"
#include "Boss.h"
#include "Medipack.h"
#include "Katana.h"
#include "Shuriken.h"
#include <SFML/Graphics.hpp>
#include "Wall.h"
using namespace std;
using namespace sf;

class EntityManager
{
private:
	static EntityManager* instance;
	vector<shared_ptr<Entity>> entities;
	vector<shared_ptr<Enemy>> enemies;
	vector<shared_ptr<Item>> items;
	shared_ptr<Boss> boss;
	shared_ptr<Player> player;
	size_t mobCap;

	Texture playerTexture;
	Texture chaserTexture;
	Texture shooterTexture;
	Texture medipackTexture;
	Texture katanaTexture;
	Texture shurikenTexture;
	Texture playerProjectileTexture;
	Texture katanaSlashTexture;
	Texture shooterProjectileTexture;
	Texture bossTexture;
	Texture bossProjectileTexture;
	Texture bossSlashTexture;

	EntityManager();
public:
	static EntityManager* getInstance();

	void addChaser(Vector2f startPosition, float initialSpeed);
	void addShooter(Vector2f startPosition, float initialSpeed);
	void addBoss(Vector2f startPosition, float initialSpeed);
	void addItem(Vector2f Position, int val);
	void setPlayer(float x, float y);
	shared_ptr<Player> getPlayer();
	void update(RenderWindow& window, float deltatime, View& view, vector<unique_ptr<Wall>>& walls, vector<unique_ptr<Door>>& doors);
	vector<shared_ptr<Enemy>> getEnemies();

	void setTextures(vector<Texture>& textures);

	void spawnEnemy();
	void dispawnEnemy();
	void removeEntity();
	vector<int> getInventory();
};

#endif // ENTITYMANAGER_H

