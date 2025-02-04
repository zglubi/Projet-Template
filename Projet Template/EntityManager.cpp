#include "EntityManager.h"

EntityManager::EntityManager() 
{
    mobCap = 10;
}

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

shared_ptr<Player> EntityManager::getPlayer()
{
    return player;
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
        break;
    }
    case 3:
    {
        shared_ptr<Shuriken> item = make_shared<Shuriken>(Position.x, Position.y);
        items.push_back(item);
        entities.push_back(item);
        break;
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

    if (player->toBeDeleted == true)
        player = nullptr;
}

void EntityManager::checkPlayerEnemyCollision()
{
    for (auto& enemy : enemies)
    {
        if (player->getSprite().getGlobalBounds().intersects(enemy->getSprite().getGlobalBounds()))
        {
            player->setToBeDeleted(true);
            break;
        }
    }
}

void EntityManager::update(RenderWindow& window, float deltatime, View& view, vector<unique_ptr<Wall>>& walls)
{
    for (auto& entity : entities)
    {
        entity->update(window, deltatime, view);
    }

    for (auto& enemy : enemies)
	{
		enemy->collisionPlayer(player);
	}

    dispawnEnemy();
    removeEntity();
    for (auto& item : items) {
        item->interact(player);
    }

	player->handleInput(window, view, walls, enemies, deltatime);
    checkPlayerEnemyCollision();
    spawnEnemy();
}

vector<int> EntityManager::getInventory()
{
	return player->getInventory();
}

void EntityManager::spawnEnemy()
{
    if (player->getWilderness() && enemies.size() < mobCap)
    {
        bool spawning = false;
        Vector2f posEnemy;
        while (!spawning)
        {
            posEnemy = { static_cast<float>(randomNumber(player->getSprite().getPosition().x - 3000, player->getSprite().getPosition().x + 3000)), static_cast<float>(randomNumber(player->getSprite().getPosition().y - 3000, player->getSprite().getPosition().y + 3000)) };
            if (posEnemy.x > player->getSprite().getPosition().x - 500 && posEnemy.x < player->getSprite().getPosition().x + 500 && posEnemy.y > player->getSprite().getPosition().y - 500 && posEnemy.y < player->getSprite().getPosition().y + 500)
            {
                continue;
            }
            else
            {
				spawning = true;
            }
        }
        int type = randomNumber(1, 2);
        switch (type)
        {
        case 1:
            addChaser(posEnemy, 100);
            break;
        case 2:
            addShooter(posEnemy, 100);
            break;
        }
    }
}

void EntityManager::dispawnEnemy()
{
    for (auto& enemy : enemies)
    {
        if (enemy->getSprite().getPosition().x > player->getSprite().getPosition().x + 3000 || enemy->getSprite().getPosition().x < player->getSprite().getPosition().x - 3000 ||
			enemy->getSprite().getPosition().y > player->getSprite().getPosition().y + 3000 || enemy->getSprite().getPosition().y < player->getSprite().getPosition().y - 3000)
		{
			enemy->setToBeDeleted(true);
		}
    }
}