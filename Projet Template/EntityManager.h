#pragma once
#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include <vector>
#include <memory>
#include "Entity.h"
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
	vector<shared_ptr<Entity>> entities;
	vector<shared_ptr<Chaser>> chasers;
	vector<shared_ptr<Shooter>> shooters;
	shared_ptr<Player> player;
public:
	EntityManager();
	void addChaser(shared_ptr<Chaser> chaser);
	void addShooter(shared_ptr<Shooter> shooter);
	void setPlayer(shared_ptr<Player> player);
	void update(RenderWindow& window, float deltatime, View& view, vector<unique_ptr<Wall>>& walls);

	template <typename T>
	void removeEntity(T enemies);
};



#endif // ENTITYMANAGER_H

