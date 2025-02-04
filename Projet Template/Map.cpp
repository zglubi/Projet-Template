#include "Map.h"
#include <fstream>
#include <iostream>


Map::Map()
{
	tilesetFloor.loadFromFile("assets/map_assets/Tilesets/TilesetFloor.png");
	
	spriteSand.setTexture(tilesetFloor);
	spriteSand.setTextureRect(IntRect(16, 16, 16, 16));
	spriteSand.setScale(2, 2);

	spriteGrass.setTexture(tilesetFloor);
	spriteGrass.setTextureRect(IntRect(0, 192, 16, 16));
	spriteGrass.setScale(2, 2);




	tilesetDesert.loadFromFile("assets/map_assets/Tilesets/TilesetDesert.png");

	spriteHouse1.setTexture(tilesetDesert);
	spriteHouse1.setTextureRect(IntRect(96, 48, 64, 64));
	spriteHouse1.setScale(2, 2);

	spriteWallH.setTexture(tilesetDesert);
	spriteWallH.setTextureRect(IntRect(304, 64, 16, 48));
	spriteWallH.setScale(2, 2);

	spriteWallV.setTexture(tilesetDesert);
	spriteWallV.setTextureRect(IntRect(240, 176, 16, 16));
	spriteWallV.setScale(2, 2);


	tilesetVillageA.loadFromFile("assets/map_assets/Tilesets/TilesetVillageAbandoned.png");


	spritePillarA.setTexture(tilesetVillageA);
	spritePillarA.setTextureRect(IntRect(32, 48, 16, 48));
	spritePillarA.setScale(2, 2);

	spriteRockA.setTexture(tilesetVillageA);
	spriteRockA.setTextureRect(IntRect(48, 80, 16, 16));
	spriteRockA.setScale(2, 2);

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
			spriteSand.setPosition(j * 32, i * 32);
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
				case 'M':
				{
					walls.push_back(make_unique<Wall>(i * 32, map.size() * 32, spriteHouse1));
					break;
				}
				case 'H':
				{
					walls.push_back(make_unique<Wall>(i * 32, map.size() * 32, spriteWallH));
					break;
				}
				case 'V':
				{
					walls.push_back(make_unique<Wall>(i * 32, map.size() * 32, spriteWallV));
					break;
				}
				case 'p':
				{
					walls.push_back(make_unique<Wall>(i * 32, map.size() * 32, spritePillarA));
					break;
				}
				case 'r':
				{
					walls.push_back(make_unique<Wall>(i * 32, map.size() * 32, spriteRockA));
					break;
				}
				default:
					break;
			}
		}
		map.push_back(row);
	}

}