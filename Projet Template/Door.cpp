#include "Door.h"

Door::Door(Texture& texture, float x, float y, int nextlvl, bool isOpen, int type) :type(type), Entity(texture, x, y)
{
	switch (type)
	{
	case(99)://grotte door
		sprite.setTextureRect(IntRect(96, 48, 48, 64)); break;
	default:
		break;
	}
	sprite.setPosition(x, y);
}

Door::~Door()
{
}

Sprite Door::getSprite()
{
	return sprite;
}

void Door::open() {

	isOpen = true;
	switch (type)
	{
	case(99)://grotte door
		sprite.setTextureRect(IntRect(144, 48, 48, 64)); break;
	default:
		break;
	}
}