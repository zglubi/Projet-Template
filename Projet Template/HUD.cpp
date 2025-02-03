#include "HUD.h"

// Constructor to initialize the HUD
HUD::HUD()
{
    // Initialize the player's health
    playerHealth = 7;

    // Load the health texture from a file
    if (!healthTexture.loadFromFile("assets/Hud/health_texture.png"))
    {
        // Handle error
        cerr << "Error loading health texture" << endl;
    }

    // Initialize the health sprite
    healthSprite.setTextureRect(IntRect(5, 2, 37, 14));
    healthSprite.setPosition(20.f, 20.f);
	healthSprite.setScale(3, 3);
	healthSprite.setTexture(healthTexture);
	// Update the health sprite based on the player's health
	updateHealthSprite();

}

// Function to set the player's health
void HUD::setPlayerHealth(int health)
{
    playerHealth = health;
    updateHealthSprite();
}

// Function to increase the player's health
void HUD::healthUp(int amount)
{
    playerHealth += amount;
    if (playerHealth > 7) playerHealth = 7; // Assuming max health is 7
    updateHealthSprite();
}

// Function to decrease the player's health
void HUD::healthDown(int amount)
{
    playerHealth -= amount;
    if (playerHealth < 0) playerHealth = 0; // Assuming min health is 0
    updateHealthSprite();
}

// Private method to update the health sprite based on the player's health
void HUD::updateHealthSprite()
{
	if (playerHealth == 7)
	{
		healthSprite.setTextureRect(IntRect(5, 2, 37, 14));
	}
	else if (playerHealth == 6)
	{
		healthSprite.setTextureRect(IntRect(5, 53, 37, 14));
	}
	else if (playerHealth == 5)
	{
		healthSprite.setTextureRect(IntRect(5, 101, 37, 14));
	}
	else if (playerHealth == 4)
	{
		healthSprite.setTextureRect(IntRect(5, 149, 37, 14));
	}
	else if (playerHealth == 3)
	{
		healthSprite.setTextureRect(IntRect(5, 197, 37, 14));
	}
	else if (playerHealth == 2)
	{
		healthSprite.setTextureRect(IntRect(5, 245, 37, 14));
	}
	else if (playerHealth == 1)
	{
		healthSprite.setTextureRect(IntRect(5, 293, 37, 14));
	}
	else if (playerHealth == 0)
	{
		healthSprite.setTextureRect(IntRect(5, 341, 37, 14));
	}
}

// Function to draw the HUD to the window
void HUD::draw(RenderWindow& window)
{
	healthSprite.setPosition(window.getView().getCenter().x - window.getView().getSize().x / 2 + 20.f, window.getView().getCenter().y - window.getView().getSize().y / 2 + 20.f);
    window.draw(healthSprite);
}