#include "Door.h"

Door::Door(Texture& texture, float x, float y, Sprite spriteopen, Sprite spriteclose, int nextlvl, bool isOpen, int type) : Wall(texture, x, y, type)
{
	if (isOpen) {
		sprite = spriteopen;
	}
	else sprite = spriteclose;
	
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
	sprite = spriteopen;
}