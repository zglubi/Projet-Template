#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	void loadTextures1();

	void loadTextures2();

	vector<Texture>& getTexturesMap();

	vector<Texture>& getTexturesHud();

	vector<Texture>& getTexturesEntities();

private:
	Texture tilesetFloor;
	Texture tilesetDesert;
	Texture tilesetVillageA;

	Texture healthTexture;
	Texture healthBarBorderTexture;
	Texture inventoryTexture;
	Texture mouseTexture;
	Texture shurikenIconTexture;
	Texture katanaIconTexture;
	Texture mediPackIconTexture;
	Texture keyIconTexture;

	Texture playerTexture;
	Texture chaserTexture;
	Texture shooterTexture;
	Texture medipackTexture;
	Texture katanaTexture;
	Texture shurikenTexture;
	Texture playerProjectileTexture;
	Texture katanaSlashTexture;
	Texture shooterProjectileTexture;
	Texture bossTexture;
	Texture bossProjectileTexture;
	Texture bossSlashTexture;
};

