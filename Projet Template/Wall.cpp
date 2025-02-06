#include "Wall.h"

Wall::Wall(Texture& texture, float x, float y, int type) : Entity(texture, x, y)
{
	sprite.setTexture(texture);//16, 32, 48, 64, 80, 96
	switch (type)			   // 1   2   3   4   5   6
	{
//===========================================TilesetDesert========================================================
	case(31)://House
		sprite.setTextureRect(IntRect(0, 0, 48, 48));break;
	case(32)://House
		sprite.setTextureRect(IntRect(48, 0, 48, 80));break;
	case(33)://House
		sprite.setTextureRect(IntRect(96, 0, 64, 48));break;
	case(34)://House
		sprite.setTextureRect(IntRect(160, 0, 96, 64));break;
	case(35)://House
		sprite.setTextureRect(IntRect(256, 0, 64, 64));break;


	case(36)://Puit
		sprite.setTextureRect(IntRect(0, 48, 32, 32));break;
	case(37)://House
		sprite.setTextureRect(IntRect(96, 48, 64, 64));break;
	case(38)://Trees
		sprite.setTextureRect(IntRect(160, 64, 64, 48));break;
	case(39)://Tour
		sprite.setTextureRect(IntRect(224, 64, 48, 80));break;
	case(40)://Wall horizontale
		sprite.setTextureRect(IntRect(304, 34, 16, 48));break;
	case(41)://fontaine
		sprite.setTextureRect(IntRect(0, 96, 32, 48));break;
	case(42)://Shop
		sprite.setTextureRect(IntRect(32, 160, 32, 32));break;
	case(43)://Panier
		sprite.setTextureRect(IntRect(96, 176, 16, 16));break;
	case(44)://Tree
		sprite.setTextureRect(IntRect(160, 160, 32, 32));break;
	case(45)://Wall Verticale
		sprite.setTextureRect(IntRect(240, 176, 16, 16));break;

//==============================================TilesetVillageA=====================================================
		//16, 32, 48, 64, 80, 96
		// 1   2   3   4   5   6
	case(46)://House1
		sprite.setTextureRect(IntRect(0, 0, 64, 48));break;
	case(47)://House2
		sprite.setTextureRect(IntRect(64, 0, 64, 48));break;
	case(48)://House3
		sprite.setTextureRect(IntRect(128, 0, 48, 48));break;
	case(49)://House4
		sprite.setTextureRect(IntRect(176, 0, 64, 48));break;
	case(50)://Tower
		sprite.setTextureRect(IntRect(224, 0, 48, 80));break;
	case(51)://Statue
		sprite.setTextureRect(IntRect(0, 48, 32, 32));break;
	case(52)://Pillar
		sprite.setTextureRect(IntRect(32, 48, 16, 48));break;
	case(53)://Kayoux
		sprite.setTextureRect(IntRect(48, 80, 16, 16));break;
	case(54)://Tronc V
		sprite.setTextureRect(IntRect(96, 96, 16, 48));break;
	case(55)://Arbre
		sprite.setTextureRect(IntRect(64, 96, 32, 32));break;
	case(56)://Big Arbre
		sprite.setTextureRect(IntRect(0, 144, 48, 48));break;


//===============================================TilesetElement============================================================

	case(57)://Pillar
		sprite.setTextureRect(IntRect(96, 176, 16, 48));break;
	case(58)://Big satue
		sprite.setTextureRect(IntRect(112, 176, 32, 48));break;
	case(59)://Ninja satue
		sprite.setTextureRect(IntRect(176, 208, 32, 32));break;
	case(60)://woman satue
		sprite.setTextureRect(IntRect(208, 176, 16, 32));break;
	case(61)://short pillar
		sprite.setTextureRect(IntRect(208, 208, 16, 32));break;
	case(62)://tombe
		sprite.setTextureRect(IntRect(0, 80, 16, 32));break;
	case(63)://pot
		sprite.setTextureRect(IntRect(0, 160, 16, 16));break;

	default:
		break;
	}
	sprite.setScale(2, 2);
	sprite.setPosition(x, y);
}

Wall::~Wall()
{
}

Sprite Wall::getSprite()
{
	return sprite;
}

void Wall::draw(RenderWindow& window)
{
	window.draw(sprite);
}

void Wall::update(RenderWindow& window, float deltatime, View& view)
{
}