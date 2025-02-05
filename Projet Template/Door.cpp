#include "Door.h"

Door::Door(Texture& texture, float x, float y, int nextlvl, bool isOpen, int type) : Wall(texture, x, y, type)
{
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
}