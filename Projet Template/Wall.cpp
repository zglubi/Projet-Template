#include "Wall.h"

Wall::Wall(Texture& texture, float x, float y, int type) : Entity(texture, x, y)
{
	sprite.setTexture(texture);//16, 32, 48, 64, 80, 96
	switch (type)			   // 1   2   3   4   5   6
	{
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

//===================================================================================================


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