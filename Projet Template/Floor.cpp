#include "Floor.h"

Floor::Floor(Texture& texture, float x, float y, int type) : Entity(texture, x, y)
{
	sprite.setTexture(texture);
	switch (type)
	{//=============================SABLE================================
	case(0)://vide
		sprite.setTextureRect(IntRect(32, 64, 16, 16));break;
	case(1)://top-left
		sprite.setTextureRect(IntRect(0, 0, 16, 16));break;
	case(2)://left
		sprite.setTextureRect(IntRect(0, 16, 16, 16));break;
	case(3)://bot left
		sprite.setTextureRect(IntRect(0, 32, 16, 16));break;
	case(4)://top
		sprite.setTextureRect(IntRect(16, 0, 16, 16));break;
	case(5)://full
		sprite.setTextureRect(IntRect(16, 16, 16, 16));break;
	case(6)://bot
		sprite.setTextureRect(IntRect(16, 32, 16, 16));break;
	case(7)://top right
		sprite.setTextureRect(IntRect(32, 0, 16, 16));break;
	case(8)://right
		sprite.setTextureRect(IntRect(32, 16, 16, 16));break;
	case(9)://bot right
		sprite.setTextureRect(IntRect(32, 32, 16, 16));break;
	case(10)://creux
		sprite.setTextureRect(IntRect(48, 48, 16, 16));break;

	case(11)://full bis
		sprite.setTextureRect(IntRect(16, 64, 16, 16));break;
	case(12)://full sand
		sprite.setTextureRect(IntRect(0, 80, 16, 16));break;
	case(13)://right grass
		sprite.setTextureRect(IntRect(48, 96, 16, 16));break;
	case(14):// top right grass 
		sprite.setTextureRect(IntRect(64, 96, 16, 16));break;
	case(15):// bot left grass
		sprite.setTextureRect(IntRect(80, 96, 16, 16));break;

	//=============================TERRE==================================
	case(16)://top-left
		sprite.setTextureRect(IntRect(0, 112, 16, 16));break;
	case(17)://left
		sprite.setTextureRect(IntRect(0, 128, 16, 16));break;
	case(18)://bot left
		sprite.setTextureRect(IntRect(0, 144, 16, 16));break;
	case(19)://top
		sprite.setTextureRect(IntRect(16, 112, 16, 16));break;
	case(20)://full
		sprite.setTextureRect(IntRect(16, 128, 16, 16));break;
	case(21)://bot
		sprite.setTextureRect(IntRect(16, 144, 16, 16));break;
	case(22)://top right
		sprite.setTextureRect(IntRect(32, 112, 16, 16));break;
	case(23)://right
		sprite.setTextureRect(IntRect(32, 128, 16, 16));break;
	case(24)://bot right
		sprite.setTextureRect(IntRect(32, 144, 16, 16));break;
	case(25)://creux
		sprite.setTextureRect(IntRect(32, 48, 16, 16));break;

	case(26)://full bis
		sprite.setTextureRect(IntRect(16, 176, 16, 16));break;
	case(27)://full grass
		sprite.setTextureRect(IntRect(0, 192, 16, 16));break;
	case(28)://right sand
		sprite.setTextureRect(IntRect(48, 208, 16, 16));break;
	case(29):// top right sand 
		sprite.setTextureRect(IntRect(64, 208, 16, 16));break;
	case(30):// bot left  sand
		sprite.setTextureRect(IntRect(80, 208, 16, 16));break;
	default:
		break;
	}
	sprite.setScale(2, 2);
	sprite.setPosition(x, y);
}

Floor::~Floor()
{
}

Sprite Floor::getSprite()
{
	return sprite;
}

void Floor::draw(RenderWindow& window)
{
	window.draw(sprite);
}

void Floor::update(RenderWindow& window, float deltatime, View& view)
{
}