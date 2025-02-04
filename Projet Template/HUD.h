#pragma once
#ifndef HUD_H
#define HUD_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class HUD
{
private:
    // Member variables to store the player's health
    int playerHealth;

    // SFML objects for displaying the health as a texture
    Texture healthTexture;
    Sprite healthSprite;

    // SFML objects for displaying the inventory as a texture
    Texture inventoryTexture;
    Sprite inventorySprite;

	// SFML objects for displaying the mouse as a texture
	Texture mouseTexture;
	Sprite mouseSprite;

	// SFML objects for displaying the items as a texture
	Texture shurikenIconTexture;
	Sprite shurikenIconSprite;

    // Private method to update the health sprite based on the player's health
    void updateHealthSprite();

public:
    // Constructor to initialize the HUD
    HUD();

    // Function to set the player's health
    void setPlayerHealth(int health);

    // Function to increase the player's health
    void healthUp(int amount);

    // Function to decrease the player's health
    void healthDown(int amount);

    // Function to draw the HUD to the window
    void draw(RenderWindow& window);

	void inventoryDisplay(RenderWindow& window, vector<int> items);
};

#endif // !HUD_H