#include "Map.h"
#include <fstream>
#include <iostream>

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
	textureGrass.loadFromFile("assets/map_assets/tileset_grass.png");
	spriteGrass.setTexture(textureGrass);
	spriteGrass.setTextureRect(IntRect(0, 0, 32, 32));

	loadMap("maps/map1.txt");
}

Map::~Map()
{
	map.clear();
}

vector<vector<char>> Map::getMap()
{
	return map;
}

void Map::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			spriteGrass.setPosition(j * 32, i * 32);
			window.draw(spriteGrass);
		}
	}

	for (auto& wall : walls)
	{
		wall->draw(window);
	}
}

void Map::loadMap(string path)
{
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
				default:
					break;
			}
		}
		map.push_back(row);
	}
}