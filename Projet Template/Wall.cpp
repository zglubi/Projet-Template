#include "Wall.h"

Wall::Wall(Texture& texture, float x, float ye) : Entity(texture, x, y)
{
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