#include "EntityManager.h"

EntityManager::EntityManager() {}

EntityManager* EntityManager::instance = nullptr;

EntityManager* EntityManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new EntityManager();
	}
	return instance;
}

void EntityManager::addChaser(Vector2f startPosition, float initialSpeed)
{
	shared_ptr<Chaser> chaser = make_shared<Chaser>(startPosition, initialSpeed);
	enemies.push_back(chaser);
	entities.push_back(chaser);
}

void EntityManager::addShooter(Vector2f startPosition, float initialSpeed)
{
	shared_ptr<Shooter> shooter = make_shared<Shooter>(startPosition, initialSpeed);
	enemies.push_back(shooter);
	entities.push_back(shooter);
}

void EntityManager::setPlayer(float x, float y)
{
	shared_ptr<Player> player = make_shared<Player>(x, y);
	this->player = player;
	entities.push_back(player);
}

void EntityManager::addItem(Vector2f Position, int val)
{

	switch (val)
	{
	case (1):
	{
		shared_ptr<Item> item = make_shared<Medipack>(Position.x, Position.y); 
		items.push_back(item);
		entities.push_back(item);
		break;
	}
	case 2:
	{
		shared_ptr<Katana> item = make_shared<Katana>(Position.x, Position.y);
		items.push_back(item);
		entities.push_back(item);
	}
	default:
		break;
	}
}


void EntityManager::removeEntity()
{
	entities.erase(
		std::remove_if(entities.begin(), entities.end(),
			[](const std::shared_ptr<Entity>& entity) { return entity->isToBeDeleted(); }),
		entities.end());
	enemies.erase(
		std::remove_if(enemies.begin(), enemies.end(),
			[](const std::shared_ptr<Entity>& entity) { return entity->isToBeDeleted(); }),
		enemies.end());
	items.erase(
		std::remove_if(items.begin(), items.end(),
			[](const std::shared_ptr<Entity>& entity) { return entity->isToBeDeleted(); }),
		items.end());
}

void EntityManager::update(RenderWindow& window, float deltatime, View& view, vector<unique_ptr<Wall>>& walls)
{
	for (auto& entity : entities)
	{
		entity->update(window, deltatime, view);
	}
	removeEntity();
	for (auto& item : items) {
		item->interact(player);
	}

	player->handleInput(window, view, walls, enemies);
}

