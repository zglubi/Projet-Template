#include "Player.h"
#include "Boss.h"
#include "Wall.h"
#include "Door.h"
#include "Projectile.h"
#include "Enemy.h"
#include <iostream>
#include <cmath>

Player::Player(Texture& texture, Texture& projTexture, Texture& katanaSlashTexture, int x, int y) : Entity(texture, x, y), hp(100), frame(0), frameKatanaSlash(0) 
{
    sprite.setTextureRect(IntRect(0, 0, 16, 16));
    sprite.setScale(2, 2);
    sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);


    katanaSlashSprite.setTexture(katanaSlashTexture);
    katanaSlashSprite.setTextureRect(IntRect(0 , 0, 32, 32));
    katanaSlashSprite.setOrigin(Vector2f(katanaSlashSprite.getLocalBounds().width / 2, katanaSlashSprite.getLocalBounds().height / 2));
    katanaSlashSprite.setScale(Vector2f(2, 2));

    projectileTexture = projTexture;

    vitesse = 900;

    dir = 4;

    attacking = false;
}

float Player::getVitesse() const
{
    return vitesse;
}

void Player::setVitesse(float newVitesse)
{
    vitesse = newVitesse;
}

void Player::setSprite(const Sprite& newSprite)
{
    sprite = newSprite;
}

