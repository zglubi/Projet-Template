#pragma once
#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include <vector>
#include <memory>
#include "Player.h"
#include "Enemy.h"
#include "Chaser.h"
#include "Shooter.h"
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
	shared_ptr<Player> player;

	EntityManager();
public:
	static EntityManager* getInstance();

	void addChaser(Vector2f startPosition, float initialSpeed);
	void addShooter(Vector2f startPosition, float initialSpeed);
	void setPlayer(float x, float y);
	void update(RenderWindow& window, float deltatime, View& view, vector<unique_ptr<Wall>>& walls);

	template <typename T>
	void removeEntity(T enemies);
};

#endif // ENTITYMANAGER_H

