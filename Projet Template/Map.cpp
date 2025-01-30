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
	textureGrass = createColoredTexture(Color::Green, Vector2u(32, 32));
	spriteGrass.setTexture(textureGrass);
	textureRock = createColoredTexture(Color::Blue, Vector2u(32, 32));
	spriteRock.setTexture(textureRock);

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
			if (map[i][j] == 'G')
			{
				spriteGrass.setPosition(j * 32, i * 32);
				window.draw(spriteGrass);
			}
			else if (map[i][j] == 'R')
			{
				spriteRock.setPosition(j * 32, i * 32);
				window.draw(spriteRock);
			}
		}
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
		}
		map.push_back(row);
	}
}