void Player::handleInput(RenderWindow& window, View& view, vector<unique_ptr<Wall>>& walls, vector<unique_ptr<Door>>& doors, vector<shared_ptr<Enemy>>& enemies, float deltatime, Map& gamemap, shared_ptr<Boss> boss)
{
    if (getSprite().getPosition().x > 0 && getSprite().getPosition().x < 1216 && getSprite().getPosition().y > 1248 && getSprite().getPosition().y < 2464)
    {
        isWilderness = false;
    }
    else
    {
		isWilderness = true;
    }
    
    
    float newX = x;
    float newY = y;

    if (!attacking)
    {
        if (Keyboard::isKeyPressed(Keyboard::Q))
        {
            newX -= vitesse * deltatime;
            dir = 2;
        }

        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            newX += vitesse * deltatime;
            dir = 4;
        }

        if (Keyboard::isKeyPressed(Keyboard::Z))
        {
            newY -= vitesse * deltatime;
            dir = 1;
        }

        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            newY += vitesse * deltatime;
            dir = 3;
        }
        
        if (Keyboard::isKeyPressed(Keyboard::E)) {

        }
    }

    // Vérification des collisions horizontales (x)
    bool collisionX = false;
    for (auto& wall : walls)
    {
        FloatRect playerBounds(newX - sprite.getGlobalBounds().width / 2, y - sprite.getGlobalBounds().height / 4, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height * 3 / 4);
        if (playerBounds.intersects(wall->getSprite().getGlobalBounds()))
        {
            collisionX = true;
            break;
        }
    }

    // Mise à jour de x si pas de collision
    if (!collisionX)
    {
        x = newX;
    }

    // Vérification des collisions verticales (y)
    bool collisionY = false;
    for (auto& wall : walls)
    {
        FloatRect playerBounds(x - sprite.getGlobalBounds().width / 2, newY - sprite.getGlobalBounds().height / 4, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height * 3 / 4);
        if (playerBounds.intersects(wall->getSprite().getGlobalBounds()))
        {
            collisionY = true;
            break;
        }
    }

    // Mise à jour de y si pas de collision
    if (!collisionY)
    {
        y = newY;
    }

    for (auto& door : doors) {

        
        FloatRect playerBounds(x - sprite.getGlobalBounds().width / 2, newY - sprite.getGlobalBounds().height / 4, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height * 3 / 4);
        if (playerBounds.intersects(door->getSprite().getGlobalBounds()))
        {
            if(door->isOpen)
            gamemap.loadMap(door->nextlvl);
            break;
        }
    }

    // Mises à jour de la vue et de la position du sprite
    view.setCenter(x, y);
    window.setView(view);
    sprite.setPosition(x, y);

    // Mise à jour des projectiles et des attaques
    for (auto& projectile : projectiles)
    {
        projectile->collision(walls);
        projectile->collisionEnemies(enemies, boss);
    }

    projectiles.erase(
        remove_if(projectiles.begin(), projectiles.end(),
            [](const unique_ptr<Projectile>& projectile) { return projectile->isToBeDeleted(); }),
        projectiles.end());

    // Gestion des attaques
    if (Mouse::isButtonPressed(Mouse::Left))
    {
        if (inventory.size() > 0)
        {
            switch (inventory[0])
            {
            case 1:
                if (cooldownProjectile.getElapsedTime().asSeconds() > 0.5)
                {
                    shoot(window, view);
                }
                break;
            case 2:
                if (cooldownKatanaSlash.getElapsedTime().asSeconds() > 1)
                {
                    cooldownKatanaSlash.restart();
                    katanaAttack = true;
                    attacking = true;
                }
                break;
            case 3:
                hpUp();
                inventory.erase(remove(inventory.begin(), inventory.end(), 3), inventory.end());
                break;
            case 4:
                for (auto& door : doors) {
                    FloatRect playerBounds(x - sprite.getGlobalBounds().width / 2, newY - sprite.getGlobalBounds().height / 4, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height * 3 / 4);
                    if (playerBounds.intersects(door->getSprite().getGlobalBounds()))
                    {
                        inventory.erase(remove(inventory.begin(), inventory.end(), 4), inventory.end());
                        door->open();
                        break;
                    }
                }
                break;
            default:
                break;
            }
        }
    }

    if (Mouse::isButtonPressed(Mouse::Right))
    {
        if (inventory.size() > 1)
        {
            switch (inventory[1])
            {
            case 1:
                if (cooldownProjectile.getElapsedTime().asSeconds() > 0.5)
                {
                    shoot(window, view);
                }
                break;
            case 2:
                if (cooldownKatanaSlash.getElapsedTime().asSeconds() > 1)
                {
                    cooldownKatanaSlash.restart();
                    katanaAttack = true;
                    attacking = true;
                }
                break;
            case 3:
                hpUp();
                inventory.erase(remove(inventory.begin(), inventory.end(), 3), inventory.end());
                break;
            case 4:
                for (auto& door : doors) {
                    FloatRect playerBounds(x - sprite.getGlobalBounds().width / 2, newY - sprite.getGlobalBounds().height / 4, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height * 3 / 4);
                    if (playerBounds.intersects(door->getSprite().getGlobalBounds()))
                    {
                        inventory.erase(remove(inventory.begin(), inventory.end(), 4), inventory.end());
                        door->open();
                        break;
                    }
                }
                break;
            default:
                break;
            }
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Num1))
    {
        if (inventory.size() > 2)
        {
            switch (inventory[2])
            {
            case 1:
                if (cooldownProjectile.getElapsedTime().asSeconds() > 0.5)
                {
                    shoot(window, view);
                }
                break;
            case 2:
                if (cooldownKatanaSlash.getElapsedTime().asSeconds() > 1)
                {
                    cooldownKatanaSlash.restart();
                    katanaAttack = true;
                    attacking = true;
                }
                break;
            case 3:
                hpUp();
                inventory.erase(remove(inventory.begin(), inventory.end(), 3), inventory.end());
                break;
            case 4:
                for (auto& door : doors) {
                    FloatRect playerBounds(x - sprite.getGlobalBounds().width / 2, newY - sprite.getGlobalBounds().height / 4, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height * 3 / 4);
                    if (playerBounds.intersects(door->getSprite().getGlobalBounds()))
                    {
                        inventory.erase(remove(inventory.begin(), inventory.end(), 4), inventory.end());
                        door->open();
                        break;
                    }
                }
                break;
            default:
                break;
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Num2))
        {
            if (inventory.size() > 3)
            {
                switch (inventory[3])
                {
                case 1:
                    if (cooldownProjectile.getElapsedTime().asSeconds() > 0.5)
                    {
                        shoot(window, view);
                    }
                    break;
                case 2:
                    if (cooldownKatanaSlash.getElapsedTime().asSeconds() > 1)
                    {
                        cooldownKatanaSlash.restart();
                        katanaAttack = true;
                        attacking = true;
                    }
                    break;
                case 3:
                    hpUp();
                    inventory.erase(remove(inventory.begin(), inventory.end(), 3), inventory.end());
                    break;
                case 4:
                    for (auto& door : doors) {
                        FloatRect playerBounds(x - sprite.getGlobalBounds().width / 2, newY - sprite.getGlobalBounds().height / 4, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height * 3 / 4);
                        if (playerBounds.intersects(door->getSprite().getGlobalBounds()))
                        {
                            inventory.erase(remove(inventory.begin(), inventory.end(), 4), inventory.end());
                            door->open();
                            break;
                        }
                    }
                    break;
                default:
                    break;
                }
            }
        }
    }

    if (katanaAttack)
    {
        katanaSlash(window, enemies, boss);
    }
}

