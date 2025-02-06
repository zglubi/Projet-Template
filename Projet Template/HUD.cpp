#include "HUD.h"

// Constructor to initialize the HUD
HUD::HUD()
{
}

// Function to display the inventory
void HUD::inventoryDisplay(RenderWindow& window, vector<int> items) {
    for (int i = 0; i < items.size(); i++) {
        switch (items[i]) {
        case 1:
            shurikenIconSprite.setPosition(window.getView().getCenter().x - window.getView().getSize().x / 2 + 562.f+70.f*i, window.getView().getCenter().y - window.getView().getSize().y / 2 + 912.f);
            window.draw(shurikenIconSprite);
            break;
        case 2:
            katanaIconSprite.setPosition(window.getView().getCenter().x - window.getView().getSize().x / 2 + 562.f + 70.f * i, window.getView().getCenter().y - window.getView().getSize().y / 2 + 912.f);
            window.draw(katanaIconSprite);
            break;

        case 3:
            mediPackIconSprite.setPosition(window.getView().getCenter().x - window.getView().getSize().x / 2 + 562.f + 70.f * i, window.getView().getCenter().y - window.getView().getSize().y / 2 + 912.f);
            window.draw(mediPackIconSprite);
            break;
        case 4:
            keyIconSprite.setPosition(window.getView().getCenter().x - window.getView().getSize().x / 2 + 562.f + 70.f * i, window.getView().getCenter().y - window.getView().getSize().y / 2 + 912.f);
            window.draw(keyIconSprite);
            break;
        }

    }

}

// Function to draw the HUD to the window
void HUD::draw(RenderWindow& window, vector<int> inventory, size_t hp, shared_ptr<Boss> boss)
{
    healthSprite.setTextureRect(IntRect(8, 54, static_cast<float>(78 * (static_cast<float>(hp) / static_cast<float>(100))), 6));
    healthSprite.setPosition(window.getView().getCenter().x - window.getView().getSize().x / 2 + 588.f, window.getView().getCenter().y - window.getView().getSize().y / 2 + 834.f);
    window.draw(healthSprite);

    healthBarBorderSprite.setScale(4, 4);
    healthBarBorderSprite.setPosition(window.getView().getCenter().x - window.getView().getSize().x / 2 + 580.f, window.getView().getCenter().y - window.getView().getSize().y / 2 + 830.f);
    window.draw(healthBarBorderSprite);

    inventorySprite.setPosition(window.getView().getCenter().x - window.getView().getSize().x / 2 + 550.f, window.getView().getCenter().y - window.getView().getSize().y / 2 + 900.f);
    window.draw(inventorySprite);

    mouseLeftSprite.setPosition(window.getView().getCenter().x - window.getView().getSize().x / 2 + 572.f, window.getView().getCenter().y - window.getView().getSize().y / 2 + 875.f);
    window.draw(mouseLeftSprite);

    mouseRightSprite.setPosition(window.getView().getCenter().x - window.getView().getSize().x / 2 + 642.f, window.getView().getCenter().y - window.getView().getSize().y / 2 + 875.f);
    window.draw(mouseRightSprite);

    if (boss)
    {
		healthBarBorderSprite.setScale(7, 7);
        healthBarBorderSprite.setPosition(window.getView().getCenter().x - window.getView().getSize().x / 2 + 480.f, window.getView().getCenter().y - window.getView().getSize().y / 2 + 30.f);
        window.draw(healthBarBorderSprite);

        bossHealthBarSprite.setPosition(window.getView().getCenter().x - window.getView().getSize().x / 2 + 494.f, window.getView().getCenter().y - window.getView().getSize().y / 2 + 37.f);
		window.draw(bossHealthBarSprite);
    }

	inventoryDisplay(window, inventory);
}


void HUD::setTextures(vector<Texture>& textures)
{
    healthTexture = textures[0];
    healthBarBorderTexture = textures[1];
    inventoryTexture = textures[2];
    mouseTexture = textures[3];
    shurikenIconTexture = textures[4];
    katanaIconTexture = textures[5];
    mediPackIconTexture = textures[6];
    keyIconTexture = textures[7];
    bossHealthBarTexture = textures[8];


    healthSprite.setTexture(healthTexture);
    healthSprite.setTextureRect(IntRect(8, 54, 78, 6));
    healthSprite.setPosition(20.f, 20.f);
    healthSprite.setScale(4.1, 4.1);

    healthBarBorderSprite.setTexture(healthBarBorderTexture);
    healthBarBorderSprite.setPosition(20.f, 20.f);
    healthBarBorderSprite.setScale(4, 4);
    healthBarBorderSprite.setTextureRect(IntRect(6, 65, 83, 11));

    inventorySprite.setTexture(inventoryTexture);
    inventorySprite.setPosition(70.f, 70.f);
    inventorySprite.setScale(0.5f, 0.5f);

    shurikenIconSprite.setTexture(shurikenIconTexture);
    shurikenIconSprite.setScale(2.0f, 2.0f);

    
    katanaIconSprite.setTexture(katanaIconTexture);
    katanaIconSprite.setScale(2.0f, 2.0f);
    
    mouseLeftSprite.setTexture(mouseTexture);
    mouseLeftSprite.setTextureRect(IntRect(210, 78, 54, 81));
    mouseLeftSprite.setScale(0.3, 0.3);

    mouseRightSprite.setTexture(mouseTexture);
    mouseRightSprite.setTextureRect(IntRect(398, 78, 54, 81));
    mouseRightSprite.setScale(0.3, 0.3);

    mediPackIconSprite.setTexture(mediPackIconTexture);
    mediPackIconSprite.setScale(2.0f, 2.0f);
    
    keyIconSprite.setTexture(keyIconTexture);
    keyIconSprite.setScale(2.0f, 2.0f);

    bossHealthBarSprite.setTexture(bossHealthBarTexture);
    bossHealthBarSprite.setTextureRect(IntRect(8, 54, 78, 6));
    bossHealthBarSprite.setPosition(20.f, 20.f);
    bossHealthBarSprite.setScale(7.1, 7.1);
}