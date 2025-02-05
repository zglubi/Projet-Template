#include "TextureManager.h"


TextureManager::TextureManager() {}

TextureManager::~TextureManager() {}

void TextureManager::loadTextures1()
{
    tilesetFloor.loadFromFile("assets/map_assets/Tilesets/TilesetFloor.png");
    tilesetDesert.loadFromFile("assets/map_assets/Tilesets/TilesetDesert.png");
    tilesetVillageA.loadFromFile("assets/map_assets/Tilesets/TilesetVillageAbandoned.png");

    healthTexture.loadFromFile("assets\\Hud\\Health\\bar.png");
    healthBarBorderTexture.loadFromFile("assets\\Hud\\Health\\border.png");
    inventoryTexture.loadFromFile("assets/Hud/Inventory.png");
    shurikenIconTexture.loadFromFile("assets/Icons/Shuriken.png");
    katanaIconTexture.loadFromFile("assets/Icons/Katana.png");
    mouseTexture.loadFromFile("assets/Hud/mouse.png");
    mediPackIconTexture.loadFromFile("assets/Icons/Heal.png");
    keyIconTexture.loadFromFile("assets/Icons/GoldenKey.png");
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
}

vector<Texture>& TextureManager::getTexturesMap()
{
    vector<Texture> textures;
	textures.push_back(tilesetFloor);
	textures.push_back(tilesetDesert);
	textures.push_back(tilesetVillageA);
	return textures;
}

vector<Texture>& TextureManager::getTexturesHud()
{
	vector<Texture> textures;
	textures.push_back(healthTexture);
	textures.push_back(healthBarBorderTexture);
	textures.push_back(inventoryTexture);
	textures.push_back(shurikenIconTexture);
	textures.push_back(katanaIconTexture);
	textures.push_back(mouseTexture);
	textures.push_back(mediPackIconTexture);
	textures.push_back(keyIconTexture);
	return textures;
}

vector<Texture>& TextureManager::getTexturesEntities()
{
	vector<Texture> textures;
	textures.push_back(playerTexture);
	textures.push_back(chaserTexture);
	textures.push_back(shooterTexture);
	textures.push_back(medipackTexture);
	textures.push_back(katanaTexture);
	textures.push_back(shurikenTexture);
	textures.push_back(playerProjectileTexture);
	textures.push_back(katanaSlashTexture);
	textures.push_back(shooterProjectileTexture);
	textures.push_back(bossTexture);
	textures.push_back(bossProjectileTexture);
	textures.push_back(bossSlashTexture);
	return textures;
}