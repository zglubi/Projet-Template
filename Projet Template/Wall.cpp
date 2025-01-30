#include "Wall.h"

Wall::Wall(float x, float y, char t) : Entity(x, y), type(t)
{
	texture.loadFromFile("assets/map_assets/props.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(288, 306, 32, 46));
	sprite.setPosition(Vector2f(x, y - 14));
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

void Wall::update(RenderWindow& window, Time deltatime, View& view)
{
}