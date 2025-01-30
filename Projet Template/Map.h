#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Wall.h"
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

	vector<vector<char>> map;

	vector<unique_ptr<Wall>> walls;

public:
	Map();
	~Map();

	vector<vector<char>> getMap();
	vector<unique_ptr<Wall>>& getWalls();

	void draw(sf::RenderWindow& window);

	void loadMap(int mapNum);
};


#endif