void Player::draw(RenderWindow& window)
{
    if (Keyboard::isKeyPressed(Keyboard::Z) || Keyboard::isKeyPressed(Keyboard::Q) || Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::D))
    {
        if (frame / 10 > 3)
        {
            frame = 0;
        }
        else
        {
            frame++;
        }
    }
    else frame = 0;
    switch (dir){
    case(1):{
        sprite.setTextureRect(IntRect(16, 0 + 16 * (frame / 10), 16, 16));
        break;}
    case(2): {
        sprite.setTextureRect(IntRect(32, 0 + 16 * (frame / 10), 16, 16));
        break;
    }case(3): {
        sprite.setTextureRect(IntRect(0, 0 + 16 * (frame / 10), 16, 16));
        break;
    }case(4): {
        sprite.setTextureRect(IntRect(48, 0 + 16 * (frame / 10), 16, 16));
        break;
    }
    default:
        break;
    }

    RectangleShape PBounds(Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height));
    PBounds.setPosition(x - sprite.getGlobalBounds().width/2, y - sprite.getGlobalBounds().height / 2);
    PBounds.setFillColor(Color::Transparent);
    PBounds.setOutlineColor(Color::Red);
    PBounds.setOutlineThickness(1.0f);
    window.draw(PBounds);
    
    window.draw(sprite);
}

void Player::update(RenderWindow& window, float deltatime, View& view)
{
    
    for (auto& projectile : projectiles)
    {
        projectile->update(window, deltatime, view);
    }
    draw(window);
}

void Player::shoot(RenderWindow& window, View& view)
{
    Vector2f mousePos = Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
    Vector2f direction = mousePos - Vector2f(720, 540);

    if (direction.x != 0 || direction.y != 0)
    {
        projectiles.push_back(make_unique<Projectile>(projectileTexture, view.getCenter(), direction, 600, 10, 2, 16, 16));
        cooldownProjectile.restart();
    }
}

void Player::katanaSlash(RenderWindow& window, vector<shared_ptr<Enemy>>& enemies, shared_ptr<Boss> boss)
{   
    
    if (frameKatanaSlash == 0)
    {
        Vector2f mousePos = Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
        slashDir = mousePos - Vector2f(720, 540);
        slashDir = normalize(slashDir);
    }
    
    if (frameKatanaSlash / 10 > 3)
    {
        katanaAttack = false;
        attacking = false;
        frameKatanaSlash = 0;
        return;
    }
    else
    {
        frameKatanaSlash++;
    }

    katanaSlashSprite.setPosition(Vector2f(x, y) + (slashDir * 50));
    katanaSlashSprite.setRotation(calculateAngle(slashDir));
    katanaSlashSprite.setTextureRect(IntRect(0 + 32 * (frameKatanaSlash / 10), 0, 32, 32));
    window.draw(katanaSlashSprite);

    if (katanaSlashSprite.getGlobalBounds().intersects(boss->getSprite().getGlobalBounds()))
    {
        boss->diminishHp(1);
    }
    else
    {
        for (auto& enemy : enemies)
        {
            if (katanaSlashSprite.getGlobalBounds().intersects(enemy->getSprite().getGlobalBounds()))
            {
                enemy->setToBeDeleted(true);
            }
        }
    }
}

void Player::addToInventory(int item)
{
    inventory.push_back(item);
}

vector<int> Player::getInventory()
{
	return inventory;
}

bool Player::getWilderness() const
{
    return isWilderness;
}

void Player::diminishHp(int damage)
{
    hp -= damage;
}

size_t Player::getHp() const { return hp; }

void Player::hpUp() { hp += 10; }