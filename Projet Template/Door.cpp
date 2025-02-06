#include "Door.h"

Door::Door(Texture& texture, float x, float y, int nextlvl, bool isOpen, int type) :type(type), nextlvl(nextlvl), Entity(texture, x, y)
{
	switch (type)
	{
	case(99)://grotte door
	{
		sprite.setTextureRect(IntRect(144, 48, 48, 64)); break;
	}

	default:
		break;
	}
	sprite.setScale(4, 4);
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
		sprite.setTextureRect(IntRect(96, 48, 48, 64)); break;
	default:
		break;
	}
}

void Door::draw(RenderWindow& window)
{
	window.draw(sprite);
}

void Door::update(RenderWindow& window, float deltatime, View& view)
{
}