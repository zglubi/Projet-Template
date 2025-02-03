#include "Player.h"
#include "Wall.h"
#include "Projectile.h"
#include <iostream>

Player::Player(int x, int y) : Entity(x, y), frame(0), frameKatanaSlash(0) {

    if (!texture.loadFromFile("assets\\player.png")) {
        std::cerr << "Erreur : impossible de charger 'playersprite'" << std::endl;
    }
    if (!projectileTexture.loadFromFile("assets\\Projectiles\\Shuriken.png")) {
        std::cerr << "Erreur : impossible de charger 'playersprite'" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
    sprite.setScale(Vector2f(2, 2));

    if (!katanaSlashTexture.loadFromFile("assets\\Slash\\katanaCurved.png"))
    {
        std::cerr << "Erreur : impossible de charger 'playersprite'" << std::endl;
    }
    katanaSlashSprite.setTexture(katanaSlashTexture);
    katanaSlashSprite.setTextureRect(IntRect(0 , 0, 32, 32));
    katanaSlashSprite.setOrigin(Vector2f(katanaSlashSprite.getLocalBounds().width / 2, katanaSlashSprite.getLocalBounds().height / 2));
    katanaSlashSprite.setScale(Vector2f(2, 2));

    hand1 = 1;
    hand2 = 2;

    vitesse = 0.125;

    dir = 4;
    slashDir = 4;

}

float Player::getVitesse() const
{
    return vitesse;
}

void Player::setVitesse(float newVitesse)
{
    vitesse = newVitesse;
}

const Sprite& Player::getSprite() const
{
    return sprite;
}

void Player::setSprite(const Sprite& newSprite)
{
    sprite = newSprite;
}

void Player::handleInput(RenderWindow& window, View& view, vector<unique_ptr<Wall>>& walls)
{
    float newX = x;
    float newY = y;

        
        if (Keyboard::isKeyPressed(Keyboard::Q)) 
        {
            newX -= vitesse;
            dir = 2;
        }
        
        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            newX += vitesse;
            dir = 4;
        }

    bool collisionDetected = false;
    for (auto& wall : walls) {
        FloatRect playerBounds(newX - sprite.getGlobalBounds().width / 2, newY - sprite.getGlobalBounds().height / 4, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height * 3 / 4);
        FloatRect wallBounds = wall->getSprite().getGlobalBounds();

        if (playerBounds.intersects(wallBounds)) {
            collisionDetected = true;
            break;
        }
    }

    if (!collisionDetected) {
        x = newX;
        y = newY;
        view.setCenter(x, y);
        window.setView(view);
        sprite.setPosition(x, y);
    }

        if (Keyboard::isKeyPressed(Keyboard::Z))
        {
            newY -= vitesse;
            dir = 1;
        }
        
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            newY += vitesse;
            dir = 3;
        }

    collisionDetected = false;
    for (auto& wall : walls) {
        FloatRect playerBounds(newX - sprite.getGlobalBounds().width / 2, newY - sprite.getGlobalBounds().height / 4, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height * 3 / 4);
        FloatRect wallBounds = wall->getSprite().getGlobalBounds();

        if (playerBounds.intersects(wallBounds)) {
            collisionDetected = true;
            break;
        }
    }

    if (!collisionDetected) {
        x = newX;
        y = newY;
        view.setCenter(x, y);
        window.setView(view);
        sprite.setPosition(x, y);
    }

    for (auto& projectile : projectiles)
    {
        projectile->collision(walls);
    }

    projectiles.erase(
        std::remove_if(projectiles.begin(), projectiles.end(),
            [](const std::unique_ptr<Projectile>& projectile) { return projectile->isToBeDeleted(); }),
        projectiles.end());

    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        window.close();
    }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
            switch (hand1)
            {
            case 0:
                break;
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
                }
                break;
            }
		}

        if (Mouse::isButtonPressed(Mouse::Right))
        {
            switch (hand2)
            {
            case 0:
                break;
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
                }
                break;
            }
        }

        if (katanaAttack)
        {
            katanaSlash(window);
        }
}

void Player::draw(RenderWindow& window) {
    window.draw(sprite);
}

void Player::update(RenderWindow& window, float deltatime, View& view) {
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
        projectiles.push_back(make_unique<Projectile>(projectileTexture, view.getCenter(), direction, 200, 10));
        cooldownProjectile.restart();
    }
}

void Player::meleeAttack(RenderWindow& window, View& view)
{
    std::cout << "Performing melee attack with Katana!" << std::endl;
    // Add melee attack logic here
}

void Player::katanaSlash(RenderWindow& window)
{   
    
    if (frameKatanaSlash == 0)
    {
        slashDir = dir;
    }
    
    if (frameKatanaSlash / 30 > 3)
    {
        katanaAttack = false;
        frameKatanaSlash = 0;
        return;
    }
    else
    {
        frameKatanaSlash++;
    }
    if (slashDir == 1)
    {
        katanaSlashSprite.setPosition(sprite.getGlobalBounds().left + (katanaSlashSprite.getGlobalBounds().width / 2), sprite.getGlobalBounds().top - (katanaSlashSprite.getGlobalBounds().height / 2));
        katanaSlashSprite.setRotation(270);
        katanaSlashSprite.setScale(Vector2f(2, 2));
    }
    else if (slashDir == 2)
    {
        katanaSlashSprite.setPosition(sprite.getGlobalBounds().left - (katanaSlashSprite.getGlobalBounds().width / 2), sprite.getGlobalBounds().top + (katanaSlashSprite.getGlobalBounds().height / 2));
        katanaSlashSprite.setScale(Vector2f(-2, 2));
    }
    else if (slashDir == 3)
    {
        katanaSlashSprite.setPosition(sprite.getGlobalBounds().left + (katanaSlashSprite.getGlobalBounds().width / 2), sprite.getGlobalBounds().top + sprite.getGlobalBounds().height + (katanaSlashSprite.getGlobalBounds().height / 2));
        katanaSlashSprite.setRotation(90);
        katanaSlashSprite.setScale(Vector2f(2, 2));
    }
    else if (slashDir == 4)
    {
        katanaSlashSprite.setPosition(sprite.getGlobalBounds().left + sprite.getGlobalBounds().width + (katanaSlashSprite.getGlobalBounds().width / 2), sprite.getGlobalBounds().top + (katanaSlashSprite.getGlobalBounds().height / 2));
        katanaSlashSprite.setRotation(0);
    }

    katanaSlashSprite.setTextureRect(IntRect(0 + 32 * (frameKatanaSlash / 30), 0, 32, 32));
    window.draw(katanaSlashSprite);
}