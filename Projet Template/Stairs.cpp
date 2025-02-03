#include "Stairs.h"
#include "Player.h"

Stairs::Stairs(float x, float y, char t) : Wall(x, y, t), isOnStairs(false)
{
}

void Stairs::interact(std::shared_ptr<Player>& player)
{
    if (checkPlayerOnStairs(player->getSprite()))
    {
        isOnStairs = true;
		cout << "Player is on stairs" << endl;
    }
    else
    {
        isOnStairs = false;
		cout << "Player is not on stairs" << endl;
    }
}

bool Stairs::checkPlayerOnStairs(const Sprite& playerSprite)
{
    // Utilisation de la méthode getSprite() pour accéder au sprite
    return getSprite().getGlobalBounds().intersects(playerSprite.getGlobalBounds());
}