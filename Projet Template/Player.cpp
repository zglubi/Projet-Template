#include "Player.h"
#include "Wall.h"
#include "Projectile.h"

Player::Player(int x, int y) : Entity(x, y) {

    if (!texture.loadFromFile("assets\\player.png")) {
        std::cerr << "Erreur : impossible de charger 'playersprite'" << std::endl;
    }
    if (!projectileTexture.loadFromFile("assets\\Projectiles\\Shuriken.png")) {
        std::cerr << "Erreur : impossible de charger 'playersprite'" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
    sprite.setScale(Vector2f(2, 2));

    vitesse = 0.125;
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
            
        }
        
        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            newX += vitesse;

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
            
        }

        
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            newY += vitesse;
           
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

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();

        }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
            if (cooldownProjectile.getElapsedTime().asSeconds() > 0.5)
            {
                shoot();
            }
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

void Player::shoot()
{
	Vector2f mousePos = Vector2f(Mouse::getPosition().x, Mouse::getPosition().y);
	Vector2f direction = mousePos - Vector2f(x, y);

    if (direction.x != 0 || direction.y != 0)
    {

        projectiles.push_back(make_unique<Projectile>(projectileTexture, Vector2f(x, y), direction, 200, 10));

        cooldownProjectile.restart();
    }
}