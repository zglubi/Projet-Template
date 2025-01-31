#include "Player.h"
#include "Wall.h"

Player::Player(int x, int y) : Entity(x, y) {

    if (!texture.loadFromFile("assets\\player.png")) {
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

        // Déplacement vers la gauche
        if (Keyboard::isKeyPressed(Keyboard::Q)) 
        {
            newX -= vitesse;
            
        }

        // Déplacement vers le haut
        if (Keyboard::isKeyPressed(Keyboard::Z))
        {
            newY -= vitesse;
            
        }

        // Déplacement vers le bas
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            newY += vitesse;
           
        }

        // Déplacement vers la droite
        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            newX += vitesse;
           
        }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			shoot();
		}

        // Vérification des collisions avant de mettre à jour la position
        bool collisionDetected = false;
        for (auto& wall : walls) {
            // On obtient les limites globales du sprite et de chaque mur
            
            FloatRect playerBounds(newX - sprite.getGlobalBounds().width/2, newY- sprite.getGlobalBounds().height/4, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height*3/4);
            FloatRect wallBounds = wall->getSprite().getGlobalBounds();


            // Vérification de la collision
            if (playerBounds.intersects(wallBounds)) {
                collisionDetected = true;
                break;  // Sortir de la boucle dès qu'une collision est détectée
            }
        }

        // Si aucune collision n'est détectée, on applique le déplacement
        if (!collisionDetected) {
            x = newX;
            y = newY;
            view.setCenter(x, y);
            window.setView(view);
            sprite.setPosition(x, y);
            
        }
}

void Player::draw(RenderWindow& window) {

    window.draw(sprite);
}

void Player::update(RenderWindow& window, float deltatime, View& view) {

    draw(window);
}

void Player::shoot()
{
	Vector2f mousePos = Vector2f(Mouse::getPosition().x, Mouse::getPosition().y);
	Vector2f direction = mousePos - Vector2f(x, y);
    
    projectiles.push_back(make_unique<Projectile>(texture, Vector2f(x, y), direction, 500, 10));
}