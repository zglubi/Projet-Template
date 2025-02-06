#include "Map.h"
#include <fstream>
#include <iostream>


Map::Map() {}


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

void Map::draw(RenderWindow& window)
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (j < 57)
			spriteSand.setPosition(j * 32, i * 32);
			else
			spriteGrass.setPosition(j * 32, i * 32);
			window.draw(spriteSand);
			window.draw(spriteGrass);
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
    map.clear();
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
        for (size_t i = 0; i < line.size(); i += 2)
        {
            if (i + 1 >= line.size())
            {
                cout << "Warning: Uneven characters in map file. Skipping last character." << endl;
                break;
            }

            string tileCode = line.substr(i, 2);
            int tileValue = stoi(tileCode);

            row.push_back(tileCode[0]);
            if (tileValue > 29)
            {
                walls.push_back(make_unique<Wall>(tilesetDesert, i / 2 * 32, map.size() * 32, tileValue));
            }
            
            else if (tileValue > 40)
            {
                walls.push_back(make_unique<Wall>(tilesetVillageA, i / 2 * 32, map.size() * 32, tileValue));
            }
            
            else
            {
                cout << "Warning: Unknown tile code '" << tileCode << "' at position " << i << "." << endl;
            }
        }
        map.push_back(row);
    }
}

void Map::setTextures(vector<Texture>& textures)
{
	tilesetFloor = textures[0];
	tilesetDesert = textures[1];
	tilesetVillageA = textures[2];


	spriteSand.setTexture(tilesetFloor);
	spriteSand.setTextureRect(IntRect(16, 16, 16, 16));
	spriteSand.setScale(2, 2);

	spriteGrass.setTexture(tilesetFloor);
	spriteGrass.setTextureRect(IntRect(0, 192, 16, 16));
	spriteGrass.setScale(2, 2);



	spriteHouse1.setTexture(tilesetDesert);
	spriteHouse1.setTextureRect(IntRect(96, 48, 64, 64));
	spriteHouse1.setScale(2, 2);

	spriteWallH.setTexture(tilesetDesert);
	spriteWallH.setTextureRect(IntRect(304, 64, 16, 48));
	spriteWallH.setScale(2, 2);

	spriteWallV.setTexture(tilesetDesert);
	spriteWallV.setTextureRect(IntRect(240, 176, 16, 16));
	spriteWallV.setScale(2, 2);



	spritePillarA.setTexture(tilesetVillageA);
	spritePillarA.setTextureRect(IntRect(32, 48, 16, 48));
	spritePillarA.setScale(2, 2);

	spriteRockA.setTexture(tilesetVillageA);
	spriteRockA.setTextureRect(IntRect(48, 80, 16, 16));
	spriteRockA.setScale(2, 2);
}