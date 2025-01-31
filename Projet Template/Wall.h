#ifndef WALL_H
#define WALL_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
using namespace sf;
using namespace std;

class Wall : public Entity
{
private:
	Texture texture;
	Sprite sprite;
	char type;
public:
	Wall(float x, float y, char t);
	~Wall();
	Sprite getSprite();

	void draw(RenderWindow& window) override;
	void update(RenderWindow& window, float deltatime, View& view) override;
};

#endif // WALL_H