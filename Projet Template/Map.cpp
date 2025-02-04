#include "Map.h"
#include <fstream>
#include <iostream>


Map::Map()
{
	tilesetFloor.loadFromFile("assets/map_assets/Tilesets/TilesetFloor.png");
	
	spriteSand.setTexture(tilesetFloor);
	spriteSand.setTextureRect(IntRect(16, 16, 16, 16));

	spriteGrass.setTexture(tilesetFloor);
	spriteGrass.setTextureRect(IntRect(0, 192, 16, 16));





	tilesetDesert.loadFromFile("assets/map_assets/Tilesets/TilesetDesert.png");

	spriteHouse1.setTexture(tilesetDesert);
	spriteHouse1.setTextureRect(IntRect(96, 64, 64, 64));

	spriteWallH.setTexture(tilesetDesert);
	spriteWallH.setTextureRect(IntRect(304, 64, 16, 48));

	spriteWallV.setTexture(tilesetDesert);
	spriteWallV.setTextureRect(IntRect(240, 176, 16, 16));


	tilesetVillageA.loadFromFile("assets/map_assets/Tilesets/TilesetVillageAbandoned.png");


	spritePillarA.setTexture(tilesetVillageA);
	spritePillarA.setTextureRect(IntRect(32, 48, 16, 48));

	spriteRockA.setTexture(tilesetVillageA);
	spriteRockA.setTextureRect(IntRect(48, 80, 16, 16));


	loadMap(1);
}


Texture Map::createColoredTexture(Color color, Vector2u size)
{
	Image image;
	image.create(size.x, size.y, color);
	Texture texture;
	texture.loadFromImage(image);
	return texture;
}



Map::~Map()
{
	map.clear();
	walls.clear();
}

vector<vector<char>> Map::getMap()
{
	return map;
}

vector<unique_ptr<Wall>>& Map::getWalls()
{
	return walls;
}

void Map::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			spriteSand.setPosition(j * 16, i * 16);
			window.draw(spriteSand);
		}
	}

	for (auto& wall : walls)
	{
		wall->draw(window);
	}
}

void Map::loadMap(int mapNum)
{
	walls.clear();
	
	string path = "maps/map" + to_string(mapNum) + ".txt";
	
	ifstream file(path);
	if (!file.is_open())
	{
		cout << "Error: file not found" << endl;
		return;
	}
	string line;
	while (getline(file, line))
	{
		vector<char> row;
		for (int i = 0; i < line.size(); i++)
		{
			row.push_back(line[i]);
			switch (line[i])
			{
				case 'R':
					walls.push_back(make_unique<Wall>(i * 32, map.size() * 32, 'R'));
					break;
				case 'S':
					walls.push_back(make_unique<Wall>(i * 32, map.size() * 32, 'S'));
					break;
				case 's':
					walls.push_back(make_unique<Wall>(i * 32, map.size() * 32, 's'));
					break;
				case 'E':
					walls.push_back(make_unique<Wall>(i * 32, map.size() * 32, 'E'));
					break;
				case 'e':
					walls.push_back(make_unique<Wall>(i * 32, map.size() * 32, 'e'));
					break;
				case 'Q':
					walls.push_back(make_unique<Wall>(i * 32, map.size() * 32, 'Q'));
					break;
				case 'q':
					walls.push_back(make_unique<Wall>(i * 32, map.size() * 32, 'q'));
					break;
				default:
					break;
			}
		}
		map.push_back(row);
	}
}