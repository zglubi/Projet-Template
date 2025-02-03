#pragma once
#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include <vector>
#include <memory>
#include "Player.h"
#include "Enemy.h"
#include "Chaser.h"
#include "Shooter.h"
#include "Medipack.h"
#include <SFML/Graphics.hpp>
#include "Wall.h"
using namespace std;
using namespace sf;

class EntityManager
{
private:
	static EntityManager* instance;
	vector<shared_ptr<Entity>> entities;
	vector<shared_ptr<Chaser>> chasers;
	vector<shared_ptr<Shooter>> shooters;
	vector<shared_ptr<Item>> items;
	shared_ptr<Player> player;

	EntityManager();
public:
	static EntityManager* getInstance();

	void addChaser(Vector2f startPosition, float initialSpeed);
	void addShooter(Vector2f startPosition, float initialSpeed);
	void addItem(Vector2f Position, int val);
	void setPlayer(float x, float y);
	void update(RenderWindow& window, float deltatime, View& view, vector<unique_ptr<Wall>>& walls);

	
	void removeEntity();
};

#endif // ENTITYMANAGER_H

