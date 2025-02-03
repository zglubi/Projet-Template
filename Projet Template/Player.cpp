#include "Player.h"
#include "Wall.h"
#include "Projectile.h"
#include "Enemy.h"
#include <iostream>
#include <cmath>

sf::Vector2f operator*(const sf::Vector2f& vector, float scalar) {
    return sf::Vector2f(vector.x * scalar, vector.y * scalar);
}

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

    vitesse = 300;

    dir = 4;
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

void Player::handleInput(RenderWindow& window, View& view, vector<unique_ptr<Wall>>& walls, vector<shared_ptr<Enemy>>& enemies, float deltatime)
{
    float newX = x;
    float newY = y;

        
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
            newY -= vitesse * deltatime;
            dir = 1;
        }
        
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            newY += vitesse * deltatime;
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
            katanaSlash(window, enemies);
        }
}

void Player::draw(RenderWindow& window)
{
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
        projectiles.push_back(make_unique<Projectile>(projectileTexture, view.getCenter(), direction, 200, 10));
        cooldownProjectile.restart();
    }
}

Vector2f normalize(const Vector2f& source) 
{
    float length = std::sqrt(source.x * source.x + source.y * source.y);
    if (length != 0)
        return Vector2f(source.x / length, source.y / length);
    else
        return source;
}

float dotProduct(const sf::Vector2f& v1, const sf::Vector2f& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

float magnitude(const sf::Vector2f& v) {
    return std::sqrt(v.x * v.x + v.y * v.y);
}

float calculateAngle(const sf::Vector2f& direction) {
    sf::Vector2f normalizedDirection = normalize(direction);
    sf::Vector2f reference(1.0f, 0.0f); // Vecteur de référence (axe des x)
    float dot = dotProduct(normalizedDirection, reference);
    float angle = std::acos(dot); // Angle en radians

    // Déterminer le signe de l'angle en utilisant le produit vectoriel
    float cross = reference.x * normalizedDirection.y - reference.y * normalizedDirection.x;
    if (cross < 0) {
        angle = -angle;
    }

    return angle * 180 / 3.14159265;
}

void Player::katanaSlash(RenderWindow& window, vector<shared_ptr<Enemy>>& enemies)
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

    RectangleShape katanaBounds(sf::Vector2f(katanaSlashSprite.getGlobalBounds().width, katanaSlashSprite.getGlobalBounds().height));
    katanaBounds.setPosition(katanaSlashSprite.getGlobalBounds().left, katanaSlashSprite.getGlobalBounds().top);
    katanaBounds.setFillColor(sf::Color::Transparent);
    katanaBounds.setOutlineColor(sf::Color::Red);
    katanaBounds.setOutlineThickness(1.0f);
    window.draw(katanaBounds);

    for (auto& enemy : enemies)
    {
        sf::RectangleShape enemyBounds(sf::Vector2f(enemy->getSprite().getGlobalBounds().width, enemy->getSprite().getGlobalBounds().height));
        enemyBounds.setPosition(enemy->getSprite().getGlobalBounds().left, enemy->getSprite().getGlobalBounds().top);
        enemyBounds.setFillColor(sf::Color::Transparent);
        enemyBounds.setOutlineColor(sf::Color::Green);
        enemyBounds.setOutlineThickness(1.0f);
        window.draw(enemyBounds);
        
        if (katanaSlashSprite.getGlobalBounds().intersects(enemy->getSprite().getGlobalBounds()))
        {            
            enemy->setToBeDeleted(true);
        }
    }
}

void Player::addToInventory(int item)
{
    inventory.push_back(item);
}