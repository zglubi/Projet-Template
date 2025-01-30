#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Map
{
private:
	Texture textureGrass;
	Sprite spriteGrass;

	Texture textureRock;
	Sprite spriteRock;

	Texture createColoredTexture(Color color, Vector2u size);

public:
	Map();
	~Map();
	void draw(sf::RenderWindow& window);
};


#endif