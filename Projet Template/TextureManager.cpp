#include "TextureManager.h"


TextureManager::TextureManager() {}

TextureManager::~TextureManager() {}

void TextureManager::loadTextures1()
{
	tilesetFloor.loadFromFile("assets/map_assets/Tilesets/TilesetFloor.png");
    tilesetDesert.loadFromFile("assets/map_assets/Tilesets/TilesetDesert.png");
    tilesetVillageA.loadFromFile("assets/map_assets/Tilesets/TilesetVillageAbandoned.png");
	texturesMap.push_back(tilesetFloor);
	texturesMap.push_back(tilesetDesert);
	texturesMap.push_back(tilesetVillageA);

    healthTexture.loadFromFile("assets\\Hud\\Health\\bar.png");
    healthBarBorderTexture.loadFromFile("assets\\Hud\\Health\\border.png");
    inventoryTexture.loadFromFile("assets/Hud/Inventory.png");
    shurikenIconTexture.loadFromFile("assets/Icons/Shuriken.png");
    katanaIconTexture.loadFromFile("assets/Icons/Katana.png");
    mouseTexture.loadFromFile("assets/Hud/mouse.png");
    mediPackIconTexture.loadFromFile("assets/Icons/Heal.png");
    keyIconTexture.loadFromFile("assets/Icons/GoldenKey.png");
	texturesHud.push_back(healthTexture);
	texturesHud.push_back(healthBarBorderTexture);
	texturesHud.push_back(inventoryTexture);
	texturesHud.push_back(mouseTexture);
	texturesHud.push_back(shurikenIconTexture);
	texturesHud.push_back(katanaIconTexture);
	texturesHud.push_back(mediPackIconTexture);
	texturesHud.push_back(keyIconTexture);
}

void TextureManager::loadTextures2()
{
    playerTexture.loadFromFile("assets/Player/SpriteSheet.png");
    chaserTexture.loadFromFile("assets/Enemies/Slime3/Slime3.png");
    shooterTexture.loadFromFile("assets/Enemies/Snake3/Snake3.png");
    medipackTexture.loadFromFile("assets/Items/Medipack.png");
    katanaTexture.loadFromFile("assets\\Items\\Weapons\\Katana.png");
    shurikenTexture.loadFromFile("assets/Projectiles/Shuriken.png");
    playerProjectileTexture.loadFromFile("assets\\Projectiles\\Shuriken.png");
    katanaSlashTexture.loadFromFile("assets\\Slash\\katanaCurved.png");
    shooterProjectileTexture.loadFromFile("assets/Projectiles/BigEnergyBall.png");
	bossTexture.loadFromFile("assets/Enemies/Slime3/Slime3.png");
	bossProjectileTexture.loadFromFile("assets\\Projectiles\\Shuriken.png");
	bossSlashTexture.loadFromFile("assets\\Slash\\katanaCurved.png");
	texturesEntities.push_back(playerTexture);
	texturesEntities.push_back(chaserTexture);
	texturesEntities.push_back(shooterTexture);
	texturesEntities.push_back(medipackTexture);
	texturesEntities.push_back(katanaTexture);
	texturesEntities.push_back(shurikenTexture);
	texturesEntities.push_back(playerProjectileTexture);
	texturesEntities.push_back(katanaSlashTexture);
	texturesEntities.push_back(shooterProjectileTexture);
	texturesEntities.push_back(bossTexture);
	texturesEntities.push_back(bossProjectileTexture);
	texturesEntities.push_back(bossSlashTexture);
}

vector<Texture>& TextureManager::getTexturesMap()
{
	return texturesMap;
}

vector<Texture>& TextureManager::getTexturesHud()
{
	return texturesHud;
}

vector<Texture>& TextureManager::getTexturesEntities()
{
	return texturesEntities;
}