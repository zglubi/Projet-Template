#include "Wall.h"

Wall::Wall(float x, float y, char t) : Entity(x, y), type(t)
{

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