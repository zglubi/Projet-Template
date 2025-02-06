#pragma once
#ifndef HUD_H
#define HUD_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Boss.h"
using namespace sf;
using namespace std;

class HUD
{
private:

    // SFML objects for displaying the health as a texture
    Texture healthTexture;
    Sprite healthSprite;

    Texture healthBarBorderTexture;
	Sprite healthBarBorderSprite;

    // SFML objects for displaying the inventory as a texture
    Texture inventoryTexture;
    Sprite inventorySprite;

	// SFML objects for displaying the mouse as a texture
	Texture mouseTexture;
	Sprite mouseLeftSprite;
    Sprite mouseRightSprite;

	// SFML objects for displaying the items as a texture
	Texture shurikenIconTexture;
	Sprite shurikenIconSprite;

	Texture katanaIconTexture;
	Sprite katanaIconSprite;

    Texture mediPackIconTexture;
    Sprite mediPackIconSprite;

    Texture keyIconTexture;
    Sprite keyIconSprite;

    Texture bossHealthBarTexture;
    Sprite bossHealthBarSprite;

    // Private method to update the health sprite based on the player's health
    void updateHealthSprite();

public:
    // Constructor to initialize the HUD
    HUD();

    // Function to draw the HUD to the window
    void draw(RenderWindow& window, vector<int> inventory, size_t hp, shared_ptr<Boss> boss);

	void inventoryDisplay(RenderWindow& window, vector<int> items);

    void setTextures(vector<Texture>& textures);
};

#endif // !HUD_H