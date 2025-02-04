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

	// Load the shuriken icon texture from a file

	if (!shurikenIconTexture.loadFromFile("assets/Icons/Shuriken.png"))
	{
		// Handle error
		cerr << "Error loading shuriken icon texture" << endl;
	}

	// Initialize the shuriken icon sprite
	shurikenIconSprite.setTexture(shurikenIconTexture);
	shurikenIconSprite.setScale(2.0f, 2.0f);
    
	// Load the katana icon texture from a file

	if (!katanaIconTexture.loadFromFile("assets/Icons/Katana.png"))
	{
		// Handle error
		cerr << "Error loading katana icon texture" << endl;
	}

	// Initialize the katana icon sprite
	katanaIconSprite.setTexture(katanaIconTexture);
	katanaIconSprite.setScale(2.0f, 2.0f);

	// Load the mouse texture from a file
	if (!mouseTexture.loadFromFile("assets/Hud/mouse.png"))
	{
		// Handle error
		cerr << "Error loading mouse texture" << endl;
	}

	// Initialize the mouse sprite
    mouseLeftSprite.setTextureRect(IntRect(210, 78, 54, 81));
    mouseLeftSprite.setScale(0.3, 0.3);
    mouseLeftSprite.setTexture(mouseTexture);

    mouseRightSprite.setTextureRect(IntRect(398, 78, 54, 81));
    mouseRightSprite.setScale(0.3, 0.3);
    mouseRightSprite.setTexture(mouseTexture);

    // Load the medipack texture from a file
    if (!mediPackIconTexture.loadFromFile("assets/Icons/Heal.png"))
    {
        // Handle error
        cerr << "Error loading medipack texture" << endl;
    }

    // Initialize the medipack sprite

    mediPackIconSprite.setTexture(mediPackIconTexture);
    mediPackIconSprite.setScale(2.0f, 2.0f);
    
    // load the key texture  from a file
    if (!keyIconTexture.loadFromFile("assets/Icons/GoldenKey.png"))
    {
        // Handle error
        cerr << "Error loading key icon texture" << endl;
    }

    // Initialize the key sprite

    keyIconSprite.setTexture(keyIconTexture);
    keyIconSprite.setScale(2.0f, 2.0f);
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
void HUD::inventoryDisplay(RenderWindow& window, vector<int> items) {
    for (int i = 0; i < items.size(); i++) {
        switch (items[i]) {
        case 1:
            shurikenIconSprite.setPosition(window.getView().getCenter().x - window.getView().getSize().x / 2 + 562.f, window.getView().getCenter().y - window.getView().getSize().y / 2 + 912.f);
            window.draw(shurikenIconSprite);
            break;
        case 2:
            katanaIconSprite.setPosition(window.getView().getCenter().x - window.getView().getSize().x / 2 + 632.f, window.getView().getCenter().y - window.getView().getSize().y / 2 + 912.f);
            window.draw(katanaIconSprite);
            break;

        case 3:
            mediPackIconSprite.setPosition(window.getView().getCenter().x - window.getView().getSize().x / 2 + 702.f, window.getView().getCenter().y - window.getView().getSize().y / 2 + 912.f);
            window.draw(mediPackIconSprite);
            break;
        case 4:
            keyIconSprite.setPosition(window.getView().getCenter().x - window.getView().getSize().x / 2 + 772.f, window.getView().getCenter().y - window.getView().getSize().y / 2 + 912.f);
            window.draw(keyIconSprite);
            break;
        }

    }

}

// Function to draw the HUD to the window
void HUD::draw(RenderWindow& window, vector<int> inventory)
{
    healthSprite.setPosition(window.getView().getCenter().x - window.getView().getSize().x / 2 + 20.f, window.getView().getCenter().y - window.getView().getSize().y / 2 + 20.f);
    window.draw(healthSprite);

    inventorySprite.setPosition(window.getView().getCenter().x - window.getView().getSize().x / 2 + 550.f, window.getView().getCenter().y - window.getView().getSize().y / 2 + 900.f);
    window.draw(inventorySprite);

    mouseLeftSprite.setPosition(window.getView().getCenter().x - window.getView().getSize().x / 2 + 572.f, window.getView().getCenter().y - window.getView().getSize().y / 2 + 875.f);
    window.draw(mouseLeftSprite);

    mouseRightSprite.setPosition(window.getView().getCenter().x - window.getView().getSize().x / 2 + 642.f, window.getView().getCenter().y - window.getView().getSize().y / 2 + 875.f);
    window.draw(mouseRightSprite);

	inventoryDisplay(window, inventory);
}