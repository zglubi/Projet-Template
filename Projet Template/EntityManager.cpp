#include "EntityManager.h"
#include "Player.h"

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
    shared_ptr<Chaser> chaser = make_shared<Chaser>(chaserTexture, startPosition, initialSpeed);
    enemies.push_back(chaser);
    entities.push_back(chaser);
}

void EntityManager::addShooter(Vector2f startPosition, float initialSpeed)
{
    shared_ptr<Shooter> shooter = make_shared<Shooter>(shooterTexture, shooterProjectileTexture, startPosition, initialSpeed);
    enemies.push_back(shooter);
    entities.push_back(shooter);
}

void EntityManager::addBoss(Vector2f startPosition, float initialSpeed)
{
    shared_ptr<Boss> _boss = make_shared<Boss>(bossTexture, bossProjectileTexture, bossSlashTexture, startPosition, initialSpeed);
    enemies.push_back(_boss);
    entities.push_back(_boss);
	this->boss = _boss;
}

void EntityManager::setPlayer(float x, float y)
{
    shared_ptr<Player> player = make_shared<Player>(playerTexture, playerProjectileTexture, katanaSlashTexture, x, y);
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
        shared_ptr<Item> item = make_shared<Medipack>(medipackTexture, Position.x, Position.y);
        items.push_back(item);
        entities.push_back(item);
        break;
    }
    case 2:
    {
        shared_ptr<Katana> item = make_shared<Katana>(katanaTexture, Position.x, Position.y);
        items.push_back(item);
        entities.push_back(item);
        break;
    }
    case 3:
    {
        shared_ptr<Shuriken> item = make_shared<Shuriken>(shurikenTexture, Position.x, Position.y);
        items.push_back(item);
        entities.push_back(item);
        break;
    }
    case 4:
	{
		shared_ptr<Key> item = make_shared<Key>(keyTexture, Position.x, Position.y);
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
        remove_if(entities.begin(), entities.end(),
            [](const shared_ptr<Entity>& entity) { return entity->isToBeDeleted(); }),
        entities.end());
    enemies.erase(
        remove_if(enemies.begin(), enemies.end(),
            [](const shared_ptr<Entity>& entity) { return entity->isToBeDeleted(); }),
        enemies.end());
    items.erase(
        remove_if(items.begin(), items.end(),
            [](const shared_ptr<Entity>& entity) { return entity->isToBeDeleted(); }),
        items.end());
}

void EntityManager::update(RenderWindow& window, float deltatime, View& view, vector<unique_ptr<Wall>>& walls, vector<unique_ptr<Door>>& doors, Map& gamemap)
{
    for (auto& entity : entities)
    {
        entity->update(window, deltatime, view);
    }

    for (auto& enemy : enemies)
	{
		enemy->collisionPlayer(player);
        enemy->collisionWall(walls);
	}

    if (boss)
    {
        boss->attack(window, player);
    }

    dispawnEnemy();
    removeEntity();
    for (auto& item : items) 
    {
        item->interact(player);
    }

	player->handleInput(window, view, walls, doors,  enemies, deltatime, gamemap);
    spawnEnemy();
}

vector<int> EntityManager::getInventory()
{
	return player->getInventory();
}

void EntityManager::setTextures(vector<Texture>& textures)
{
    playerTexture = textures[0];
    chaserTexture = textures[1];
	shooterTexture = textures[2];
    medipackTexture = textures[3];
	katanaTexture = textures[4];
	shurikenTexture = textures[5];
    playerProjectileTexture = textures[6];
    katanaSlashTexture = textures[7];
    shooterProjectileTexture = textures[8];
    bossTexture = textures[9];
    bossProjectileTexture = textures[10];
    bossSlashTexture = textures[11];
    keyTexture = textures[12];
}

void EntityManager::spawnEnemy()
{
 /*   if (player->getWilderness() && enemies.size() < mobCap)
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
    else if (!player->getWilderness())
    {
        for (auto enemy : enemies)
        {
            enemies.erase(std::remove(enemies.begin(), enemies.end(), enemy), enemies.end());
            entities.erase(std::remove(entities.begin(), entities.end(), enemy), entities.end());
        }
    }*/

    if (boss == nullptr)
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
        addBoss(posEnemy, 100);
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

void EntityManager::Dungeon() {
    for (auto enemy : enemies)
    {
        enemies.erase(std::remove(enemies.begin(), enemies.end(), enemy), enemies.end());
        entities.erase(std::remove(entities.begin(), entities.end(), enemy), entities.end());
    }
    addBoss(Vector2f(0, 0), 100);
}

shared_ptr<Boss> EntityManager::getBoss()
{
    return boss;
}