#ifndef FLOOR_H
#define FLOOR_H
#include "Entity.h"
using namespace sf;
using namespace std;

class Floor : public Entity
{
public:

	Floor(Texture& texture, float x, float y, int type);
	~Floor();
	Sprite getSprite();

	void draw(RenderWindow& window) override;
	void update(RenderWindow& window, float deltatime, View& view) override;
};

#endif // WALL_H