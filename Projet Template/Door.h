#pragma once
#ifndef DOOR_H
#define DOOR_H
#include "Entity.h"


class Door : public Entity
{
public:
	int type;
	bool isOpen = true;
	int nextlvl;
	Door(Texture& texture, float x, float y, int nextlvl, bool isOpen, int type);
	~Door();
	Sprite getSprite();
	void open();

	void draw(RenderWindow& window) override;

	void update(RenderWindow& window, float deltatime, View& view) override;
};

#endif // WALL_H