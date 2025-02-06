#include "Wall.h"

Wall::Wall(Texture& texture, float x, float y, int type) : Entity(texture, x, y)
{
	switch (type)
	{
	case(31):
		sprite.setTextureRect(IntRect(96, 48, 64, 64));
	case(32):
		sprite.setTextureRect(IntRect(304, 64, 16, 48));
	case(33):
		sprite.setTextureRect(IntRect(240, 176, 16, 16));
	
	
	
	case(34):
		sprite.setTextureRect(IntRect(96, 48, 64, 64));
	case(35):
		sprite.setTextureRect(IntRect(96, 48, 64, 64));
	case(36):
		sprite.setTextureRect(IntRect(96, 48, 64, 64));
	case(37):
		sprite.setTextureRect(IntRect(96, 48, 64, 64));
	case(38):
		sprite.setTextureRect(IntRect(96, 48, 64, 64));
	case(39):
		sprite.setTextureRect(IntRect(96, 48, 64, 64));

	case(40):
		sprite.setTextureRect(IntRect(32, 48, 16, 48));
	case(41):
		sprite.setTextureRect(IntRect(48, 80, 16, 16));
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