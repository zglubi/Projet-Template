#include "Wall.h"

Wall::Wall(float x, float y, Sprite Sprite) : Entity(x, y)
{
	sprite = Sprite;
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