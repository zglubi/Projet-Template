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

    // Load the inventory texture from a file
    if (!inventoryTexture.loadFromFile("assets/Hud/Inventory.png"))
    {
        // Handle error
        cerr << "Error loading inventory texture" << endl;
    }

    // Initialize the inventory sprite
    inventorySprite.setTexture(inventoryTexture);
    inventorySprite.setPosition(70.f, 70.f);
    inventorySprite.setScale(0.5f, 0.5f);

//    // Load the mouse texture from a file
//    if (!inventoryTexture.loadFromFile("assets/mouse.png"))
//    {
//        // Handle error
//        cerr << "Error loading mouse texture" << endl;
//    }
//
//    // Initialize the mouse sprite
//    mouseSprite.setTexture(mouseTexture);
//    mouseSprite.setPosition(70.f, 70.f);
//    mouseSprite.setScale(0.2f, 0.2f);
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

// Function to display the inventory
void HUD::inventoryDisplay(RenderWindow& window, vector<int> item)
{
	for (int i = 0; i < item.size(); i++)
	{
		if (item[i] == 1)
		{
			inventorySprite.setTextureRect(IntRect(0, 0, 32, 32));
			inventorySprite.setPosition(70.f + i * 40.f, 70.f);
			window.draw(inventorySprite);
		}
		else if (item[i] == 2)
		{
			inventorySprite.setTextureRect(IntRect(32, 0, 32, 32));
			inventorySprite.setPosition(70.f + i * 40.f, 70.f);
			window.draw(inventorySprite);
		}
		else if (item[i] == 3)
		{
			inventorySprite.setTextureRect(IntRect(64, 0, 32, 32));
			inventorySprite.setPosition(70.f + i * 40.f, 70.f);
			window.draw(inventorySprite);
		}
	}
}

// Function to draw the HUD to the window
void HUD::draw(RenderWindow& window)
{
    healthSprite.setPosition(window.getView().getCenter().x - window.getView().getSize().x / 2 + 20.f, window.getView().getCenter().y - window.getView().getSize().y / 2 + 20.f);
    window.draw(healthSprite);

    inventorySprite.setPosition(window.getView().getCenter().x - window.getView().getSize().x / 2 + 550.f, window.getView().getCenter().y - window.getView().getSize().y / 2 + 900.f);
    window.draw(inventorySprite);
}