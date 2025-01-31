#include "EntityManager.h"


EntityManager::EntityManager()
{
}

void EntityManager::addChaser(shared_ptr<Chaser> chaser)
{
	chasers.push_back(chaser);
	entities.push_back(chaser);
}

void EntityManager::addShooter(shared_ptr<Shooter> shooter)
{
	shooters.push_back(shooter);
	entities.push_back(shooter);
}

void EntityManager::setPlayer(shared_ptr<Player> player)
{
	this->player = player;
	entities.push_back(player);
}

void EntityManager::update(RenderWindow& window, float deltatime, View& view, vector<unique_ptr<Wall>>& walls)
{
	for (auto& entity : entities)
	{
		entity->update(window, deltatime, view);
	}
	for (auto& chaser : chasers)
	{
		chaser->moveUpdate(player);
		chaser->update(window, deltatime, view);
	}
	for (auto& shooter : shooters)
	{
		shooter->moveUpdate(player);
		shooter->update(window, deltatime, view);
	}
	for (auto& chaser : chasers)
	{
		chaser->draw(window);
	}
	for (auto& shooter : shooters)
	{
		shooter->draw(window);
	}
}

template <typename T>
void EntityManager::removeEntity(T enemies)
{
	entities.erase(
		std::remove_if(entities.begin(), entities.end(),
			[](const std::shared_ptr<Entity>& entity) { return entity->isToBeDeleted(); }),
		entities.end());
}