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

	Texture tilesetFloor;

	Sprite spriteGrass;
	Sprite spriteSand;


	Texture tilesetDesert;

	Sprite spriteHouse1;
	Sprite spriteHouse2;
	Sprite spriteHouse3;
	Sprite spriteTower;
	Sprite spriteWallT;
	Sprite spriteWallH;
	Sprite spriteWallV;
	Sprite spriteTree;
	Sprite spriteShop;
	Sprite spriteWell;


	Texture tilesetVillageA;

	Sprite	spritePillarA;
	Sprite	spriteRockA;

	Texture createColoredTexture(Color color, Vector2u size);

	vector<vector<char>> map;

	vector<unique_ptr<Wall>> walls;

public:
	Map();
	~Map();

	vector<vector<char>> getMap();
	vector<unique_ptr<Wall>>& getWalls();

	void draw(RenderWindow& window);

	void loadMap(int mapNum);

	void setTextures(vector<Texture>& textures);
};


#endif // MAP_H