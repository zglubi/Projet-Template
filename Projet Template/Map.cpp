#include"Map.h"
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
	floors.clear();
}

vector<vector<char>> Map::getMap()
{
	return map;
}

vector<unique_ptr<Wall>>& Map::getWalls()
{
	return walls;
}

vector<unique_ptr<Door>>& Map::getDoor()
{
    return doors;
}

vector<unique_ptr<Floor>>& Map::getFloor()
{
    return floors;
}

void Map::draw(RenderWindow& window)
{
    for (auto& floor : floors)
    {
        floor->draw(window);
    }
    for (auto& wall : walls)
    {
        wall->draw(window);
    }
    for (auto& door : doors)
    {
        door->draw(window);
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

            // Vérifiez que tileCode contient bien deux caractères numériques
            if (!isdigit(tileCode[0]) || !isdigit(tileCode[1]))
            {
                cout << "Warning: Invalid tile code '" << tileCode << "' at position " << i << "." << endl;
                continue;
            }

            int tileValue;
            try
            {
                tileValue = stoi(tileCode);
            }
            catch (const std::invalid_argument& e)
            {
                cout << "Error: Invalid argument for stoi: " << tileCode << " at position " << i << "." << endl;
                continue;
            }
            catch (const std::out_of_range& e)
            {
                cout << "Error: Out of range argument for stoi: " << tileCode << " at position " << i << "." << endl;
                continue;
            }

            row.push_back(tileCode[0]);
            if (tileValue == 00 )
            {
                floors.push_back(make_unique<Floor>(tilesetFloor, i / 2 * 32, map.size() * 32, tileValue));
            }
            else if (tileValue < 31)
            {
                floors.push_back(make_unique<Floor>(tilesetFloor, i / 2 * 32, map.size() * 32, tileValue));
            }
			else if (tileValue <= 45)
            {
                walls.push_back(make_unique<Wall>(tilesetDesert, i / 2 * 32, map.size() * 32, tileValue));
            }
            else if (tileValue <= 56)
            {
                walls.push_back(make_unique<Wall>(tilesetVillageA, i / 2 * 32, map.size() * 32, tileValue));
            }
            else if (tileValue <= 64)
            {
                walls.push_back(make_unique<Wall>(tilesetElement, i / 2 * 32, map.size() * 32, tileValue));
            }
            else if (tileValue == 99)
            {
                doors.push_back(make_unique<Door>(tilesetElement, i / 2 * 32, map.size() * 32, 2, false,  tileValue));
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
    tilesetElement = textures[3];
}