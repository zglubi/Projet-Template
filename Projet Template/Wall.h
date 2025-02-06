#ifndef WALL_H
#define WALL_H
#include "Entity.h"


class Wall : public Entity
{
public:
	int type;
	Wall(Texture& texture, float x, float y, int type);
	~Wall();
	Sprite getSprite();

	void draw(RenderWindow& window) override;
	void update(RenderWindow& window, float deltatime, View& view) override;
};

#endif // WALL_H