#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Wall.h"
#include "Door.h"
#include "Floor.h"

using namespace std;
using namespace sf;

class Map
{
private:

	Texture tilesetFloor;
	Texture tilesetDesert;
	Texture tilesetVillageA;
	Texture tilesetElement;

	Texture createColoredTexture(Color color, Vector2u size);

	vector<vector<char>> map;

	vector<unique_ptr<Wall>> walls;
	vector<unique_ptr<Door>> doors;
	vector<unique_ptr<Floor>> floors;

public:
	Map();
	~Map();

	vector<vector<char>> getMap();
	vector<unique_ptr<Wall>>& getWalls();
	vector<unique_ptr<Floor>>& getFloor();
	vector<unique_ptr<Door>>& getDoor();

	void draw(RenderWindow& window);

	void loadMap(int mapNum);

	void setTextures(vector<Texture>& textures);
};


#endif // MAP_H