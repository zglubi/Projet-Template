#include "Wall.h"

Wall::Wall(float x, float y, char t) : Entity(x, y), type(t)
{
	switch (type)
	{
	case 'R':
		texture.loadFromFile("assets/map_assets/props.png");
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(288, 306, 32, 46));
		sprite.setPosition(Vector2f(x, y - 14));
		break;
	case 'S':
		texture.loadFromFile("assets/map_assets/struct.png");
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(32, 160, 64, 96));
		sprite.setPosition(Vector2f(x, y));
		break;

	case 's':
		texture.loadFromFile("assets/map_assets/struct.png");
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(32, 32, 64, 96));
		sprite.setPosition(Vector2f(x, y));
		break;
	case 'E':
		texture.loadFromFile("assets/map_assets/struct.png");
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(128, 160, 64, 96));
		sprite.setPosition(Vector2f(x, y));
		break;
	case 'e':
		texture.loadFromFile("assets/map_assets/struct.png");
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(128, 32, 64, 96));
		sprite.setPosition(Vector2f(x, y));
		break;
	case 'Q':
		texture.loadFromFile("assets/map_assets/struct.png");
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(224, 160, 64, 96));
		sprite.setPosition(Vector2f(x, y));
		break;
	case 'q':	
		texture.loadFromFile("assets/map_assets/struct.png");
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(224, 32, 64, 96));
		sprite.setPosition(Vector2f(x, y));
		break;
	}

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