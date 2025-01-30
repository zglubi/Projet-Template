#include "Map.h"

Texture Map::createColoredTexture(Color color, Vector2u size)
{
	Image image;
	image.create(size.x, size.y, color);
	Texture texture;
	texture.loadFromImage(image);
	return texture;
}

Map::Map()
{
	textureGrass = createColoredTexture(Color::Green, Vector2u(32, 32));
	spriteGrass.setTexture(textureGrass);
	textureRock = createColoredTexture(Color::Blue, Vector2u(32, 32));
	spriteRock.setTexture(textureRock);
}